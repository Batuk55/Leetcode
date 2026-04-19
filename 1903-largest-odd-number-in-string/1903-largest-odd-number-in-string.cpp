class Solution {
public:
    string largestOddNumber(string num) {

        int last = num.size() - 1;
        while (last >= 0) {
            // int number = stoi(num[last]);
            int number = num[last] - '0'; // do this instead
            if (number % 2 == 1) {
                return num.substr(0, last + 1);
            } else last--;
        }
        return "";
    }
};

/* // out of bounds condition, becouse in constraints size is too high
long long number = stoll(num);
        while(number > 0){
            if(number % 2 == 1){
                string str = to_string(number);
                return str;
            }
            number /= 10;
        }
        return "";
        */