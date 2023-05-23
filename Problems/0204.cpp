class Solution {
public:
  int countPrimes(int n) {
    vector<bool> sieve(n);
    int res = 0;
    for (long i = 2; i < n; i++) {
      if (sieve[i]) continue;
      for (long j = i * i; j < n; j += i) sieve[j] = true;
      res++;
    }
    return res;
  }
};
