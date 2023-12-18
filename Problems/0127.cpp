// Make graph and search, interesting similarity test, O(n^2)
class Solution {
    static uint64_t convert(const string &word) {
        uint64_t res = 0;
        for (const char c : word)
            res = (res << 5) + (c & 0x1F);
        return res;
    }

    static bool connected(uint64_t a, uint64_t b) {
        const uint64_t cmp = max(a, b) ^ min(a, b);
        return (63 - __builtin_clzll(cmp)) / 5 == __builtin_ctzll(cmp) / 5;
    }

  public:
    int ladderLength(const string &beginWord, const string &endWord, const vector<string> &wordList) const {
        static uint64_t val[5001];
        const int n = wordList.size();
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < n; i++)
            val[i] = convert(wordList[i]);
        val[n] = convert(beginWord);

        int m = -1;
        for (int i = 0; i < n; i++) {
            if (wordList[i] == beginWord) continue;
            if (wordList[i] == endWord) m = i;
            for (int j = i + 1; j <= n; j++) {
                if (connected(val[i], val[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        if (m == -1) return 0;

        unordered_set<int> seen;
        queue<int> q;
        q.push(n);
        seen.insert(n);
        for (int lvl = 1; !q.empty(); lvl++) {
            for (int k = q.size(); k > 0; k--) {
                const int crnt = q.front();
                q.pop();
                for (const int next : adj[crnt]) {
                    if (seen.count(next)) continue;
                    if (next == m) return lvl + 1;
                    seen.insert(next);
                    q.push(next);
                }
            }
        }

        return 0;
    }
};

// Optimal solution, by trying all similar strings, O(m*n)
class Solution {
  public:
    int ladderLength(const string &beginWord, const string &endWord, const vector<string> &wordList) const {
        const int n = wordList.size(), m = wordList[0].size();
        unordered_set<string> list(begin(wordList), end(wordList));
        unordered_set<string> seen;
        queue<string> q;

        q.push(beginWord);
        seen.insert(beginWord);
        for (int lvl = 1; !q.empty(); lvl++) {
            for (int k = q.size(); k > 0; k--) {
                const string &crnt = q.front();
                for (int i = 0; i < m; i++) {
                    for (int c = 'a'; c <= 'z'; c++) {
                        string next = crnt;
                        next[i] = c;
                        if (list.count(next) && !seen.count(next)) {
                            if (next == endWord) return lvl + 1;
                            seen.insert(next);
                            q.push(next);
                        }
                    }
                }
                q.pop();
            }
        }

        return 0;
    }
};
