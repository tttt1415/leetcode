class Solution {
public:
    int totalNQueens(int n) {
		int count = 0;
		vector<int> colLocation(n, -1); //colLocation[i] is the column location for queen at row i
		
		findSol(n, 0, colLocation, count);
		return count;
    }
	
	void findSol(int n, int currentRow, vector<int>& colLocation, int& count) {
		if (currentRow == n) {
			count++;
			return;
		}
		
		for (int col = 0; col < n; col++) {
			if (isValid(col, currentRow, colLocation)) {
				colLocation[currentRow] = col;
				findSol(n, currentRow + 1, colLocation, count);
				colLocation[currentRow] = -1;
			}
		}
		
	}
	
	bool isValid(int col, int row, vector<int>& colLocation) {
		for (int i = 0; i < row; i++) {
			//be careful about the condition
			//check if there is already a queen at the same column
			//check if there is a queen at the diagonal location
			if (col == colLocation[i] || abs(i - row) == abs(colLocation[i] - col)) return false;
		}
		return true;
	}
};