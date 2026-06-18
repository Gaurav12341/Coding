#include <bits/stdc++.h>
using namespace std;

void recurpermute(vector<int> &nums, vector<int> &ds, vector<bool> &visited, vector<vector<int>> &ans)
{
    //brute TC: O(n*n!) SC: O(n) + O(n) + O(n*n!)

    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }

    for(int i=0; i<nums.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            ds.push_back(nums[i]);
            recurpermute(nums, ds, visited, ans);
            visited[i] = false;
            ds.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    vector<bool> visited(nums.size(), false);
    recurpermute(nums, ds, visited, ans);
    return ans;
}

int main()
{
    vector<int> nums = {5, 2, 3};
    sort(nums.begin(), nums.end()); //nlogn. for next permutation, we have an stl as well next_permutation(nums.begin(), nums.end()); but here we are doing it manually. so we need to sort the array first, because next_permutation works on sorted array.
    vector<vector<int>> ans = permute(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}