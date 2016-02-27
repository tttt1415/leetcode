class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int sum = detectNegMax(nums);
        if (sum < 0) {
            return sum;
        }
        else {
           sum = 0; 
        }
        int result = nums[0];
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum < 0) {
                sum = 0;
            }
            if (sum > result) {
                result = sum;
            }
        }
        
        return result;
    }
    
    //if all the array elements are negative, return max negative value
    int detectNegMax(vector<int>& nums) {
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            //return zero once there is a positive value
            if (nums[i] > 0) return 0;
            
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        return max;
    }
};