class Solution {
  public:
    string convertDateToBinary(const string &date) const {
        const auto year = stoi(date.substr(0, 4));
        const auto month = stoi(date.substr(5, 2));
        const auto day = stoi(date.substr(8, 2));

        return format("{:b}-{:b}-{:b}", year, month, day);
    }
};
