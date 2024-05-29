class Solution {
  public:
    int videoStitching(vector<vector<int>> &clips, const int time) const {
        const int n = size(clips);
        int res = 0, start = 0, finish = 0;

        sort(begin(clips), end(clips));
        for (int i = 0; start < time; res++) {
            for (; i < n && clips[i][0] <= start; i++) {
                finish = max(finish, clips[i][1]);
            }
            if (start == finish) return -1;
            start = finish;
        }

        return res;
    }
};
