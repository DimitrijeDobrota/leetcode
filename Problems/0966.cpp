class Solution {
    static bool isvowel(const char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }

    static string devow(string word) {
        for (char &c : word)
            if (isvowel(c)) c = '_';
        return word;
    }

    static string tolower(string word) {
        for (char &c : word)
            c = std::tolower(c);
        return word;
    }

  public:
    vector<string> spellchecker(const vector<string> &wordlist, vector<string> &queries) const {
        unordered_set<string> words(begin(wordlist), end(wordlist));
        unordered_map<string, string> caps, vows;

        for (const auto &word : wordlist) {
            const string low = tolower(word);
            caps.emplace(low, word);
            vows.emplace(devow(low), word);
        }

        for (auto &word : queries) {
            if (words.count(word)) continue;
            const string low = tolower(word);

            const auto it = caps.find(low);
            if (it != caps.end()) {
                word = it->second;
                continue;
            }

            word = vows[devow(low)];
        }

        return queries;
    }
};
