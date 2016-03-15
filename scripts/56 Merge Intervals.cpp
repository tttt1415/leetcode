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
    //create a compare function for inteval
    struct compInterval {
        bool operator()(const Interval &a, const Interval &b) const {
            return a.start < b.start;
        }
    };
    
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compInterval());
        vector<Interval> result;
        if (intervals.size() == 0) return result;
        result.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back().end < intervals[i].start) {
                result.push_back(intervals[i]);
            }
            else {
                //remember to consider two end points here
                result.back().end = max(intervals[i].end, result.back().end);
            }
        }
        
        return result;
    }
};