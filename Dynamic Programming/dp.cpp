#include<bits/stdc++.h>
using namespace std;

int printFibonacci(int n, vector<int>&dp){
    if(n<=1)
    return n;
    if(dp[n]!= -1) return dp[n];
    
    return dp[n] = printFibonacci(n-1,dp)+printFibonacci(n-2,dp) ;
}

int recSolve(int n){
        //Base case
        if(n==1 || n==0)
            return n;

        int ans = recSolve(n-1)+recSolve(n-2);
        return ans;
    }
    int topDownSolve(int n, vector<int> &dp){
        //Base case
        if(n==1 || n==0)
            return n;
        //Step 3: Check if answer already exist
        if(dp[n]!=-1){
            return dp[n];
        }

        // Step 2 : store the value in dp vector
        dp[n] = topDownSolve(n-1,dp)+topDownSolve(n-2,dp);
        return dp[n];
    }
    int bottomUp(int n){
        //Step 1: create a dp array
        vector<int> dp(n+1,-1);
        // Step 2 : Observe base case in above solution
        dp[0] = 0; 
        if(n==0) return dp[0];
        dp[1] = 1;
        if(n==1) return dp[1];
        // Step 3 : bottom up approach
        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int spaceOptSolve(int n){
        
        
        int prev2 = 0; 
        int prev1 = 1;
        int curr;
        if(n==0) return prev2;
        if(n==1) return prev1;
        for(int i = 2;i<=n;i++){
            curr = prev1 + prev2;
            //Shifting
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }

    int fib(int n) {
        // int ans = recSolve(n);
        // return ans;

        // step 1: create dp array
        // vector<int> dp (n+1, -1);
        // int ans = topDownSolve(n, dp);
        int ans = bottomUp(n);
        return ans;
    }

int main(){
    int n;
    cin>>n;
vector<int> dp(n+1,-1);
   cout<<printFibonacci(n, dp);
}