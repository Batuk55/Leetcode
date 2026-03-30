class Solution {
public:
    bool checkStrings(string s1, string s2) {

        unordered_map<char , int> s1odd , s1even;
        unordered_map<char , int> s2odd , s2even;

        int i = 0, j = 1;
        while (i < s1.size() || j < s1.size()) {
            s1even[s1[i]]++;
            s2even[s2[i]]++;
            i += 2;

            s1odd[s1[j]]++;
            s2odd[s2[j]]++;
            j += 2;
        }

        if (s1even == s2even && s1odd == s2odd) {
            return true;
        }
        return false;
    }
};