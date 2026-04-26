#include <string>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int furthestDistanceFromOrigin(std::string moves) {
        int countL = 0;
        int countR = 0;
        int countUnderline = 0;
        
        // Count the occurrences of 'L', 'R', and '_'
        for (char c : moves) {
            if (c == 'L') {
                countL++;
            } else if (c == 'R') {
                countR++;
            } else {
                countUnderline++;
            }
        }
        
        // To maximize distance, treat all '_' as the direction 
        // that is already furthest from the origin.
        // The distance is |countL - countR| + countUnderline
        return std::abs(countL - countR) + countUnderline;
    }
};
