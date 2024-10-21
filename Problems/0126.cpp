class Solution {
    unordered_map<string, vector<string>> adj;
    vector<vector<string>> res;
    vector<string> state;

    void dfs(const string &crnt, int lvl) {
        if (lvl == 0) {
            res.push_back(state);
            return;
        }

        for (const auto &word : adj[crnt]) {
            state[lvl - 1] = word;
            dfs(word, lvl - 1);
        }
    }

  public:
    vector<vector<string>> findLadders(const string &beginWord, const string &endWord,
                                       vector<string> &wordList) {
        unordered_set<string> set(begin(wordList), end(wordList));
        unordered_set<string> seen;
        queue<string> q;

        q.push(beginWord);
        for (int lvl = 1; !q.empty(); lvl++) {
            for (int k = size(q); k > 0; k--) {
                const auto root = q.front();
                q.pop();

                cout << root << endl;
                if (root == endWord) {
                    state = vector<string>(lvl);
                    state[lvl - 1] = endWord;
                    dfs(root, lvl - 1);
                    return res;
                }

                auto crnt = root;
                for (int i = 0; i < size(crnt); i++) {
                    const char og = crnt[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        crnt[i] = c;
                        if (!set.count(crnt)) continue;
                        if (!seen.count(crnt)) {
                            seen.emplace(crnt);
                            q.push(crnt);
                        }
                        adj[crnt].push_back(root);
                    }
                    crnt[i] = og;
                }
            }

            for (const auto &word : seen)
                set.erase(word);
        }

        return {};
    }
};
