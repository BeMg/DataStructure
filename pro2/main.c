#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;


Node* search(Node *root, int k){
    if(!root)return NULL;
    if(root->data == k)return root;
    if(root->data > k)
	search(root->left,k);
    else
	search(root->right,k);
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
	    }else{
		if(temp->right==NULL){
		    temp->right = ptr;
		    break;
		}
		temp = temp->right;
	    }
	}
    }
    return root;
}

Node* Delete(Node* root, int k){
    Node* delete = root;
    Node* pre_delete = root;
    while(delete->data != k){
	pre_delete = delete;
	if(delete == NULL){
	    printf("The number %d is not in tree.\n",k);
	    return NULL;
	}
	if(delete->data > k)
	    delete = delete->left;
	else
	    delete = delete->right;
    }
    Node *temp = delete;
    if(delete->right)
	temp = delete->right;
    Node *pre_temp = delete;
    int flag = 1;
    while(1){
	if(temp->left){
	    pre_temp = temp;
	    temp = temp->left;
	    flag = 0;
	}else
	    break;
    }
    if(!(delete->right) && !(delete->left)){
	if(pre_delete->right == delete)
	    pre_delete->right = NULL;
	else if(pre_delete->left == delete)
	    pre_delete->left = NULL;
	else if(pre_delete == delete)
	    root = NULL;
	free(delete);
    }else if(!(delete->right)){
	if(pre_delete->right == delete)
	    pre_delete->right = delete->left;
	else if(pre_delete->left == delete)
	    pre_delete->left = delete->left;
	else if(pre_delete == delete){
	    root = root->left;
	}
	free(delete);	
    }else{
	delete->data = temp->data;
	if(flag){
	    pre_temp->right = NULL;
	}    
	else if(temp->right)
	    pre_temp->left = temp->right;
	else
	    pre_temp->left = NULL;
	free(temp);
    }
    return root;
}

void infixorder(Node *root){
    if(root){
	infixorder(root->left);
	printf("%d ",root->data);
	infixorder(root->right);
    }
}

void levelorder(Node* root){
    Node* treequeue [1024];
    int front = 0;
    int rear = 0;
    treequeue [rear++] = root;
    while(1){
	if(front == rear)
	    break;
	Node *curr = treequeue[front++];
	printf("%d ",curr->data);
	if(curr->left)
	    treequeue[rear++] = curr->left;
	if(curr->right)
	    treequeue[rear++] = curr->right;
    }
}


void implement_bst(){
    Node* root;
    root = NULL;
    int k;
    while(1){
    printf("(S)earch\n(I)nsert\n(D)elete\n(P)rintorder\n(E)xit\n");
	char input[10];
	fgets(input,10,stdin);
	int len = strlen(input);
	if (input[len-1] == '\n') {
	    input[len-1] = '\0';
	    len--;
	}
	if(input[0] == 'S' || input[0] == 's'){
	    printf("Enter number want to search:");
	    scanf("%d",&k);
	    if(search(root,k))
		printf("The number is in the tree.\n");
	    else
		printf("The number is not in the tree.\n");
	}
	else if(input[0] == 'I' || input[0] == 'i'){
	    printf("Enter number want to insert:");
	    scanf("%d",&k);
	    if(search(root,k))
		printf("Error.The number is already in the tree.\n");
	    else{
		root = insert(root,k);
	    }
	}
	else if(input[0] == 'D' || input[0] == 'd'){
	    printf("Enter number want to delete:");
	    scanf("%d",&k);
	    if(search(root,k))
		root = Delete(root,k);
	    else{
		printf("Error.The number is not in the tree.\n");
	    }   
	}
	else if(input[0] == 'P' || input[0] == 'p'){
	    printf("Infixorder:");
	    infixorder(root);
	    printf("\nLevelorder:");
	    levelorder(root);
	    printf("\n");
	    continue;
	}else if(input[0]=='E' || input[0]=='e'){
	    return ;
	}else
	    printf("Not such instruction.\n");
	getchar();
    }

}


int main(){
    while(1){
	printf("(I)mplement\n(T)reasure Hunter\n");
	char input[10];
	fgets(input,10,stdin);
	int len = strlen(input);
	if (input[len-1] == '\n') {
	    input[len-1] = '\0';
	    len--;
	}
	if(input[0]=='I' || input[0]=='i'){
	    implement_bst();
	}else if(input[0]=='T' || input[0]=='t'){
	
	}else
	    printf("No such instruction\n");
    }
    return 0;
}
