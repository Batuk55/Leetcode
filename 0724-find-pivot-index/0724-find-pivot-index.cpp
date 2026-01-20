class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int Sum = 0;
        for (int a = 0; a < nums.size(); a++) {
            //for (int i = 0; i < index; i++) {
                Sum = Sum + nums[a];
               // nums[i+1] = nums[i] + nums[i+1];
            }
            //return nums[index-1];
            int leftSum= 0;
            for (int j = 0; j < nums.size(); j++) {
                if(leftSum == Sum - leftSum - nums[j])
                {return j;} 
                leftSum = leftSum + nums[j];
//                nums[j] = nums[j-1] + nums[j];
            }
            //return nums[nums.size()-1];
            //if (nums[index-1] == nums[nums.size()-1])
            //{return index;}
            return -1;
        }
};