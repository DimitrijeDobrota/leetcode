class Solution {
  public:
    string simplifyPath(string path) {
        deque<string> dq;
        int start = 0;

        path.push_back('/');
        for (int i = 0; i < path.size(); i++) {
            if (path[i] != '/')
                continue;
            else {
                string s = path.substr(start, i - start);
                if (s == "..") {
                    if (!dq.empty()) dq.pop_back();
                } else if (!s.empty() && s != ".")
                    dq.push_back(s);
                start = i + 1;
            }
        }

        string res = "";
        while (!dq.empty()) {
            res += "/" + dq.front();
            dq.pop_front();
        }
        return res.empty() ? "/" : res;
    }
};
