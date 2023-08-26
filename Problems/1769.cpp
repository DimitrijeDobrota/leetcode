class Solution {
  public:
    vector<int> minOperations(const string &boxes) {
        vector<int> res(boxes.size(), 0);

        for (int i = 0, ops = 0, cnt = 0; i < boxes.size(); i++) {
            res[i] += ops;
            ops += cnt += (boxes[i] == '1');
        }

        for (int i = boxes.size() - 1, ops = 0, cnt = 0; i >= 0; i--) {
            res[i] += ops;
            ops += cnt += (boxes[i] == '1');
        }

        return res;
    }
};
