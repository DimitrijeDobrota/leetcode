class Solution {
  public:
    int finalValueAfterOperations(const vector<string> &operations) const {
        int res = 0;

        for (const auto &op : operations) {
            if (op.front() == '-' || op.back() == '-')
                res--;
            else
                res++;
        }

        return res;
    }
};
