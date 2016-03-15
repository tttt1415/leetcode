/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        bool isInserted = false;
        
        for (int i = 0; i < intervals.size(); i++) {
            //interval is smaller than newInterval
            if (intervals[i].end < newInterval.start) {
                result.push_back(intervals[i]);
            }
            //overlap
            else if (intervals[i].end >= newInterval.start && newInterval.end >= intervals[i].start) {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
            //interval is larger than newInterval
            else {
                if (isInserted) {
                    result.push_back(intervals[i]);
                }
                else {
                    result.push_back(newInterval);
                    result.push_back(intervals[i]);
                    isInserted = true;
                }
            }
        }
        
        //becareful is all the intervlas are overlapped with newInterval
        if (!isInserted) result.push_back(newInterval);
        return result;
    }
};