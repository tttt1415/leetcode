class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        //remeber to handle the int max case
        int end = x/2 < sqrt(INT_MAX) ? x/2 + 1 : sqrt(INT_MAX);
        
        while (start <= end) {
            int mid = (end - start) / 2 + start;
            int sqr = mid * mid;
            
            if (sqr == x) return mid;
            else if (sqr < x) start = mid + 1;
            else end = mid - 1;
        }
        
        //the return should be this to avoid answer+1 but not '(end - start) / 2 + start'
        return (start + end) / 2;
    }
};
