class Solution {
public:
    long long totalHours(vector<int>& piles, int speed) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed; // ceil
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (totalHours(piles, mid) <= h) {
                ans = mid;
                high = mid - 1;   // try smaller speed
            } else {
                low = mid + 1;    // need faster speed
            }
        }

        return ans;
    }
};