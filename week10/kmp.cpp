int KMP(string s1, string s2) {
    // find the occurrence of s2 in s1
    int len1 = s1.length(), len2 = s2.length();

    int f[MAXN];
    
    int occurrence = 0;

    f[0] = 0;
    for (int i = 1; i < len2; ++i) {
        int x = f[i - 1];
        while (x > 0 && s2[x] != s2[i])
            x = f[x - 1];
        if (s2[x] == s2[i]) f[i] = x + 1;
        else f[i] = 0;
    }

    int j = 0;
    for (int i = 0; i < len1; ++i) {
        while (j > 0 && s1[i] != s2[j])
            j = f[j - 1];
        if (s1[i] == s2[j]) ++j;
        if (j == len2) {
            // s2 appears at position i - len2 + 1
            ++occurrence;
            j = f[j - 1];
        }
    }
    return occurrence;
}
