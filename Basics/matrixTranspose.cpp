#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& v) {
        int m = v.size(); int n = v[0].size();
        vector<vector<int>> ans(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = v[j][i];
            }
        }
        return ans;
    }

int main(){
    vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    for(int i=0;i<v.size();i++){
        for (int j = 0; j < v[0].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    vector<vector<int>> v2 = transpose(v);
    for(int i=0;i<v.size();i++){
        for (int j = 0; j < v[0].size(); j++)
        {
            cout<<v2[i][j]<<" ";
        }
        cout<<endl;
    }
}