#include <bits/stdc++.h>
using namespace std;

vector<int> allDivisors(int n)
{
    vector<int> res;
    for (int i = 1; i <= sqrt(n); i++)  // all then divisors of a number are in pairs, so we only need to loop till sqrt(n) 
    // for 36, the divisors are 1*36, 2*18, 3*12, 4*9, 6*6. So we only need to loop till 6 which is sqrt(36) to find all the divisors.
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (n / i != i)
            {
                res.push_back(n / i);
            }
        }
    }
    sort(res.begin(), res.end()); //O(klog k) where k is the number of divisors
    return res;
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    cout << "The divisors of " << number << " are: ";
    for (auto it : allDivisors(number)) 
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}