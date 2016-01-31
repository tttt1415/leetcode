class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> sol;
		vector<bool> used(nums.size(), false);
		if (nums.size() == 0) return result;
		
        findPermutation(nums, sol, result, used);
		return result;
    }
	
	void findPermutation(vector<int>& nums, vector<int>& sol, vector<vector<int>>& result, vector<bool>& used) {
		if (sol.size() == nums.size()) {
			result.push_back(sol);
			return;
		}
		
		for (int i = 0; i < nums.size(); i++) {
			if (!used[i]) {
				used[i] = true;
				sol.push_back(nums[i]);
				findPermutation(nums, sol, result, used);
				used[i] = false;
				sol.pop_back();
			}
		}
	}
};