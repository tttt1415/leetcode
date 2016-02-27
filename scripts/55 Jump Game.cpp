class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        int size = nums.size();
        
        for (int i = 0; i < size; i++) {
            //i > maxIndex means we are not able to reach the ith location
            if (maxIndex >= (size-1) || i > maxIndex) break;
            maxIndex = max(maxIndex, nums[i] + i);
        }
        
        return maxIndex >= (size-1) ? true : false;
    }
};