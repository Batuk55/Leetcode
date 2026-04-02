class Solution {
public:
    long long total_hours(vector<int>& piles, int k) {
        long long hoursum = 0;
        for (int pile : piles) {
            hoursum += (pile + k - 1) / k;
        }
        return hoursum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1, high = *max_element(piles.begin(), piles.end());
        // int k = INT_MAX; // or k = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = total_hours(piles , mid);
            if(hours <= h){
                // k = mid;
                high = mid - 1;
            }
            else if(hours > h){
                low = mid + 1;
            }
        }
        return low;
    }
};
/*
class Solution {
public:
    long long total_hours(vector<int>& piles, int k) {
        long long hoursum = 0;
        for (int pile : piles) {
            hoursum += (pile + k - 1) / k;
        }
        return hoursum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int k = 1;
        while (true) {

            long long hoursum = total_hours(piles, k);
            // for (int pile : piles) {
            //     hoursum += (pile + k - 1) / k;
            // }

            if (hoursum <= h)
                return k;
            k++;
        }
        return 0;
    }
};
*/