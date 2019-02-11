#include <iostream>
using namespace std;

typedef struct point {
    int x, y;
} point;

typedef struct neighbours {
    int n;
    point elems[4];
} neighbours;

void write(int** labyrinth, int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			printf("%d\t",labyrinth[i][j]);
		printf("\n");	
	}		
}

neighbours get_neighbours(int** labyrinth, int n, int m, point p) {
    // find (if exist) all neighbours of point p
        // (consider points: one above p, one below p, one on the left site and one on the right site)
    // use defined structures
    int cnt = 0;
    int xp[] = {0,1,0,-1};
    int yp[] = {-1,0,1,0};
    
	neighbours nb;
    for(int i = 0; i < 4; i++){
    	int x = p.x + xp[i];
    	int y = p.y + yp[i];
    	if(x >= 0 and x < n and labyrinth[x][p.y] == 1) nb.elems[i].x = x;
    	else nb.elems[i].x = -2;
    	if(y >= 0 and y < m and labyrinth[p.x][y] == 1) nb.elems[i].y = y;
    	else nb.elems[i].y = -2;
    	cnt++;
	}
	nb.n = cnt;
    return nb;
}

bool dfs(int** graph, int n, int m, bool** visited, point p, point end) {
    // if p is already at the end - return true
    //if(graph[end.y][end.x] == 0) return false;
    if(p.x == end.x and p.y == end.y) return true;
    // mark p visited
    visited[p.x][p.y] = true;
    // call recursively on every unvisited neighbour
    neighbours nb = get_neighbours(graph,n,m,p);
    for(int i = 0; i < 4; i++){
    	p = nb.elems[i];
    	if(p.x > -1 and p.y > -1 and !visited[p.x][p.y])    
			if(dfs(graph,n,m,visited,p,end)) return true;	
	}
    // if all calls finished fruitlessly - you didn't find exit
    return false;
}


int main() {
    int n, m;
    cin >> n;
    cin >> m;
    int **labyrinth = new int*[n];
    for(int i=0; i<n; i++) labyrinth[i] = new int[m];
    bool** visited = new bool*[n];
    for(int i=0; i<n; i++) visited[i] = new bool[m];
		   
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> labyrinth[i][j];
            visited[i][j] = false;
        }
    }
	//write(labyrinth,n,m);
    point start, end;
    cin >> start.x;
    cin >> start.y;
    cin >> end.x;
    cin >> end.y;
    cout << (dfs(labyrinth, n, m, visited, start, end) ? "TAK" : "NIE") << endl;
}
