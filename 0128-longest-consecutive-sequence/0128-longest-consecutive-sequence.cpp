class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int lar_count = 0;
        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        for (auto it : st) {
            if (st.find(it - 1)==st.end()) { // means that (it-1) does not exists in set.
                int count = 1;
                int x = it;

                while (st.find(x + 1) != st.end()) { // means if it+1 exists in set
                    x++;
                    count++;
                }
                lar_count = max(lar_count, count);
            }
        }

        return lar_count;
    }
};