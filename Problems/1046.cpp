class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    int n = stones.size();
    make_heap(stones.begin(), stones.end());
    while (stones.size() > 1) {
      int x, y;
      pop_heap(stones.begin(), stones.end());
      y = stones.back(), stones.pop_back();
      pop_heap(stones.begin(), stones.end());
      x = stones.back(), stones.pop_back();
      if (x != y) {
        stones.push_back(y - x);
        push_heap(stones.begin(), stones.end());
      }
    }
    return !stones.empty() ? stones.back() : 0;
  }
};
