vector<int> primes;
vector<bool> isp;

void sieve()
{
  isp.resize(1000005, 1);
  isp[0] = isp[1] = 0;
  frr(i, 2, 1000004) {
    if (isp[i]) {
      primes.push_back(i);
      for (int j = i * i; j < 1000005; j += i) {
        isp[j] = 0;
      }
    }
  }
}
