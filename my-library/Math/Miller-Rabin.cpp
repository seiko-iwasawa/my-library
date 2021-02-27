#include <iostream>
#include <random>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll sum(ll a, ll b, ll mod) { return a + b < mod ? a + b : a + b - mod; }

ll mul(ll a, ll b, ll mod) {
  ll res = 0;
  do {
    if (b & 1) {
      res = sum(res, a, mod);
    }
    a = sum(a, a, mod);
  } while (b >>= 1);
  return res;
}

ll qp(ll a, ll k, ll mod) {
  ll res = 1;
  do {
    if (k & 1) {
      res = mul(res, a, mod);
    }
    a = mul(a, a, mod);
  } while (k >>= 1);
  return res;
}

bool miller_rabin_test(ll a, ll n) {
  if (a >= n) {
    return true;
  }
  if (gcd(a, n) != 1) {
    return false;
  }
  ll m = n - 1;
  while (~(m >>= 1) & 1) {
    if (qp(a, m, n) == n - 1) {
      return true;
    }
  }
  return qp(a, m, n) == n - 1 || qp(a, m, n) == 1;
}

bool is_prime(ll n) {
  if (n == 1) {
    return false;
  } else if (n % 2 == 0) {
    return n == 2;
  } else {
    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19}) {
      if (!miller_rabin_test(a, n)) {
        return false;
      }
    }
    mt19937 rnd(239);
    for (ll it = 0; n >> it; ++it) {
      if (!miller_rabin_test(rnd() % (n - 1) + 1, n)) {
        return false;
      }
    }
    return true;
  }
}
