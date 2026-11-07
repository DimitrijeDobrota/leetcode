class Solution {
  public:
    vector<int> assignTasks(const std::vector<int> &servers, const std::vector<int> &tasks) const {
        using pair = std::pair<std::ptrdiff_t, int>;
        std::priority_queue<pair, std::vector<pair>, std::greater<>> free;
        std::priority_queue<pair, std::vector<pair>, std::greater<>> busy;

        for (const auto [idx, weight] : std::views::enumerate(servers)) {
            free.emplace(weight, idx);
        }

        std::ptrdiff_t time = 0;
        std::vector<int> result(std::size(tasks));
        for (const auto [index, task] : std::views::enumerate(tasks)) {
            time = std::max(time, index);

            if (std::empty(free)) {
                time = std::max(time, busy.top().first);
            }

            while (!std::empty(busy) && busy.top().first <= time) {
                const auto [_, candid] = busy.top();
                busy.pop();

                free.emplace(servers[candid], candid);
            }

            const auto [_, candid] = free.top();
            free.pop();

            busy.emplace(time + task, candid);
            result[index] = candid;
        }
        return result;
    }
};
