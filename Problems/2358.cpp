class Solution {
  public:
    int maximumGroups(const vector<int> &grades) {
        int k = 0, total = 0;
        while (total + k < grades.size())
            total += ++k;
        return k;
    }
};
