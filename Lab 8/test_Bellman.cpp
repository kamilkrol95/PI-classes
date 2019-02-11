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

bool relax(Node *u, Node *v, int weight) {
    // put your code here
    if(v->dist > (u->dist + weight)){
        v->dist = u->dist + weight;
        printf("relax: %d %d\n",u->dist,v->dist);
        return false;
    }
    printf("relax: %d %d\n",u->dist,v->dist);
    return true;
}

bool bellmann_ford(Node **nodes, int n, Node *start) {
    // put your code here
    // printf("jestm bf\n");
    bool test;
    start->dist = 0;
    test = true;
    vector<pair<Node*, int>>::iterator it;
    for(it = start->neighbours.begin(); it != start->neighbours.end(); it++){
        test = relax(start,get<0>(*it),get<1>(*it));
        // printf("relax: %d %d %d\n",nodes[i]->dist,get<0>(*it)->dist,get<1>(*it));
    }
    if(test) return true;

    for(it = start->neighbours.begin(); it != start->neighbours.end(); it++)
        if(get<0>(*it)->dist > start->dist + get<1>(*it))
            return false;

    return true;
}

void write(Node **nodes, int n){
    for(int i = 0; i < n; i++){
        vector<pair<Node*, int>>::iterator it;
        printf("%d: ",i);
        for(it = nodes[i]->neighbours.begin(); it != nodes[i]->neighbours.end(); it++)
            // printf("%d $%d, ",get<0>(*it)->val,get<0>(*it)->dist);//get<1>(*it));
            printf("%d ",get<0>(*it)->val);
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
        addEdge(nodes[u], nodes[v], w); // w - edge value
    }
    printf("ver. 1\n");
    write(nodes,N);

    cin >> start >> end;
    if (!bellmann_ford(nodes, N, nodes[start])) cout << "CYKL" << endl;
    else if (nodes[end]->dist < INF) cout << nodes[end]->dist << endl;
    else cout << "NIE" << endl;
    // write(nodes,N);
    for(int i=0; i<N; i++) delete nodes[i];
}