class Solution {
  public:
    bool checkString(string_view s) {
        return std::ranges::is_partitioned(s, [](char c) { return c == 'a'; });
    }
};
