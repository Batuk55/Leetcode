class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int, vector<int>, greater<int>> greed;
        priority_queue<int, vector<int>, greater<int>> cookieSize;

        for(int gr:g) greed.push(gr);
        for(int size:s) cookieSize.push(size);


        int cnt = 0;
        while(!greed.empty() && !cookieSize.empty()){
            if(greed.top() <= cookieSize.top()){
                cnt++;
                greed.pop();
                cookieSize.pop();
            }
            else{
                cookieSize.pop();
            }
        }
        return cnt;
    }
};