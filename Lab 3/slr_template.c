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


void removeFromList(SkipList* list, Node* node) {
    Node* tmp = list->start;
    int i = node->height - 1;
    while (i >= 0) {
        // while value of tmp->next[i] is less than value of given node, go ahead
        // remove (unplug) given node on level 'i'
        i--;
    }
}

int main(int argc, char** argv) {
    /*
     * test data:
     * Z - number of test cases
     * h, I, R, F - max height of single node (h), number of values to insert (I), remove(R) and find (F)
     * I values to insert
     * R values to remove (should exist in the previous set)
     * F values to find
     * Output:
     * F lines, "y" or "n" in each one - depending on whether given value is present in the skiplist or not
    */
    srand(time(NULL));
    int Z;
    scanf("%d", &Z);

    for (int i=0; i<Z; i++) {
        int h, I, R, F;
        scanf("%d", &h);
        scanf("%d", &I);
        scanf("%d", &R);
        scanf("%d", &F);

        SkipList* list = newSkipList(h);
        int x;
        // insert
        for(int j=0; j<I; j++) {
            scanf("%d", &x);
            insert(list, newNode(x, h));
        }
        // remove
        for(int j=0; j<R; j++) {
            scanf("%d", &x);
            Node* n = find(list, x);
            removeFromList(list, n);
            deleteNode(n);
        }
        // find
        for(int j=0; j<F; j++) {
            scanf("%d", &x);
            printf("%s\n", find(list, x) == NULL ? "n" : "y");
        }

        // cleanup
        deleteSkipList(list);
    }
}