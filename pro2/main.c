#include <stdio.h>

typedef struct node Node;

struct node {
    int data;
    struct node *left;
    struct node *right;
};


Node* search(Node *root , int k){
    if(!root) return NULL;
    if(root->data == k) return &(root->data);
    if(root->data < k)
	return search(root->left,k);
    return search(root->right,k);
}


void insert(struct node *root, int k){

}






int main(){
    Node *root;
    root = NULL;
    

    return 0;
}
