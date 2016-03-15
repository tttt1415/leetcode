class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	vector<vector<int>> result;
    	if (nums.size() == 0) return result;
		
		vector<int> sol;
		vector<bool> used(nums.size(), false);
		//remember to sort for duplicate check later
		sort(nums.begin(), nums.end());
		
        findPermutation(nums, sol, result, used);
		return result;
    }
	
	void findPermutation(vector<int>& nums, vector<int>& sol, vector<vector<int>>& result, vector<bool>& used) {
		if (sol.size() == nums.size()) {
			result.push_back(sol);
			return;
		}
		
		for (int i = 0; i < nums.size(); i++) {
		    //continue is faster than else?
		    if (used[i]) continue;
		    //remember to check if the previous one is used or not
			//otherwise the result will not have enough numbers
		    if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
		    
		    used[i] = true;
    		sol.push_back(nums[i]);
    		findPermutation(nums, sol, result, used);
    		sol.pop_back();
    		used[i] = false;
		}
	}
};