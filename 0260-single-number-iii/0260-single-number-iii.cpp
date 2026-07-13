class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xor_ = 0;
        for(int i = 0; i< nums.size(); i++){
            xor_ ^= nums[i];
        }
        int last_set_bit = (xor_&(xor_ - 1))^xor_;
        
        int num1 = 0, num2 = 0;

        for(int i = 0; i< nums.size(); i++){
            if(nums[i] & last_set_bit) num1 = num1 ^ nums[i];
            else num2 = num2 ^ nums[i];
        }
        return {num1, num2};
    }
};