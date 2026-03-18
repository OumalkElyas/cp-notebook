template<typename T>
pair<vector<int>,int> compress(const vector<T> &val) {
    vector<T> v = val;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    vector<int> comp;
    for(const T &x : val) {
        comp.push_back(lower_bound(v.begin(),v.end(),x) - v.begin());
    }
    return {comp,int(v.size())};
}
