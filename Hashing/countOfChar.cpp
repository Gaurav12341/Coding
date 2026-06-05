#include <bits/stdc++.h>
using namespace std;

int countOfChar(vector<int> &hash, char target)
{
    return hash[target - 'a']; // return the frequency of the character in the hash array.
}

int main()
{
    string str = "helloworld"; 
    int n = str.size();
    vector<int> hash(26, 0); // create a hash array of size 26 to store the frequency of each character in the input string. We can use counting sort to count the frequency of each character in O(n) time and O(n) space.
    for (int i = 0; i < n; i++)
    {
        hash[str[i] - 'a']++; // increment the frequency of the character in the hash array.
    }
    for (int i = 0; i < n; i++)
    {
        cout << "The count of '" << str[i] << "' in the string is: " << countOfChar(hash, str[i]) << endl;
    }
    return 0;
}