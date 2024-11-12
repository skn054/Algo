

#include<stdio.h>


void insertionsort(int arr[],int size){
    
    for(int j=1 ;j<size;j++){
        int i = j-1;
        int k = arr[j];
        while(arr[i]> k && i>=0){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = k;

    }

    for(int i=0;i<size;i++){
        printf("%d", arr[i]);
    }
}
void main(){


    int arr[] = {6,5,3,8,7,1,1,4};
    int size = sizeof(arr)/sizeof(int);

    insertionsort(arr,size);

}