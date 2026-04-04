class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int low = 0 , high = arr.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            if(missing < k){
                low = mid + 1;
            }
            else high = mid - 1;            
        }
        return high + 1 + k;// more = k -missing ,, missing = arr[high] - (high + 1);
        //after solving the above equation it becomes high + 1+ k; 

    }
};

/*

        // if(arr.front() == 1 && arr.back() == arr.size()){ //arr,front() ==
        // arr[0];
        //     return arr.back() + k;
        // }

        int missing = 0;
        int j = 0;
        for (int i = 1; i <= arr.back() + k; i++) {
            // arr[arr.size() - 1] or arr.back();
            // if(j < arr.size() && i != arr[j]){
            //     missing++;
            //     if(missing == k) return i;
            // }
            // else j++;
            if (j < arr.size() && i == arr[j]) {
                j++;
            } else {
                missing++;
                if (missing == k)
                    return i;
            }
        }

        return -1;
        */