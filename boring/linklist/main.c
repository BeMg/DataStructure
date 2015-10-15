#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
struct Node{
    int num;
    struct Node* next;
};

typedef struct Node Node;

bool insert(Node** node, int num){
    Node* ptr = (Node*) malloc(sizeof(Node));
    if(ptr == NULL)
	return false;
    ptr -> next = *node;
    ptr -> num = num;
    *node = ptr;
    return true;
}

void print_all_list(Node* node){
    while(node!=NULL){
	printf("%d ",node -> num);
	node = node -> next;
    }
    puts("");
}


int main(){
    Node* start = NULL;
    insert(&start,1);
    insert(&start,2);   
    insert(&start,3);
    print_all_list(start);
    return 0;
}
