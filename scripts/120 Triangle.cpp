class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int numRows = triangle.size();
    if (numRows == 0) return 0;
    vector<int> minVal(triangle[numRows - 1].size());
    
    for (int j = 0; j < triangle[numRows - 1].size(); j++) {
      minVal[j] = triangle[numRows - 1][j];
    }
    
    for (int i = numRows - 2; i >= 0; i--) {
      for (int j = 0; j < triangle[i].size(); j++) {
        minVal[j] = min(minVal[j], minVal[j + 1]) + triangle[i][j];
      }
    }
    
    return minVal[0];
  }
};