class Solution {
  public:
    string entityParser(const string &text) const {
        unordered_map<string, char> um = {{"&quot;", '"'}, {"&apos;", '\''}, {"&amp;", '&'},
                                          {"&gt;", '>'},   {"&lt;", '<'},    {"&frasl;", '/'}};

        string res, crnt;
        for (const char c : text) {
            if (crnt.empty()) {
                if (c != '&')
                    res += c;
                else
                    crnt = "&";
            } else {
                if (c == '&') {
                    res += crnt;
                    crnt = "&";
                } else {
                    crnt += c;
                    if (c == ';') {
                        if (um.count(crnt))
                            res += um[crnt];
                        else
                            res += crnt;
                        crnt.clear();
                    }
                }
            }
        }

        return res + crnt;
    }
};
