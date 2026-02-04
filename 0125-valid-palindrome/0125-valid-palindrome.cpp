class Solution {
public:
    bool isPalindrome(string s) {
        vector <char> t;
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                t.push_back(tolower(s[i]));
            }
        }
        int i = 0, len = t.size();

        while (i < len / 2) {
            if (t[i] != t[len - 1 - i])
                return false;
            i++;
        }
        return true;
    }
};