class Solution {
  public:
    string toHex(int num) const {
        std::stringstream ss;
        ss << std::hex << num;
        return ss.str();
    }
};
