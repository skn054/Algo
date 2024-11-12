// #include<stdio.h>
// #include<stdlib.h>


// //{ Driver Code Starts

// using namespace std;

// // } Driver Code Ends
// class Solution{
//     map<int,int> m;
// 	public:
// 	int minSteps(int n) 
// 	{ 
// 	    // Your code goes here
// 	    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
// 	   // if(n<=1) return 0;
	    
// 	   // if(m[n]!=0){
// 	   //     return m[n];
// 	   // }
	    
// 	   // if(n%2==0){
// 	   //     a = minSteps(n/2);
// 	   // }
// 	   // if(n%3==0){
// 	   //     b = minSteps(n/3);
// 	   // }
	        
	        
// 	   //c = minSteps(n-1);
// 	   //int ans = 1 + min(a,min(b,c));
// 	   //m[n] = ans;
	    
// 	   // return  ans;
	   
// 	   int arr[10005]={0};
// 	   arr[2] = 1;
// 	   arr[3] = 1;
// 	   for(int i=4;i<10001;i++){
// 	       //if(i%2 == 0){
// 	       //    a = arr[i/2];
// 	       //}
// 	       //if(i%3==0){
// 	       //    b = arr[i/3];
// 	       //}
	       
// 	       //c= arr[i-1];
	       
// 	       a  = i%2 == 0 ? arr[i/2] : INT_MAX;
// 	       b = i %3 ==0 ? arr[i/3] : INT_MAX;
// 	       c = arr[i-1];
	       
// 	       arr[i] = 1 + min(a,min(b,c));
// 	   }
	   
// 	   return arr[n];
	    
// 	} 
// };


// //{ Driver Code Starts.
// int main() 
// {
   	
   
//    	int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;

       

// 	    Solution ob;
// 	    cout << ob.minSteps(n) << "\n";
	     
//     }
//     return 0;
// }


// // } Driver Code Ends