class Solution {
  public:
    long long subArrayRanges(const vector<int> &nums) {
        const int n = nums.size();
        long long res = 0;
        stack<int> st;

        for (int right = 0, mid, left; right <= n; right++) {
            while (!st.empty() && (right == n || nums[st.top()] >= nums[right])) {
                mid = st.top(), st.pop();
                left = st.empty() ? -1 : st.top();
                res -= (long long)nums[mid] * (right - mid) * (mid - left);
            }
            st.push(right);
        }

        st.pop();
        for (int right = 0, mid, left; right <= n; right++) {
            while (!st.empty() && (right == n || nums[st.top()] <= nums[right])) {
                mid = st.top(), st.pop();
                left = st.empty() ? -1 : st.top();
                res += (long long)nums[mid] * (right - mid) * (mid - left);
            }
            st.push(right);
        }

        return res;
    }
};
