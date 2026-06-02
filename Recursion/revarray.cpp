#include   <bits/stdc++.h>
using namespace std;


// void reverseArray(int (&arr)[], int start, int end) // end = n-1-i
void reverseArray(int arr[], int start, int n) // end = n-1-i
{
    if (start >= n/2)
        return;

    swap(arr[start], arr[n-1-start]);
    reverseArray(arr, start + 1, n);
}

bool palindrome (string &s, int i)
{
    if(i>=s.size()/2)
        return true;
    if(s[i] != s[s.size()-1-i])
        return false;
    return palindrome(s, i+1);
}   

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    reverseArray(arr, 0, n);
    cout << "The reversed array is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    string s;
    cout << "Enter a string: ";
    cin >> s;
    if (palindrome(s, 0))
        cout << s << " is a palindrome." << endl;
    else
        cout << s << " is not a palindrome." << endl;
    return 0;
}