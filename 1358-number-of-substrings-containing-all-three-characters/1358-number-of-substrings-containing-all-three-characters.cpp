class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int>last_seen(3,-1);
        int cnt = 0;

        for(int i = 0; i<n; i++){
            last_seen[s[i]-'a'] = i;

            if(last_seen[0] != -1 && last_seen[1] != -1 && last_seen[2] != -1){

                int min_idx = *min_element(last_seen.begin(), last_seen.end());
                cnt += (1 + min_idx);
            }

        }
        return cnt;
    }
};