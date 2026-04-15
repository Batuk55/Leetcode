class Solution {
public:
    string removeOccurrences(string s, string part) {
        // while (s.find(part) != string::npos) {
        // string::npos means if the part is not found
        while (s.find(part) < s.length())
            s.erase(s.find(part), part.size());
        return s;
    }
};