class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int size1 = nums1.size(), size2 = nums2.size();

        vector<int> arr;

        int i = 0, j = 0;
        int n = size1 + size2;

        while (i < size1 && j < size2) {
            // if (nums1[i] == nums2[j]) {
            //     arr.push_back(nums1[i++]);
            //     j++;
            // }
            // duplicates are preserved. i.e.
            // nums1 = [1,1,1,1,1,1,1,1,1,4,4]
            // nums2 = [1,3,4,4,4,4,4,4,4,4]  so the result is
            // [1,1,1,1,1,1,1,1,1,1,3,4,4,4,4,4,4,4,4,4,4] not [1,3,4]

            if (nums1[i] <= nums2[j]) { // else if (nums1[i] < nums2[j]) { (for
                                        // not preserving the duplicates)
                                        //  arr.push_back(nums1[i++]);
                arr.push_back(nums1[i++]);
            } else
                arr.push_back(nums2[j++]);

            if (arr.size() == (n / 2) + 1) {
                if (n % 2 == 1)//odd
                    return arr.back();
                else {//even
                    return (arr.back() + arr[arr.size() - 2]) / 2.0;
                }
            }
        }

        while (i < size1) {
            arr.push_back(nums1[i++]);
            if (arr.size() == (n / 2) + 1) {
                if (n % 2 == 1)//odd
                    return arr.back();
                else {//even
                    return (arr.back() + arr[arr.size() - 2]) / 2.0;
                }
            }
        }
        while (j < size2) {
            arr.push_back(nums2[j++]);
            if (arr.size() == (n / 2) + 1) {
                if (n % 2 == 1)//odd
                    return arr.back();
                else {//even
                    return (arr.back() + arr[arr.size() - 2]) / 2.0;
                }
            }
        }

        if (n % 2 == 1) {
            return (double)arr[n / 2];
        }
        return (double)((double)(arr[(n / 2) - 1] + (double)arr[(n / 2)]) /
                        2.0);
    }
};