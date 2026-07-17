class Solution {
public:
    int MOD = (int)1e9+7;
    vector<int> find_nse(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        int i = n-1;
        while(i>=0){
            while(!st.empty() && arr[i]<arr[st.top()]) st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i--);
        }
        return ans;
    }
    vector<int> find_psee(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        int i = 0;
        while(i<n){
            while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i++);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = find_nse(arr);
        vector<int> pseOrEq = find_psee(arr);
        
        long long sum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            int left = i - pseOrEq[i];
            int right =nse[i] - i;

            sum = (sum + (right*left*1LL* arr[i]) % MOD) % MOD;
        }
        return sum;
    }
};