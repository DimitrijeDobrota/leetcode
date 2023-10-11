class Solution {
  public:
    vector<int> fullBloomFlowers(const vector<vector<int>> &flowers, const vector<int> &people) const {
        vector<int> start, finish, res;

        start.reserve(flowers.size());
        finish.reserve(flowers.size());
        for (const auto &flower : flowers) {
            start.push_back(flower[0]);
            finish.push_back(flower[1] + 1);
        }

        sort(begin(start), end(start));
        sort(begin(finish), end(finish));

        res.reserve(people.size());
        for (const int person : people) {
            const int left = upper_bound(begin(start), end(start), person) - begin(start);
            const int right = upper_bound(begin(finish), end(finish), person) - begin(finish);
            res.push_back(left - right);
        }
        return res;
    }
};
