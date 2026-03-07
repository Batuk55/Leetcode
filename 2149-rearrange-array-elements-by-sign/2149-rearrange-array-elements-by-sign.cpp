class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        /*
        //brute
 int n = nums.size();

            vector<int> pos;
            vector <int> neg;


            for(int i = 0; i < n ; i++){
                if(nums[i] > 0){
                    pos.push_back(nums[i]);
                }
                else neg.push_back(nums[i]);
            }
            int j = 0;
            for(int i =0; i< n ; i+=2){
                nums[i] = pos[j];
                nums[i+1] = neg[j];
                j++;

            }
        return nums;
        //*/
        
///*
//optimal
        int p =0, n = 1;
        vector<int> arr(nums.size());
        
        for(int i =0; i< nums.size() ; i++){
            if(nums[i]>0){
                arr[p] = nums[i];
                p+=2;
            }
            else {
                arr[n] = nums[i];
                n+=2;
            }
        }
        // nums = arr;
        // return nums;
        return arr;
//*/


        //when freq of neg and pos differs.
        /*
 int n = nums.size();

            vector<int> pos;
            vector <int> neg;


            for(int i = 0; i < n ; i++){
                if(nums[i] > 0){
                    pos.push_back(nums[i]);
                }
                else neg.push_back(nums[i]);
            }

            int psize = pos.size(), nsize = neg.size();
            
            int i = 0;
            int j = 0;
            
            vector<int> ans;

            //for(int i =0; i< n ; i+=2){

                while(i<pos.size() && j < neg.size()){
                //if(pos[j]!= pos.end()){
                    ans.push_back(pos[i++]);
                    ans.push_back(neg[j++]);
                    }

            
            while (i< psize){
                ans.push_back(pos[i++]);
            }

            while(j< nsize){
                ans.push_back(neg[j++]);
            }
        return ans;
        */
    }
};