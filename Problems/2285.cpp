class Solution {

    typedef pair<int, int> pii;

  public:
    long long maximumImportance(int n, vector<vector<int>> &roads) {
        vector<int> count(n, 0);

        for (auto &e : roads) {
            count[e[0]]++;
            count[e[1]]++;
        }

        sort(count.begin(), count.end());

        long long res = 0ll;
        for (int i = 0; i < n; i++)
            res += (i + 1ll) * count[i];

        return res;
    }
};
