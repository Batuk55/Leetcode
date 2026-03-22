class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        // O(log n) solution
        int n = nums.size();
        int low = 0, high = n - 1;

        int first = -1;
        while (high >= low) { // for first occurance
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            }

            if (target < nums[mid])
                high = mid - 1;
            else if (target > nums[mid])
                low = mid + 1;
        }

        if(first == -1){
            return {-1,-1};
        }

        low = 0, high = n - 1;

        int last = -1;
        while (high >= low) { // for last occurance
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            if (target < nums[mid]) {
                high = mid - 1;
            } else if (target > nums[mid])
                low = mid + 1;
        }
        return {first, last};
    }
};

/* O(n) solution 1
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
*/

/* // O(n) solution 2

        int n = nums.size();
        int first = -1, last = -1;

        int i = 0;
        while( i< n){
            if(nums[i]==target){
                first = i;
                 break;
                 }
            i++;
        }

        int j = n-1;
        while( j >= 0){
            if(nums[j] == target){
                last = j;
                break;
            }
            j--;
        }

        // if(i == n || j == -1){
        //     return {-1,-1};
        // }

        return {first , last};
        */