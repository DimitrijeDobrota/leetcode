class Solution {
  public:
    int maxLength(const vector<string> &arr) const {
        typedef bitset<27> bs;
        vector<bs> vec(1, 0);
        int res = 0;

        for (const auto &s : arr) {
            const int n = size(s);
            bs crnt;
            for (const char c : s)
                crnt.set(c & 0x1F);
            if (crnt.count() != n) continue;
            for (int i = size(vec) - 1; i >= 0; i--) {
                const auto &prev = vec[i];
                if ((prev & crnt).any()) continue;
                res = max(res, (int)prev.count() + n);
                vec.push_back(prev | crnt);
            }
        }

        return res;
    }
};
