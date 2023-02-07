class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    pair<int, int> used = {fruits[0], -1}, count = {0, 0}, pos = {0, 0};
    int start = 0, res = 0;

    for (start = 0; start < fruits.size(); start++)
      if (fruits[start] != used.first)
        break;
      else
        count.first++;

    if (start == fruits.size()) return count.first;

    used.second = fruits[start];
    for (int i = start; i < fruits.size(); i++) {
      if (fruits[i] == used.first)
        count.first++, pos.first++, pos.second = 0;
      else if (fruits[i] == used.second)
        count.second++, pos.first = 0, pos.second++;
      else {
        res = max(res, count.first + count.second);
        if (fruits[i - 1] == used.second) {
          used.first = fruits[i];
          count = pos;
          pos = {1, 0};
          count.first++;
        } else {
          used.second = fruits[i];
          count = pos;
          pos = {0, 1};
          count.second++;
        }
      }
    }

    return max(res, count.first + count.second);
  }
};
