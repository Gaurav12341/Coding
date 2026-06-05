#include <bits/stdc++.h>
using namespace std;

int fib (int n){
    if(n<=1)
        return n;
    return fib(n-1) + fib(n-2);
} //TC: O(2^n) which is not efficient for large n. We can use memoization to store the previously calculated Fibonacci numbers and avoid redundant calculations, which will reduce the time complexity to O(n). 

int fibMemo(int n, vector<int> &memo) {
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
}
//TC: O(n) where n is the input number, which is efficient for large n.
 
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<int> memo(n + 1, -1);
    cout << "The " << n << "th Fibonacci number is: " << fibMemo(n, memo) << endl;
    return 0;
}