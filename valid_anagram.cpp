/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

*/
#include <algorithm> // for heap operations
#include <iostream>

using namespace std;
class Solution
{
public:
    bool isAnagram(string sr, string te)
    {

        // if not same length then they can't be anagram by default
        if (sr.length() != te.length())
        {
            return false;
        }

        // I take a hashtable and then increment from one string ( decrement from the other)
        unordered_map<char, int> string1;

        for (int i = 0; i < te.length(); i++)
        {
            string1[te[i]]++;
            string1[sr[i]]--;
        }

        // if at any point they aren't even, then we have no anagram
        for (auto c : string1)
        {
            if (c.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};