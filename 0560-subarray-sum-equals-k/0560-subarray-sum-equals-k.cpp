class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        /* this approach will work if all numbers are positive
         int n = nums.size();
         int sum = 0;

         int count = 0;
         int j = 0;
         for (int i = 0; i < n && j<=i; i++) {
             sum += nums[i];

             if (sum == k) {
                 count++;
             } else if (sum > k) {
                 sum -= nums[j++];
             }
         }
         return count;
        */
        int n = nums.size();
        long long sum = 0;
        int count = 0;

        unordered_map<int, int> presum_map;
// (if sum - k == 0) then, initially 0 will not exist in map, we have to provide that value. 
        presum_map[0] = 1;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            // if (sum == k) {
            //     count++;
            // }

            int rem = sum - k;

            if (presum_map.find(rem) != presum_map.end()) { // means that rem exist in map.

                // count++; not just single increment, because rem can appear
                // multiple times.
                count = count + presum_map[rem];
            }

            presum_map[sum]++;
        }
        return count;
    }
};