class Solution {
  public:
    vector<string> neighbours(const string &code) {
        vector<string> res;
        for (int i = 0; i < 4; i++) {
            for (int j = -1; j <= 1; j += 2) {
                string s = code;
                s[i] = (code[i] - '0' + j + 10) % 10 + '0';
                res.push_back(s);
            }
        }
        return res;
    }

    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> um(deadends.begin(), deadends.end());
        if (um.count("0000")) return -1;

        queue<string> q({"0000"});
        for (int cnt = 0; !q.empty(); ++cnt) {
            for (int i = q.size(); i > 0; --i) {
                string s = q.front();
                q.pop();
                if (s == target) return cnt;

                for (string &s : neighbours(s)) {
                    if (um.count(s)) continue;
                    um.insert(s);
                    q.push(s);
                }
            }
        }
        return -1;
    }
};
