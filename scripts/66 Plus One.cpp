class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //use this to detect special case like 99, 999
        int done = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                done = 1;
                break;
            }
            else {
                digits[i] = 0;
            }
        }
        
        if (done == 0) {
            digits.resize(digits.size() + 1);
            digits[0] = 1;
        }
        
        
        return digits;
    }
};