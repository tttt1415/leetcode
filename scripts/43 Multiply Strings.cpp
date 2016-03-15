class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 0 || num2.size() == 0) return "";
        string result(num1.size() + num2.size(), '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for (int i = 0; i < num1.size(); i++) {
            int value = 0;
            for (int j = 0; j < num2.size(); j++) {
                value += (num1[i] - '0') * (num2[j] - '0') + (result[i+j] - '0');
                result[i + j] = value % 10 + '0';
                value = value / 10;
            }
            //remember to habdle the case if there is still remaining for value
            if (value != 0) result[num2.size() + i] = value + '0';
        }
        reverse(result.begin(), result.end());
        
        //find the first non-zero index after calulation
        //please note there might be '000' -> '0' case
        int nonZeroIndex = 0;
        for (; nonZeroIndex < result.size() - 1; nonZeroIndex++) {
            if (result[nonZeroIndex] != '0') break;
        }
        result.erase(0, nonZeroIndex);
        
        return result;
    }
};