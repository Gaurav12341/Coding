#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& arr) {
    int maxDiff = 0;
    for(int i = 0; i < arr.size(); i++) {

        for(int j = i + 1; j < arr.size(); j++) {

            if(arr[j] > arr[i]) {
                maxDiff = max(maxDiff, arr[j] - arr[i]);
            }
        }
    }
    return maxDiff;
    // TC: O(n^2) SC: O(1)
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    cout << maxProfit(arr);
    return 0;
}