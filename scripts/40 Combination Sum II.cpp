class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> sol;
        if (candidates.size() == 0) return result;
        sort(candidates.begin(), candidates.end());
        
        findCombination(candidates, 0, target, sol, result);
        return result;
    }
    
    void findCombination(vector<int>& candidates, int startIndex, int target, vector<int>& sol, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(sol);
            return;
        }
        
        for (int i = startIndex; i < candidates.size(); i++) {
            if (target >= candidates[i]) {
                sol.push_back(candidates[i]);
                //compared to Combination Sum, startIndex + 1
                findCombination(candidates, i + 1, target - candidates[i], sol, result);
                sol.pop_back();
                //bypass the duplicate elements
                while(i < (candidates.size() - 1) && candidates[i] == candidates[i + 1]) i++;
            }
        }
    }
};