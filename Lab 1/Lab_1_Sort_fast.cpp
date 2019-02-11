#include<stdio.h>
#include<stdlib.h>
  
struct Node
{
    int val;
    Node* next;
};
 
/* function declarations */
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source, Node*& frontRef, Node*& backRef);

Node* MergeSort(Node* headRef) {
  //struct Node* head = headRef;
  Node* a = headRef;
  Node* b = headRef;

  if ((headRef == NULL) || (headRef->next == NULL)) {
    return headRef;
  }

  while(b != NULL){
  	b = b->next;
  	if(b->next != NULL)
  		b = b->next;
  	a = a->next;
  }
  // split into two lists in half
  //FrontBackSplit(head, a, b); 
  b = a->next;
  a->next = NULL;
  a = headRef;
  // Recursively sort the sublists
  a = MergeSort(a);
  b = MergeSort(b);

  // merge the two sorted lists together
  return SortedMerge(a, b);
}
 
Node* SortedMerge(Node* a, Node* b) {
  Node* result = NULL;

  if (a == NULL)
     return(b);
  else if (b == NULL)
     return(a);
 
  if (a->val <= b->val){
  	a->next = SortedMerge(a->next,b);
  	return a;
  }
  else{
  	b->next = SortedMerge(a,b->next);
  	return b;
  }
  
}
 
/* Split the nodes of the given list into front and back halves,
   and return the two lists using the reference parameters.
   Uses the fast/slow pointer strategy - one pointer should
   move by 1 one node, while second one by 2 nodes.  */
void FrontBackSplit(Node* source, Node*& frontRef, Node*& backRef) {
  Node *fast;
  Node *slow;
  if (source == NULL || source->next == NULL)
  {
    /* length < 2 cases */
    frontRef = source;
    backRef = NULL;
  }
  else
  {
    slow = source;
    fast = source->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */

    /**********************************
    * This is the place for your code *
    ***********************************/
 
    /* 'slow' is before the midpoint in the list, so split it in two
      at that point. */
    frontRef = source;
    backRef = slow->next;
    slow->next = NULL;
  }
}

 
int main() {
    
    int Z;
    scanf("%d", &Z);

    int val;

    while (Z--) {

        Node *head = NULL;
        Node *curr = NULL;
        
        int n, val;
        scanf("%d", &n);

        while (n--) {
            scanf("%d", &val);
            Node *temp = new Node;
            temp->val = val;
            temp->next = NULL;
            if (head == NULL) {
                head = temp;
                curr = temp;
            } else {
                curr->next = temp;
                curr = temp;
            }
        }

        Node *pr = head;
      	head = MergeSort(head);

        while (head != NULL) {
            printf("%d\n", head->val);
            curr = head;
            head = head->next;
            /**************************************
            * Hey! Remember not to litter around! *
            **************************************/
        }

    }

}
