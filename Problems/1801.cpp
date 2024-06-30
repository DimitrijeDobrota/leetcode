class Solution {
    static const int mod = 1e9 + 7;
    using tii_t = tuple<int, int>;

    template <typename C, typename T, typename M>
    void exchange(T &first, M &second, int price, int amount) const {
        const auto cmp = C();
        while (!first.empty() && amount > 0) {
            const auto [cprice, camount] = first.top();
            if (cmp(cprice, price)) break;
            first.pop();

            if (camount <= amount)
                amount -= camount;
            else {
                first.emplace(cprice, camount - amount);
                amount = 0;
            }
        }
        if (amount > 0) second.emplace(price, amount);
    }

    template <typename T> long long count(T &pq) const {
        long long res = 0;
        while (!pq.empty()) {
            const auto [_, amount] = pq.top();
            res = (res + amount) % mod;
            pq.pop();
        }
        return res;
    }

  public:
    int getNumberOfBacklogOrders(const vector<vector<int>> &orders) const {
        priority_queue<tii_t, vector<tii_t>, greater<tii_t>> buy;
        priority_queue<tii_t, vector<tii_t>, less<tii_t>> sell;
        int res = 0;

        for (const auto &order : orders) {
            if (!order[2])
                exchange<greater<int>>(buy, sell, order[0], order[1]);
            else
                exchange<less<int>>(sell, buy, order[0], order[1]);
        }

        return (count(buy) + count(sell)) % mod;
    }
};
