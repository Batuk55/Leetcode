class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int count = 0;
        int temp = 0;
       /* for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 1) {
                temp = max(temp, count); // added later
                count = 0;
                continue;
            }
            count++;
        }
        temp = max(temp, count);
        return temp;
        */

        //or

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                temp = max(temp, count); // added later
                //continue;
            }

           else count =0;
        }
        
        return temp;
    }
};