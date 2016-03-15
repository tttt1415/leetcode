class Solution {
public:
    int jump(vector<int>& nums) {
        //try to find the max coverage based on current coverage
        //keep updating start and end idex
		if (nums.size() <= 1) return 0;
        int start = 0;
		int end = 0;
		int numJumps = 0;
		int maxIndex = nums.size() - 1;
		
		while (end < maxIndex) {
			int currentMax = 0;
			numJumps++;
			for (int i = start; i <= end; i++) {
				if ((nums[i] + i) >= maxIndex) {
					return numJumps;
				}
				currentMax = max(currentMax, nums[i] + i);
			}
			start = end + 1;
			end = currentMax;
		}
		
    }
};