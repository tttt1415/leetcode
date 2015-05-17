class Solution {
public:
    int reverse(int x) {
        //in c, % is reminder, (a/b) * b + a%b shall equal a, so the negative will be preserved
        int result = 0;
        while(x != 0) {
            // handle overflow/underflow
            if (abs(result) > INT_MAX/10) return 0;
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }
};