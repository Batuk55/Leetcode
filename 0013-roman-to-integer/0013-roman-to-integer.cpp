class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> mpp;
        mpp = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
               {'C', 100}, {'D', 500}, {'M', 1000}};

        int sum = mpp[s[s.size() - 1]];
        for (int i = 0; i < s.size() - 1; i++) {
            if (mpp[s[i]] < mpp[s[i + 1]]) {
                // subtract
                sum = sum - mpp[s[i]];
            } else {
                // add
                sum = sum + mpp[s[i]];
            }
        }
        // sum = sum + mpp[s[s.size() - 1]];
        return sum;
    }
};