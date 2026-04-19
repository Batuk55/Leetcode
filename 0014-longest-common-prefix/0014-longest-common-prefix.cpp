class Solution {
public:
    string common_till_i(string& common, string& common_in_pair) { //(string& common, do this instead --> next element)
        // string temp_common = "";
        int size = min(common.size(), common_in_pair.size());

        // for (int i = 0; i < size; i++) {
        //     if (common[i] == common_in_pair[i])
        //         temp_common += common[i];
        //     else
        //         break;
        // }
        // return temp_common;

        int i = 0;// can do this to save the space
        while(i < size && common[i] == common_in_pair[i]){ //shrink in place, kyuki new common previous common se kam hi hoga
            i++;
        }
        common.resize(i);
        return common;
    }

    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 1)
            return strs[0];

        // string common = "";

        // string word0 = strs[0], word1 = strs[1];
        // int size01 = min(word0.size(), word1.size());
        // for (int i = 0; i < size01; i++) {
        //     if (word0[i] == word1[i])
        //         common += word0[i];
        //     else
        //         break;
        // }
        string common = common_till_i(strs[0] , strs[1]);

        for (int i = 2; i < n ; i++) {
            common = common_till_i(common , strs[i]);
            if(common.empty()) return ""; // to avoid unnecessary iterations
        }
        return common;
    }
};
