
#include<stdio.h>
#include<stdlib.h>
struct Node{

    int data;
    struct Node *next;
};


struct Node* createNode(int data){

    struct Node* newNode = malloc(sizeof(struct Node));
    if(newNode == NULL){

        printf("Memory allocation failed");
        exit(1);

    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
struct Node* constructLinkedList( int arr[],int lenOfArr){
   
   if(lenOfArr == 0){
    return NULL;
   }

   struct Node *head = createNode(arr[0]);
   struct Node *current = head;

   for(int i=1;i<lenOfArr;i++){
      current->next = createNode(arr[i]);
      current = current->next;
   }
    return head;
}

void printLinkedList(struct Node *head){

    struct Node* current = head;
    while(current!=NULL){
        printf("%d",current->data);
        current=current->next;
    }
}

void freeLinkedList(struct Node* head){
    struct Node* current = head;
    struct Node* next;
    while(current!=NULL){
        next = current->next;
        free(current);
        current = next;
    }
}


int main(){

    int arr[] = {1,2,3,4,5};
    int lengthOfArr = sizeof(arr)/sizeof(arr[0]);
    printf("%d ",lengthOfArr);
    struct Node *head;
    head = constructLinkedList(arr,lengthOfArr);
    printLinkedList(head);
    freeLinkedList(head);
    return 1;
}