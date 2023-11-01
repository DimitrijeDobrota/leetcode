class Solution {
  public:
    int maxProduct(const vector<string> &words) {
        static uint32_t masks[1001];

        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            uint32_t mask = 0;
            for (const char c : words[i])
                mask |= 1 << (c & 0x1F);
            masks[i] = mask;
            for (int j = 0; j < i; j++) {
                if ((masks[i] & masks[j]) == 0) {
                    res = max(res, (int)(words[i].size() * words[j].size()));
                }
            }
        }

        return res;
    }
};

class Solution {
  public:
    int maxProduct(const vector<string> &words) {
        unordered_map<int, int> um;

        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            uint32_t mask = 0;
            for (const char c : words[i])
                mask |= 1 << (c & 0x1F);
            um[mask] = max(um[mask], (int)words[i].size());
        }

        for (const auto [k1, v1] : um) {
            for (const auto [k2, v2] : um) {
                if ((k1 & k2) == 0) res = max(res, v1 * v2);
            }
        }

        return res;
    }
};
