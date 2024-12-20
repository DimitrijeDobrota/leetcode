class Solution {
  public:
    vector<int> canSeePersonsCount(const vector<int> &heights) const {
        const int n = size(heights);
        vector<int> res(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            const int h = heights[i];
            int run = 0;

            while (!st.empty() && h >= st.top()) {
                st.pop();
                run++;
            }

            res[i] = run + !st.empty();
            st.push(h);
        }

        return res;
    }
};
