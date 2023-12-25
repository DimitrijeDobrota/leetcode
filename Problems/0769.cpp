class Solution {
  public:
    int maxChunksToSorted(const vector<int> &arr) const {
        set<int> st;
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            st.insert(arr[i]);
            if (*st.rbegin() == i) res++;
        }
        return res;
    }
};
