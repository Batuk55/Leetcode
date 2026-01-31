class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /* int n = strs.size();
         int m = strs[0].size();*/

        map<map<char, int>, vector<string>> mpp;

        for (int i = 0; i < strs.size(); i++) {
            map<char, int> frequency;
            for (int j = 0; j < strs[i].size(); j++) {
                frequency[strs[i][j]]++;
            }
            mpp[frequency].push_back(strs[i]);
            //  sort(mpp2[mpp[strs[i]]].begin(),mpp2[mpp[strs[i]]].end());
        }
        vector<vector<string>> result;
        for (map<map<char, int>, vector<string>>::iterator it = mpp.begin();
             it != mpp.end(); it++) {
            result.push_back(it->second);
        }
        /*or
        for (auto &it : mpp) {
            result.push_back(it.second);
        }*/
        return result;
    }
};