class Solution {
public:
    int findMin(vector<int>& nums) {
        /*// to find minimum by search in sorted array method (LC-33)
                int low = 0, high = nums.size() - 1;
                int mini = nums[high];

                while (high >= low) {
                    int mid = low + (high - low) / 2;

                    if (nums[low] < nums[mid]) {

                        if (nums[low] <= mini && mini <= nums[mid]) {
                            mini = nums[low];
                            high = mid - 1;
                        }

                        else {
                            low = mid + 1;
                        }
                    }

                    else {
                        if (nums[mid] <= mini && mini <= nums[high]) {
                            mini = nums[mid];
                            low = mid + 1;
                        }

                        else {
                            high = mid - 1;
                        }
                    }
                }
                return mini;
                */

        int low = 0, high = nums.size() - 1;
        int mini = INT_MAX;

        while (high >= low) {

            if (nums[high] >= nums[low]) { // already sorted
                mini = min(mini,nums[low]);
                
            }
            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid]) { /* left is sorted , that equal sign is
                                             very important to handle only
                                             single element in array*/
                mini = min(mini, nums[low]);
                low = mid +
                      1; // eliminate the left half after haveing the min value

            } else { // right is sorted
                mini = min(mini, nums[mid]);
                high =
                    mid -
                    1; // eliminate the right half after haveing the min value
            }
        }
        return mini;
    }
};