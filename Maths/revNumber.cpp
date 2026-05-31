#include<bits/stdc++.h>
using namespace std;

int reverseNumber(int n) {
        int rem=0;
        int rev = 0;
        while(n>0){
            rem = n%10;
            if(rem>0)// if 0 is to be removed from the end of the number
                rev = rev * 10 + rem; 
            n=n/10;
        }
        return rev;
    }

int reverseWithBoundary(int x) {
        int rev = 0; 
        int rem = 0;
        while (x!=0){
            rem = x%10;
            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && rem > 7)) //INT_MAX = 2147483647 so we cant cross that, hence only till 7
                return 0; //overflow
            if(rev < INT_MIN/10 || (rev == INT_MIN/10 && rem < -8)) //INT_MIN = -2147483648 so we cant cross that, hence only till -8
                return 0;
            rev = rev*10 + rem;
            x=x/10;
        }
        return rev;
    }

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    int reversed = reverseNumber(number);
    cout << "The reversed number is: " << reversed << endl;
    return 0;
}