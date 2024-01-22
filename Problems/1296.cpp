class Solution {
  public:
    bool isPossibleDivide(const vector<int> &nums, const int k) const {
        map<int, int> um;
        for (const int num : nums)
            um[num]++;
        for (auto start = begin(um); start != end(um); start++) {
            const auto [crnt, step] = *start;
            if (!step) continue;
            for (int goal = crnt; goal < crnt + k; goal++) {
                auto it = um.find(goal);
                if (it == end(um) || it->second < step) return false;
                it->second -= step;
            }
        }
        return true;
    }
};
