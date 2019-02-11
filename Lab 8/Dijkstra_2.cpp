#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int INF = INT_MAX;

typedef struct Node {
    Node *parent;
    vector <pair<Node *, int>> neighbours;
    int val, dist;
} Node;

Node *newNode(int val) {
    Node *n = new Node;
    n->val = val;
    n->dist = INF;
    n->parent = NULL;
}

void addEdge(Node *u, Node *v, int w) {
    pair <Node *, int> u_edge(v, w);
    pair <Node *, int> v_edge(u, w);
    u->neighbours.push_back(u_edge);
    v->neighbours.push_back(v_edge);
}

auto cmp = [](Node *x, Node *y) { return x->dist > y->dist; };

bool relax(Node *u, Node *v, int weight) {
    // put your code here
}

void writeQueue(priority_queue<Node *, vector<Node *>, decltype(cmp)> q){
    while(!q.empty()){
        printf("%d ",q.top()->val);
        q.pop();
    }
}

void dijkstra(Node **nodes, int n, Node *start) {
    priority_queue <Node *, vector<Node *>, decltype(cmp)> queue(cmp);
    
    queue.push(start);
    
    start->dist = 0;
    while(!queue.empty()){
        Node *uu = queue.top();
        int u = queue.top()->val;
        queue.pop();
       
        vector <pair<Node*, int>>::iterator it;
        for(it = nodes[u]->neighbours.begin(); it != nodes[u]->neighbours.end(); it++){
            if(get<0>(*it)->dist > (nodes[u]->dist + get<1>(*it))){
                get<0>(*it)->dist = nodes[u]->dist + get<1>(*it);
                get<0>(*it)->parent = uu;
                queue.push(get<0>(*it));
            }
        }
    }

}

void write(Node **nodes, int n){
    vector<pair<Node*, int>>::iterator it;
    for(int i = 0; i < n; i++){
        printf("%d: ",i);
        for(it = nodes[i]->neighbours.begin(); it != nodes[i]->neighbours.end(); it++)
            printf("%d $%d | ",get<0>(*it)->val,get<1>(*it));
        printf("\n");
    }
}

int main() {
    int N, k, start, end;
    cin >> N >> k;
    Node *nodes[N];
    for (int i = 0; i < N; i++) nodes[i] = newNode(i);

    for (int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(nodes[u], nodes[v], w);
    }
 
    cin >> start >> end;
    dijkstra(nodes, N, nodes[start]);
    cout << nodes[end]->dist << endl;

    for (int i=0; i<N; i++) delete nodes[i];
}