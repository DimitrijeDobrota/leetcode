class Solution {
  public:
    int minOperations(string_view s) const {
        if (std::ranges::is_sorted(s)) return 0;
        if (std::size(s) == 2) return -1;

        const auto [min, max] = std::ranges::minmax(s);
        if (s.front() == min || s.back() == max) return 1;

        const auto interior = s.substr(1, std::size(s) - 2);
        const bool in_interior = std::ranges::any_of(interior, [&](char c) { return c == min || c == max; });

        return in_interior ? 2 : 3;
    }
};
