/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/

So my first solution was very slow 156ms but it kinda made sense for me by using vector.erase
this was slow since that is O(n) technically in teh way it resizes the vector on it's own
That solution ( easy to understand is below).
Onen thing to remember is to check if vector is empty at the start as an edge case 
to avoid run time error

*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        unsigned int index = 0;
        if (nums.empty())
        {
            return index;
        }
        // we only go till next to last element
        while (index < nums.size() - 1)
        {

            // since it's sorted next one is same
            if (nums[index] == nums[index + 1])
            {
                nums.erase(nums.begin() + index);
                index--; // we go back as size went down
            }
            index++;
        }

        // since all should duplicate gone we return size
        return nums.size();
    }
};

/*
The following solution is much faster because instead of changing the size of the vector
wechange the index of the last unique element while iterating through it
*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        // if there is another element we want to start at 1
        int j = !nums.empty();
        // go through each element
        for (int n : nums)
        {

            // if an element is bigger then we overwrite it
            if (n > nums[j - 1])
            {
                // shift it away while increasing the count of elements
                nums[j++] = n;
            }
        }
        return j;
    }
};