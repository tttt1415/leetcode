class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sol;
        vector<vector<int>> result;
        result.push_back(sol);
        sort(nums.begin(), nums.end());
        
        generateSubset(nums, 0, sol, result);
        return result;
    }
    
    void generateSubset(vector<int>& nums, int level, vector<int>& sol, vector<vector<int>> &result) {
        for (int i = level; i < nums.size(); i++) {
            //use "i > level" sicne we want to push the value at least once
            if (i > level && nums[i] == nums[i-1]) continue;
            sol.push_back(nums[i]);
            result.push_back(sol);
            generateSubset(nums, i + 1, sol, result);
            sol.pop_back();
            
        }
    }
    
};