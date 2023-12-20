static auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
};

class Solution {
    static bool check(const unordered_map<string, int> &count, const string &s, int len) {
        static unordered_map<string, int> lcount;
        lcount.clear();
        for (int i = 0; i < s.size(); i += len) {
            string word = s.substr(i, len);
            const auto it = count.find(word);
            if (it == count.end()) return false;
            if (++lcount[word] > it->second) return false;
        }
        return true;
    }

  public:
    vector<int> findSubstring(const string &s, const vector<string> &words) const {
        const int n = words.size(), m = words[0].size();
        unordered_map<string, int> count;
        for (const string &word : words)
            count[word]++;

        vector<int> res;
        for (int i = 0; i + m * n <= s.size(); i++) {
            if (check(count, s.substr(i, m * n), m)) {
                res.push_back(i);
            }
        }
        return res;
    }
};
