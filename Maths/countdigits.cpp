#include <bits/stdc++.h>
using namespace std;

int countDigit(int n) {
        int count =0;
        // while (n>0){
        //     count++;
        //     cout<<n<<" ";
        //     n=n/10;
        // }
        //TC: O(log n) 
        count =  (int) (log10(n) + 1); // Alternative method to count digits O(1)
        return count;
    }

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int digitCount = countDigit(number);
    cout << "The number of digits in " << number << " is: " << digitCount << endl;

    return 0;
}