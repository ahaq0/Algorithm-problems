class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // We can avoid dividing by 0 by simply multipling both sides of the array
        // by each others product from the other side
        
        // These will remain the same due since there's nothing on the other side.
        vector<int> output (nums.size(), 1);
        // We know that at the start it's one
        int left = 1, right = 1;
        for (int i = 1; i < nums.size(); i++){
            left *= nums[i - 1];
            result[i] *= left;
            right *= nums[nums.size() - i];
            result[nums.size() - i - 1] *= right;
        }
        return result;

    }
}; 