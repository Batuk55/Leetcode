class comparator{
    public:
    bool operator()(pair<int,int> a, pair<int, int> b){
        return a.first > b.first; //Min-heap
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        // Your code goes here
        priority_queue<pair<int,int>, vector<pair<int, int>>, comparator> pq;

        for(int i = 0; i< n; i++){
            pq.push({arr[i],i});
        }
        vector<int> ans(n);
        int rank = 1;
        int prev = INT_MIN;
        
        while(!pq.empty()){
            // arr[x] = pq.top().second;
            auto it = pq.top();
            pq.pop();
            
            int val = it.first;
            int idx = it.second;

            if(val != prev){
                prev = val;
                ans[idx] = rank++;
            }
            else{
                ans[idx] = rank-1;
            }
        }
        return ans;
    }
};