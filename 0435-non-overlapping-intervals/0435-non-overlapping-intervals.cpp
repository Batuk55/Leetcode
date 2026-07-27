class comp{
public:
    bool operator()(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp());

        int cnt = 0;
        int prevEnd = intervals[0][1];

        for(int i = 1; i< n; i++){
            if(intervals[i][0] <prevEnd){
                cnt++; // remove current interval
            }
            // if(intervals[i] == intervals[i-1]) cnt++;
            else{
                prevEnd = intervals[i][1];
            }
        }
        return cnt;
    }
};