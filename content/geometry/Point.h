template<typename T>
struct P{
    T x,y;
    P() : x(0),y(0) {};
    P(T x,T y) : x(x),y(y) {};
    void operator =(const P &p) { x = p.x; y = p.y; }
    void read() { cin >> x >> y; }
    static double dist(const P &u,const P &v) { return hypot(u.x - v.x, u.y - v.y); }
    static T cross(const P &u,const P &v,const P &w) { return (v.x - u.x) * (w.y - u.y) - (w.x - u.x) * (v.y - u.y); }
    // uv -> (v.x - u.x,v.y - u.y)
    // uw -> (w.x - u.x,w.y - u.y)
};
