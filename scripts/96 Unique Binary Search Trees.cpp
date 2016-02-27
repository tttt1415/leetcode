class Solution {
public:
    int numTrees(int n) {
        //http://fisherlei.blogspot.com/2013/03/leetcode-unique-binary-search-trees.html
        vector<int> count(n + 1, 0);
        count[0] = 1;
        count[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                count[i] += count[j] * count[i - j - 1];
            }
        }
        return count[n];
    }
};