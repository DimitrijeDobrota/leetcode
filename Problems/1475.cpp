// Brute Force
class Solution {
  public:
    vector<int> finalPrices(vector<int> &prices) const {
        const int n = size(prices);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[j] > prices[i]) continue;
                prices[i] -= prices[j];
                break;
            }
        }

        return prices;
    }
};

// Monotonic Stack
class Solution {
  public:
    vector<int> finalPrices(vector<int> &prices) const {
        const int n = size(prices);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }

            st.push(i);
        }

        return prices;
    }
};
