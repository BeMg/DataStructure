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

void UIinit(){
    printf("(S)earch\n(I)nsert\n(D)elete\n(P)rintorder\n");
}

int main(){
    Node* root;
    root = NULL;
    root = insert(root,30);
    root = insert(root,5);
    root = insert(root,2);
    root = insert(root,40);
    root = insert(root,35);
    root = insert(root,80);
    infixorder(root);
    printf("\n");
    root = Delete(root,30);
    infixorder(root);
    printf("\n");
    while(1){
	UIinit();
	char input[10];
	fgets(input,10,stdin);
	int len = strlen(input);
	if (input[len-1] == '\n') {
	    input[len-1] = '\0';
	    len--;
	}
	if(input[0] == 'S' || input[0] == 's'){

	}
	else if(input[0] == 'I' || input[0] == 'i'){

	}
	else if(input[0] == 'D' || input[0] == 'd'){

	}
	else if(input[0] == 'P' || input[0] == 'p'){

	}else
	    printf("Not such action.\n");
    }
    return 0;
}
