class Solution {
public:
    void helper(vector<string> &ans, string &digits, const string mapping[], string &result, int idx){//Add const as const string mapping[] to guarantee the function won't accidentally modify your map (optional)

        if(idx == digits.size()){
            ans.push_back(result);
            return;
        }
        int number = digits[idx] - '0';
        string char_at_number = mapping[number];

        for(int i = 0; i<char_at_number.size(); i++){
            result.push_back(char_at_number[i]);
            helper(ans, digits, mapping, result, idx + 1);
            result.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;

        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string result = "";

        helper(ans, digits, mapping, result, 0);
        return ans;    
    }
};