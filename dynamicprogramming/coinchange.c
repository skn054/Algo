#include<stdio.h>

int count =0;
void countWays(int coins[],int n ,int sum,int csum,int index){

    // int count =0,c=0;
    if(sum == 0) return ;
    if(csum == sum ){
        count++;
        return;
    }

    

    for(int i=index;i<n;i++){
        if(csum+coins[i] <=sum){
            countWays(coins,n,sum,csum+coins[i],i);
            // c=c+count;
        }
        
        
    }

    // return c;

}
int main()
{
    int n = 1, sum = 0;
    int coins[] = {1};

    countWays(coins, n, sum, 0,0);
    printf("%d", count);
    return 0;
}