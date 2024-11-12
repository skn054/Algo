#include<stdio.h>
#include<math.h>
#define TRUE 1
#define FALSE 0


void print_array(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d", arr[i]);
    }

    printf("\n");
}

int is_min_heap(int arr[],int size){
    for(int i = floor(size/2) - 1; i>=0;i--){
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < size && arr[i] > arr[left] ){
            return FALSE;
        }
        if(right < size && arr[i] > arr[right]){
            return FALSE;
        }
    }

    return TRUE;
}

void heapify(int index,int arr[], int size){
    // printf("heapify called");
    int min = index;
    int lchild = 2*index + 1;
    int rchild = 2*index + 2;

    if(lchild < size && arr[lchild] < arr[min] ){
        min = lchild;
    }
    if(rchild < size && arr[rchild] < arr[min] ){
        min = rchild;
    }

    // printf("min is %d ", min);
    if(min!=index){
        int temp = arr[index];
        arr[index] = arr[min];
        arr[min] = temp; 
        heapify(min,arr,size);
    }
}


void test_heapify(int arr[],int size,char* test_name){
     printf("Test: %s\n", test_name);
     printf("Before heapify: ");
     print_array(arr, size);

     for(int i=floor(size/2) - 1;i>=0;i--){
        // printf(" i is %d", i);
            heapify(i,arr,size);
    }

    printf("After heapify: ");

    print_array(arr, size);

    if (is_min_heap(arr, size)) {
        printf("Result: PASS (Min-heap property satisfied)\n\n");
    } else {
        printf("Result: FAIL (Min-heap property not satisfied)\n\n");
    }


}





void main(){

    int test1[] = {4, 10, 3, 5, 1};
    int test2[] = {1, 2, 3, 4, 5};
    int test3[] = {5, 4, 3, 2, 1};
    int test4[] = {7, 12, 6, 10, 17, 15, 2, 4};
    // int size = sizeof(arr)/ sizeof(int);

     test_heapify(test1, sizeof(test1)/sizeof(test1[0]), "Random Array");
    test_heapify(test2, sizeof(test2)/sizeof(test2[0]), "Already Sorted Array");
    test_heapify(test3, sizeof(test3)/sizeof(test3[0]), "Reverse Sorted Array");
    test_heapify(test4, sizeof(test4)/sizeof(test4[0]), "Larger Random Array");
    

    

}