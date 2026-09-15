class Solution {
public:
    int binSearch(vector<int>& nums, int low, int high, int target){
        if(low>high) return -1;// base case
        int mid = low + (high - low) / 2;
        if(nums[mid] == target) return mid;

        if(nums[mid]>target) return binSearch(nums, low, mid-1, target);
        if(nums[mid]<target) return binSearch(nums, mid+1, high, target);
        return -1;
        
    }
    int search(vector<int>& nums, int target) {
        
        return binSearch(nums, 0, nums.size()-1, target);
        
    }
};