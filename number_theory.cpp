int bpow(int A, int B)
{
	int product = 1;
	while (B > 0) {
		if (B & 1)
			product = product * A;
		A = A * A;
		B = B >> 1;
	}
	return product;
}

int bpow(int A, int B, int mod)
{
	A %= mod;
	int product = 1;
	while (B > 0) {
		if (B & 1)
			product = (product * A) % mod;
		A = (A * A) % mod;
		B = B >> 1;
	}
	return product;
}

int extendedEuclid(int A, int B, int &X, int &Y)
{
	if (B == 0)
	{
		X = 1;
		Y = 0;
		return A;
	}
	int X1, Y1;
	int GCD = extendedEuclid(B, A % B, X1, Y1);
	X = Y1;
	Y = X1 - Y1 * (A / B);
	return GCD;
}

int modInverse(int A, int M)
{
	int X, Y;
	int GCD = extendedEuclid(A, M, X, Y);
	if (GCD != 1) {
		cout << "A and M are not coprime...Check again" << nl;
		return -1;
	}
	else {
		return (X % M + M) % M;
	}
}

int modInverseFermat(int A, int M)
{
	/* assert M is prime */
	return bpow(A, M - 2, M);
}

void getModInverse(int *inv, int M)
{
	/* assert M is a prime and int inv[M] */
	inv[0] = -1;
	inv[1] = 1;
	for (int i = 2; i < M; i++) {
		inv[i] = M - (M / i) * inv[M % i] % M;
	}
}
