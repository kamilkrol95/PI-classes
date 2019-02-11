#include <stdio.h>
#include <iostream>
// we're big guys now, let's use already implemeted list
// you might want check this out: http://www.cplusplus.com/reference/list/list/#functions
#include <list>
#include <stack>

using namespace std;

// Global variables are bad, but in this case
// passing them in function would soon exceed memory limit.
// Trust me, I tried.
int n;
list<int> *graph;
list<int> *line;
stack<int> STOS;

/* void euler(int u) {
    while (!graph[u].empty())
    {
        int v = // take first neighbour of u


        // iterate over neighbours of v
        // you can use list<int>::iterator it = graph[v].begin()
        // which makes "it" iterator (sth like pointer) pointing on first element of graph[v] list
        // iterator can be moved to next position like this: it++
        // and if you move it after last element of list it will be equal to graph[v].end()
        for ()
        {
            // if you find u remove it from list
            // you can access element pointed by iterator just like with pointer
            if ()
            {
                // use erase method
            }
        }

        // recursively enter v
    }

    // add city to line

}
 */
void iterLine(list<int> *graph){
    for (list<int>::iterator it = graph->begin(); it != graph->end(); it++)
        std::cout << *it << ' ';
    printf("\n");
}

void iterate(list<int> graph){
    for (list<int>::iterator it = graph.begin(); it != graph.end(); it++)
        std::cout << *it << ' ';
    printf("\n");
}

/* void euler(int u){
    while(!graph[u].empty()){
        int v = graph[u].front(); 
        for(list<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++){            
            iterate(graph[u]);
            iterate(graph[v]); printf(" %d\n",graph[v].front());
            if(u == *it){
                printf("jestem\n");
                it = graph[u].erase(it);
                graph[v].erase(graph[u].front());
            }
            iterate(graph[u]);
            iterate(graph[v]);
        }
        u = v;
        line->push_back(u); printf("+u: %d\n",u);
    }
    
} */

void euler(int u){
    STOS.push(u);
    while(STOS.size()){
        int u = STOS.top();
        if(!graph[u].empty()){
            list<int>::iterator it, it_p;
            it = graph[u].begin();
            it_p = it;
            int v = graph[u].front();
            STOS.push(v);
            graph[u].erase(it);
            graph[v].erase(graph[u].begin());
            u = v;
        }
        else{
            STOS.pop();
            line->push_back(u);
        }
    }
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
        }


       int start = 1;
        for(int i = 1; i <= n; i++)   
            if (graph[i].size() != start){
                start = graph[i].size();
                // printf("START: %d %d\n",start,graph[i].size());
            }  
        euler(start);         
        printf("LISTA: \n");
        printf("1\n");
        printf("%lu, size ", line->size());
        for (list<int>::iterator it = line->begin(); it != line->end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");

        delete [] graph;
        delete line;
    }
}
