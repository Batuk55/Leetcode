class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> mapS, mapT;
        for (int i = 0; i < s.size(); i++) {
            mapS[s[i]]++;
            mapT[t[i]]++;
        }
        return (mapS == mapT);
        // if(mapS == mapT) return true;
        // return false;
    }
};
/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(t.begin(), t.end());
        sort(s.begin(), s.end());
        return s==t;
    }
};
/*
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
/
//or
*/