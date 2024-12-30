class Solution {
  public:
    int minimumSum(int num) {
        vector<int> arr = {num % 10, num / 10 % 10, num / 100 % 10, num / 1000 % 10};
        sort(begin(arr), end(arr));
        return (arr[0] + arr[1]) * 10 + arr[2] + arr[3];
    }
};
