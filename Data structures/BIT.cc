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
