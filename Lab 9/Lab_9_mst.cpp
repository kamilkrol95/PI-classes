#include <cstdio>
#include <queue>

using namespace std;

struct edge{
    int u, v;
    int s;
};

// this is called operator overload
// we can now use operator < with edges
// priority_queue<edge> will also use this operator to sort edges
bool operator< (edge a, edge b){
    if (a.s > b.s)
        return true;
    else
        return false;
}


int find (int x, int* parent){
    if(parent[x] != x)
        return parent[x] = find(parent[x],parent);
    return parent[x];
}

void uni (int x, int y, int* parent){
    x = find(x,parent);
    y = find(y,parent);
    if(x == y) return;
    parent[y] = x;
}

unsigned long long mst(priority_queue<edge> Q, int n){
    unsigned long long cost = 0;
    int *parent = new int[n+1];
    
    for (int i = 0; i <= n; i++){
         parent[i] = i;
    }
    edge tmp;
    for(int i = 1; i < n; i++){
        do{
            tmp = Q.top();
            Q.pop();
        } while(find(tmp.u,parent) == find(tmp.v,parent) && !Q.empty());
        cost += tmp.s;
        uni(tmp.u,tmp.v,parent);
    }
    delete [] parent;
    return cost;
}

void write(priority_queue<edge> Q){
    while(!Q.empty()){
        edge e = Q.top(); 
        printf("%d <-> %d: %d\n",e.u, e.v, e.s);
        Q.pop();
    }
}

int main (){
    int Z;
    scanf("%d", &Z);
    while(Z--){
        int n, m;
        scanf ("%d %d", &n, &m);

        edge temp;
        int u, v, s;

        priority_queue<edge> Q;

        for (int i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &s);
            temp.u = u;
            temp.v = v;
            temp.s = s;            
            Q.push(temp);
        }
        // write(Q);
        unsigned long long cost = mst(Q, n);

        printf ("%llu\n", cost);
    }
}
