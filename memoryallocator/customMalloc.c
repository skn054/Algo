#include<stdio.h>
#include<stdlib.h>


struct header_t{

    size_t size;
    unsigned is_free;
    struct header_t *next;
};

struct header_t *head,*tail;

void *custom_malloc(size_t size){
    struct header_t *header;
    size_t total_size;
    
    // before allocating memory ,check if a block of total_size is free by traversing through the list of blocks.
    // if suitable block is found then mark is as not free and updated its size.

     /*  mistakes : did not add lock while using sbrk. check why locks are needed before using sbrk.*/

     
     // before allocating memory ,check if a block of total_size is free by traversing through the list of blocks.
    // if suitable block is found then mark is as not free and updated its size.
    struct header_t *is_free_block = get_free_block(size);
    if(is_free_block){
        is_free_block->is_free = 0;
        
        return (void *)(is_free_block+1);
    }
    total_size = sizeof(struct header_t) + size;
    void *block = sbrk(total_size);
    if(block == (void*)-1){
        return NULL;
    }
    header = block;
    header->size = size;
    header->is_free = 0;
    header->next = NULL;
    if(head == NULL){
        head = header;
    }

    if(tail){
        tail->next = header;
        
    }
    tail = header;


    return (void*)header+1;
}


void free(void *block){
    // check if block point to top of heap, i.e block address == sbrk(0).
    // if equal then reduce the size of heap by calling sbrk(-totalsize)
    // else find the block by travesing through the list of blocks and update is_free variable.
    // struct header_t *head,*tail;

    //   given block address, find out header address

   
    struct header_t *pointer = block;
    size_t total_size = pointer->size + sizeof(struct header_t);
    void *current_head_heap = sbrk(0);
    // // typecast pointers 

    if(block == current_head_heap){
        void *block = sbrk(-total_size);
    }else{
        while(head!=tail){
            if(head == block){
                head->is_free = 1;

            }

            head = head->next;
        }
    }

    


}

struct header_t * get_free_block(size_t size){
    /* before incrementing sbrk pointer, check if any block is free which can accomodate new malloc request
       If so return the block, else return null
     */
    struct header_t *temp = head;
    size_t total_size = size + sizeof(struct header_t);
    while(temp){
        if(temp->is_free == 1 && temp->size >=size){
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

void main(){
 
      

}