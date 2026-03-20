vector<P> convexhull(const vector<P> &p) {
    vector<P> pts = p;
    int n = int(pts.size());
    sort(pts.begin(),pts.end());
    vector<P> up,down;
    up.push_back(pts[0]); up.push_back(pts[1]);
    for(int i = 2;i<n;++i) {
        int m = int(up.size());
        while(m > 1 && P::cross(up[m-2],pts[i],up[m-1]) < 0) {
            up.pop_back();
            m = int(up.size());
        }
        up.push_back(pts[i]);
    }

    down.push_back(pts[0]); down.push_back(pts[1]);
    for(int i = 2;i<n;++i) {
        int m = int(down.size());
        while(int(down.size()) > 1 && P::cross(down[m-2],pts[i],down[m-1]) > 0) { 
            down.pop_back();
            m = int(down.size());
        }
        down.push_back(pts[i]);
    }
    up.insert(up.end(),down.rbegin()+1,down.rend()-1); 
    return up;
}
