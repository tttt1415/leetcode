class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n,0));
        
        int numLevels = n/2;
        int value = 1;
        
        for (int i = 0; i < numLevels; i++) {
            int last = n - i - 1;
            
            for (int j = i; j < last; j++) {
                result[i][j] = value++;
            }
            for (int j = i; j < last; j++) {
                result[j][last] = value++;
            }
            for (int j = last; j > i; j--) {
                result[last][j] = value++;
            }
            for (int j = last; j > i; j--) {
                result[j][i] = value++;
            }
        }
        
        //handle the middle (last) element
        if (n%2 != 0) {
            result[n/2][n/2] = value++;
        }
        
        return result;
    }
};