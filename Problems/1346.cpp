class Solution {
public:
  bool checkIfExist(vector<int> &arr) {
    unordered_set<int> us;
    for (int i : arr)
      if ((i % 2 == 0 && us.find(i / 2) != us.end()) ||
          us.find(i * 2) != us.end())
        return true;
      else
        us.insert(i);

    return false;
  }
};
