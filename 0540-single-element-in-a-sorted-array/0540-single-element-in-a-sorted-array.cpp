class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // can be done by xor but it will be O(N)
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1, high = n - 2;
        while (high >= low) {

            int mid = low + (high - low) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {

                /*nums = [1,1,2,2,3,3,4,5,5]
                    Step 1:
                    low = 1, high = 7
                    mid = 4  → EVEN ❗

👉 Right at the beginning, mid is even.
so, || (mid%2==0 && nums[mid]== nums[mid+1]) wil be used*/
                low = mid + 1;
            }

            else high = mid - 1;
        }
        return -1;
    }
};

/*
        int low = 0, high = nums.size()-1;
        while(high>=low){

            int mid = low + (high - low) / 2;

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return
   nums[mid];

            if(nums[mid] == nums[mid-1]){
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }

        }
        return -1;*/