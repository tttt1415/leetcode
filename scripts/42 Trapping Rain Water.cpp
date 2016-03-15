class Solution {
public:
    int trap(vector<int>& height) {
        //O(n)
        //1. scan from left to right to find max left of every index
        //2. scan from right to left to find max right of every index
        //3. use the minimum of its max left and max right to caculate the volumn
        int length = height.size();
        if (length < 2) return 0;
        vector<int> maxLeft(length, 0);
        vector<int> maxRight(length, 0);
        int currentMax = height[0];
        int totalWater = 0;
        int currentWater;
        
        for (int i = 1; i < length; i++) {
            maxLeft[i] = currentMax;
            currentMax = max(currentMax, height[i]);
        }
        
        currentMax = height[length - 1];
        for (int i = length - 2; i >= 0; i--) {
            maxRight[i] = currentMax;
            currentWater = min(maxRight[i], maxLeft[i]) - height[i];
            if (currentWater > 0) totalWater += currentWater;
            currentMax = max(currentMax, height[i]);
        }
        
        return totalWater;
    }
};