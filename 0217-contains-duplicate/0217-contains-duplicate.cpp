class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        // for(map<int,int> :: iterator it = nums.begin(); it !=nums.end() ;
        // it++) or
        for (auto it : nums) {
            if (mpp[it] >= 2) {
                return true;
            }
        }
        return false;
    }
};