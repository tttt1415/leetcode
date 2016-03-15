class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
		if (nums.size() == 0) return result;
		int start = 0;
		int end = nums.size() - 1;
		int mid;
		
		while (end > start) {
			mid = start + (end - start) / 2;
			if (nums[mid] >= target) {
				end = mid;
			}
			else {
				start = mid + 1;
			}
		}
		int left = nums[start] == target ? start : -1;
		if (left == -1) return result;
		
		start = left; // or 0
		//please note that this is different than the previous one since we use start - 1 as a result
		end = nums.size();
		while (end > start) {
			mid = start + (end - start) / 2;
			if (nums[mid] <= target) {
				start = mid + 1;
			}
			else {
				end = mid;
			}
		}
		
		int right = start - 1;
		result[0] = left;
		result[1] = right;
		return result;
    }
};