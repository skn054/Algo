#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "hashheader.c"

#define TABLE_SIZE 250

/**
 * 
 * linear proe requires table to beresized when load factor is > 0.7. 
 * This is done because, we store elements in table itself unlike chaining where any number of elements can be added.
 * 
 * Load Factor: The hash table should be resized when the load factor (number of elements / table size) becomes too high to maintain good performance.
 */

// typedef struct Node{
//   char *key;
//   int value;
// }Node;

// typedef struct{
//     Node* table[TABLE_SIZE];
//     int size;
// }hashtable;

int hash(char *key){
    int hash = 0;
    for(int i=0;key[i]!='\0';i++){
         hash = hash * 31 + key[i];
    }

    return hash % TABLE_SIZE;
}

Node* createNode(char *key,int value){
      Node *temp = malloc(sizeof(Node));
      temp->key = key;
      temp->value = value;
      return temp;
}


int lookup(hashtable *ht,char *key){
    int index = hash(key);
    int i=0;
    Node *current = ht->table[index];
    while(current!=NULL){
        if(strcmp(current->key,key) == 0){
            return current->value;
        }
 
        index = (index + 1) % TABLE_SIZE;
        current = ht->table[index];
        i++;
        if(i>=TABLE_SIZE){
            // printf("Key not found.\n");
            return -1;
        }
    }

    // printf("Key not found.\n");
    return -1;
}


void insert(hashtable *ht,char *key,int value){
    if(ht->size>=TABLE_SIZE){
        printf("Hash table is full.\n");
        return;
    }

    int index = hash(key);

    Node *current = ht->table[index];
    int i=0;
    while(current!=NULL){
        // if key is found update value
        if(strcmp(current->key,key) == 0){
            current->value = value;
            return ;
        }
        
        index = (index + 1) % TABLE_SIZE;  // make sense to check entire table using mod.
        current = ht->table[index];
        i++;
        if(i>=TABLE_SIZE){
            printf("Hash table is full.\n");
            return;
        }

    }

    // no key found , then insert new node at index location
    ht->table[index] = createNode(key,value);
    ht->size++;
    
    // handle resize .
    
}

void delete(hashtable *ht,char *key){
    int index = hash(key);
    Node *current = ht->table[index];
    int i=0;
    while(current!=NULL){
        if(strcmp(current->key,key) == 0){
            // dont delete the node, if node is deleted then linear probing sequence is distrubed.

            /**
             * Handling Deletions: When deleting a key-value pair, the slot is not immediately cleared. 
             * Instead, it is marked as "deleted" to maintain the linear probing sequence.
             */
            Node *temp = current;
            temp->key = NULL;
            temp->value = 0;
            ht->size--;
            return;
        }
        i++;
        if(i>=TABLE_SIZE){
            printf("key cannot be found\n");
            return;
        }
        index = (index + 1)%TABLE_SIZE;
        current = ht->table[index];
    }

    printf("key not found\n");
}

void freeHashTable(hashtable *ht){
    for(int i=0;i<TABLE_SIZE;i++){
        Node *temp = ht->table[i];
        if(temp!=NULL){
            free(temp);
        }
    }
}

void initHashTable(hashtable *ht){
    for(int i=0;i<TABLE_SIZE;i++){
        ht->table[i] = NULL;
    }
    ht->size = 0;
}

// void main(){
//     hashtable ht;
//     initHashTable(&ht);
//     insert(&ht,"key1",120);
//     insert(&ht,"key2",150);

    

//     printf("value of key %s is %d \n","key1",lookup(&ht,"key1"));
//     printf("value of key %s is %d \n","key2",lookup(&ht,"key2"));
//     insert(&ht,"key2",15);
//     printf("value of key %s is %d \n","key2",lookup(&ht,"key2"));
//     printf("value of key %s is %d \n","key3",lookup(&ht,"key3"));
    
    
// }