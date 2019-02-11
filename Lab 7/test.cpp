#include <iostream>
#include <stdio.h>
#include <list>
#include <ctime>

using namespace std;

list<int> makeList(list<int> graph, int n){
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        graph.push_back(x);
    } 
    return graph; 
}

void writeList(list<int> graph, int n){
	while(!graph.empty()){
        printf("%d ",graph.front());
        graph.pop_front();
    }
}

void iterate(list<int> graph){
    for (list<int>::iterator it = graph.begin(); it != graph.end(); it++)
    std::cout << *it << ' ';
}

int main(){
    
    int n;
    list<int> graph;
	cin >> n;
 
    graph = makeList(graph,n);
    // printf("FRONT: %d\n",graph.front());
    // writeList(graph,n);
    iterate(graph);
}