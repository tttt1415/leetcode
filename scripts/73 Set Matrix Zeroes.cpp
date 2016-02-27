class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //use the first row and first column to record which row and column need to be 0
        //check if the first row and column need to be cleared to zero first
        
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        bool clearFirstRow = false;
        bool clearFirstCol = false;
        
        for (int i = 0; i < numRows; i++) {
			if (matrix[i][0] == 0) {
				clearFirstCol = true;
			}
		}
		for (int  i = 0; i < numCols; i++) {
			if (matrix[0][i] == 0) {
				clearFirstRow = true;
			}
		}
		
		for (int i = 1; i < numRows; i++) {
			for (int j = 1; j < numCols; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		
		for (int i = 1; i < numRows; i++) {
			for (int j = 1; j < numCols; j++) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
		
		if (clearFirstCol) {
			for (int i = 0; i < numRows; i++) {
				matrix[i][0] = 0;
			}
		}
        
		if (clearFirstRow) {
			for (int i = 0; i < numCols; i++) {
				matrix[0][i] = 0;
			}
		}
		
    }
};