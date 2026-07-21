class Solution {
public:
    int nice(vector<int>& nums, int k){
        if(k<0) return 0;
        int n = nums.size();
        int l = 0, r = 0;
        int odd_cnt = 0;
        int total = 0;

        while(r<n){
            if(nums[r]%2==1) odd_cnt++; //!(nums[r]&1) == nums[r]%2==1;
            while(odd_cnt > k){
                if(nums[l]%2==1) odd_cnt--;
                l++;
            }
            total = total+ (r-l+1);
            r++;
        }
        return total;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return nice(nums, k) - nice(nums, k-1);
        
    }
};