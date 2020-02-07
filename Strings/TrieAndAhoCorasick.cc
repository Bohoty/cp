const int K = 26;
struct node {
    int nxt[K];
    bool leaf = 0;
    node() {
        fill(begin(nxt), end(nxt), -1);
    }
};
vector < node > trie(1);
void add_string(string &s) {
    int cur = 0;
    for(char c : s) {
        int cc = c - 'a';
        if (trie[cur].nxt[cc] == -1) trie[cur].nxt[cc] = trie.size(), trie.emplace_back();
        cur = trie[cur].nxt[cc];
    }
    trie[cur].leaf = 1;
}
