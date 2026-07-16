class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums2.size());
        stack<int>st;
        int i = nums2.size()-1;

        st.push(nums2[i]);
        ans[i] = -1;
        i--;
        while(i>=0){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                // st.push(arr[i]);
                ans[i] = -1;
                // i--;
                // continue;
            }
            else ans[i] = st.top();
        st.push(nums2[i]);
        
        i--;
        }

    unordered_map<int,int> mpp;
    for(int j = 0; j < nums2.size(); j++){ //nums2.size()== ans.size();
        mpp[nums2[j]] = ans[j];
    }
    
    vector<int> result;
    for(int j = 0; j < nums1.size(); j++){
        result.push_back(mpp[nums1[j]]);
    }
    return result;

    }
};