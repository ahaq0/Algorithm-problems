/*
Given an int array nums and an int target, find how many unique pairs in the array such that their sum is equal to target. Return the number of pairs.

Example 1:

Input: nums = [1, 1, 2, 45, 46, 46], target = 47
Output: 2
Explanation:
1 + 46 = 47
2 + 45 = 47
Example 2:

Input: nums = [1, 1], target = 2
Output: 1
Explanation:
1 + 1 = 2
Example 3:

Input: nums = [1, 5, 1, 5], target = 6
Output: 1
Explanation:
[1, 5] and [5, 1] are considered the same.

So this problem is eerily similar to the 2 sum problem with the added part of finding duplicates
so the fastest way to only add duplicates is to use a set, in C++ that is a unordered_set ( normal set = logn times)
*/

using namespace std;
#include <iostream>
#include <unordered_map>
#include <unordered_set>
unordered_set<int, int> uniqueTwoSums(int nums[], int target);
int main()
{
    return 0;
}
unordered_set<int, int> uniqueTwoSums(int nums[], int target)
{
    // I will output only the unique values
    unordered_set<int, int> output;

    // in order to find what values add up to the target in one pass, I'll loop through
    for (const int &a : nums)
    {
    }
}
