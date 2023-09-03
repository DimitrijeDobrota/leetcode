class Solution {
  public:
    int minSetSize(vector<int> &arr) {
        sort(begin(arr), end(arr));

        vector<int> count;
        int n = arr.size() / 2, crnt = 1, res = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1])
                crnt++;
            else {
                count.push_back(crnt);
                crnt = 1;
            }
        }

        count.push_back(crnt);
        sort(rbegin(count), rend(count));

        for (int i = 0; n > 0; i++)
            n -= count[i], res++;
        return res;
    }
};
