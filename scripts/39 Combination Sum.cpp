class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> sol;
		if (candidates.size() == 0) return result;
		sort(candidates.begin(),candidates.end());
		
		checkCombinationSum(candidates, 0, target, sol, result);
        return result;
    }
	
	void checkCombinationSum(vector<int>& candidates, int startIndex, int target, vector<int>& sol, vector<vector<int>>& result) {
		if (target == 0) {
			result.push_back(sol);
			return;
		}
		
		for (int i = startIndex; i < candidates.size(); i++) {
			if (candidates[i] <= target) {
				sol.push_back(candidates[i]);
				checkCombinationSum(candidates, i, target - candidates[i], sol, result);
				sol.pop_back();
			}
		}
	}
};