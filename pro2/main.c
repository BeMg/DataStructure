#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node* search(Node *root , int k){
    if(!root) return NULL;
    if(root->data == k) return (Node*) &(root->data);
    if(root->data < k)
	return search(root->left,k);
    return search(root->right,k);
}


Node* search_terminal(Node *root , int k){
    while(root){
	if(k == root->data) return NULL;
	if(k < root->data){
	    if(!(root->left))
		return root;
	    root = root->left;
	}else{ 
	    if(!(root->right))
		return root;
	    root = root->right;
	}
    }
    return NULL;
}

void insert(Node **root, int k){
    Node *ptr = (Node*) malloc(sizeof(Node)),*temp = search_terminal(*root,k);
    if(temp || !(*root)){
	ptr->data = k;
	ptr->right = ptr->left = NULL;
	if(*root)
	    if(k > ptr->data)
		temp->right = ptr;
	    else
		temp->left = ptr;
	else
	    *root = ptr;
    }
    else{
	printf("Error.The number is already in tree.\n");
    }
}

void delete(Node **root ,int k){
    Node *temp = search(*root,k);
    if(!(temp->left) && !(temp->right)){
	temp = NULL;
    }else if((temp->left) && (temp->right)){
	Node *ptr = temp->right;
	while(1){
	    if(!(ptr->left)){
		temp = ptr;
		ptr = ptr->right;
		break;
	    }
	    ptr = ptr->left;	
	}
    }else{
	if((temp->right))
	    temp = temp->right;
	else
	    temp = temp->left;
    }
}

int main(){
    Node *root;
    root = NULL;
    insert(&root,20);
    insert(&root,15);
    insert(&root,10);
    insert(&root,12);
    insert(&root,25);
    insert(&root,22);
    if(!(search(root,10)))
	printf("YA!\n");
    return 0;
}
