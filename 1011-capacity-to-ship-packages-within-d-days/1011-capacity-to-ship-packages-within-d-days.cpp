class Solution {
public:
    long long total_days(vector<int> weights, int temp_weight) {
        int sum = 0;
        int no_of_days = 1;

        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] <= temp_weight) {
                sum += weights[i];
            } else {
                no_of_days++;
                // sum = 0;
                sum = weights[i];
                // i--;
            }
        }
        return no_of_days;
    }
    long long sum_of_all_weights(vector<int> weights) {
        long long sum = 0;
        for (int weight : weights) {
            sum += weight;
        }
        return sum;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        long long high = sum_of_all_weights(weights);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int no_of_days = total_days(weights, mid);
            if (no_of_days <= days) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};
/*
        int temp_weight = *max_element(weights.begin() , weights.end());

        while (true){
            long long no_of_days = total_days(weights , temp_weight);
            if(no_of_days <= days){
                return temp_weight;
                }
            // if( no_of_days > days){
            temp_weight ++;
            // }
        }
        return -1;*/