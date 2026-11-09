class Solution {
  public:
    vector<int> busiestServers(int k, const std::vector<int> &arrival, const std::vector<int> &load) const {
        using state = std::pair<std::size_t, int>;
        std::priority_queue<state, std::vector<state>, std::greater<>> pq;
        std::set<int> free;

        for (const auto server : std::views::iota(0, k)) {
            free.insert(server);
        }

        auto place = [&](int idx, std::size_t arrival, std::size_t load) {
            while (!std::empty(pq) && pq.top().first <= arrival) {
                free.insert(pq.top().second);
                pq.pop();
            }

            if (std::empty(free)) {
                return k;
            }

            auto it = free.lower_bound(idx % k);
            if (it == std::end(free)) {
                it = std::begin(free);
            }

            const auto server = *it;
            pq.emplace(arrival + load, server);
            free.erase(it);
            return server;
        };

        std::vector<int> count(k + 1, 0);
        for (const auto i : std::views::iota(0UZ, std::size(load))) {
            count[place(i, arrival[i], load[i])]++;
        }
        count.pop_back();

        int maxi = 0;
        std::vector<int> result;
        for (const auto [idx, cnt] : std::views::enumerate(count)) {
            if (cnt < maxi) continue;
            if (cnt > maxi) {
                result.clear();
                maxi = cnt;
            }
            result.emplace_back(idx);
        }
        return result;
    }
};

class Solution {
  public:
    vector<int> busiestServers(std::size_t k, const std::vector<int> &arrival,
                               const std::vector<int> &load) const {
        const auto base = std::bit_ceil(k);
        std::vector<int> tree(2 * base, -1);

        for (const auto server : std::views::iota(0UZ, k)) {
            tree[base + server] = server;
        }

        for (const auto node : std::views::iota(1UZ, base) | std::views::reverse) {
            tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
        }

        const auto tree_set = [&](auto server) {
            auto node = base + server;
            tree[node] = server;

            while ((node >>= 1) != 0) {
                tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
            }
        };

        const auto tree_get = [&](auto idx) {
            if (tree[1] == -1) return k;

            int goal = tree[1] >= idx % k ? idx % k : 0;

            int node = 1;
            while (node < base) {
                node *= 2;
                node += tree[node] < goal;
            }

            const auto server = node - base;
            tree[node] = -1;

            while ((node >>= 1) != 0) {
                tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
            }

            return server;
        };

        using state = std::pair<std::size_t, int>;
        std::priority_queue<state, std::vector<state>, std::greater<>> pq;

        auto place = [&](int idx, std::size_t arrival, std::size_t load) {
            while (!std::empty(pq) && pq.top().first <= arrival) {
                tree_set(pq.top().second);
                pq.pop();
            }

            const auto server = tree_get(idx);
            if (server == k) return k;
            pq.emplace(arrival + load, server);
            return server;
        };

        std::vector<int> count(k + 1, 0);
        for (const auto i : std::views::iota(0UZ, std::size(load))) {
            count[place(i, arrival[i], load[i])]++;
        }
        count.pop_back();

        int maxi = 0;
        std::vector<int> result;
        for (const auto [idx, cnt] : std::views::enumerate(count)) {
            if (cnt < maxi) continue;
            if (cnt > maxi) {
                result.clear();
                maxi = cnt;
            }
            result.emplace_back(idx);
        }
        return result;
    }
};
