int lead[?]; // initialise
int find(int x) { return lead[x] == x ? x : lead[x] = find(lead[x]); }
bool add(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    lead[y] = x;
    return true;
}
// Init: for(int i = 0; i < n; i++) lead[i] = i;
