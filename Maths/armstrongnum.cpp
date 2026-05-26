#include<bits/stdc++.h>
using namespace std;

bool isArmstrong(int n) {
        int sum =0;
        int rem=0;
        int temp=n;
        while(n>0){
            rem = n%10;
            sum += rem * rem * rem;
            n = n/10;
        }
        cout<<sum;
        return sum==temp;
    }

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if(isArmstrong(number))
        cout << number << " is an Armstrong number." << endl;
    else
        cout << number << " is not an Armstrong number." << endl;
    return 0;
}