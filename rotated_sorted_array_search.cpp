class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // iterative solution is faster vs recursive
        
        int start = 0;
        int end = nums.size() -1 ;
        
        while(start <= end)
        {
            int mid = (start + end)/ 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            
            
            // so we check if the array is sorted from start to mid
            if(nums[start] <= nums[mid])
            {
                //next is the target smaller? then we adjust mid
                if(target <= nums[mid] && target >= nums[start ])
                {
                    // always move one at least since it isn't mid by default ( we checked already)
                    end = mid-1;
                }
                
                // is target bigger? adjust other side
                else
                {
                    start = mid +1;
                }
            }
            
            // now we do the same for the opposite case happening
            else
            {
                if (nums[mid] < target && target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid- 1;
                }
            }
        }
        return -1;
    }
};