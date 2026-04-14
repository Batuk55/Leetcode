class Solution {
public:
    string removeOccurrences(string s, string part) {


    //    for(int i = 0 ; i < s.size() - t.size() + 1){
    //     if()
    //    }
    while(s.find(part) != string::npos){ 
        //string::npos means if the part is not found
        s.erase(s.find(part) , part.size());
    }
        return s;
    }
};