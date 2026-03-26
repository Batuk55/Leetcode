class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int low = 1, high = nums.size() - 2;
        if(nums.size() == 1) return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[high + 1] > nums[high])
            return high + 1;

        while (high >= low) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            // now how to eliminat left or right halfs??
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else if(nums[mid] < nums[mid - 1]){
                high = mid - 1;
            }
        }
        return -1; // never happens
    }
};