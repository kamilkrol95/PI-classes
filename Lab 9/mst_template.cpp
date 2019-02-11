#include <cstdio>
#include <queue>

using namespace std;

struct edge
{
    int u, v;
    int s;
};

// this is called operator overload
// we can now use operator < with edges
// priority_queue<edge> will also use this operator to sort edges
bool operator< (edge a, edge b)
{
    if (a.s > b.s)
        return true;
    else
        return false;
}


int find (int x, int* parent)
{
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
}

void union (int x, int y, int* parent)
{
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
}

unsigned long long mst(priority_queue<edge> Q, int n)
{
    unsigned long long cost = 0;
    int *parent = new int[n+1];
    
    for (int i = 0; i <= n; i++) {
        parent[i] = // ????;
    }

    /**********************
    * PLACE FOR YOUR CODE *
    **********************/

    return cost;
}

int main ()
{
    int Z;
    scanf("%d", &Z);
    while(Z--)
    {
        int n, m;
        scanf ("%d %d", &n, &m);

        edge temp;
        int u, v, s;

        priority_queue<edge> Q;

        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &s);
            /**********************
            * PLACE FOR YOUR CODE *
            **********************/
        }

        unsigned long long cost = mst(Q, n);

        printf ("%llu\n", cost);
    }
}
