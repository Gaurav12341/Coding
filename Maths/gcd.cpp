#include <bits/stdc++.h>
using namespace std;

int GCD(int n1, int n2)
{
    if (n2%n1 == 0)
            return n1;
        else if (n1%n2 ==0)
            return n2;
        int maxi = INT_MIN;
        int n = min(n1, n2);
        // for (int i=1;i<=n;i++){
        //     if (n1%i ==0 && n2 %i ==0)
        //         maxi = i;
        // }
        //TC: O(n) where n is the minimum of the two numbers, which is not efficient for large numbers. We can use Euclidean algorithm to find GCD in O(log(min(n1, n2))) time.

        for (int i = n; i > 0; i--) {
            if (n1 % i == 0 && n2 % i == 0) {
                return i; // Return the first common divisor found, which is the greatest one
            }
        }
        return maxi;

        //Euclidean algorithm, gcd (a, b) = gcd (a mod b, b)
        while (n1 > 0 && n2 > 0) {
            if (n1 > n2) {
                n1 = n1 % n2;
            } else {
                n2 = n2 % n1;
            }
        }
        if( n1 == 0)
            return n2;
        else
            return n1;
        // TC: O(log phi(min(n1, n2))) which is efficient for large numbers.
}

int main()
{
    int number1, number2;
    cout << "Enter two numbers: ";
    cin >> number1 >> number2;
    int result = GCD(number1, number2);
    cout << "The GCD of " << number1 << " and " << number2 << " is: " << result << endl;
    return 0;
}
