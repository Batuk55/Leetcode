class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mpp;
        for (int i = 0; i< s.size(); i++) {
            mpp[s[i]]++;
        }
        map<char, int> mapp;
        for (int i = 0; i < t.size(); i++) {
            mapp[t[i]]++;
        }
if (s.size() == t.size()){
return mpp==mapp;
}
return false;
    }
};