#include <stdio.h>

struct Node
{
    int val;
    Node *next;
};

// use if you want implement selection sort
Node* remove_maximum(Node *head) {
    if (head == NULL) {
    	printf("jestem - null\n");
        return NULL;    	
    }
    if (head->next == NULL) {
        Node *tmp = head;
        head = NULL;
        printf("jestem - null,next\n");
        return tmp;
    }

	Node *prev = head;
	head = head->next;	
	Node *befor_max = prev;
	
	while(prev->next != NULL){
		if(head->val > befor_max->next->val)
			befor_max = prev;
			
		prev = prev->next;
		if(head->next != NULL)
			head = head->next;
	}
	
	Node *max = befor_max->next;
	if(max != NULL)
		befor_max->next = max->next;
	return max;
    
}
// use if you want implement insertion sort
Node* insert(Node *&head, Node *item) {
    if (head == NULL || head->val > item->val) {
        item->next = head;
        head = item;
        return head;
    }
	Node *tmp = head;
	while(tmp->next != NULL){
		if(tmp->next->val < item->val)
		tmp = tmp->next;
	}
	item->next = tmp->next;
	tmp->next = item;
	return tmp;
    /*****************************************************
    * What if item should be placed further on the list? *
    *****************************************************/
}

Node* sort(Node *head) {
	Node *new_head = new Node; 
	new_head->next = head;
	Node *result = NULL;
    while(new_head->next != NULL){
    	Node *tmp = remove_maximum(new_head);
    	tmp->next = result;
    	result = tmp;
	}
	delete new_head;
	return result;
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
        head = sort(head);

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
