class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int Maxlength = 0;

        vector<int> hash(256,-1);// it will store the occured index of that element.
        int l=0, r=0;

        while(r<n){
            if(hash[s[r]]!= -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }
            int len = r-l+1;
            Maxlength = max(len, Maxlength);
            
            hash[s[r]] = r;
            r++;
        }
        return Maxlength;
    }
};