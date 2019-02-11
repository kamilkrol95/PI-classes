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
    Node* n = (Node*)(malloc(sizeof(Node*)));
    n->val = val;
    n->height = getHeight(max_height);
    n->next = (Node**)(malloc(sizeof(Node*)*max_height));
    return n;
}

void deleteNode(Node* n) {
    n = NULL;
    free(n);
}

SkipList* newSkipList(int max_height, int n) {
    SkipList* list = (SkipList*)(malloc(sizeof(Node*)*n));
    list->max_height = max_height;
    
    list->start = newNode(INT_MIN,max_height);
    list->end = newNode(INT_MAX,max_height);
    list->start->next = (Node**)(malloc(sizeof(Node*)*max_height));
    list->end->next = (Node**)(malloc(sizeof(Node*)*max_height));
    
    for(int i=0; i<max_height; i++) {
        list->start->next[i] = list->end;
        list->end->next[i] = NULL;
    }

    return list;
}

void deleteSkipList(SkipList* list) {
    Node* tmp = NULL;
    for(int i = 0; i < list->max_height; i++){
        tmp = list->start->next[i];
        deleteNode(list->start);
        list->start = tmp;
    }
    free(list);
}

void insert(SkipList* list, Node* node) {
    Node* tmp = list->start;
    node->next = (Node**)(malloc(sizeof(Node*)*list->max_height));
    Node* prev[list->max_height];
    for(int i = list->max_height-1; i >= 0; i--){
        while(tmp->next[i]->val < node->val && tmp->next[i] != NULL) tmp = tmp->next[i];
        prev[i] = tmp; 
    }
    if(tmp->next[0]->val == node->val) return;
    for(int i = list->max_height-1; i >= 0; i--){
        node->next[i] = prev[i]->next[i];
        prev[i]->next[i] = node;
    }
}

int main(int argc, char** argv) {
    /*
     * test data:
     * Z - number of test cases
     * h, I - max height of single node (h), number of values to insert (I)
     * I values to insert
     * Output:
     * I lines, subsequent values stored in list
    */
    srand(time(NULL));
    int Z;
    scanf("%d", &Z);

    for (int i=0; i<Z; i++) {
        int h, I;
        scanf("%d", &h);
        scanf("%d", &I);

        SkipList* list = newSkipList(h,I);
        int x;
        // insert
        for(int j=0; j<I; j++) {
            scanf("%d", &x);
            insert(list, newNode(x, h));
        }
        // print all values
        Node* iter = list->start;
        Node* tmp = list->start;
        tmp = tmp->next[0];
        while(tmp->next[0] != NULL) {
            printf("%d\n", iter->next[0]->val);
            tmp = tmp->next[0];
            iter = iter->next[0];
        }        
        // cleanup
        deleteSkipList(list);
    }
}