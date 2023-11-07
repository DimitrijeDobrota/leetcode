class Solution {
  public:
    int eliminateMaximum(const vector<int> &dist, const vector<int> &speed) const {
        static float time[100001];
        const int n = dist.size();

        for (int i = 0; i < n; i++)
            time[i] = (float)dist[i] / (float)speed[i];
        sort(begin(time), begin(time) + n);

        for (int i = 0; i < n; i++)
            if (time[i] <= i) return i;
        return n;
    }
};
