// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int memo(int i, int W, int wt[], int val[], vector<vector<int>> &dp){
        if(i==0){
            if(wt[0]<=W) return val[0];
            return 0;
        }
        if(dp[i][W]!=-1) return dp[i][W];
        int notpick=memo(i-1, W, wt, val, dp);
        int pick=INT_MIN;
        if(wt[i]<=W) pick=val[i]+memo(i-1, W-wt[i], wt, val, dp);
        return dp[i][W]=max(pick, notpick);
    }
    int knapSack(int W, int wt[], int val[], int n) { 
       // vector<vector<int>> dp(n, vector<int>(W+1,-1));
       // return memo(n-1, W, wt, val, dp);
       
       /*
       vector<vector<int>> dp(n, vector<int>(W+1, 0));
       for(int j=wt[0]; j<=W;j++) dp[0][j]=val[0];
       for(int i=1;i<n;i++){
           for(int j=0;j<=W;j++){
                int notpick=dp[i-1][j];
                int pick=INT_MIN;
                if(wt[i]<=j) pick=val[i]+dp[i-1][j-wt[i]];
                dp[i][j]=max(pick, notpick);
           }
       }
       return dp[n-1][W];
      */
      
      /*
       vector<int> prev(W+1, 0), curr(W+1, 0);
       for(int j=wt[0]; j<=W;j++) prev[j]=val[0];
       for(int i=1;i<n;i++){
           for(int j=0;j<=W;j++){
                int notpick=prev[j];
                int pick=INT_MIN;
                if(wt[i]<=j) pick=val[i]+prev[j-wt[i]];
                curr[j]=max(pick, notpick);
           }
           prev=curr;
       }
       return prev[W];
       */
       
       vector<int> prev(W+1, 0);
       for(int j=wt[0]; j<=W;j++) prev[j]=val[0];
       for(int i=1;i<n;i++){
           for(int j=W;j>=0;j--){
                int notpick=prev[j];
                int pick=INT_MIN;
                if(wt[i]<=j) pick=val[i]+prev[j-wt[i]];
                prev[j]=max(pick, notpick);
           }
       }
       return prev[W];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends