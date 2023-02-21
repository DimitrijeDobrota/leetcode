class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int aster : asteroids) {
            while (!st.empty() && st.back() > 0 && st.back() < -aster) st.pop_back();
            if (st.empty() || aster > 0 || st.back() < 0) st.push_back(aster);
            else if (aster < 0 && st.back() == -aster) st.pop_back();
        }
        return st;
    }
};
