class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        map<char , int> mpp;
        for(int i = 0; i < n ; i++){
            mpp[s[i]]++;
        }

        set<pair<int , char>> sett;
        for(auto it : mpp){
            sett.insert({it.second , it.first}); //pairs are sorted automatically using lexicographical comparison
        }
        string str = "";
        for(auto it = sett.rbegin() ; it != sett.rend() ; it++){
            str += string(it->first , it->second);
        }
        return str;
    }
};