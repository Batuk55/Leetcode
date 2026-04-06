class Solution {
public:
//same as book allocation problem...
    int cnt(vector<int> nums, int pages){
        int students = 1 , pages_holding = 0;
        // int subarrays = 1 , num_sum = 0;

        for(int i = 0; i< nums.size() ; i++){
            if(pages_holding + nums[i] <= pages) pages_holding += nums[i];
            else {
                students ++;
                pages_holding = nums[i];
        }
    }
    return students;
    }

    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin() , nums.end());
        int sum = 0;
        for(int num : nums) sum += num;
        int high = sum;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int count_subarrays = cnt(nums, mid);

            if(count_subarrays > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};