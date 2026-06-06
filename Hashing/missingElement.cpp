#include <bits/stdc++.h>
using namespace std;

int missingElement(vector<int> &hash)
{
    int n = hash.size() - 1; 
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0) // check if the frequency of the element is zero in the hash array. If it is zero, then it means that the element is missing in the input array.
        {
            return i; // return the missing element.
        }
    }
    return -1; // return -1 if there is no missing element in the input array.
}

int main()
{
    vector<int> nums = {1, 2, }; 
    int n = nums.size();
    vector<int> hash(n + 1, 0); // create a hash array of size n+1 to store the frequency of each element in the input array. We can use counting sort to count the frequency of each element in O(n) time and O(n) space.
    for (int i = 0; i < n; i++)
    {
        hash[nums[i]]++; 
    }
    cout << "The missing element in the array is: " << missingElement(hash) << endl; // find the missing element in the input array using the hash array and print the result.
    return 0;
}