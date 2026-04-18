class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        if (n == 1)
            return 1;
        vector<char> compr;

        int count = 1;

        for (int i = 1; i <= n; i++) {
            if (i<n && chars[i] == chars[i - 1]) {
                count++;
            } else {
                compr.push_back(chars[i - 1]);
	
                // if (count > 1 && count < 10)
                //     compr.push_back(count);
                // if (count >= 10) {
                //     vector<int> num;
                //     while (count > 0) {
                //         int temp = count;
                //         int a = temp % 10;
                //         num.push_back(a);
                //         temp /= 10;
                //     }
                //     reverse(num.begin(), num.end());
                //     compr.insert(compr.end(), num.begin(), num.end());
                // }

                //use this way instead
                if(count > 1){
                    string cnt = to_string(count);
                    for(char c : cnt){
                        compr.push_back(c);
                    }
                }
                count = 1;
            }
        }
        chars = compr;
        return chars.size();
    }
};