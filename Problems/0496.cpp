class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res(nums1.size(), -1);
    unordered_map<int, int> um;
    stack<int> st;

    for (int i = 0; i < nums2.size(); i++) {
      while (!st.empty() && nums2[i] > st.top()) {
        um.insert(make_pair(st.top(), nums2[i]));
        st.pop();
      }
      st.push(nums2[i]);
    }

    for (int i = 0; i < nums1.size(); i++)
      if (um.find(nums1[i]) != um.end()) res[i] = um[nums1[i]];

    return res;
  }
};
