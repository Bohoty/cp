/// point update range query
// sum
#define T int
T bit[N];
T sum(int r, T ret = 0) {
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += bit[r];
    return ret;
}
void add(int idx, T val) {
    for (; idx < n; idx = idx | (idx + 1))
        bit[idx] += val;
}

// same goes for min and max
#define T int
T bit[N];
T mn(int r, T ret = inf) {
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret = min(ret, bit[r]);
    return ret;
}
void update(int idx, T val) {
    for (; idx < n; idx = idx | (idx + 1))
        bit[idx] = min(val, bit[idx]);
}

// 2D b2a
#define T int
T bit[N][N];
T sum(int x, int y, T ret = 0) {
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            ret += bit[i][j];
    return ret;
}
T add(int x, int y, T val) {
    for (int i = x; i < n; i = i | (i + 1))
        for (int j = y; j < n; j = j | (j + 1))
            bit[i][j] += val;
}

/// range query point update
add(l, val); add(r + 1, - val);
sum(i); // to get required index value


// range update range query 
#define T int
T bit1[N], bit2[N];
void range_add(int l, int r, T val) {
    add(bit1, l, val);
    add(bit1, r + 1, -val);
    add(bit2, l, val * (l - 1));
    add(bit2, r + 1, -val * r);
}
T prefix_sum(int idx) {
    return sum(bit1, idx) * idx - sum(bit2, idx);
}



