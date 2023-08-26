class Solution {
  public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
        vector<int> res;
        res.reserve(obstacles.size());
        vector<int> mono;
        mono.reserve(obstacles.size());

        for (int o : obstacles) {
            int left = 0, right = mono.size();
            while (left < right) {
                int mid = (left + right) / 2;
                if (mono[mid] <= o)
                    left = mid + 1;
                else
                    right = mid;
            }
            res.push_back(left + 1);
            if (mono.size() == left) mono.push_back(o);
            mono[left] = o;
        }

        return res;
    }
};
