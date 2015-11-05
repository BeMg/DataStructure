#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int level;
};

typedef struct node Node;

int a[1024][1024];

Node* insert(Node* root, int k){
    Node *ptr = (Node*) malloc (sizeof(Node));
    ptr->data = k;
    ptr->right = ptr->left = NULL;
    ptr->level = 0;
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
        ptr->level++;
	    }else{
		if(temp->right==NULL){
		    temp->right = ptr;
		    break;
		}
		temp = temp->right;
        ptr->level++;
        }
	}
    }
    return root;
}

void infixorder(Node *root){
    if(root){
	infixorder(root->left);
	a[root->level][root->data] = 1;
	infixorder(root->right);
    }
}


int main(){
    Node *root;
    root = NULL;
    int temp;
    for(int i=0; i<50; i++){
        scanf("%d",&temp);
        root = insert(root,temp);
    }
        memset(a,0,sizeof(a));
        infixorder(root);
        int flag=0;
        for(int i=0; i<1024; i++){
            for(int j=0; j<1024; j++){
                if(a[i][j]){
                    printf("%d ",j);
                    flag=1;
                }
            }
            if(flag){
            printf("\n");
            flag = 0;
        }
        }
return 0;
}
