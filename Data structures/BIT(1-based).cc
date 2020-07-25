void upd(int idx, int val) {
    for (; idx < n + 4; idx += (idx & (-idx))) bit[idx] += val;
}

int sum(int idx, int ret = 0) {
    for (; idx; idx -= (idx & (-idx))) ret += bit[idx];
    return ret;
}
