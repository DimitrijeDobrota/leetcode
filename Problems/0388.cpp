class Solution {
  public:
    int lengthLongestPath(const string &input) const {
        const int n = size(input);
        stack<pair<int, int>> st;
        int res = 0;

        st.emplace(0, 0);
        for (int i = 0, dir_len = 0; i < n;) {
            if (input[i] == '\n') {
                int cnt = 0;
                while (++i < n && input[i] == '\t')
                    cnt++;

                while (cnt < st.top().first)
                    st.pop();
                if (cnt > st.top().first) st.emplace(cnt, st.top().second + dir_len + 1);
            } else {
                int cnt = 0, is_file = 0;

                while (i < n && input[i] != '\n') {
                    if (input[i] == '.') is_file = true;
                    i++, cnt++;
                }

                if (is_file)
                    res = max(res, st.top().second + cnt);
                else
                    dir_len = cnt;
            }
        }

        return res;
    }
};
