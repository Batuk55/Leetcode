class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

/*
    class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                count++;
                nums.erase(nums.begin() + i);
            }
            nums.insert(nums.end(), _);

            
        }
                for (int i = 0; i < nums.size(); i++) {
                cout << nums[i];
                }
        return count;
    }};
    */