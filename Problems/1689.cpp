class Solution {
public:
  int minPartitions(const string &n) {
    return *max_element(n.begin(), n.end()) & 0xF;
  }
};
