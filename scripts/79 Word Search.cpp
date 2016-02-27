class Solution {
public:
    //similar backtracking problem
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return false;
        if (board.size() == 0 || board[0].size() == 0) return false;
        int numRows = board.size();
        int numCols = board[0].size();
        vector<int> visited(numRows*numCols, 0); 
        
        for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				if (board[i][j] == word[0]) {
					visited[i * numCols + j] = 1;
					if (search(board, word, visited, 0, i, j)) {
						return true;
					}
					visited[i * numCols + j] = 0;
				}
			}
		}
		
		return false;
    }
	
	//note: use string& instead of string
	bool search(vector<vector<char>>& board, string& word, vector<int>& visited, int wordIndex, int row, int col) {
		if (wordIndex == word.size() - 1) return true;
		int numRows = board.size();
        int numCols = board[0].size();
		
		//go down
		if (row + 1 < numRows) {
			if (board[row + 1][col] == word[wordIndex + 1] && visited[(row + 1) * numCols + col] == 0) {
				visited[(row + 1) * numCols + col] = 1;
				if (search(board, word, visited, wordIndex + 1, row + 1, col)) {
					return true;
				}
				visited[(row + 1) * numCols + col] = 0;
			}
		}
		
		//go up
		if (row - 1 >= 0) {
			if (board[row - 1][col] == word[wordIndex + 1] && visited[(row - 1) * numCols + col] == 0) {
				visited[(row - 1) * numCols + col] = 1;
				if (search(board, word, visited, wordIndex + 1, row - 1, col)) {
					return true;
				}
				visited[(row - 1) * numCols + col] = 0;
			}
		}
		
		//go right
		if (col + 1 < numCols) {
			if (board[row][col + 1] == word[wordIndex + 1] && visited[row * numCols + (col + 1)] == 0) {
				visited[row * numCols + (col + 1)] = 1;
				if (search(board, word, visited, wordIndex + 1, row, col + 1)) {
					return true;
				}
				visited[row * numCols + (col + 1)] = 0;
			}
		}
		
		//go left
		if (col - 1 >= 0) {
			if (board[row][col - 1] == word[wordIndex + 1] && visited[row * numCols + (col - 1)] == 0) {
				visited[row * numCols + (col - 1)] = 1;
				if (search(board, word, visited, wordIndex + 1, row, col - 1)) {
					return true;
				}
				visited[row * numCols + (col - 1)] = 0;
			}
		}
	    
	    return false;
	}
};