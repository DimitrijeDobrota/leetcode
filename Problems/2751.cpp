class Solution {
  public:
    vector<int> survivedRobotsHealths(const vector<int> &positions, vector<int> &healths,
                                      const string &directions) const {
        static int indexes[100001];
        const int n = size(positions);
        vector<int> res;
        stack<int> st;

        iota(indexes, indexes + n, 0);
        sort(indexes, indexes + n, [&](int a, int b) { return positions[a] < positions[b]; });

        for (const int idx : std::span(indexes, n)) {
            if (directions[idx] == 'R') {
                st.push(idx);
                continue;
            }

            int &health = healths[idx];
            while (!st.empty() && health > 0) {
                int &top = healths[st.top()];
                if (health == top)
                    top = health = 0, st.pop();
                else if (health > top)
                    health--, top = 0, st.pop();
                else
                    top--, health = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            if (healths[i] == 0) continue;
            res.push_back(healths[i]);
        }

        return res;
    }
};
