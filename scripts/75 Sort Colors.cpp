class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int i = 0;
        int temp;
        
        while (i <= end) {
            if (nums[i] == 0) {
                temp = nums[start];
                nums[start] = nums[i];
                nums[i] = temp;
                start++;
                i++;
            }
            else if (nums[i] == 1) {
                i++;
            }
            //if value is 2, do not increment i after swap since it needs to be examined
            else if (nums[i] == 2) {
                temp = nums[end];
                nums[end] = nums[i];
                nums[i] = temp;
                end--;
            }
        }
        
    }
};