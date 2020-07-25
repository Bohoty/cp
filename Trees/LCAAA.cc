void dfs(int node, int parent = -1) {
    depth[node] = parent == -1 ? 1 : depth[parent] + 1;
    timer++;
    in[node] = timer;
    f[timer] = node;
    First[node] = euler.size();
    euler.push_back(node);
    for (int child: tree[node])
        if (child != parent)
            dfs(child, node), euler.push_back(node);
}

void buildLCA(int node) {
    dfs(node);
    int num = euler.size();
    lg[1] = 0;
    for (int i = 2; i < N; i++) lg[i] = lg[i / 2] + 1;
    for (int i = 0; i < num; i++) sp[i][0] = in[euler[i]];
    for (int k = 1; (1 << k) <= num; k++)
        for (int i = 0; (i + (1 << k) - 1) < num; i++)
            sp[i][k] = min(sp[i][k - 1], sp[i + (1 << (k - 1))][k - 1]);
}

pair < int, int >getLcaAndDist(int a, int b) {
    int orgA = a, orgB = b;
    a = First[a], b = First[b];
    if (a > b) swap(a, b);
    int len = b - a + 1;
    int lca = f[min(sp[a][lg[len]], sp[b - (1 << lg[len]) + 1][lg[len]])];
    return {lca, depth[orgA] + depth[orgB] - 2 * depth[lca]};
}
