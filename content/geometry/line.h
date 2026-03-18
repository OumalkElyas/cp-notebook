struct line {
    Point<ll> p1,p2;
    line() {};
    line(const Point<ll> &p1,const Point<ll> &p2) : p1(p1),p2(p2) {};
    void read() { cin >> p1.x >> p1.y >> p2.x >> p2.y; }
    int intersect(const line &l) {
        ll cross[4];
        cross[0] = Point<ll>::cross(p1,p2,l.p1),cross[1] = Point<ll>::cross(p1,p2,l.p2);
        cross[2] = Point<ll>::cross(l.p1,l.p2,p1),cross[3] = Point<ll>::cross(l.p1,l.p2,p2);
        int ans = (cross[0] == 0 && belong(*this,l.p1))
            || (cross[1] == 0 && belong(*this,l.p2))
            || (cross[2] == 0 && belong(l,this->p1))
            || (cross[3] == 0 && belong(l,this->p2));
        ans += ((cross[0] > 0 && cross[1] < 0) || (cross[0] < 0 && cross[1] > 0)) 
            && ((cross[2] > 0 && cross[3] < 0) || (cross[2] < 0 && cross[3] > 0));
        return ans;
    }
private:
    bool belong(const line &l,const Point<ll> &p) {
        auto p1 = l.p1,p2 = l.p2;
        return max(p1.x,p2.x) >= p.x
            && max(p1.y,p2.y) >= p.y
            && min(p1.x,p2.x) <= p.x
            && min(p1.y,p2.y) <= p.y;
    }
};
