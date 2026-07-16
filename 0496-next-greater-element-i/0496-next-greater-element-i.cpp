class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map <int, int> mpp;
        int a = 0;

        int j = 0;
        while(j< nums2.size()-1){
            int k = j+1;
            while(k< nums2.size() && nums2[j] > nums2[k]){
                k++;
            }
            if(k<nums2.size()) a = nums2[k];
            else a = -1;

            mpp[nums2[j]] = a;
            j++;
        }
        mpp[nums2[j]] = -1;

        for(int i = 0; i<nums1.size(); i++){
            // auto it = mpp.find(nums1[i]);

            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};