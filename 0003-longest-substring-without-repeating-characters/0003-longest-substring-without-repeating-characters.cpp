class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int Maxlength = 0;

        char hash[256] = {-1};
        int l=0, r=0;
        unordered_map<char, int> mpp;


        // int len = 0;
        while(r<n){

            while(mpp.find(s[r]) != mpp.end()){
                mpp.erase(s[l]);
                // len--;
                l++;
            }
            mpp[s[r]] = r;
            // len++;
            int len = r-l+1;
            Maxlength = max(len, Maxlength);
            r++;

        }
        return Maxlength;
    }
};