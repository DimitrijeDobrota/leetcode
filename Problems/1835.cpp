class Solution {
  public:
    int getXORSum(const vector<int> &arr1, const vector<int> &arr2) const {
        static const auto count = [](const auto &arr) {
            return accumulate(begin(arr), end(arr), 0, bit_xor());
        };
        return count(arr1) & count(arr2);
    }
};
