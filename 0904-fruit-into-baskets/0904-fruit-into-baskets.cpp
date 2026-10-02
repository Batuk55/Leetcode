class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp; //{type, freq}
        int maxFruits = 0;
        int l = 0, r = 0;
        while(r<fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0)mpp.erase(fruits[l]);
                l++;
            }
            if(mpp.size()<= 2){
                maxFruits = max(maxFruits, r-l+1);
            }
            r++;
        }
        return maxFruits;
    }
};