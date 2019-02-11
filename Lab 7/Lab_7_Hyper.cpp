#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

int n;
list<int> *graph;
list<int> *line;


void iterate(list<int> graph){
    for (list<int>::iterator it = graph.begin(); it != graph.end(); it++)
        std::cout << *it << ' ';
    printf("\n");
}

void euler(int u) {
    // printf("E1: %d %d\n",u,graph[u].front());
    while (!graph[u].empty()){
        int v = graph[u].front();// take first neighbour of u
        // printf("E2: %d\n",v);
        // iterate(graph[v]);
        for (list<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++){
            // if you find u remove it from list
            // you can access element pointed by iterator just like with pointer
            if (u == *it){
                it = graph[u].erase(it);
                //iterate(graph[v]);
                // printf("E3: %d %d\n",v,*it);
                // line->erase(it);
                // if(!line->empty())   printf("front line: %d\n",line->front());
                // else printf("nie\n");
                // use erase method
            }
            //printf("E33: %d\n",*it);
        }
        // recursively enter v
        // printf("E4: %d\n",v);
        euler(v);
    }

    // add city to line
    // printf("E5: %d\n",u);
    line->push_back(u);
}


int main() {
    int Z;

    scanf("%d", &Z);

    while (Z--) {

        int m, u, v;
        scanf("%d %d", &n, &m);

        graph = new list<int>[n+2];
        line = new list<int>;

        for(int i=0; i<m; i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i = 1; i <= n; i++){
            printf("%d: ",i);
            iterate(graph[i]);
            printf("\n");
        }
        printf("\n");
       
        int start = 1;
        for(int i = 1; i <= n; i++)   
            if (graph[i].size() != start){
                start = graph[i].size();
                // printf("START: %d %d\n",start,graph[i].size());
            }  

        // start euler from correct city
        // printf("\nstart: %d\n",start);           
        euler(start);

        printf("1\n");
        printf("%lu ", line->size());
        for (list<int>::iterator it = line->begin(); it != line->end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");

        delete [] graph;
        delete line;
    }
} 
