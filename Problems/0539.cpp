class Solution {
    static const int day = 24 * 60;

    static inline int val(const char *time) { return (time[0] & 0xF) * 10 + (time[1] & 0xF); }

    static inline int val(const string &time) { return val(time.c_str()) * 60 + val(time.c_str() + 3); }

  public:
    int findMinDifference(const vector<string> &timePoints) {
        const int n = size(timePoints);
        vector<int> time(n);

        for (int i = 0; i < n; i++)
            time[i] = val(timePoints[i]);
        sort(begin(time), end(time));

        int res = day - time.back() + time.front();
        for (int i = 1; i < n; i++)
            res = min(res, time[i] - time[i - 1]);

        return res;
    }
};

// No extra memory, little bit slower
class Solution {
    static const int day = 24 * 60;

    static inline int val(const char *time) { return (time[0] & 0xF) * 10 + (time[1] & 0xF); }

    static inline int val(const string &time) { return val(time.c_str()) * 60 + val(time.c_str() + 3); }

  public:
    int findMinDifference(vector<string> &timePoints) {
        const int n = size(timePoints);
        sort(begin(timePoints), end(timePoints));

        int res = INT_MAX;
        int first = val(timePoints[0]), prev = first;
        for (int i = 1; i < n; i++) {
            const int crnt = val(timePoints[i]);
            res = min(res, crnt - prev);
            prev = crnt;
        }

        return min(res, first + (day - prev));
    }
};
