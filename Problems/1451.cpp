#pragma GCC optimize("fast")
static auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
  public:
    string arrangeWords(string &text) {
        map<int, vector<string>> um;
        string word, res;

        text[0] = tolower(text[0]);
        stringstream ss(text);
        while (ss >> word)
            um[word.size()].push_back(word);

        res.reserve(text.size());
        for (const auto &[_, v] : um) {
            for (const auto &w : v)
                res += w + " ";
        }
        res[0] = toupper(res[0]);
        res.pop_back();
        return res;
    }
};
