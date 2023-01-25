class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    int n = position.size();
    if (!n) return 0;
    vector<pair<int, double>> vp(n + 1);

    for (int i = 0; i < n; i++)
      vp[i] = {position[i], (double)(target - position[i]) / speed[i]};
    sort(vp.rbegin(), vp.rend());

    int res = 0;
    double ct = 0;
    for (int i = 0; i < n; i++) {
      auto [_, time] = vp[i];
      if (time > ct) {
        res++;
        ct = time;
      }
    }
    return res;
  }
};

// Using map for the heavy lifting
class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    map<int, double> mp;

    for (int i = 0; i < speed.size(); i++)
      mp[-position[i]] = (double)(target - position[i]) / speed[i];

    int res = 0;
    double ct = 0;
    for (auto [_, time] : mp) {
      if (time > ct) {
        res++;
        ct = time;
      }
    }
    return res;
  }
};
