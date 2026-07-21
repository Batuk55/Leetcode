class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();

        int lsum = 0, rsum = 0, MaxSum = 0;

        for(int l = 0; l< k; l++){
            lsum+= cardPoints[l];
            MaxSum = lsum;
        }
        int r = n-1;
        for(int i = k-1; i>=0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[r--];

            MaxSum = max(MaxSum, lsum + rsum);
        }

        return MaxSum;
    }
};