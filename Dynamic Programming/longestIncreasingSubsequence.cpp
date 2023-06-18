class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int curr,int prev){
        if(curr>=nums.size()){
            return 0;
        }
    
        //Include
        int include = 0;
        if(prev==-1 || nums[curr]>nums[prev]){
            include = 1 + solveUsingRecursion(nums,curr+1,curr);
        }
        //Exclude
        int exclude = 0 + solveUsingRecursion(nums,curr+1,prev);
        return max(include,exclude);  
    }
    int solveUsingMem(vector<int>& nums, int curr,int prev,vector<vector<int>> &dp){
        if(curr>=nums.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        //Include
        int include = 0;
        if(prev==-1 || nums[curr]>nums[prev]){
            include = 1 + solveUsingMem(nums,curr+1,curr,dp);
        }
        //Exclude
        int exclude = 0 + solveUsingMem(nums,curr+1,prev,dp);
        dp[curr][prev+1] = max(include,exclude);
        return dp[curr][prev+1];
    }
    int solveUsingTab(vector<int> &nums){
        int n= nums.size();
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                //Include
                int include = 0;
                if(prev==-1 || nums[curr]>nums[prev]){
                    include = 1 + dp[curr+1][curr+1];
                }
                //Exclude
                int exclude = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(include,exclude);
                
            }
        }
        return dp[0][0];// return dp[0][-1+1];
    }
    int solveUsingTabSO(vector<int> &nums){
        int n= nums.size();
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                //Include
                int include = 0;
                if(prev==-1 || nums[curr]>nums[prev]){
                    include = 1 + nextRow[curr+1];
                }
                //Exclude
                int exclude = 0 + nextRow[prev+1];
                currRow[prev+1] = max(include,exclude);
                
            }
            //shift
            nextRow = currRow;
        }
        return nextRow[0];// return dp[0][-1+1];
    }
    int solveOptimal(vector<int> &nums){
        // Time complexity O(nlogn)
        if(nums.size()==0) return 0;
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                // Include
                ans.push_back(nums[i]);
            }
            else{
                // Overwrite
                // Find index of just bada element
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        // int ans = solveUsingRecursion(nums,curr,prev);
        // vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        // int ans = solveUsingMem(nums,curr,prev,dp);
        // int ans = solveUsingTab(nums);
        // int ans = solveUsingTabSO(nums);
        int ans = solveOptimal(nums);
        return ans;
    }
};