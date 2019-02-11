#include <iostream>
#include <climits>
#include <vector>
#include <utility>

using namespace std;

const int INF = INT_MAX-100;

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

bool relax(Node *u, Node *v, int weight) {
    // put your code here
    if(v->dist == 0 || u->dist == INF) return false;
    if(v->dist > (u->dist + weight)){
        v->dist = u->dist + weight;
        v->parent = u;
        return false;
    }
    return true;
}

bool bellmann_ford(Node **nodes, int n, Node *start) {
    bool test;
    start->dist = 0;
    vector<pair<Node*, int>>::iterator it;
    for(int i = 1; i < n; i++){   
        test = true;
        for(int j = 0; j < n; j++){
            for(it = nodes[j]->neighbours.begin(); it != nodes[j]->neighbours.end(); it++){
                test = relax(nodes[j],get<0>(*it),get<1>(*it));
            }
        }
        if(test) return true;
    }

    for(int i = 0; i < n; i++){
        vector<pair<Node*, int>>::iterator it;
        for(it = nodes[i]->neighbours.begin(); it != nodes[i]->neighbours.end(); it++)
            if(get<0>(*it)->dist != 0 && get<0>(*it)->dist != INF && get<0>(*it)->dist > (nodes[i]->dist + get<1>(*it)))
                return false;
    }
    return true;
}

void write(Node **nodes, int n){
    for(int i = 0; i < n; i++){
        vector<pair<Node*, int>>::iterator it;
        printf("%d: ",i);
        for(it = nodes[i]->neighbours.begin(); it != nodes[i]->neighbours.end(); it++)
            printf("%d $%d, ",get<0>(*it)->val,get<1>(*it));
        printf("\n");
    }
}

int main() {
    int N, k, start, end;
    cin >> N >> k;
    Node **nodes = new Node*[N];
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