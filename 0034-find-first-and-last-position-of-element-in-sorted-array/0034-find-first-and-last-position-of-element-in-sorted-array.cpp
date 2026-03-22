class Solution{
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();

        int i = 0;
        while( i< n){
            if(nums[i]==target) break;
            i++;
        }

        int j = n-1;
        while( j >= 0){
            if(nums[j] == target) break;
            j--;
        }

        if(i == n || j == -1){
            return {-1,-1};
        }
        return {i,j};
    }
};