class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
		int start = 0;
		int end = nums.size() - 1;
		
		while (end >= start) {
			int mid = start + (end - start) / 2;
			if (nums[mid] == target) return mid;
			
			//left side is sorted
			//remember to use equal in case there is only two elements
			if (nums[mid] >= nums[start]) {
				if (target >= nums[start] && nums[mid] > target) {
					end = mid - 1;
				}
				else{
					start = mid + 1;
				}
			}
			else {
				if (target <= nums[end] && nums[mid] < target) {
					start = mid + 1;
				}
				else{
					end = mid - 1;
				}				
			}
		}
		return -1;
    }
};