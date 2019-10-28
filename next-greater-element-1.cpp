/*
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.


*/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> output;

        // so to solve this, knowing that my first array is inside of the second array ( Definition of a subset),
        // I need to find the next biggest element for every element inside the second array
        // to do that I will traverse through it while pushing values on a stack to determine if their is a next element.
        // I'll store each value in a hashtable corresponding to the next biggest number

        stack<int> tempValues;
        unordered_map<int, int> temp;

        for (int i = 0; i < nums2.size(); i++)
        {

            // if the stack has a value in it ( meaning something that might have a next bigger number) and there is a next bigger #
            while (!tempValues.empty() && tempValues.top() < nums2[i])
            {
                //store it in the map
                temp[tempValues.top()] = nums2[i];

                // remove it from the stack
                tempValues.pop();
            }

            // add the current value
            tempValues.push(nums2[i]);
        }

        // now for every element left on the stack, it does not have a next greater element so we'll map it to -1 per the question

        while (!tempValues.empty())
        {
            temp[tempValues.top()] = -1;
            tempValues.pop();
        }

        // finally, we have to find the next greater element by simply searching the map which is an O(1) operation for each value in the nums1 array

        for (auto m : nums1)
        {
            output.push_back(temp[m]);
        }

        return output;
    }
};