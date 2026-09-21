class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0, high = letters.size()-1;

        while(low<= high){
            int mid = low + (high - low) / 2;

            if(letters[mid] > target) high = mid-1;
            else low = mid+1;

        }
        if(low>= letters.size()) return letters[0];
        return letters[low];
    }
};