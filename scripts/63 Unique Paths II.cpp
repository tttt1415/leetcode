class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //becareful to handle the case if [0][0] = 1
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 || obstacleGrid[0][0] == 1) return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		int helpArray[m+2][n+2] = {0};
		helpArray[m][n+1] = 1;
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (obstacleGrid[i][j] == 1) {
					helpArray[i + 1][j + 1] = -1;
				}
				else {
					helpArray[i + 1][j + 1] = obstacleGrid[i][j];
				}
			}
		}
		
		for (int i = m; i >= 1; i--) {
			for (int j = n; j >=1 ;j--) {
			    //avoid caculate for obstacle part
			    if (helpArray[i][j] != -1) {
    			    int first = (helpArray[i+1][j] == -1) ? 0 : helpArray[i+1][j];
    				int second = (helpArray[i][j+1] == -1) ? 0 : helpArray[i][j+1];
    				helpArray[i][j] = first + second;
			    }
			}
		}
		
        return helpArray[1][1];
    }
};