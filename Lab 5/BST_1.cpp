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

void free_BST(BSTnode* root){
    if(root == NULL){
        return;
    }
    if(root != NULL){
        free_BST(root->left);
    }
    if(root != NULL){
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
    if(node == NULL) return;
}

int main(){
    /*
     * test data:
     * Z - number of test cases
     * N - number of insert values
     * N values to insert
     * Output:
     * min
     * max
     * N-X lines od numbers
    */
    srand(time(NULL));
    int Z;
    scanf("%d", &Z);

    for(int i = 0 ; i < Z ; i++){
        int N;
        scanf("%d", &N);

        BSTnode* tree = NULL;

        int x;
        // insert
        for(int j = 0 ; j < N ; j++) {
            scanf("%d", &x);
            add_node(tree, x);
        }
		
        printf("%d\n", min(tree)->val);
        printf("%d\n", max(tree)->val);        
        in_order_tree_walk(tree);

        // cleanup
        free_BST(tree);
    }
}
