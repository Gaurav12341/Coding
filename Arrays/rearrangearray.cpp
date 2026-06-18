#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    // // brute O(n+n/2) Sc: O=(n)
    // vector<int> positives;
    // vector<int> negatives;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i] > 0)
    //         positives.push_back(nums[i]);
    //     else
    //         negatives.push_back(nums[i]);
    // }
    // for (int i = 0; i < nums.size() / 2; i++)
    // {
    //     nums[2 * i] = positives[i];
    //     nums[2 * i + 1] = negatives[i];
    // }
    // return nums;

    // DP
    vector<int> ans(nums.size());
    int pos = 0, neg = 1;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]>0 && pos<nums.size()){
            ans[pos] = nums[i];
            pos+=2;
        }
        else if(nums[i]<0 && neg<nums.size()){
            ans[neg] = nums[i];
            neg+=2;
        }
    }
    return ans;
}

vector<int> rearrangeArray2(vector<int> &nums) //positives and negatives are not equal
{
    vector<int> positives;
    vector<int> negatives;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            positives.push_back(nums[i]);
        else
            negatives.push_back(nums[i]);
    }

    if(positives.size() > negatives.size()) //TC: O(n) + O(min (pos,neg)) + O(leftover) - O(2n) SC: O(n)
    {
        for (int i = 0; i < negatives.size(); i++)
        {
            nums[2 * i] = positives[i]; //even place
            nums[2 * i + 1] = negatives[i]; //odd place
        }
        int index = 2*negatives.size(); // this will be the index of the next positive number, because we have already filled the first 2*negatives.size() elements of the array with positives and negatives, so the next positive number will be at index 2*negatives.size()
        for(int i=negatives.size(); i<positives.size(); i++){
            nums[index] = positives[i];
            index++;
        }
    }
    else 
    {
        for (int i = 0; i < positives.size(); i++)
        {
            nums[2 * i] = positives[i];
            nums[2 * i + 1] = negatives[i];
        }
        int index = 2*positives.size(); // this will be the index of the next negative number, because we have already filled the first 2*positives.size() elements of the array with positives and negatives, so the next negative number will be at index 2*positives.size()
        for(int i=positives.size(); i<negatives.size(); i++){
            nums[index] = negatives[i];
            index++;
        }
    }
    return nums;   
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, -2, -7, -8, -5};
    nums = rearrangeArray(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    vector<int> nums2 = {1, 2, 3, 4, 7, 9, -2, -7, -8};
    nums2 = rearrangeArray2(nums2);
    cout << endl;
    for (int i = 0; i < nums2.size(); i++)
    {
        cout << nums2[i] << " ";
    }
    return 0;
}