// by 3eno
const int M = 2, MOD = 1e9 + 7;
struct Matrix {
	ll mat[M][M];
	Matrix(bool I) {
		memset(mat, 0, sizeof mat);
		if (I)
			for (int j = 0; j < M; j++)
				mat[j][j] = 1;
	}
	ll * operator [](ll i) {
		return mat[i];
	}
	friend Matrix operator *(Matrix A, Matrix B) {
		Matrix ret(0);
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
				for (int k = 0; k < M; k++)
					ret[i][j] = (ret[i][j] + A[i][k] * B[k][j]) % MOD;
		return ret;
	}
	Matrix expo(ll n) {
		if (!n)
			return Matrix(1);
		if (n & 1LL)
			return *this * expo(n - 1);
		return (*this * *this).expo(n >> 1LL);
	}
};
