class Solution {

  public:
    void wiggleSort(vector<int> &nums) const {
        const int n = size(nums);

        const auto midptr = begin(nums) + n / 2;
        nth_element(begin(nums), midptr, end(nums));
        const int mid = *midptr;

#define map(i) nums[(2 * (i) + 1) % (n | 1)]
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (map(j) > mid)
                swap(map(i++), map(j++));
            else if (map(j) < mid)
                swap(map(j), map(k--));
            else
                j++;
        }
    }
};
