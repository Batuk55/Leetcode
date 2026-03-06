class Solution {
public:
    /*
    static bool comp(int i1, int i2){
    //    if(i1 <= i2){
    //         return true;
    //     }
    //     else return false;
        return i1 <= i2;
    }
    */
    void sortColors(vector<int>& nums) {
        // Brute
        // sort(nums.begin(), nums.end()); O(n logn)
        // sort(nums.begin(), nums.end() , comp);

        /* Better --> hash array
        int hash[3] = {0};
        for(int i = 0; i< nums.size() ; i++){
         hash[nums[i]]++;
        }

 int j = 0;
        for(int i =0; i< hash[0]; i++){
         nums[j++] = 0;
        }

         for(int i =0; i< hash[1]; i++){
         nums[j++] = 1;
        }

         for(int i =0; i< hash[2]; i++){
         nums[j++] = 2;
        }
 */
        // optimal --> dutch national flag algo
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        // for (int i = 0; i < n; i++) {
        //     // or use while
        //     if (mid > high)
        //         return;
            while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid++], nums[low++]);
            } else if (nums[mid] == 1)
                mid++;
            else if (nums[mid] == 2) {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};