class Solution {
public:
    bool isPalindrome(string &s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--]) return false;
        }
        return true;

    }
    void helper(vector<vector<string>> &ans, string &s, vector<string> &result, int idx){
        if(idx == s.size()){
            ans.push_back(result);
            return;
        }


        for(int i = idx; i< s.size(); i++){
            if(isPalindrome(s, idx, i)){
                result.push_back(s.substr(idx, i-idx+1));
                helper(ans, s, result, i+1);
                result.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> result;

        helper(ans, s, result, 0);

        return ans;        
    }
};