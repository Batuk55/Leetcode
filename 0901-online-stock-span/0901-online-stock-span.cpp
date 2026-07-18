class StockSpanner {
public:
    stack<pair<int, int>> st;
    int idx;
    StockSpanner() {
        idx = -1;
        // st.clear();
    }
    
    int next(int  price) {
        idx++;

            while(!st.empty() && price >= st.top().first) st.pop();

            int pg_idx = st.empty() ? -1: st.top().second;
            int ans = idx - pg_idx;

            st.push({price,idx});
        
        return ans;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */