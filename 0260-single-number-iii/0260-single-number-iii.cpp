class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
            vector<int> res;
            int i = 0;
            int j = 1;
            
            while(j<nums.size()){
                if(nums[i]!= nums[j]){
                     res.push_back(nums[i]);
                     i++;
                     j++;
                     continue;
                }
                i+=2;
                j+=2;
            }
            if(i==nums.size()-1) res.push_back(nums[i]);
            return res;
    }
};