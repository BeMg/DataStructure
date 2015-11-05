#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

int table[100000];

Node* search(Node *root, int k){
    if(!root)return NULL;
    if(root->data == k)return root;
    if(root->data > k)
	return search(root->left,k);
    else
	return search(root->right,k);
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
	}else{
	    printf("Not such instruction.\n");
	    continue;
	}
	getchar();
    }
}

int have_eight(int k){
    while(k!=0){
	if(k%10==8)return 1;
	k/=10;
    }
    return 0;
}

void hunter(Node *root,int key,int treasure){
    int a[1024];
    int b[1024];
    memset(table,0,sizeof(table));
    int aflag=0,bflag=0;
    Node *temp = root;
    while(1){
	if(!temp){
	    printf("Key not found.\n");
	    return ;
	}
	a[aflag++] = temp->data;
	if(have_eight(temp->data) && !table[temp->data]){
        table[temp->data] = 1;
	    if(!(temp->left) && !(temp->right))
		root = Delete(root,temp->data);
	    else if((temp->left) && !(temp->right))
		root = Delete(root,temp->left->data);
	    else if(!(temp->left) && (temp->right))
		root = Delete(root,temp->right->data);
	    else{
		if(temp->left->data > temp->right->data)
		    root = Delete(root,temp->right->data);
		else
		    root = Delete(root,temp->left->data);
	    }
	}
	if(temp->data == key)break;
	if(temp->data > key)
	    temp = temp->left;
	else
	    temp = temp->right;
    }
    //for(int i=0; i<aflag; i++)
    //	printf("%d%c",a[i],i==aflag-1 ? '\n' : ' ');
    temp = root;
    while(1){
	if(!temp){
	    printf("Treasure not found.\n");
	    return ;
	}
	b[bflag++] = temp->data;
	if(have_eight(temp->data) && !table[temp->data]){
        table[temp->data] = 1;
	    if(!(temp->left) && !(temp->right))
		root = Delete(root,temp->data);
	    else if((temp->left) && !(temp->right))
		root = Delete(root,temp->left->data);
	    else if(!(temp->left) && (temp->right))
		root = Delete(root,temp->right->data);
	    else{
		if(temp->left->data > temp->right->data)
		    root = Delete(root,temp->right->data);
		else
		    root = Delete(root,temp->left->data);
	    }
	}
	if(temp->data == treasure)break;
	if(temp->data > treasure)
	    temp = temp->left;
	else
	    temp = temp->right;
    }
    //for(int i=0; i<bflag; i++)
    //	printf("%d%c",b[i],i==aflag-1 ? '\n' : ' ');
    int flag = 0;
    for(int i=0; i<aflag; i++){
	if(a[i]!=b[i] && !flag){
	    flag = i;
	}
	printf("%d -> ",a[i]);
    }
    for(int i=aflag-2; i>=flag-1; i--){
	printf("%d -> ",a[i]);
    }
    for(int i=flag; i<bflag; i++){
	printf("%d -> ",b[i]);
    }
    printf("END\n");
}

void Treasure(){
    Node* root;
    root = NULL;
    while(1){
	printf("(O)pen file\n(S)et maze detail\n");
	char input[10];
	fgets(input,10,stdin);
	int len = strlen(input);
	if (input[len-1] == '\n') {
	    input[len-1] = '\0';
	    len--;
	}
	if(input[0]=='O' || input[0]=='o'){
	    printf("Please enter your file name:");
	    char a[100];
	    fgets(a,100,stdin);
	    len = strlen(a);
	    if (a[len-1] == '\n') {
		a[len-1] = '\0';
		len--;
	    }
	    puts(a);
	    FILE * file = fopen(a,"r");
	    if(!(file)){
		printf("Not such file.\n");
		continue;
	    }
	    int temp;
	    while(fscanf(file,"%d",&temp)!=EOF){
		root = insert(root,temp);
	    }
	    fclose(file);
	    //levelorder(root);
	    //printf("\n");
	}else if(input[0]=='S' || input[0]=='s'){
	    int key , treasure;
	    printf("Enter key:");
	    scanf("%d",&key);
	    printf("Enter treasure:");
	    scanf("%d",&treasure);
	    hunter(root,key,treasure);
	    getchar();
	}
	//infixorder(root);
	//printf("\n");
	//levelorder(root);
	//printf("\n");
    }
}

int main(){
    while(1){
	printf("(I)mplement\n(T)reasure Hunter\n(E)xit\n");
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
	    Treasure();
	}else if(input[0]=='E' || input[0]=='e'){
	    break;
	}else{
	    printf("No such instruction\n");
	    continue;
	}
    }
    return 0;
}
