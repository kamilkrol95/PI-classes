#include <stdio.h>
// we're big guys now, let's use already implemeted list
// you might want check this out: http://www.cplusplus.com/reference/list/list/#functions
#include <list>

using namespace std;

// Global variables are bad, but in this case
// passing them in function would soon exceed memory limit.
// Trust me, I tried.
int n;
list<int> *graph;
int curr_line;
list<int> *lines;
bool is_euler;


void euler(int u)
{
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

    // if we're visiting our dummy city, start a new line
    if (!is_euler && ) {
        // ???
    } else {
        // if not, just add city to current line
    }

}

int main() {
    int Z;

    scanf("%d", &Z);

    while (Z--) {
        int m, u, v;
        scanf("%d %d", &n, &m);

        graph = new list<int>[n+2];
        lines = new list<int>[n+2];

        for(int i=0; i<m; i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        is_euler = true;
        for (int i = 1; i <= n; i++)
        {
            // add dummy city to each city that has odd number of neighbours
            if ()
            {
                // ???
                is_euler = false;
            }
        }

        curr_line = 0;

        if (is_euler) {
            // start euler from any city            
        } else {
            // start euler from dummy city
        }

        // ignore empty lines
        int lines_number = 0;
        for (int i = 0; i <= curr_line; i++)
        {
            if (lines[i].size()>1)
                lines_number++;
        }

        printf("%d\n", lines_number);

        for (int i = 0; i <= lines_number; i++)
        {
            if (lines[i].size() > 1)
            {
                printf("%lu ", lines[i].size());
                for (list<int>::iterator it = lines[i].begin(); it != lines[i].end(); it++)
                {
                    printf("%d ", *it);
                }
                printf("\n");
            }
        }

        delete[] graph;
        delete[] lines;
    }
}
