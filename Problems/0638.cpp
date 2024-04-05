class Solution {
    static bool finished(const vector<int> needs) {
        for (const int n : needs)
            if (n) return false;
        return true;
    }

  public:
    int shoppingOffers(const vector<int> &price, const vector<vector<int>> &special, const vector<int> &needs,
                       int offer = 0, int cost = 0) const {
        if (finished(needs)) return cost;

        const int n = size(price);

        int res = cost;
        for (int i = 0; i < n; i++) {
            res += needs[i] * price[i];
        }

        for (int i = offer; i < size(special); i++) {
            int times = INT_MAX;
            for (int j = 0; j < n && times; j++) {
                if (!special[i][j]) continue;
                times = min(times, needs[j] / special[i][j]);
            }

            if (!times) continue;

            vector<int> next = needs;
            int added = 0;

            for (int k = 1; k <= times; k++) {
                added += special[i].back();
                if (cost + added >= res) break;
                for (int j = 0; j < n; j++)
                    next[j] -= special[i][j];
                res = min(res, shoppingOffers(price, special, next, i + 1, cost + added));
            }
        }

        return res;
    }
};
