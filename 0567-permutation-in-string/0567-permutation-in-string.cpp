class Solution {
public:
    bool isfreqsame(int freq1[] , int freq_window[]){//O(1)
        for(int i = 0 ; i< 26 ; i++ ){
            if(freq1[i] != freq_window[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        int freq1[26] = {0};
        // or vector<char> freq2(26,0);

        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
        }

        // to compare the window
        int wind_size = s1.length();
        for (int i = 0; i < s2.length(); i++) {
            int freq_window[26] = {0};
            int winIdx = 0, idx = i;

            while (winIdx < wind_size && idx < s2.length()) {
                freq_window[s2[idx] - 'a']++;
                idx++; winIdx++;
            }
            if(isfreqsame(freq1 , freq_window)){
                return true;
            }

        }
        return false;
    }
};
/*
 //check all the permutations
        //for each permutation search in the s2 if that exist or not

        int n = s1.size();
        // int index = -1;
        string np = s1;
        while(){
        for(int i = n-2 ; i>= 0 ; i--){
            if(s1[i] < s1[i+1]){
                index = i;
                break;
            }
        }
        // if(index == -1){
        //     reverse(s1.begin() , s1.end());
        //     np = s1;
        // }

        for(int i = n-1 ; i > index ; i--){
            if(s1[i] > s1[index]){
                swap(s1[index], s1[i]);
                break;
            }
        }
        reverse(s1.begin() + index + 1 , s1.end());
        np = s1;

        if(s2.find(np) < s2.size()) return true;
        }
        return false;

*/