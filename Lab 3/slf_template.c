#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Node {
    int val;
    int height;
    struct Node** next;
} Node;

typedef struct SkipList {
    int max_height;
    Node* start;
    Node* end;
} SkipList;

int getHeight(int max_h) {
    int h = 1;
    float p = 0.8;
    while (h < max_h && rand() / (RAND_MAX + 1.) < p) h++;
    return h;
}


/*
 * paste here your pretty code from previous task
 */


Node* find(SkipList* list, int val) {
    Node* tmp = list->start;
    int i = list->max_height - 1;
    while (i >= 0) {
        // while value of tmp->next[i] is less than value of given node, go ahead
        i--;
    }
    // return desired node or NULL if such value doesn't exist in the skiplist
}

int main(int argc, char** argv) {
    /*
     * test data:
     * Z - number of test cases
     * h, I, F - max height of single node (h), number of values to insert (I) and find (F)
     * I values to insert
     * F values to find
     * Output:
     * F lines, "y" or "n" in each one - depending on whether given value is present in the skiplist or not
    */
    srand(time(NULL));
    int Z;
    scanf("%d", &Z);

    for (int i=0; i<Z; i++) {
        int h, I, F;
        scanf("%d", &h);
        scanf("%d", &I);
        scanf("%d", &F);

        SkipList* list = newSkipList(h);
        int x;
        // insert
        for(int j=0; j<I; j++) {
            scanf("%d", &x);
            insert(list, newNode(x, h));
        }
        // find
        for(int j=0; j<F; j++) {
            scanf("%d", &x);
            printf("%s\n", find(list, x) == NULL ? "n" : "y");
        }

        // cleanup
    }
}