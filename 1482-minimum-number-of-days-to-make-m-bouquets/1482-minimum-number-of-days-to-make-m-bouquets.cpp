class Solution {
public:
    int fn(vector<int> bloomDay, int mid, int k) {
        int no_of_flowers = 0, no_of_bouquet = 0;
        for (int bloom : bloomDay) {
            if (bloom <= mid) { // mid --> day
                no_of_flowers++;
            } else {
                no_of_bouquet += no_of_flowers / k;
                no_of_flowers = 0;
            }
        }
        no_of_bouquet += no_of_flowers / k;
        return no_of_bouquet;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((1LL * m * k) > bloomDay.size())
            return -1;

        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        int day = 1;
        while (low <= high) {

            int mid = low + (high - low) / 2;

            int total_days = fn(bloomDay, mid, k);

            if (total_days >= m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
/*
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((1LL * m * k) > bloomDay.size())
            return -1;

        // int low = 1 , high = *max_element(bloomDay.begin() , bloomDay.end());

        int day = 1;

        while (true) {

            int no_of_bouquets = 0;
            int no_of_flowers = 0;
            // there should be adjecent elements. indices must be continuous
            for (int bloom : bloomDay) {
                if (bloom <= day) {
                    no_of_flowers++;
                }
                // bloom > day
                // that flower has not bloomed yet.
                // So the consecutive streak breaks here.
                // That means:
                // whatever streak we had before this point is finished
                // Now we must calculate:
                // how many bouquets can be formed from that streak?
                else {
                    no_of_bouquets += no_of_flowers / k;
                    no_of_flowers = 0;
                }
            }
            no_of_bouquets += no_of_flowers / k;


            if (no_of_bouquets >= m)
                return day;
            day++;
        }

        return 0;
    }
};
*/