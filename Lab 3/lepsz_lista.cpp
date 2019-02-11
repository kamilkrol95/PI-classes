#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>

struct Node {
    int val;
    int height;
    struct Node** next;
} ;

struct SkipList {
    int max_height;
    Node* start;
    Node* end;
} ;

int getHeight(int max_h) {
    int h = 1;
    float p = 0.8;
    while (h < max_h && rand() / (RAND_MAX + 1.) < p) h++;
    return h;
}

Node* newNode(int val, int max_height) {	
    Node* n = new Node;
	printf("new node %d %d\n",val,max_height);
    //n = malloc(sizeof(n));
    n->val = val;
    n->height = getHeight(max_height);
    n->next[n->height] = NULL;
    //n->next = NULL;
    return n;
}

void deleteNode(Node* n) {
	printf("jestem deleteNode\n");
    n = NULL;
    delete n;
}

SkipList* newSkipList(int max_height) {	
    SkipList* list = new SkipList; //malloc(sizeof(SkipList));
    list->max_height = max_height;  
    list->start = newNode(0,max_height);
    list->end = newNode(10,max_height);
    printf("jestem newSkipList%d\n",max_height);
	// allocate list->start and list->end
    // initialize height and next for each one
    
    for(int i = 0; i < max_height; i++) {		    	
        list->start->next[i] = list->end;
        list->end->next[i] = NULL;       
        printf("jestem newSkipList %d\n",i);
    }
	printf("koniec newSkipList\n");
    return list;
}

void deleteSkipList(SkipList* list) {
	Node* tmp = NULL;
	for(int i = 0; i < list->max_height; i++){
		tmp = list->start->next[i];
		deleteNode(list->start);	
		list->start = tmp;	
	}
	
    // call deleteNode() on every node in skiplist
    // call free() on list
}

void insert(SkipList* list, Node* node) {	
    printf("jestem insert%d\n",node->val);
    Node* tmp = list->start;
    int i = list->max_height - 1;
    while (i >= 0) {
    	if(tmp->next[i]->val <= node->val)	tmp = tmp->next[i];
    	else{
    	Node* tmp1 = tmp->next[i];
		tmp->next[i] = node;
		node->next[i] = tmp1; 
		}
        // while value of tmp->next[i] is less than value of given node, go ahead
        // if i isn't too high - insert (plug) given node on level 'i'
        i--;
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

        SkipList* list = newSkipList(h);
        int x;
        // insert        
        for(int j=0; j<I; j++) {
            scanf("%d", &x);
            printf("ins %d %d\n",x,h);
            //Node *temp = newNode(x,h);
            printf("start insert\n");
            insert(list, newNode(x,h));
        }
        // print all values
        Node* iter = list->start, tmp;
        while(iter->next[0] != NULL) {
            printf("%d\n", iter->next[0]->val);
            iter = iter->next[0];
        }
        
        // cleanup
        
    }
}
