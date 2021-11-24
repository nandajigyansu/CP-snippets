#include <bits/stdc++.h>
using namespace std;
#define nl      '\n'
#define f       first
#define s       second
#define str     string
#define pb      push_back
#define int     long long
#define skip    continue
#define ld      long double
#define vi      vector<int>
#define pii     pair<int, int>
#define PI      3.141592653589793238462
#define all(v)  (v).begin(), (v).end()
#define reset(a, k) memset(a, k, sizeof a)
#define fr(i, N) for (int i = 0; i < (int) N; i++)
#define frr(i, A, B) for (int i = (int) A; i <= (int) B; i++)
#define fro(i, A, B) for (int i = (int) A; i >= (int) B; i--)

void fileIO()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int _gcd(int A, int B) { return (B) ? _gcd(B, A % B) : A; }
int _lcm(int A, int B) { return A * B / _gcd(A, B); }
int max(int A, int B) { return (A >= B) ? A : B; }
int min(int A, int B) { return (A <= B) ? A : B; }

int bpow(int A, int B) { int res = 1; while (B > 0) { if (B & 1) { res = res * A; } A = A * A; B = B >> 1; } return res; }
int bpow(int A, int B, int MOD) { int res = 1; A %= MOD; while (B > 0) { if (B & 1) { res = (res * A) % MOD; } A = (A * A) % MOD; B = B >> 1; } return res; }
int exGCD(int A, int B, int& X, int& Y) { if (B == 0) { X = 1; Y = 0; return A; } int X1, Y1; int gcd = exGCD(B, A % B, X1, Y1); X = Y1; Y = X1 - (Y1 * (A / B)); return gcd; }
int modInv(int A, int M) { int X, Y; int gcd = exGCD(A, M, X, Y); if (gcd != 1) { cout << "A and M are NOT coprime" << "\n"; return -1; } else { return (X % M + M) % M; } }
int modInvFormat(int A, int M) { return bpow(A, M - 2, M); } // Assert M is prime

const int inf = (int)1e18 + 2;
const int ninf = -(int)1e17;
const int mod = (int)1e9 + 7;
const int mod2 = 998244353;

/* ----------------------------( solution )---------------------------- */




void solve(int T = 0) {
	//
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int TC = 1;
	fileIO();
	cin >> TC;
	for (int T = 1; T <= TC; T++) {
		solve(T);
	}
	return 0;
}
