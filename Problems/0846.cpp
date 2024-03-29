class Solution {
  public:
    bool isNStraightHand(const vector<int> &hand, const int groupSize) const {
        map<int, int> um;
        for (const int num : hand)
            um[num]++;
        for (auto start = begin(um); start != end(um); start++) {
            const auto [crnt, step] = *start;
            if (!step) continue;
            for (int goal = crnt; goal < crnt + groupSize; goal++) {
                auto it = um.find(goal);
                if (it == end(um) || it->second < step) return false;
                it->second -= step;
            }
        }
        return true;
    }
};
