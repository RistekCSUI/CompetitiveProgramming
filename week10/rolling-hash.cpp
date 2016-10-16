// Rabin-Karp String Matching algorithm

const int BASE = 137;
const int MOD = 1000000007;

// prefix hash:
// hash the string from the beginning of the string to the end of the string
//
// (H(i - 1) * BASE + charAt(i)) % MOD

int prefix_hash(string s) {
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        ans = (((long long) ans * BASE) + s[i]) % MOD;
    }
    return ans;
}

// suffix hash:
// hash the string from the end of the string to the beginning of the string
//
// (charAt(i) * BASE^(length(i + 1)) + H(i + 1)) % MOD
//
// length(x): length_of_string - x - 1 (assuming it is 0-based)

int suffix_hash(string s) {
    int ans = 0;
    int base = 1;
    for (int i = s.length() - 1; i >= 0; --i) {
        ans = (((long long) s[i] * base) + ans) % MOD;
        base = ((long long) base * BASE) % MOD;
    }
    return ans;
}

// int main() 
//
// cin >> s;
// cout << (prefix_hash(s) == suffix_hash(s)) << endl; 
