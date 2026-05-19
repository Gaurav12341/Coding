#include<bits/stdc++.h>
using namespace std;
vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i =0; 
        int j =0;
        while (i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                i++;
            }                
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                if(result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                i++; j++;
            }
        }

        return result;

        // TC: O(n+m) where n and m are sizes of nums1 and nums2 respectively
        // SC: O(min(n,m)) in worst case when all elements are common
    }

int main() {
    vector<int> nums1 = {1,1,3,4,5};
    vector<int> nums2 = {1,3,4,5,6,7};
    vector<int> result = intersectionArray(nums1, nums2);
    for(int i:result){
        cout << i << " ";
    }
    return 0;
}