#include <iostream>
#include<stack>

using namespace std;

typedef struct Node {
    int n;
    struct Node* next;
} Node;

enum color {
    white,
    gray,
    black
};
void dfs(Node** graph, int n, int component_no) {
    // traverse the graph and mark all nodes which belong to the component

    stack<int>stos;
    bool* visited=new bool[n];
    for(int i=0;i<n;i++) visited[i]=false;
    stos.push(component_no);



    while(!stos.empty())
    {
        int curr=stos.top();
        stos.pop();
        //cout << curr;

        visited[curr]=true;

        Node*tmp=graph[curr];

        while(tmp!=NULL)
        {
            if(visited[tmp->n]==false)
            {
              //  cout << "adding "<<tmp->n<<" on stack"<<endl;
                stos.push(tmp->n);
                visited[tmp->n]=true;
            }
            tmp=tmp->next;
        }
        //cout << "out of neighbour while\n";
    }
    delete visited;





}
bool find_cycle_from(Node** graph, color* visited, int n, int x) {
    // gray color means "we already processed this node in current lookup" - once x is gray, we are sure we've got a cycle
    if(visited[x]==gray) return true;
    // mark x grey
    visited[x]=gray;

    // iterate over each neighbour and proceed with DFS (recursively or using stack)
     stack<int>stos;
    bool* been_here=new bool[n];
    for(int i=0;i<n;i++) been_here[i]=false;
    stos.push(x);

    while(!stos.empty())
    {
        int curr=stos.top();
        stos.pop();
        //cout << curr;
        if(curr!=x)
        {
            if(find_cycle_from(graph,visited,n,curr)) return true;
        }

        been_here[curr]=true;

        Node*tmp=graph[curr];

        while(tmp!=NULL)
        {
            if(been_here[tmp->n]==false)
            {
              //  cout << "adding "<<tmp->n<<" on stack"<<endl;
                stos.push(tmp->n);
                been_here[tmp->n]=true;
            }
            tmp=tmp->next;
        }
        //cout << "out of neighbour while\n";
    }
    delete visited;

        // once you found cycle - return immediately

    // black means "ok, we finally processed that node" - mark x black
    visited[x]=black;

    // found nothing? Return
    return false;
}

bool has_cycle(Node** graph, int n) {
    color visited[n];
    for (int i=0; i<n; i++) visited[i] = white;
    for(int i = 0; i<n; i++) {
        if (visited[i] == white) {
            if (find_cycle_from(graph, visited, n, i)) return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n;
    Node **graph = new Node*[n];
    for(int i=0;i<n;i++) graph[i]=NULL;
    cin >> k;
    for(int i=0; i<k; i++) {
        Node* tmp = new Node;
        int x, y;
        cin >> x;
        cin >> y;
        tmp->n = y;
        tmp->next = graph[x];
        graph[x] = tmp;
    }
    cout << (has_cycle(graph, n) ? "CYKL" : "OK") << endl;
}
