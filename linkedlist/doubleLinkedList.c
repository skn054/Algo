#include<stdio.h>
#include<stdlib.h>


struct Node{

    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* createNode(int data,struct Node* current){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = current;
}

struct Node* constructDoubleLinked(int *arr,int size){
        struct Node* head,*current ;
        if(size == 0){
            return NULL;
        }

        head = createNode(arr[0],NULL);
        current = head;
        for(int i=1;i<size;i++){
            current->next = createNode(arr[i],current);
            current = current->next;
        }
        return head;

        
}

void printDoubleLinked(struct Node *current){

    while(current!=NULL){
            printf("%d",current->data);
            current = current->next;
    }
}

void freeDoubleLinked(struct Node *current){
    struct Node* next;
    while(current!=NULL){
        next = current->next;
    free(current);
    current = next;
    }
    
}

void main(){
    int arr[] = {1};
    int size = sizeof(arr)/sizeof(arr[0]);
    struct Node *head = NULL;
    head = constructDoubleLinked(arr,size);
    printDoubleLinked(head);
    freeDoubleLinked(head);

}