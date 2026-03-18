vector<int> Z(string s) {
    int n = int(s.length()),L = 1,R = 0;
    s += '#';
    vector<int> z(n);
    z[0] = n;
    for(int i = 1;i<n;++i) {
        z[i] =  max(0,min(R-i+1,z[i-L]));
        while(s[z[i]] == s[i + z[i]]) ++z[i];
        if(i+z[i]-1 > R) L = i,R = i + z[i]-1; 
    }
    return z;
}
