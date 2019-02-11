#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct Node{
	int val;
	Node* next;
} Node;

void write(Node** graph, int n){
	
	for(int i = 0; i < n; i++){
		Node* tmp = graph[i];
		printf("%d: ",i);
		while(tmp != NULL){
			printf("%d ",tmp->val);
			tmp = tmp->next;
		}
		printf("\n");
	}
	printf("\n");
}

Node** create(int n, int k){
	Node** graph = new Node*[n];
	for(int i = 0; i < n; i++) graph[i] = NULL;
	int x, y;
	for(int i = 0; i < k; i++){
		cin >> x; 
		cin >> y;	
		Node* tmp1 = new Node;
		Node* tmp2 = new Node;
		
		tmp1->val = y;
		tmp1->next = graph[x];
		graph[x] = tmp1;
		tmp2->val = x;
		tmp2->next = graph[y];
		graph[y] = tmp2;
	}
	return graph;	
}

bool checkConnectList(Node** graph, int n, int x, int y){
	bool *visit = new bool[n];
	for(int i = 0; i < n; i++)
		visit[i] = false;
	
	visit[x] = true;
	for(Node* tmp = graph[x]; tmp; tmp = tmp->next)
		if(visit[tmp->val] == false and tmp->val == y)
			return true;
	delete [] visit;
	return false;
}

int main(){
	
	int n, k, p;
	
	cin >> n;
	cin >> k;
	cin >> p;
	Node** graph = create(n,k);
	//write(graph,n);
		
	for(int i = 0; i < p; i++){
		int x, y;
		cin >> x; 
		cin >> y;

		if(checkConnectList(graph,n,x,y)) printf("TAK\n");
		else printf("NIE\n");
	}
	delete [] graph;
}


