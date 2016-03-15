class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
		if (matrix.size() == 0 || matrix[0].size() == 0) return result;
		int numRows = matrix.size();
		int numCols = matrix[0].size();
		//determine the number of layers based on the minimum rows, columns
		int numLayers = (min(numRows, numCols) + 1 )/ 2;
		
		for (int i = 0; i < numLayers; i++) {
			int lastRow = numRows - 1 - i;
			int lastCol = numCols - 1 - i;

			//if there is only one row left
			if (lastRow == i) {
				for (int j = i; j <= lastCol; j++) {
					result.push_back(matrix[i][j]);
				}
			}
			//if there is only one column left
			else if (lastCol == i) {
				for (int j = i; j <= lastRow; j++) {
					result.push_back(matrix[j][i]);
				}
			}
			else {
				for (int j = i; j < lastCol; j++) {
					result.push_back(matrix[i][j]);
				}
				for (int j = i; j < lastRow; j++) {
					result.push_back(matrix[j][lastCol]);
				}
				for (int j = lastCol; j > i; j--) {
					result.push_back(matrix[lastRow][j]);
				}
				for (int j = lastRow; j > i; j--) {
					result.push_back(matrix[j][i]);
				}
			}
		}
		
		return result;
    }
};