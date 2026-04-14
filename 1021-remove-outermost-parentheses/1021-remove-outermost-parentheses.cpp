class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count = 0;

        for (char c : s) {
            // if (count == 0)
            //     continue;
            if (c == '(') {
                if(count > 0) ans.push_back(c);
                count++;
            } else {
                count--;
                if(count > 0) ans.push_back(c);
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    string removeOuterParentheses(string s) {
        int size = s.length();
        stack<char> st;
        int count = 0;
        st.push(s[0]);
        for(int i = 1; i < size ; i++){
            if(s[i] == st.top()) st.pop(); //or continue()
            // if(s[i] == ')' &&  st.top() == ')') st.pop();
            // if(s[i] == '(' &&  st.top() == '(') st.pop();
            st.push(s[i]);

        }

    }
};*/