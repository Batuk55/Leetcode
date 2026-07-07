class Solution {
public:
    void helper(string str, int last, vector<string> &ans , int n){
            if(str.size() == n){
                ans.push_back(str);
                return;
            }
            helper(str+'1', 1, ans, n); //add'0' (left)
            if(last == 1){
                helper(str+'0', 0, ans, n);  //add'1' (right)
            }

        }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string str = "";
        int last = 1;
        helper(str, last, ans , n);      

        return ans;
    }
};