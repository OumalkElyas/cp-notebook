template<typename T = long long>
struct Pt{
    T x,y;
    Pt() : x(0),y(0) {};
    Pt(T x,T y) : x(x),y(y) {};

    Pt operator +(const Pt &p) const { return Pt{x + p.x,y + p.y}; }
    Pt operator -(const Pt &p) const { return Pt{x - p.x,y - p.y}; }
    bool operator <(const Pt &p) const { return make_pair(x,y) < make_pair(p.x,p.y); }
    bool operator ==(const Pt &p) const { return p.x == x && y == p.y; }
    T operator *(const Pt &p) const { return x * p.y - y * p.x; }
    T operator ^(const Pt &p) const { return x * p.x + y * p.y; }
    void read() { cin >> x >> y; }
    static double dist(const Pt &u,const Pt &v) { return hypot(u.x - v.x, u.y - v.y); }
    static T cross(const Pt &u,const Pt &v,const Pt &w) { return (v - u) * (w - u); }
    // uv -> (v.x - u.x,v.y - u.y)
    // uw -> (w.x - u.x,w.y - u.y)
};
using P = Pt<>;
