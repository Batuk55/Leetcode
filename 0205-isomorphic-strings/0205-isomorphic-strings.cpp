class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size(), n = t.size();
        if (m != n)
            return false;

        unordered_map<char, char> char_map;

        for (int i = 0; i < m; i++) {
            char original = s[i];
            char replacement = t[i];

            if (char_map.find(original) == char_map.end()) {

                bool value_exists = false; // replacement_exists
                for (auto& it : char_map) {
                    if (it.second == replacement) {
                        value_exists = true;
                        break;
                    }
                }

                if (!value_exists) { // same as --> if (valueExists == false)
                    char_map[original] = replacement;
                } else
                    return false;
            } else {
                // char mapped_char = char_map[original];

                // if (mapped_char != replacement)
                if (char_map[original] != replacement)
                    return false;
            }
        }
        return true;
    }
};