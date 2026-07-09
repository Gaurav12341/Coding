#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    //brute - for every element check if the next element is present or not. TC: O(n^2)
    int longest= 1;

    // for(int i=0; i<nums.size(); i++){
    //    int x = nums[i];
    //    int count = 1;
    //    while(find(nums.begin(), nums.end(), x+1) != nums.end()){
    //         count++;
    //         x++;
    //     }
    //     longest = max(longest, count);
    // }
    // return longest;

    //better
    // sort(nums.begin(), nums.end());
    // int lastElementTaken = 0;
    // int lastSmall = INT_MIN;
    // int cnt = 0;
    // for(int i=0; i<nums.size(); i++){
    //     if (i==0){
    //         lastElementTaken = nums[i];
    //         lastSmall = nums[i];
    //         cnt++;
    //     }
    //     else if(nums[i] == lastSmall){
    //         continue;
    //     }
    //     else if(nums[i] == lastElementTaken + 1){
    //         cnt++;
    //         lastElementTaken = nums[i];
    //         lastSmall = nums[i];
    //     }
    //     else{
    //         cnt = 1;
    //         lastElementTaken = nums[i];
    //         lastSmall = nums[i];
    //     }
    //     longest = max(longest, cnt);
    // }
    // return longest;
    // TC: O(nlogn) + O(n) = O(nlogn) SC: O(1)

    //Optimal
    unordered_set<int> st;
    for(int i=0; i<nums.size(); i++){
        st.insert(nums[i]);  // sometimes O(n) sometimes O(1) but average case is O(1)
    }
    int longestSeq = 0;
    for (auto it : st){
        if(st.find(it-1) == st.end()){
            int start = it;
            int count = 1;
            while(st.find(start+1) != st.end()){
                count++;
                start++;
            }
            longestSeq = max(longestSeq, count);
        }
    }
    return longestSeq; //TC : O(n) + O(n) = O(n) SC: O(n)
}

int main()
{
    vector<int> nums = {1002, 4, 100, 1, 101, 3, 2, 1, 1};
    vector<int> nums2 = {100, 5, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2};
    int ans = longestConsecutive(nums);
    cout << ans << endl;
    ans = longestConsecutive(nums2);
    cout << ans << endl;
    return 0;
}