using int128 = __int128_t;

istream& operator>>(istream& is, int128& n) {
    string s; is >> s;
    n = 0;
    int i = 0;
    bool neg = (s[0] == '-');
    if (neg) i = 1;
    for (; i < s.length(); ++i) n = n * 10 + (s[i] - '0');
    if (neg) n = -n;
    return is;
}

ostream& operator<<(ostream& os, int128 n) {
    if (n == 0) return os << "0";
    if (n < 0) {
        os << '-';
        n = -n;
    }
    string s;
    while (n > 0) {
        s += (char)('0' + (n % 10));
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}
