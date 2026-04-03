class Solution {
public:
    long long total_sum(vector<int> nums, int divisor) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + divisor - 1) / divisor; // ceil(num/divisor)
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1, high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long sum = total_sum(nums, mid);

            if (sum <= threshold) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};

// ceil value = (nums[i] + k - 1) / k

/*
 if (nums.size() > threshold)
            return -1;


        int divisor = 1;
        while (true) {
            long long sum = total_sum(nums, divisor);

            if (sum <= threshold)
                return divisor;

            if (sum > threshold) {
                divisor++;
            }
        }
        return divisor;
*/