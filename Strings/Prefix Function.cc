// p[i]: the length of the longest proper prefix of the substring s[0....i] which is also a suffix of this substring.

vector<int> prefix_fn(string s) {
    int n = (int) s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

/* KMP ???
  s: the string you search for.
  t: the text you search in.
  prefix_fn(s + "#" + t)
*/

// calculate the number of occurrences of each prefix
vector<int> ans(n + 1);
for (int i = 1; i < n; i++)
    ans[pi[i]]++;
for (int i = n - 1; i > 0; i--)
    ans[pi[i - 1]] += ans[i];
for (int i = 1 ; i < n ; i++) ans[i]++;

/* 
  to calculate the number of occurrences of each prefix in other string we use the same trick we used in KMP and calculate
  the answer from s.size() + 1 to the end 
*/

// find the number of different substrings in string (Online) after adding char to the end in complexity O(n^2)
int diff_substrings(string &s, char c){ // not verified yet
    string t = s + c;
    reverse(t.begin(), t.end());
    vector < int > pi = prefix_fn(t);
    bool exist[t.size() + 1];
    memset(exist, 0, sizeof exist);
    for(auto it : pi) exist[it] = 1;
    int ret = t.size();
    for(int i = 1 ; i < t.size() ; i++) ret -= exist[i];
    s = s + c;
    return ret;
}

// compressing a string: the min length of a string that you can concanecate diff occurences of it to obtain s
int comp_len(string s) { // not verified
  int k = n - pi[n - 1];
  return (n % k? n : k);
}

// compute the automation s + # + t
void compute_automaton(string s, vector<vector<int>>& aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
}


