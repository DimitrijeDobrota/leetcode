class Solution {
  public:
    bool doesValidArrayExist(const vector<int> &derived) const {
        return accumulate(begin(derived), end(derived), 0, bit_xor<int>()) == 0;
    }
};
