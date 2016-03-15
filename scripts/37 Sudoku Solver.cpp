class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        findSol(board, 0, 0);
    }
	
	bool findSol(vector<vector<char>>& board, int row, int col) {
	    if (row == 9) return true;
	    
	    //do not use ++row/ ++col in the recursion
		if (col > 8) return findSol(board, row+1, 0);
		
		if (board[row][col] == '.') {
			for (int i = 1; i < 10; i++) {
				board[row][col] = '0' + i;
				if (isValidInput(board, row, col)) {
					//for backtracking, cannot return findSol here
					if (findSol(board, row, col+1)) {
						return true;
					}
				}
				board[row][col] = '.';
			}
		}
		else {
			return findSol(board, row, col+1);
		}
		return false;
	}
	
	bool isValidInput(vector<vector<char>>& board, int row, int col) {
		int input = board[row][col];
		
		for (int i = 0; i < 9; i++) {
			if (board[i][col] == input && i != row) return false;
			if (board[row][i] == input && i != col) return false;
		}
		
		for (int i = row/3*3; i < row/3*3 + 3; i++) {
			for (int j = col/3*3; j < col/3*3 + 3; j++) {
			    //be careful about i and j conditions
				if (board[i][j] == input && (i != row || j != col)) return false;
			}
		}
		
		return true;
	}
};