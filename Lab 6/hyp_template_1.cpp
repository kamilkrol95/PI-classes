#include <iostream>
#include <stack>

using namespace std;

typedef struct Node {
    int n;
    struct Node* next;
} Node;

void dfs(Node** graph, int* components, int n, int i, int component_no) {
    // traverse the graph and mark all nodes which belong to the component

    stack<int>stos;
    bool* visited=new bool[n];
    for(int i=0;i<n;i++) visited[i]=false;
    
    stos.push(component_no);

    while(!stos.empty()){
        int curr=stos.top();
        stos.pop();
        components[curr]=i;
        visited[curr]=true;

        Node*tmp=graph[curr];

        while(tmp!=NULL){
            if(visited[tmp->n]==false){
                stos.push(tmp->n);
                visited[tmp->n]=true;
            }
            tmp=tmp->next;
        }
    }
    delete visited;
}

int* count_components(Node** graph, int n) {
    // this array shows to which component each node belongs
    // -1 means that node hasn't been visited yet
    int* components = new int[n];
    for(int i=0; i<n; i++) components[i] = -1;
    // prepare components counter
    int j=0;
    // in loop: find unvisited node, call DFS/BFS
    for(int i=0;i<n;i++)
        if(components[i]==-1){
            dfs(graph,components,n,j,i);
            j++;
        }    
    return components;
}

int main() {
    int n, k, p;
    cin >> n;
    Node **graph = new Node*[n];
    for(int i=0;i<n;i++) graph[i]=NULL;
    cin >> k;
    cin >> p;
    for (int i=0; i<k; i++) {
        Node *tmp1 = new Node, *tmp2 = new Node;
        int x, y;
        cin >> x;
        cin >> y;
        tmp1->n = y;
        tmp1->next = graph[x];
        graph[x] = tmp1;
        tmp2->n = x;
        tmp2->next = graph[y];
        graph[y] = tmp2;
    }
    int* components = count_components(graph, n);
    for (int i=0; i<p; i++) {
        int x, y;
        cin >> x;
        cin >> y;
        cout << (components[x] == components[y] ? "TAK" : "NIE") << endl;
    }
}
