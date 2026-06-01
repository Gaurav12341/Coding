#include <bits/stdc++.h>
using namespace std;

void func(int i, int n)
{
    if (i > n)
        return;
    cout << i << " ";  //1, 2, 3, 3, 2, 1
    func(i+1, n);
    cout << i<<" ";
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    func(1, n);
    cout << endl;
    return 0;
}