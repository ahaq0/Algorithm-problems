
/*
So this was my first attempt without looking at anything that I need to diagnose and fix
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int output = search(nums, target, nums.size()-1, 0);
        return output;
    }
    
    int search (vector<int> & nums, int target, int end, int start)
    {
        // so if the number on the left is bigger, that means that it's rotated there
        int mid = (end + start) / 2;
        
        // so we check if it is at the mid, quickly
        if(nums[mid] == target)
        {
            return mid;
        }
        
        // so we check to see if it's sorted between the start and mid
        // easiest way by a simple if
        if(nums[start] < nums[mid])
        {

            // if the value is lower than what we have currently have
            if(nums[mid] > target)
            {
                return search(nums,target,mid,start);
            }
            // so it's sorted but value is bigger, we gotta move ahead
            else
            {
                return search(nums,target,end,mid+1);
            }
        }
        
        // so it's not sorted from where we are at from start, so it's sorted from mid to high ( one has to be sorted)
        else
        {
            // if the value is less that means we need to move as it's sorted
            if(nums[mid ]< target)
            {
                return search(nums,target,end,mid + 1);
            }
            
            // otherwise we have to go search in the opposite direction
            else
            {
                return search(nums, target,mid, start);
            }
        }
        
        
        return -1;
        
}
};