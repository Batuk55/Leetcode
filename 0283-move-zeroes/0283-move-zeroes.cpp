class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        int a = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if (nums[i]!=0)
            {
                swap(nums[i], nums[a]);
                a++;
            }
        }*/
        
        int i = 0;
        for(int j = 0; j<nums.size(); j++){
            if(nums[j]!=0){
                nums[i] = nums[j];
                i++;               
            }
        }
        for(int k = i; k < nums.size(); k++){
            nums[k] = 0;
        }
    }
};

/* ANOTHER APPROACH (SLIGHT WRONG)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if (nums[i]==0)
            {
                count ++;
                nums.erase(nums.begin()+i);
            }
        }
        nums.insert(nums.end(), count, 0);

    }
};*/