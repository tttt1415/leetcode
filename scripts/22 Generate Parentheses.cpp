class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        if (n!=0)
            getCombination(result, s, n, n);
        return result;
    }
    //remember to use reference for result
    void getCombination(vector<string>& result, string& s, int left, int right) {
        if (left == 0 && right == 0) {
            result.push_back(s);
            return;
        }
        
        if (left > 0) {
            s.push_back('(');
            getCombination(result, s, left-1, right);
            //remember to resize the string
            s.resize(s.size()-1);
        }
        
        //only add the right Parentheses when it is larger than number of the left one
        if (right > left) {
            s.push_back(')');
            getCombination(result, s, left, right-1);
            s.resize(s.size()-1);
        }
    }
};