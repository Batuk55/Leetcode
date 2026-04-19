class Solution {
public:
    string common_till_i(string& common, string& common_in_pair) {
        string temp_common = "";
        int size = min(common.size(), common_in_pair.size());

        for (int i = 0; i < size; i++) {
            if (common[i] == common_in_pair[i])
                temp_common += common[i];
            else
                break;
        }
        return temp_common;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 1)
            return strs[0];

        string common = "";

        string word0 = strs[0], word1 = strs[1];

        int size01 = min(word0.size(), word1.size());
        for (int i = 0; i < size01; i++) {
            if (word0[i] == word1[i])
                common += word0[i];
            else
                break;
        }

        // int i = 1;
        for (int i = 1; i < n - 1; i++) {
            string common_in_pair = "";
            string word = strs[i], next_word = strs[i + 1];
            int size = min(word.size(), next_word.size());

            for (int j = 0; j < size; j++) {
                if (word[j] == next_word[j])
                    common_in_pair += word[j];

                else
                    break;
            }
            common = common_till_i(common, common_in_pair);
        }
        return common;
    }
};

/*
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        // int arr[26] = {0}; //vector<int> arr(26, 0);

        int i = 0;
        string common = "";

        while (i < n - 1) {
            string common_in_pair = "";
            string word = strs[i];
            string next_word = strs[i + 1];

            int size = min(word.size(), next_word.size());

            for (int j = 0; j < size; j++) {
                if (word[j] == next_word[j]) {
                    common_in_pair += word[j];
                } else {
                    i++;
                    continue;
                }
            }
            common = common_in_pair;
        }
    }
};
*/