#include <bits/stdc++.h>
using namespace std;

int countOfElem(vector<int> &hash, int target)
{
    return hash[target];
}

void countofElemMap(vector<int> &nums)
{
    map<int, int> hash; // create a hash map to store the frequency of each element in the input array. We can use counting sort to count the frequency of each element in O(n) time and O(n) space.
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]++; // increment the frequency of the element in the hash map.
    }
    for (auto it : hash)
    {
        cout << "The count of " << it.first << " in the array is: " << it.second << endl;
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 22, 2}; //constrain size of array to 10^5 and elements to 10^5, so that we can use counting sort to count the frequency of each element in O(n) time and O(n) space.
    int n = nums.size();
    vector<int> hash(pow(10, 5) + 1, 0); // create a hash array of size n+1 to store the frequency of each element in the input array. We can use counting sort to count the frequency of each element in O(n) time and O(n) space.
    for (int i = 0; i < n; i++)
    {
        hash[nums[i]]++; // increment the frequency of the element in the hash array.
    }
    int target = 7;
    cout << "The count of " << target << " in the array is: " << countOfElem(hash, target) << endl;

    countofElemMap(nums); // count the frequency of each element in the input array using a hash map and print the result.
    return 0;
}

// tc: O(n) where n is the size of the input array, which is efficient for large n. SC: O(n) where n is the size of the hash array, which is efficient for large n.