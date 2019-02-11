#include <stdio.h>
#include <iostream>
// we're big guys now, let's use already implemeted list
// you might want check this out: http://www.cplusplus.com/reference/list/list/#functions
#include <list>

using namespace std;

enum graph_type {
    EULER = 1,
    HALF = 2,
    NO = 3
};

graph_type check_graph(list<int> graph[], int n) {
    int p = 0, np = 0;
    for(int i = 0; i < n; i++){
        if(graph[i].size()%2 == 0) p++;
        else np++;
    }

    if ( p == n ) {
        return EULER;
    } else if ( np <= 2 ) {
        return HALF;
    } else {
        return NO;
    }
}

void iterate(list<int> graph[], int n){
    for(int i = 0; i < n; i++){
        printf("%d: ",i);
        for(list<int>::iterator it = graph[i].begin(); it != graph[i].end(); it++)
            cout << *it << ' ';
        printf("\n");
    }
}
int main() {
    int Z;

    scanf("%d", &Z);

    while (Z--) {

        int n, m;
        int u, v;
        scanf("%d %d", &n, &m);
        list<int> *graph = new list<int>[n+1];
        for(int i=0; i<m; i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        //iterate(graph,n);
        graph_type result = check_graph(graph, n);
        switch(result) {
            case EULER:
                printf("EULER\n");
                break;
            case HALF:
                printf("HALF\n");
                break;
            case NO:
                printf("NO\n");
                break;
        }
        delete [] graph;
    }
}
