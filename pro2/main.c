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
	while(1){
	    if(temp->data > k){
		if(temp->left==NULL){
		    temp->left = ptr;
		    break;
		}
		temp = temp ->left;
	    }else
		if(temp->right==NULL){
		    temp->right = ptr;
		    break;
		}
	    temp = temp->right;
	}
    }
    return root;
}

Node* delete(Node* root, int k){
    Node* delete = root;
    while(delete->data != k){
	if(delete == NULL){
	    printf("The number %d is not in tree.\n",k);
	    return NULL;
	}
	if(delete->data > k)
	    delete = delete->left;
	else
	    delete = delete->right;
    }
    if(!(delete->right) && !(delete->left)){
	delete = NULL;
    }else if((delete->right) && (delete->left)){
	Node* temp = delete->right;
	while(1){
	    if(temp->left==NULL){
		int swap = temp->data;
		root = delete(root,temp->data);
		delete->data = swap;
		break;
	    }
	    temp = temp->left;
	}
    }else{
	if(delete->right){
	    Node* temp = delete->right;
	    int swap = temp->data;
	    root = delete(root,temp->data);
	    delete->data = swap;
	}
	else{
	    Node* temp = delete->left;
	    int swap = temp->data;
	    root = delete(root,temp->data);
	    delete->data = swap;
	}
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
