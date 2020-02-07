const int K = 26;
struct node {
    int nxt[K], go[K], p = -1, link = -1;
    char pch;
    bool leaf = 0;
    node() {
        fill(begin(nxt), end(nxt), -1);
    }
    node(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(nxt), end(nxt), -1);
        fill(begin(go), end(go), -1);
    }
};
vector < node > t(1);
void add_string(string &s) {
    int cur = 0;
    for(char c : s) {
        int cc = c - 'a';
        if (t[cur].nxt[cc] == -1) t[cur].nxt[cc] = t.size(), t.emplace_back(cur, c);
        cur = t[cur].nxt[cc];
    }
    t[cur].leaf = 1;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].nxt[c] != -1)
            t[v].go[c] = t[v].nxt[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

// Find all strings from a given set in a text
// Finding the lexicographical smallest string of a given length that doesn't match any given strings
