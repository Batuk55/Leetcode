class Solution {
public:
    static bool comp(pair<int, int>& P1, pair<int, int>& P2) {
        if (P1.second > P2.second) {
            return true;
        }
        return false;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        /* or
         map<int,int> mpp;
        for (int i : nums) {
            mpp[i]++;
        }*/

        // converting the map of frequencies to pairs for further sorting
        // according to frequencies.
        vector<pair<int, int>> vec(mpp.begin(), mpp.end());
        sort(vec.begin(), vec.end(), comp);
        // or
        /*sort(v.begin(), v.end(), [](auto &a, auto &b) {
                return a.second > b.second;
            });*/
        vector<int> result;
        while (k > 0) {
            result.push_back(vec[k - 1].first);
            k--;
        }

        return result;
    }
};