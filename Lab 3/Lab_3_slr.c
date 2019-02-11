#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

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

Node* newNode(int val, int max_height) {
    Node* n = (Node*)(malloc(sizeof(Node)));
    n->val = val;
    n->height = getHeight(max_height);
    n->next = (Node**)(malloc(sizeof(Node*)*max_height));
    for(int i = 0; i < max_height; i++){
        n->next[i] = NULL;
    }
    return n;
}

void deleteNode(Node* n) {
    free(n->next);
    free(n);
}

SkipList* newSkipList(int max_height, int n) {
    SkipList* list = (SkipList*)(malloc(sizeof(SkipList)));
    list->max_height = max_height;
    
    list->start = newNode(INT_MIN,max_height);
    list->end = newNode(INT_MAX,max_height);
    list->start->height = max_height;
    list->end->height = max_height;
    
    for(int i=0; i<max_height; i++) {
        list->start->next[i] = list->end;
        list->end->next[i] = NULL;
    }

    return list;
}

void deleteSkipList(SkipList* list) {
    Node* tmp = list->start;
    while(tmp != NULL){
        Node *pom = tmp;
        tmp = tmp->next[0];
        deleteNode(pom);
    }
    free(list);
}

void insert(SkipList* list, Node* node) {
    Node* tmp = list->start;
    Node* prev[list->max_height];
    for(int i = list->max_height-1; i >= 0; i--){
        while(tmp->next[i]->val < node->val && tmp->next[i] != NULL) tmp = tmp->next[i];
        prev[i] = tmp; 
    }
    for(int i = list->max_height-1; i >= 0; i--){
        node->next[i] = prev[i]->next[i];
        prev[i]->next[i] = node;
    }
}

Node* find(SkipList* list, int val) {
    Node* tmp = list->start;
    
    for(int i = list->max_height-1; i >= 0; i--)
        while(tmp->next[i]->val < val && tmp->next[i] != NULL) tmp = tmp->next[i];
        tmp = tmp->next[0];
        return tmp->val == val ? tmp : NULL;   
}

void removeFromList(SkipList* list, Node* node) {    
    Node* tmp = list->start;
    
    for(int i = list->max_height-1; i >= 0; i--){
        while(tmp->next[i]->val < node->val) tmp = tmp->next[i];

        if(tmp->next[i]->val == node->val){
            tmp->next[i] = tmp->next[i]->next[i];
        }
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

        SkipList* list = newSkipList(h,I);
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