#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int>& nums){
    int maxi=INT_MIN;
    int sum=0, currstart=-1, ansStart=-1, ansEnd=-1; 
    
    for (int i=0;i<nums.size(); i++){
        if(sum==0)
            currstart=i;
        sum+=nums[i];
        if(sum>maxi){
            maxi=sum;
            ansStart = currstart; 
            ansEnd = i;
        }
        if (sum<0)
            sum=0;
    }
    return maxi;
}
//TC: O(n), SC: O(1)

int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubarraySum(nums)<<endl;
    return 0;
}