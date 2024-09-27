class MyCalendarTwo {
    using interval = pair<int, int>;
    vector<interval> sgl, dbl;

    static bool isOverlap(int s1, int e1, int s2, int e2) { return max(s1, s2) < min(e1, e2); }

    static interval overlap(int s1, int e1, int s2, int e2) { return {max(s1, s2), min(e1, e2)}; }

  public:
    bool book(int start, int end) {
        for (const auto [s, e] : dbl) {
            if (isOverlap(start, end, s, e)) return false;
        }

        for (const auto [s, e] : sgl) {
            if (!isOverlap(start, end, s, e)) continue;
            dbl.push_back(overlap(start, end, s, e));
        }

        sgl.emplace_back(start, end);
        return true;
    }
};
