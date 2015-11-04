#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;


Node* search(Node *root, int k){
   
    return NULL;
}

Node* insert(Node* root, int k){
    Node *ptr = (Node*) malloc (sizeof(Node));
    ptr->data = k;
    ptr->right = ptr->left = NULL;
    if(root==NULL){
	root = ptr;
    }else{
	Node *temp = root;
	if(temp->data > k){
	    if(temp->left==NULL)
		temp->left = ptr;
	    else
		temp = temp ->left;
	}else
	    if(temp->right==NULL)
		temp->right = ptr;
	    else
		temp = temp->right;
    }
    return root;
}

void infixorder(Node *root){
    if(root){
	infixorder(root->left);
	printf("%d",root->data);
	infixorder(root->right);
    }
}

int main(){
    Node* root;
    root = NULL;
    root = insert(root,5);
    root = insert(root,10);    
    root = insert(root,3);
    infixorder(root);

    return 0;
}
