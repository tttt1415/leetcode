class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//binary search for first elements in each rows
		//binary search for each colums in the selected row
        int numRows = matrix.size();
		if (numRows == 0) return false;
		int numCols = matrix[0].size();
		if (numCols == 0) return false;
		if (target < matrix[0][0] || target > matrix[numRows - 1][numCols - 1]) {
			return false;
		}
		
		int start = 0;
		int end = numRows - 1;
		int mid;
		while (start <= end) {
			mid = (start + end)/2;
			if (matrix[mid][0] == target) {
				return true;
			}
			else if (matrix[mid][0] > target) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		int row = end;
		start = 0;
		end = numCols - 1;
		while (start <= end) {
			mid = (start + end)/2;
			if (matrix[row][mid] == target) {
				return true;
			}
			else if (matrix[row][mid] > target) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		
		return false;
    }
};