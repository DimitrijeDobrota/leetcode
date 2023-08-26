class Solution {
public:
  vector<string> buildArray(vector<int> &target, int n) {
    vector<string> res;
    int stream = 1;
    for (int t : target) {
      while (stream++ != t) {
        res.push_back("Push");
        res.push_back("Pop");
      }
      res.push_back("Push");
    }
    return res;
  }
};
