class Solution {
    static const uint8_t map[27];

  public:
    int findTheLongestSubstring(const string &s) {
        static int um[1 << 5];
        memset(um, 0xFF, sizeof(um));
        int res = 0, crnt = 0;
        for (int i = 0; i < s.size(); i++) {
            crnt ^= (1 << map[s[i] & 0x1F]) >> 1;
            if (!crnt)
                res = max(res, i + 1);
            else if (um[crnt] == -1)
                um[crnt] = i;
            else
                res = max(res, i - um[crnt]);
        }
        return res;
    }
};

const uint8_t Solution::map[27] = {0, 1, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 0,
                                   0, 4, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0};
