class Solution {
public:
    std::string digitSum(std::string s, std::size_t k) const {
        while(std::size(s) > k) {
          std::string tmp = "";
          for(const auto chunk: s | std::views::chunk(k)) {
            const auto sum = std::ranges::fold_left(chunk, 0UZ, [](auto sum, char c) {
                return sum + (c - '0');
            });
            tmp += to_string(sum);
          }
          s = std::move(tmp);
        }
        return s;
    }
};