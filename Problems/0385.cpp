/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
  public:
    NestedInteger deserialize(const string &s) const {
        if (s[0] != '[') return NestedInteger(stoi(s));

        stack<NestedInteger> st;
        const int n = size(s);

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == ',') continue;

            if (s[i] == '[')
                st.push({});
            else if (s[i] == ']') {
                const auto top = st.top();
                st.pop();
                st.top().add(top);
            } else {
                const int start = i;
                while (i < n && s[i] != '[' && s[i] != ']' && s[i] != ',')
                    i++;
                st.top().add(stoi(s.substr(start, i - start)));
                i--;
            }
        }

        return st.top();
    }
};
