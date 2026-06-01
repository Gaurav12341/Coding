#include<bits/stdc++.h>
using namespace std;

int sumToN(int n)
{
    if (n<1)
        return 0;
    return n + sumToN(n-1);
}

int factorial(int n){
    if( n <1)
        return 1;
    return n*factorial(n-1);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = sumToN(n);
    cout << "The sum of first " << n << " natural numbers is: " << result << endl;
    int fact = factorial(n);
    
    cout << "The factorial of " << n << " is: " << fact << endl;
    return 0;
}