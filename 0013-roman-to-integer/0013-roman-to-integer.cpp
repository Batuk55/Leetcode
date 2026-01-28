class Solution {
public:
    int romanToInt(string s) {
      unordered_map<char, int> val = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int sum= 0;
        for(int i= 0; i <s.size()-1; i++){
            if(val[s[i]]< val[s[i+1]]){
            sum = sum - val[s[i]];}
        else {
            sum = sum+val[s[i]];
        }
        }  
        //adding last character
        sum = sum + val[s[s.size()-1]];
        return sum;

    }
};

/*class Solution {
public:
    int romanToInt(string s) {
        int I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000;
        int sum = 0;
        for (int i = 0; i < s.size()-1; i++)
            if (s[i] < s[i + 1]) {
                // subtract
                sum = sum - s[i];
            } else {
                //add
                sum = sum + s[i];
            }
    return sum;}
};*/