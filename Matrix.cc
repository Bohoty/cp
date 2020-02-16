struct matrix {
    int n;
    ll a[M][M];
    matrix(int _n, ll val){
        memset(a, 0, sizeof a);
        n = _n;
        for(int i = 0 ; i < n ; i++)
            a[i][i] = val;
    }
};
matrix operator*(const matrix&a, const matrix&b) {
    matrix c(a.n, 0);
    for(int i = 0 ; i < a.n ; i++)
        for(int j = 0 ; j < a.n ; j++)
            for(int k = 0 ; k < a.n ; k++)
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % mod) % mod;
    return c;
}
matrix power(matrix a, ll b){
    matrix res(a.n, 1),temp=a;
    while(b){
        if(b&1)res=res*temp;
        temp=temp*temp;
        b>>=1;
    }
    return res;
}
