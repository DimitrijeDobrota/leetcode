class Solution {
  public:
    int numOfSubarrays(const vector<int> &arr, int k, int threshold) {
        int total = 0, res = 0;
        for (int i = 0; i < k; i++)
            total += arr[i];

        threshold *= k;
        for (int i = k; i < arr.size(); i++) {
            if (total >= threshold) res++;
            total += arr[i];
            total -= arr[i - k];
        }
        if (total >= threshold) res++;

        return res;
    }
};
