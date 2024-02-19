class Solution {
  public:
    string lastNonEmptyString(const string &s) const {
        int count[27] = {0}, last[27] = {0};
        int maxi = 0;

        for (int i = 0; i < size(s); i++) {
            const int idx = s[i] & 0x1F;
            maxi = max(maxi, ++count[idx]);
            last[idx] = i;
        }

        vector<int> make;
        for (int i = 1; i <= 26; i++) {
            if (count[i] != maxi) continue;
            make.push_back(i);
        }

        sort(begin(make), end(make), [&](int i, int j) { return last[i] < last[j]; });

        string res(size(make), 0);
        for (int i = 0; i < size(make); i++)
            res[i] = '`' + make[i];
        return res;
    }
};
