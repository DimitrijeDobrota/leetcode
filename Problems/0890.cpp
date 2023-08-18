class Solution {
public:
  vector<string> findAndReplacePattern(const vector<string> &words,
                                       const string &pattern) {
    vector<string> res;
    static int um[27] = {0};
    static bool used[27] = {0};
    for (const auto &word : words) {
      for (int i = 0; i < pattern.size(); i++) {
        const uint8_t w = word[i] & 0x1F;
        const uint8_t p = pattern[i] & 0x1F;
        if (um[w]) {
          if (um[w] != p) goto next;
          continue;
        }
        if (used[p]) goto next;
        used[p] = true;
        um[w] = p;
      }
      res.push_back(word);
    next:;
      memset(um, 0x00, sizeof(um));
      memset(used, 0x00, sizeof(used));
    }

    return res;
  }
};
