// original solution - accepted
class Solution {
public:
  int candy(vector<int> &ratings) {
    // place holder rating for easy neighbor calculation
    ratings.insert(ratings.begin(), -1), ratings.push_back(-1);
    int n = ratings.size();

    // sort by rating remembering the original index
    vector<pair<int, int>> vec;
    vec.reserve(n);
    for (int i = 1; i < n - 1; i++) vec.push_back({ratings[i], i});
    sort(vec.begin(), vec.end());

    vector<int> res(n, 1);        // 'Each child must have at least one candy'
    res.front() = res.back() = 0; // except placeholders
    for (auto &[rating, index] : vec) {
      if (rating < ratings[index + 1])
        res[index + 1] = max(res[index + 1], res[index] + 1);

      if (rating < ratings[index - 1])
        res[index - 1] = max(res[index - 1], res[index] + 1);
    }

    return accumulate(res.begin(), res.end(), 0);
  }
};

// improved solution - same logic no nonsense
class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    if (n <= 1) return n;

    vector<int> res(n, 1);
    for (int i = 0; i < n - 1; i++) {
      if (ratings[i] < ratings[i + 1]) res[i + 1] = res[i] + 1;
    }

    for (int i = n - 1; i > 0; i--) {
      if (ratings[i] < ratings[i - 1]) res[i - 1] = max(res[i - 1], res[i] + 1);
    }

    return accumulate(res.begin(), res.end(), 0);
  }
};
