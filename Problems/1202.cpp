#include "../Templates/Union_Find.cpp"

class Solution {
  public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        UnionFind uf(s.size());
        vector<vector<char>> vs(s.size());

        for (auto &p : pairs)
            uf.join(p[0], p[1]);

        for (int i = 0; i < s.size(); i++)
            vs[uf.find(i).index()].push_back(s[i]);

        for (auto &s : vs)
            sort(s.rbegin(), s.rend());

        for (int i = 0; i < s.size(); i++) {
            int index = uf.find(i).index();
            s[i] = vs[index].back();
            vs[index].pop_back();
        }
        return s;
    }
};
