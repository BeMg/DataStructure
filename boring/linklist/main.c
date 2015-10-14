#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node Node;

typedef struct {
    int num;
    struct Node* next;
}Node;

bool insert(Node* node, int num){
    Node* ptr;
    if(ptr == NULL)
	return false;
    ptr -> next = node;
    ptr -> num = num;
    node = ptr;
}

void print_all_list(Node* node){
    if(*node){
	printf("%d ",node -> num);
	node = node -> next;
    }
}


int main(){
    Node* start;
    insert(start,1);   
    insert(start,2);   
    insert(start,3);
    print_all_list(start);

}
