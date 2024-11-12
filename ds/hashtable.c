#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// typedef struct{
//     char *key;
//     int value;
//     sturct Node *next; // cannot have self referential node using typedef
// }

/*

This program is hashtable which can handle collision using chaining.
*/

#define MAX_SIZE 250
typedef struct Node{
    char *key;
    int value;
    struct Node *next;
}Node;

typedef struct{
    Node* hashtable[MAX_SIZE];
}Hashtable;

int hashfunction(char *key){
            int hash = 0;
            for(int i=0;key[i]!='\0';i++){
                hash= hash*31 + key[i];
            }

            return hash % MAX_SIZE;
}

Node* createNode(char *key,int value){
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->key = key;
    newnode->value = value;
    newnode->next = NULL;
    return newnode;
}


void insert(Hashtable *ht,char *key,int value){
    int index = hashfunction(key);
    Node *current = ht->hashtable[index];
    

    //if key already exists

    while(current!=NULL){
        if(strcmp(current->key,key) == 0){
            current->value = value;
            return ;
        }

        current= current->next;
    }

    
    Node *newnode = createNode(key,value);
    newnode->next = ht->hashtable[index];
    ht->hashtable[index] = newnode;
    
        
    
}

int lookup(Hashtable *ht,char *key){
    int index = hashfunction(key);
    Node *current = ht->hashtable[index];

    

    while(current!=NULL){
        if(strcmp(current->key, key) == 0){
            return current->value;
        }

        current = current->next;
    }

    return -1;
}

void delete(Hashtable *ht,char *key){
    int index = hashfunction(key);
    Node *current = ht->hashtable[index];
    
    Node *prev = NULL;
    

    while(current!=NULL){
        if(strcmp(current->key,key)==0){
             if(prev == NULL){

                // First node in the list
                ht->hashtable[index] = current->next;

             }else{
                prev->next = current->next;
             }

             free(current);
             return;
        }

        prev = current;
        current = current->next;

    }
}




void initHashTable(Hashtable *ht){
    for(int i=0;i<MAX_SIZE;i++){
        ht->hashtable[i] = NULL;
    }
}

void freeHashTable(Hashtable *ht){

    for(int i=0;i<MAX_SIZE;i++){
        Node *current = ht->hashtable[i];
        while(current!=NULL){
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }

}


void main(){

    Hashtable ht;
    initHashTable(&ht);
    
    insert(&ht, "key1", 100);
    insert(&ht, "key2", 200);
    
    printf("Value: %d\n", lookup(&ht, "key1")); // Output: 100

    
    
    delete(&ht, "key1");

    printf("Value: %d\n", lookup(&ht, "key1"));
    freeHashTable(&ht);

    printf("Value: %d\n", lookup(&ht, "key1"));

}

/**
 * difference between Hashtable ht; and Hashtable *ht = malloc(sizeof(Hashtable)); where is memory allocated for both statement. explian with an diagram.
ChatGPT said:

ChatGPT
The two declarations Hashtable ht; and Hashtable *ht = malloc(sizeof(Hashtable)); both allocate memory for a Hashtable, but they do so in different locations and have different ways of being accessed. Here’s a breakdown of both:

1. Hashtable ht;
Memory Allocation: This allocates memory on the stack.

Lifetime: The memory is automatically deallocated when the function in which it is declared returns (i.e., goes out of scope).

Direct Access: You use the . operator to access its members.

Diagram:

swift
Copy code
Stack Memory
┌──────────────┐
│   Hashtable  │  <- This is the memory allocated for `ht`
│ ht           │
└──────────────┘
2. Hashtable *ht = malloc(sizeof(Hashtable));
Memory Allocation: This allocates memory on the heap (dynamic memory), and the pointer ht itself is usually on the stack.

Lifetime: The memory persists until you explicitly free it with free(ht);.

Pointer Access: You use the -> operator to access its members.

Diagram:

csharp
Copy code
Stack Memory                          Heap Memory
┌──────────────┐                      ┌──────────────┐
│    ht        │ ───────────────────> │  Hashtable   │ <- This is the memory allocated by `malloc`
└──────────────┘                      └──────────────┘
ht (the pointer) is on the stack, but it points to memory on the heap, which contains the Hashtable struct.
Comparison Summary
Hashtable ht; is allocated on the stack and has automatic storage duration, so it’s automatically freed when it goes out of scope.
Hashtable *ht = malloc(sizeof(Hashtable)); allocates memory on the heap. The pointer itself (ht) is on the stack, and it points to a location in heap memory. This memory must be manually freed using free(ht); to avoid memory leaks.
 */

/**
 * When calling initHashTable(ht); versus initHashTable(&ht);, there is an important distinction in how the Hashtable is passed to the function, which affects whether the function can modify the original Hashtable struct.

Understanding the Difference
Passing ht directly (as initHashTable(ht);)

Call by Value: When ht is passed directly, it is passed by value. This means a copy of ht is created and sent to initHashTable.
Effects: Any changes made to the Hashtable within initHashTable affect only the copy and do not affect the original ht in the calling function.
Use: This approach is rarely useful when you need to modify the original struct because changes won't be reflected outside the function.

void initHashTable(Hashtable ht) {
    for(int i = 0; i < MAX_SIZE; i++) {
        ht.hashtable[i] = NULL; // Only affects the copy of `ht`
    }
}

int main() {
    Hashtable ht;
    initHashTable(ht);  // Passes by value, so `ht` in main remains unchanged
    // ht.hashtable[i] is NOT set to NULL outside initHashTable
}


Passing &ht (as initHashTable(&ht);)

Call by Reference (Pointer): When &ht is passed, a pointer to the original ht is sent to initHashTable. The function then receives an address that points directly to ht in the caller’s context.
Effects: Any modifications made to ht through this pointer affect the original Hashtable struct, as the function is working with the actual memory location of ht.
Use: This approach is ideal when you want initHashTable to modify the original Hashtable, such as initializing or updating it.


void initHashTable(Hashtable *ht) {
    for(int i = 0; i < MAX_SIZE; i++) {
        ht->hashtable[i] = NULL;  // Modifies the original `ht`
    }
}

int main() {
    Hashtable ht;
    initHashTable(&ht);  // Passes a pointer to `ht`, so modifications are made directly
    // ht.hashtable[i] is set to NULL outside initHashTable
}


Summary
initHashTable(ht);: Passes ht by value (copy), so the original ht in main remains unchanged.
initHashTable(&ht);: Passes ht by reference (pointer), allowing initHashTable to modify the actual Hashtable in main.
For scenarios where you need the function to update or initialize the data, passing by reference (&ht) is the preferred approach.
 */


/**
 * 
 * difference between current->key == key and strcmp(current->key, key) == 0
 * 
 * The difference between current->key == key and strcmp(current->key, key) == 0 lies in what they compare and how they handle strings.

1. current->key == key
Pointer Comparison: This compares the memory addresses of current->key and key.
Meaning: It checks if current->key and key point to the exact same memory location.
Usage: This is generally only useful if you’re comparing whether two pointers refer to the exact same string location in memory, which is rarely the goal when comparing strings.
Outcome: If current->key and key are two separate memory allocations with the same content, current->key == key will return false because the pointers point to different addresses.
2. strcmp(current->key, key) == 0
String Content Comparison: This compares the content of the two strings character-by-character.
Meaning: strcmp returns 0 if the strings are identical in content.
Usage: This is the correct approach for comparing the actual content of two strings in C, as it checks if both strings contain the same characters in the same order.
Outcome: Even if current->key and key are different memory locations with identical content, strcmp(current->key, key) == 0 will return true.
Example
Suppose you have:

c
Copy code
char *key1 = "example";
char *key2 = strdup("example");  // `key2` points to a different memory location with the same content
key1 == key2 would be false because key1 and key2 point to different addresses.
strcmp(key1, key2) == 0 would be true because the content of key1 and key2 is identical.
Summary
Use current->key == key for pointer comparisons (checking if two pointers point to the same memory location).
Use strcmp(current->key, key) == 0 for string content comparisons (checking if two strings have the same characters).
 */