class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        //similar to Combination Sum
        vector<vector<int>> result;
		vector<int> sol;
		
		checkCombination(n, k, 0, sol, result);
        return result;
    }
	
	void checkCombination(int n, int k, int level, vector<int>& sol, vector<vector<int>>& result) {
		if (sol.size() == k) {
			result.push_back(sol);
			return;
		}
		
		for (int i = level; i < n; i++) {
			sol.push_back(i + 1);
			//remember to pass i + 1 to level
			checkCombination(n, k, i + 1, sol, result);
			sol.pop_back();
		}
	}
	
};