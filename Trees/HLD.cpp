// A7la HLD 3lek ya sa7be
vector<int> g[N];
int ptr, parent[N], sz[N], heavy[N], pos[N], head[N], depth[N];

void pre(int node = 1) { // just finding the heavy child of each node(the one with max subtree) and depths
    sz[node] = 1;
    depth[node] = depth[parent[node]] + 1;
    heavy[node] = -1;
    int mx = 0;
    for (int child : g[node]) {
        if (child == parent[node]) continue;
        parent[child] = node;
        pre(child);
        sz[node] += sz[child];
        if (sz[child] > mx)
            mx = sz[child], heavy[node] = child;
    }
}

void decompose(int node = 1, int Head = 1) {
    pos[node] = ++ptr;  // assigning the position of this node in the segment tree
    head[node] = Head; // save the head of the heavy path where the node is

    if (heavy[node] != -1)
        decompose(heavy[node], Head); // if the node has a heavy child continue with the same heavy path

    for (int child : g[node]) // iterating over the rest of nodes to make their own heavy paths
        if (child != parent[node] && child != heavy[node])
            decompose(child, child);
}

int query(int v, int u) { // find the max value on the path from v to u
    int res = -2e9;
    for (; head[v] != head[u]; u = parent[head[u]]) { // find the max from each of the nodes to the LCA
        if (depth[head[v]] > depth[head[u]])
            swap(v, u);
        res = max(res, seg_tree_shit(pos[head[u]], pos[u]));
    }
    if (depth[v] > depth[u])
        swap(u, v);
    res = max(res, seg_tree_shit(pos[v], pos[u]));
    return res;
}
