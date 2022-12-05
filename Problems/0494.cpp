class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    queue<int> st;
    st.push(0);

    int zc = 0;
    for (int i = 0; i != nums.size(); ++i) {
      if (!nums[i]) {
        zc++;
        continue;
      }

      for (int j = st.size(); j > 0; --j) {
        int n = st.front();
        st.pop();
        st.push(n - nums[i]);
        st.push(n + nums[i]);
      }
    }

    int count = 0;
    while (!st.empty()) {
      if (st.front() == target) count++;
      st.pop();
    }

    return count * exp2(zc);
  }
};
