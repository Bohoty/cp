ll get_hash(string &s) {
    const int p = 31;
    ll p_pow = 1, val = 0;
    for(auto c : s) {
        val = (val + (c - 'a' + 1) * p_pow) % mod;
        p_pow = p_pow * p % mod;
    }
    return val;
}
// 1e9 + 7, 31 
// 1e9 + 9, 33
// 1e13 + 37, 37
// 1e13 + 51, 51
 
 /*
 Hash[i....j] = (Hash[j] - Hash[i - 1]) / p[i];
 Rabin-Karp: find pattern s in text t, just hash s and iterate over t hashing every substring with length s.size() 
  and compare hashes.
 
 */
