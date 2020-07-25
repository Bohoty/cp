void pre(int node, int parent) {
    in[node] = ++timer;
    vertex[timer] = node;
    sz[node] = 1;
    for (auto child : g[node])
        if (child != parent)
            pre(child, node), sz[node] += sz[child];
    out[node] = timer;
}

void dfs(int node, int parent, bool keep) {
    int mx = -1, bigChild = -1;
    for (auto child : g[node])
        if (child != parent && sz[child] > mx) mx = sz[child], bigChild = child;
    for (auto child : g[node])
        if (child != bigChild && child != parent) dfs(child, node, 0);
    if (~bigChild) dfs(bigChild, node, 1);
    for (auto child : g[node])
        if (child != parent && child != bigChild)
            for (int i = in[child]; i <= out[child]; i++) add(vertex[i]);
    add(node);
    solveQueries(node);
    if (!keep)
        for (int i = in[node]; i <= out[node]; i++) rem(vertex[i]);
}
