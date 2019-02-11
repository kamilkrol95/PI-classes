#include <cstdio>
#include <queue>
// #define DEBUG 1

using namespace std;

struct edge{
    int u, v;
    int s;
};

bool operator< (edge a, edge b){
    if (a.s < b.s)
        return true;
    else
        return false;
}

void print_map(int **map, int n){
    #ifdef DEBUG
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", map[i][j]);        
        printf("\n");
    }    
    printf("\n");
    #endif
}

void writeTab(int *tab, int n){
    for(int i = 0; i < n*n; i++)
        printf("%d ",tab[i]);
    printf("\n");
}

void writeGraph(priority_queue<edge> Q){
    edge tmp;
    while(!Q.empty()){
        tmp = Q.top();
        Q.pop();
        printf("%d <-> %d: %d\n",tmp.u,tmp.v,tmp.s);
    }
    printf("\n");
}

int find (int x, int* parent){
    if(parent[x] != x)
        return parent[x] = find(parent[x],parent);
    return x;
}

void unia (int x, int y, int* parent, int* rank){
    x = find(x,parent);
    y = find(y,parent);
    if(x == y) return;
    if(rank[x] > rank[y])
        parent[y] = x;
    else{
        parent[x] = y;
        if(rank[x] == rank[y])
            rank[y]++;
    }
}

int draught_calculator(int **map, int n, int k){
    int containers = 0;
    int *parent = new int[n*n];
    int* rank = new int[n*n];
    edge tmp;
    priority_queue<edge> Q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            parent[i*n+j] = (i*n+j);
            rank[i*n+j] = 0;
        }
            
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x = i*n+j;
            if(x+1 < (i+1)*n){
                tmp.u = x;
                tmp.v = x+1;
                tmp.s = map[i][j+1];
                Q.push(tmp); 
            }
            if(x+n < n*n){
                tmp.u = x;
                tmp.v = x+n;
                tmp.s = map[i+1][j]; 
                Q.push(tmp);
            }
        } 
    }
    // printf("Size: %d\n",Q.size());
    // writeGraph(Q);
    while(!Q.empty()){
        tmp = Q.top();
        Q.pop();
        if(tmp.s < k) containers = (k - tmp.s);
        if(find(0,parent) == find(n*n-1,parent))
            return containers;
        unia(tmp.u,tmp.v,parent,rank);
    }
    return containers;
}

int main (){
    int Z;
    scanf("%d", &Z);
    while(Z--){
        int n, k;
        scanf ("%d %d", &n, &k);
        int **map = new int*[n];
        for (int i = 0; i < n; i++)
            map[i] = new int[n];

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                scanf("%d", &map[i][j]);
            }
        }

        print_map(map, n);
        
        int result = draught_calculator(map, n, k);

        printf ("%d\n", result);

        for (int i = 0; i < n; i++)
            delete[] map[i];
        delete[] map;

    }
}
