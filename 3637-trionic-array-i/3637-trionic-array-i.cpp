class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if (nums.size() < 4)
            return false;
        int i = 0;
        // increasing

/*For a vector of size n:

valid indices: 0 … n-1


So:

nums[i] is valid if i < n

nums[i + 1] is valid only if i + 1 < n*/
        while (i + 1 < nums.size() && nums[i] < nums[i + 1])
            i++;
        if (i == 0 || i == nums.size() - 1)
            return false;

        // decreasing
        int mid = i;
        while (i + 1 < nums.size() && nums[i] > nums[i + 1])
            i++;
        if (i == mid || i == nums.size() - 1)
            return false;

        // increasing
        int mid2 = i;
        while (i + 1 < nums.size() && nums[i] < nums[i + 1])
            i++;
        if (i == mid2 ||i < nums.size() - 1)
            return false;
            return true;
    }
};