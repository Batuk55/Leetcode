class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";

        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++) {
            string word = "";

            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if (word.length() > 0) {
                // ans.push_back(word); //push_back() only accepts a single
                // character (char)
                ans += word + ' ';
            }
        }
        ans.erase(ans.end() - 1);
        return ans;
    }
};