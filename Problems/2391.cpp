class Solution {
  public:
    int garbageCollection(const vector<string> &garbage, const vector<int> &travel) {
        int truck[4] = {0}, sum = 0, total = 0, i = 0;
        while (true) {
            total += garbage[i].size();
            for (char c : garbage[i])
                truck[c & 3] = sum;
            if (i == garbage.size() - 1) break;
            sum += travel[i++];
        }
        return total + truck[0] + truck[1] + truck[3];
    }
};
