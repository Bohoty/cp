const int N = 1e5 + 5;
const int M = 26;
int trie[N][M], suffix_link[N], exit_link[N], go[N][M];
bool leaf[N], vis[N];
int ptr = 1;
void dfs (int node) {
    if (vis[node] || node == 0) return;
    vis[node] = 1;
    dfs(suffix_link[node]);
    if (leaf[suffix_link[node]]) exit_link[node] = suffix_link[node];
    else exit_link[node] = exit_link[suffix_link[node]];
}
void Aho(){
    queue<int> q;
    for(int i = 0; i < M; i++) if(trie[0][i]) q.push(trie[0][i]), suffix_link[trie[0][i]] = 0;
    for(int i = 0; i < M; i++) go[0][i] = trie[0][i];
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int i = 0; i < M; i++) {
            if(trie[x][i]) {
                int y = trie[x][i];
                suffix_link[y] = suffix_link[x];
                while(suffix_link[y] && !trie[suffix_link[y]][i])
                    suffix_link[y] = suffix_link[suffix_link[y]];
                if(trie[suffix_link[y]][i]) suffix_link[y] = trie[suffix_link[y]][i];
                q.push(y);
            }
            if(trie[x][i]) go[x][i] = trie[x][i];
            else go[x][i] = go[suffix_link[x]][i];
        }
    }
    for(int i = 0; i < N ; i++) dfs(i);
}
int idx[N];
void ins(string x, int ii){
    int cur = 0;
    for(int i = 0; i < x.size(); i++){
        if(!trie[cur][x[i]-'a'])
        trie[cur][x[i]-'a'] = ptr++;
        cur = trie[cur][x[i]-'a'];
    }
    idx [ii] = cur;
    leaf[cur] = 1;
}
// Finding the lexicographical smallest string of a given length that doesn't match any given strings
// Finding the shortest string containing all given strings (bfs(node, mask)).
// Finding the lexicographical smallest string of length L containing k strings
