class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int start = 0;
		int end = matrix.size() - 1;
		
		//rotate by layer
		while (start < end) {
			for (int i = start; i < end; i++) {
				int temp = matrix[start][i];
				int offset = i - start;
				matrix[start][i] = matrix[end - offset][start];
				matrix[end - offset][start] = matrix[end][end - offset];
				matrix[end][end - offset] = matrix[start + offset][end];
				matrix[start + offset][end] = temp;
			}
			start++;
			end--;
		}
    }
};