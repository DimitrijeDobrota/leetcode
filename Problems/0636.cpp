class Solution {
  public:
    vector<int> exclusiveTime(int n, const vector<string> &logs) {
        stack<pair<int, int>> st;
        vector<int> res(n, 0);
        int time, id;
        char op[6];

        for (const string &log : logs) {
            sscanf(log.c_str(), "%d:%[^:]:%d", &id, op, &time);
            if (!strcmp(op, "start"))
                st.push({id, time});
            else {
                const int added = time - st.top().second + 1;
                res[id] += added;
                st.pop();

                if (!st.empty()) res[st.top().first] -= added;
            }
        }
        return res;
    }
};
