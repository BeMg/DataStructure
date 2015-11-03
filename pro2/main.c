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
    while(1){
	printf("(I)nsert\n(S)earch\n(D)elete\n");
	char input;
	int k;
	scanf("%c",&input);
	if(input=='I' || input=='i'){
	    printf("Please enter number you want to insert:");
	    scanf("%d",&k);
	    if(!(search(root,k)))
		insert(&root,k);
	    else
		printf("Error.The number is already in tree.\n");
	}
	else if(input=='S' || input=='s'){
	    printf("Please enter number you want to search:");
	    scanf("%d",&k);
	    if((search(root,k)))
		printf("The number is in the tree.\n");
	    else
		printf("The number is not in the tree.\n");
	}
	else if(input=='D' || input=='d'){
	    printf("Please enter number you want to delete:");
	    scanf("%d",&k);
	    if((search(root,k)))
		delete(&root,k);
	    else
		printf("The number is not in the tree.\n");
	}
	getchar();
    }
    return 0;
}
