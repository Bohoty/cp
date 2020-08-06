int sp[N][K], lg[N];
 
void build(vector<int> &v) {
    int n = v.size();
    lg[1] = 0;
    for (int i = 2; i < N; i++)
        lg[i] = lg[i / 2] + 1;
    for (int i = 0; i < n; i++) sp[i][0] = v[i];
    for (int k = 1; (1 << k) <= n; k++) {
        for (int i = 0; i + (1 << k) - 1 < n; i++) {
            sp[i][k] = min(sp[i][k - 1], sp[i + (1 << (k - 1))][k - 1]);
        }
    }
}
 
int query(int l, int r) {
    assert(l <= r);
    int len = r - l + 1;
    return min(sp[l][lg[len]], sp[r + 1 - (1 << lg[len])][lg[len]]);
}
 
void sort(vector<int> &p, vector<int> &c, int n) {
    vector<int> pos(n + 1, 0), pn(n);
    for (auto it : c) pos[it + 1]++;
    for (int i = 1; i < n; i++) pos[i] += pos[i - 1];
    for (int i = 0; i < n; i++) pn[pos[c[p[i]]]++] = p[i];
    p = pn;
}
 
vector<int> getSuffixArray(string s, vector<int> &lcp, vector<int> &c) {
    s += '$';
    int n = s.size();
    vector<int> cn(n), p(n);
    vector<pair<int, int> > tmp(n);
    for (int i = 0; i < n; i++) tmp[i] = {s[i], i};
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++) p[i] = tmp[i].second;
    c[p[0]] = 0;
    for (int i = 1; i < n; i++)
        c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
    int k = 0;
    while ((1 << k) < n) {
        for (int i = 0; i < n; i++) p[i] = (p[i] - (1 << k) + n) % n;
        sort(p, c, n);
        cn[p[0]] = 0;
        for (int i = 1; i < n; i++)
            cn[p[i]] = cn[p[i - 1]] + (make_pair(c[p[i]], c[(p[i] + (1 << k)) % n]) !=
                                       make_pair(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]));
        k++;
        c = cn;
    }
    k = 0;
    for (int i = 0; i < n - 1; i++) {
        while (s[i + k] == s[p[c[i] - 1] + k]) k++;
        lcp[c[i] - 1] = k;
        k = max(0, k - 1);
    }
    build(lcp);
    return p;
}
