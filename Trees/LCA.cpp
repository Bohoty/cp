vector<vector<int> > g(N);
int n, l;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;
int lvl[N];
void dfs(int v, int p){
    lvl[v] = lvl[p] + 1;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (auto u : g[v]) {
        if (u != p)
            dfs(u, v);
    }
    tout[v] = timer;
}
bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
void preprocess(int root) {
    tin.resize(n + 1);
    tout.resize(n + 1);
    timer = 0;
    l = ceil(log2(n + 1));
    up.assign(n + 1, vector<int>(l + 1));
    dfs(root, root);
}
int dist(int a, int b) {
    int l = lca(a,b);
    return abs (lvl[l] - lvl[a]) + abs(lvl[l] - lvl[b]);
}
