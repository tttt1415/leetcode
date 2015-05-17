class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        
        //start from -1 as trick
        int i = -1;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        return ++i;
    }
};