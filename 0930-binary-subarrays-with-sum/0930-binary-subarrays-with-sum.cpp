class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        long long sum = 0;
        int count = 0;
        // int l = 0, r = 0;

        unordered_map<int, int> presum_map;
        presum_map[0] = 1;

        for (int i = 0 ; i < n; i++) {
            sum += nums[i];
            int rem = sum - goal;

            if (presum_map.find(rem) != presum_map.end()) {
                count += presum_map[rem];
            }
            presum_map[sum]++;
        }
        return count;
    }
};