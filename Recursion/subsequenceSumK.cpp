#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

void printSubsquenceK(int idx,int s, vector<int> ans, vector<int> arr, int sum)
{
    if (idx == arr.size())
    {
        if (s == sum)
        {
            printArr(ans);           
        }
        return;
    }
    ans.push_back(arr[idx]);
    s += arr[idx];
    printSubsquenceK(idx+1,s,ans,arr,sum);
    s -= arr[idx];
    ans.pop_back();
    printSubsquenceK(idx+1,s,ans,arr,sum);
}

int main()
{
    vector<int> arr;
    int idx = 0;
    int n;
    cin >> n;
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        arr.push_back(ele);
    }
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> ans;
    int sum;
    cin >> sum;
    printSubsquenceK(0,0, ans, arr, sum);
    return 0;
}