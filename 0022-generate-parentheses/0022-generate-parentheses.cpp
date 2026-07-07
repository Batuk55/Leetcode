class Solution {
public:

    void helper(string str, int open, int close, vector<string> &ans, int n){
        

        if(open == n && close == n){
            ans.push_back(str);
            return;
        }

        if(open < n){
            helper(str + "(", open+1, close, ans, n);
        }
        if(close<open){
            helper(str + ")", open, close+1, ans, n);
        }


    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";

        helper(str, 0, 0, ans, n);

        return ans;
    }
};