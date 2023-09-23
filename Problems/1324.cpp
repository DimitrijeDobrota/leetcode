class Solution {
  public:
    vector<string> printVertically(const string &s) {
        vector<string> vec, res;

        string tmp, buf;
        stringstream ss(s);
        while (ss >> tmp)
            vec.push_back(tmp);

        for (int i = 0; true; i++) {
            tmp.clear(), buf.clear();
            for (const string &s : vec) {
                if (s.size() <= i)
                    buf += " ";
                else
                    tmp += buf + s[i], buf.clear();
            }
            if (!tmp.size()) break;
            res.push_back(tmp);
        }
        return res;
    }
};
