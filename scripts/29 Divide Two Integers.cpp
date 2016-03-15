class Solution {
public:
    int divide(int dividend, int divisor) {
        //http://bangbingsyb.blogspot.com/2014/11/divide-two-integers-divide-two-integers.html
        //32 = 3*[2^3 + 2^1] + 2
        //3*2^3 < 32 < 3*2^4, div = 32 - 3*2^3 = 8
        //3*2^1 < 8 < 3*2^2, div = 8 - 3*2^1 = 2
        //since 2 < 3, res = 2^3 + 2^1 = 10;
        if (divisor == 0) return (divisor > 0) ? INT_MAX : INT_MIN;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        bool isNeg = false;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) isNeg = true;
        unsigned long y = abs((long)dividend);
        unsigned long x = abs((long)divisor);
        
        int i = 0;
        while (y >= x<<(i+1)) i++;
        
        int res = 0;
        while (y >= x) {
            if (y >= x<<i) {
                y -= x<<i;
                res += 1<<i;
            }
            i--;
        }
        
        return isNeg ? -res : res;
    }
};