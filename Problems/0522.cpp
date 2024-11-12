class Solution {
  public:
    int findLUSlength(vector<string> &strs) const {
        static const auto LCS = [](const string &a, const string &b) {
            int i = 0, j = 0;
            while (i < size(a) && j < size(b)) {
                if (a[i] == b[j]) i++;
                j++;
            }

            return i == size(a);
        };

        sort(begin(strs), end(strs), [](const string &a, const string &b) { return size(a) > size(b); });

        const int n = size(strs);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && LCS(strs[i], strs[j])) goto next;
            }
            return size(strs[i]);
        next:;
        }

        return -1;
    }
};
