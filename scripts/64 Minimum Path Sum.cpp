class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //S[i][j] = min(S[i-1][j], S[i][j-1]) + grid[i][j]
        //use 1-d array to update the result 
        int numRows = grid.size();
		if (numRows == 0) return 0;
		int numCols = grid[0].size();
		if (numCols == 0) return 0;
		vector<int> result(numCols, INT_MAX);
		result[0] = 0;
		
		for (int i = 0; i < numRows; i++) {
			result[0] = result[0] + grid[i][0];
			for (int j = 1; j < numCols; j++) {
				result[j] = min(result[j], result[j - 1]) + grid[i][j];
			}
		}
		
		return result[numCols - 1];
    }
};