class Solution {
public:
    int beautySum(string s) {
        int n = s.size();

        int ans = 0;

        for(int i = 0; i < n ; i++){
            int freq[26] = {0};
            for(int j = i ; j < n ;j++){
                freq[s[j] - 'a']++;

                int max_freq = 0;
                int min_freq = INT_MAX;

                for(int k = 0 ; k < 26 ; k++){
                    if(freq[k] > 0){
                        max_freq = max(freq[k] , max_freq);
                        min_freq = min(freq[k] , min_freq);
                    }
                }
                ans = ans + (max_freq - min_freq);

            }

        }
        return ans;
        
    }
};