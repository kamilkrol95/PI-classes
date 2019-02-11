#include <iostream>
#include <climits>
#include <vector>
#include <utility>

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
    pair <Node *, int> edge(v, w);
    u->neighbours.push_back(edge);
}

void relax(Node *u, Node *v, int weight) {
    // put your code here
}

bool bellmann_ford(Node **nodes, int n, Node *start) {
    // put your code here
}

void write(Node **nodes, int n){
    for(int i = 0; i < n; i++)
        printf("%d: %d %d",i,nodes[i]->val,nodes[i]->dist);
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
    if (!bellmann_ford(nodes, N, nodes[start])) cout << "CYKL" << endl;
    else if (nodes[end]->dist < INF) cout << nodes[end]->dist << endl;
    else cout << "NIE" << endl;

    for(int i=0; i<N; i++) delete nodes[i];
}