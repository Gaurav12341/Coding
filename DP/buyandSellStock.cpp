#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& arr) {
    // //brute force approach
    // int maxDiff = 0;
    // for(int i = 0; i < arr.size(); i++) {

    //     for(int j = i + 1; j < arr.size(); j++) {

    //         if(arr[j] > arr[i]) {
    //             maxDiff = max(maxDiff, arr[j] - arr[i]);
    //         }
    //     }
    // }
    // return maxDiff;
    // // TC: O(n^2) SC: O(1)

    //dynamic programming approach
    int minPrice =arr[0];
    int maxProfit = 0;
    for(int i=1; i<arr.size();i++){
        minPrice=min(minPrice, arr[i]);
        maxProfit = max(maxProfit, arr[i]-minPrice);
    }
    return maxProfit; //tc: O(n) SC: O(1)
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    cout << maxProfit(arr);
    return 0;
}