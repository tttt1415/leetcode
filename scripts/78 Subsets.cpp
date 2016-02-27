class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		//similar to combination, permutation
		vector<vector<int>> result;
		vector<int> sol;
		if (nums.size() == 0) return result;
		result.push_back(sol);
		sort(nums.begin(), nums.end());
		generateSubsets(nums, 0, sol, result);
		
		return result;
	}
	
	void generateSubsets(vector<int>& nums, int level, vector<int>& sol, vector<vector<int>>& result) {
		for (int i = level; i < nums.size(); i++) {
			sol.push_back(nums[i]);
			result.push_back(sol);
			generateSubsets(nums, i+1, sol, result);
			sol.pop_back();
		}
	
	}
};