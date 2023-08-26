class Solution {
    bool valid(const string &s) {
        if (s.empty()) return true;
        return stoi(s) >= 0 && stoi(s) <= 255;
    }

  public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();

        vector<string> res;
        string s1, s2, s3, s4;
        bool e4;

        s1 = "";
        for (int i = 0; i < n; i++) {
            s1 += s[i], s2 = "";
            if (!valid(s1)) break;
            for (int j = i + 1; j < n; j++) {
                s2 += s[j], s3 = "";
                if (!valid(s2)) break;
                for (int k = j + 1; k < n; k++) {
                    s3 += s[k], s4 = "";
                    if (!valid(s3)) break;
                    for (int l = k + 1; l < n; l++) {
                        s4 += s[l], e4 = false;
                        if (!valid(s4) || (s4.size() >= 2 && s4.front() == '0')) {
                            e4 = true;
                            break;
                        }
                    }
                    if (!e4 && !s4.empty()) res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                    if (s3.front() == '0') break;
                }
                if (s2.front() == '0') break;
            }
            if (s1.front() == '0') break;
        }
        return res;
    }
};
