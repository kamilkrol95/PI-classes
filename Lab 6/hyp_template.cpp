#include <iostream>

using namespace std;

typedef struct Node {
    int n;
    struct Node* next;
} Node;

void write(Node** graph, int n){
	Node* tmp;
	for(int i = 0; i < n; i++){
		tmp = graph[i];
		printf("%d: ",i);
		while(tmp->next != NULL){
			printf("%d ",tmp->n);
			tmp = tmp->next;
		}
		printf("\n");
	}
}

void dfs(Node** graph, int* components, int n, int i, int component_no) {
    // traverse the graph and mark all nodes which belong to the component
 	components[i] = 0;
 	component_no++;
 	for(Node* tmp = graph[i]; tmp->next; tmp = tmp->next){
 		printf("%d %d %d\n", components[i], component_no, tmp->n);
	 	if(components[tmp->n] == -1) 
		 	dfs(graph,components,n,tmp->n,component_no);		
	}
	if()component_no++;
	components[i] = component_no;
	
/*	for(int j = 0; j < n; j++){
		Node* tmp = graph[j];
		while(tmp->next != NULL){
			if(tmp->n == component_no) components[i]++;	
			tmp = tmp ->next;	
		}
	}	*/
//    for(int j = 0; j < n; j++){
//    	if(graph[i]->n == component_no) components[i]++;
//	}
}

int* count_components(Node** graph, int n) {
    // this array shows to which component each node belongs
    // -1 means that node hasn't been visited yet
    int* components = new int[n];
    for(int i=0; i<n; i++) components[i] = -1;
    // prepare components counter
	int cnt = 0;	
	// in loop: find unvisited node, call DFS/BFS
	for(int i = 0; i < n; i++){
		printf("jestem cnty\n");
		if(components[i] == -1) 
			dfs(graph,components,n,i,cnt);
	}
    return components;
}

int main() {
    int n, k, p;
    cin >> n;
    Node **graph = new Node*[n];
    
    for(int i = 0; i < n; i++) {
    	graph[i] = new Node;
		graph[i]->next = NULL;	
	}
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
    //  for(int i = 0; i < n; i++) printf("%d: %d\n",i,graph[i]->n);
    }
    write(graph,n);
    int* components = count_components(graph, n);
 	for(int i = 0; i < n; i++) printf("%d: %d\n",i,components[i]);
    for (int i=0; i<p; i++) {
        int x, y;
        cin >> x;
        cin >> y;
        cout << (components[x] == components[y] ? "TAK" : "NIE") << endl;
    } 
}
