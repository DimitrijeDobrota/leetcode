class Solution {
  public:
    vector<string> removeComments(vector<string> &source) {
        vector<string> res = {""};
        bool block = false;

        for (const auto &l : source) {
            int j = 0, i;

            for (i = 0; i < size(l); i++) {
                if (!block && l[i] == '/' && l[i + 1] == '/')
                    break;
                else if (!block && l[i] == '/' && l[i + 1] == '*') {
                    if (i != j) res.back() += l.substr(j, i - j);

                    i++; // prevent /*/ as close
                    block = true;
                } else if (block && l[i] == '*' && l[i + 1] == '/') {
                    j = i + 2;
                    i++; // prevent */* as open
                    block = false;
                }
            }

            if (!block && i != j) res.back() += l.substr(j, i - j);
            if (!block && !res.back().empty()) res.push_back("");
        }

        if (res.back().empty()) res.pop_back();
        return res;
    }
};
