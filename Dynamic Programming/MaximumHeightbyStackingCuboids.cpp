/*
1691. Maximum Height by Stacking Cuboids
Hard

Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.
*/
class Solution {
public:
    bool check(vector<int> a,vector<int> b){
        if(b[0]<=a[0] && b[1]<=a[1] && b[2]<=a[2]){
            return true;
        }
        else 
            return false;
    }
    int solveUsingTabSO(vector<vector<int>> &arr){
        int n= arr.size();
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                //Include
                int include = 0;
                if(prev==-1 || check(arr[curr],arr[prev])){
                    include = arr[curr][2] + nextRow[curr+1];
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
    int maxHeight(vector<vector<int>>& cuboids) {
        // Sort every array
        for(auto &a:cuboids){
            sort(a.begin(),a.end());
        }
        // Sort 2d Array
        sort(cuboids.begin(),cuboids.end());
        // Apply LIS logic
        int ans = solveUsingTabSO(cuboids);
        return ans;
    }
};