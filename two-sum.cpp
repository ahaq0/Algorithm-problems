#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        unordered_map<int, int> hash;

        vector<int> output;

        for (int i = 0; i < nums.size(); i++)
        {
            int toFind = target - nums[i];

            // so there is only one solution that means as soon as we find a solution
            // we must return what we got
            if (hash.find(toFind) != hash.end())
            {
                output.push_back(i);
                output.push_back(hash[toFind]);

                cout << hash[toFind] << "  and index rn " << i;
                break;
            }

            // must store the values in the hashtable after a pass to avoid finding a duplicate
            hash[nums[i]] = i;
        }
        return output;
    }
};