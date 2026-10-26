#include "../Templates/Union_Find.cpp"

class Solution {
  public:
    bool equationsPossible(vector<string> &equations) {
        UnionFind uf(26);
        for (auto &s : equations)
            if (s[1] == '=') uf.join(s[0] - 'a', s[3] - 'a');

        for (auto &s : equations)
            if (s[1] == '!' && uf.find(s[0] - 'a') == uf.find(s[3] - 'a')) return false;
        return true;
    }
};
