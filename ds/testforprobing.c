#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hashheader.c"


void testInsert(){
    hashtable ht;
    initHashTable(&ht);
     
    insert(&ht, "key1", 100);
    insert(&ht, "key2", 200);
    insert(&ht, "key3", 300);

    // printf("value of key %s is %d \n","key3",lookup(&ht,"key3"));
    // printf("size of table is %d",ht.size);

    assert(ht.size == 3);
    assert(lookup(&ht, "key1") == 100);
    assert(lookup(&ht, "key2") == 200);
    assert(lookup(&ht, "key3") == 300);

    insert(&ht, "key2", 250);
    assert(lookup(&ht, "key2") == 250);

    freeHashTable(&ht);
}

void testSearch() {
    hashtable ht ;
    initHashTable(&ht);

    insert(&ht, "key1", 100);
    insert(&ht, "key2", 200);
    insert(&ht, "key3", 300);

    assert(lookup(&ht, "key1") == 100);
    assert(lookup(&ht, "key2") == 200);
    assert(lookup(&ht, "key3") == 300);

    // Test searching for non-existent key
    assert(lookup(&ht, "key4") == -1);

    freeHashTable(&ht);
}


void testDelete() {
    hashtable ht;

    initHashTable(&ht);


    insert(&ht, "key1", 100);
    insert(&ht, "key2", 200);
    insert(&ht, "key3", 300);

    // Test deleting existing key
    delete(&ht, "key2");
    assert(lookup(&ht, "key2") == -1);
    assert(ht.size == 2);

    // Test deleting non-existent key
    delete(&ht, "key4");
    assert(ht.size == 2);

    freeHashTable(&ht);
}


void testDeleteDoesNotDisturbLinearSequence() {
    hashtable ht;
    initHashTable(&ht);

    // Insert a series of keys that will collide and use linear probing
    insert(&ht, "key1", 100);
    insert(&ht, "key2", 200);
    insert(&ht, "key3", 300);
    insert(&ht, "key4", 400);
    insert(&ht, "key5", 500);

    // Delete a key in the middle of the linear sequence
    delete(&ht, "key3");

    // Verify that the linear sequence is maintained after deletion
    assert(lookup(&ht, "key1") == 100);
    assert(lookup(&ht, "key2") == 200);
    assert(lookup(&ht, "key4") == 400);
    assert(lookup(&ht, "key5") == 500);

    freeHashTable(&ht);
}



void main(){

    // printf("im here");
    testInsert();
    testSearch();
    testDelete();
    testDeleteDoesNotDisturbLinearSequence();

}