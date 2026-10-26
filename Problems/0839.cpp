#include "../Templates/Union_Find.cpp"

class Solution {
    bool similar(const string &s1, const string &s2) {
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) continue;
            if (diff < 2)
                diff++;
            else
                return false;
        }
        return true;
    }

  public:
    int numSimilarGroups(const vector<string> &strs) {
        int n = strs.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (similar(strs[i], strs[j])) uf.join(i, j);
            }
        }
        return uf.count();
    }
};
