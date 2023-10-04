class Solution {
    static const int MOD = 1e9 + 7;

  public:
    int sumSubarrayMins(const vector<int> &arr) {
        const int n = arr.size();
        stack<int> st;

        long long res = 0;
        for (int right = 0, mid, left; right <= n; right++) {
            while (!st.empty() && (right == n || arr[st.top()] > arr[right])) {
                mid = st.top(), st.pop();
                left = st.empty() ? -1 : st.top();
                res = (res + (long long)arr[mid] * (right - mid) * (mid - left)) % MOD;
            }
            st.push(right);
        }
        return res;
    }
};
