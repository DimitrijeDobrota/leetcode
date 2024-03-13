class Solution {
  public:
    int pivotInteger(const int n) const {
        int i = 1, j = n, l = 0, h = 0;
        while (i < j) {
            if (l < h)
                l += i++;
            else
                h += j--;
        }
        return l == h ? i : -1;
    }
};

class Solution {
  public:
    int pivotInteger(const int n) const {
        const int sum = n * (n + 1) / 2;
        const int pivot = sqrt(sum);
        return pivot * pivot == sum ? pivot : -1;
    }
};
