#include <stdio.h>
#include <time.h>
#include <cstdlib>

typedef struct BSTnode{
    int val;
    struct BSTnode* right;
    struct BSTnode* left;
    struct BSTnode* parent;
} BSTnode;

void add_node(BSTnode* &root, int value){
    BSTnode* tmp = new BSTnode;
    tmp->val=value;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->parent = NULL;

    // If root is empty?
    if(root == NULL){
    	root = new BSTnode;
		root = tmp;
		return;
    }
	
    BSTnode* tmpRoot = root; 	
    BSTnode* prevRoot = NULL;	

    // Find the father of a new node
    while(tmpRoot != NULL){
        prevRoot = tmpRoot;
        if(tmpRoot->val < value)
        	tmpRoot = tmpRoot->right;
        else 
        	tmpRoot = tmpRoot->left;
    }
    tmp->parent = prevRoot;
	
    // Insert the new node
    if(prevRoot == NULL){
  		root = tmp;
  	}
    else if(prevRoot->val < value){
        prevRoot->right = tmp;
	}
    else{
        prevRoot->left = tmp;
	}
}

BSTnode* min(BSTnode* root){
    if(root == NULL) return root;
	BSTnode* tmp = root;
    while(tmp->left != NULL){
    	tmp = tmp->left;
    }
    return tmp;
}

BSTnode* max(BSTnode* root){
    if(root == NULL) return root;
    BSTnode* tmp = root;
    while(tmp->right != NULL)
    	tmp = tmp->right;
    return tmp;
}
void transplant(BSTnode* u, BSTnode* v){ // u => v w mijesce u wstaiwamy v
	if(u->parent == NULL)
		u = v;
	else if(u == u->parent->left)
		u->parent->left = v;
	else 
		u->parent->right = v;
	if(v != NULL)
	v->parent = u->parent; 		
}

BSTnode* find_succesor(BSTnode* node){
	if(node->right != NULL) 
		return min(node->right);
	
	BSTnode* x = node->parent;
	while(x != NULL && x->right == node){
		node = x;
		x = x->parent;			
	}
	return x;	
}

BSTnode* remove_node(BSTnode* root, int value){
    // When root is null
    if (root == NULL){
        return root;
    }
    BSTnode *x , *y , *node = root;
    while(node != NULL && node->val != value){			// znalezenie noda o war. value
    	if(node->val < value)
    		node = node->right;
    	else 
    		node = node->left; 
	}
	
	if(node->left == NULL || node->right == NULL) y = node; // ustawianie node *y do usuniecia  
	else y = find_succesor(node);

	if(y->left != NULL)	x = y->left;		// przypisanie do x war. y != NULL
	else x = y->right;

	if(x != NULL) x->parent = y->parent;

	if(y->parent == NULL) root = x;
	else if(y == y->parent->left) y->parent->left = x;
	else y->parent->right = x;
	
	if(y != node){
		node->val = y->val;
	}

    return root;
}

void free_BST(BSTnode* root){
    if(root == NULL){
        return;
    }
    if(root->left != NULL){
        free_BST(root->left);
    }
    if(root->right != NULL){
        free_BST(root->right);
    }
    delete root;
    return;
}

void in_order_tree_walk(BSTnode* node){
    if(node->left != NULL){
        in_order_tree_walk(node->left);
    }
    printf("%d\n", node->val);
    if(node->right != NULL){
        in_order_tree_walk(node->right);
    }
}

int main(){
    /*
     * test data:
     * Z - number of test cases
     * N, X - number of insert values, number of deleted values
     * N values to insert
     * X values to remove
     * Output:
     * N-X lines od numberts
    */
    srand(time(NULL));
    int Z;
    scanf("%d", &Z);

    for(int i = 0 ; i < Z ; i++){
        int N, X;
        scanf("%d %d", &N, &X);

        BSTnode* tree = NULL;

        int x;
        // insert
        for(int j = 0 ; j < N ; j++) {
            scanf("%d", &x);
            add_node(tree, x);
        }
        
        in_order_tree_walk(tree);
        printf("\n");

        // remove
        for(int j = 0 ; j < X ; j++) {
            scanf("%d", &x);
            tree = remove_node(tree, x);
        }

        in_order_tree_walk(tree);
        // cleanup
        free_BST(tree);
    }
}
