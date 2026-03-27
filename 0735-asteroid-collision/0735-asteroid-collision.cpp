class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        stack<int> st;
        // st.push(a);
        for (int a : asteroids) {

            bool currentdestroyed = false;
            while (!st.empty() && a < 0 && st.top() > 0) { // means they will
                                                           // colloid
                if (abs(a) > abs(st.top())) {
                    st.pop();
                } else if (abs(a) == abs(st.top())) {
                    st.pop();
                    currentdestroyed = true;
                    break;
                } else {
                    currentdestroyed = true;
                    break;
                }
            }
            if (currentdestroyed == false)
                st.push(a);
        }
        asteroids.clear();
        while (!st.empty()) {
            asteroids.push_back(st.top());
            st.pop();
        }
        reverse(asteroids.begin(), asteroids.end());
        return asteroids;
    }
};