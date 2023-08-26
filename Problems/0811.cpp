class Solution {
  public:
    vector<string> subdomainVisits(const vector<string> &cpdomains) {
        unordered_map<string, int> um;
        for (const auto &s : cpdomains) {
            int start, pos;
            pos = start = s.find(' ');
            int value = stoi(s.substr(0, pos));
            while (pos != string::npos) {
                um[s.substr(pos + 1)] += value;
                pos = s.find('.', pos + 1);
            }
        }
        vector<string> res;
        res.reserve(um.size());
        for (const auto &[s, n] : um)
            res.push_back(to_string(n) + " " + s);
        return res;
    }
};
