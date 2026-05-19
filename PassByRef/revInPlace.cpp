#include <bits/stdc++.h>
using namespace std;

void revInPlace(vector<int> &arr){
    int i=0;
        int j = arr.size()-1;
        // while(i<=j){
        //     int temp = arr[i];
        //     arr[i] = arr[j];
        //     arr[j]=temp;
        //     i++;
        //     j--;
        // }

        // TC: O(n/2) = O(n)
        // SC: O(2) = O(1)

        for (;i<arr.size()/2;i++){
            int temp = arr[i];
            arr[i] = arr[j-i];
            arr[j-i]=temp;
        }

        // TC: O(n/2) = O(n)
        // SC: O(1)
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    revInPlace(arr);
    for(int i:arr){
        cout << i << " ";
    }
    return 0;
}