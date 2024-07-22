class Solution {
  public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights) const {
        static int idxes[1001];
        const int n = size(names);

        iota(idxes, idxes + n, 0);
        sort(idxes, idxes + n, [&](int a, int b) { return heights[a] > heights[b]; });

        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = names[idxes[i]];
        }

        return res;
    }
};
