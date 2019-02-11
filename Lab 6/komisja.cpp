#include <iostream>

using namespace std;

typedef struct Node {
    int n;
    struct Node* next;
} Node;

enum color {
    white,
    gray,
    black
};

void write(Node** graph, int n){
	
	for(int i = 0; i < n; i++){
		Node* tmp = graph[i];
		printf("%d: ",i);
		while(tmp != NULL){
			printf("%d ",tmp->n);
			tmp = tmp->next;
		}
		printf("\n");
	}
	printf("\n");
}

bool find_cycle_from(Node** graph, color* visited, int n, int x) {
    // gray color means "we already processed this node in current lookup" - once x is gray, we are sure we've got a cycle
    // mark x grey
    if(visited[x] == gray) return true;
	visited[x] = gray;
    // iterate over each neighbour and proceed with DFS (recursively or using stack)
    for(Node* tmp = graph[x]; tmp; tmp = tmp->next)
		if (visited[tmp->n] == gray) return true;
		else if (visited[tmp->n] == white)
			if(find_cycle_from(graph,visited,n,tmp->n)) return true;
        // once you found cycle - return immediately 
    // black means "ok, we finally processed that node" - mark x black
    visited[x] = black;
    // found nothing? Return
    return false;
}

bool has_cycle(Node** graph, int n) {
    color visited[n];
    for (int i=0; i<n; i++) visited[i] = white;
    for(int i = 0; i<n; i++) {
        if (visited[i] == white) {
            if (find_cycle_from(graph, visited, n, i)) return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n;
    Node **graph = new Node*[n];
    for(int i = 0; i < n; i++)
    	graph[i] = NULL;
    cin >> k;
    for(int i=0; i<k; i++) {
        Node* tmp = new Node;
        int x, y;
        cin >> x;
        cin >> y;
        tmp->n = y;
        tmp->next = graph[x];
        graph[x] = tmp;
    }
    //write(graph,n);
    cout << (has_cycle(graph, n) ? "CYKL" : "OK") << endl;
}
