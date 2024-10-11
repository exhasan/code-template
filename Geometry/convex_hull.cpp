#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<vector>
#define int long long int
/*
bool Line_Segment_Intersection(P p1,P p2,P p3,P p4)
check_p3onp1andp2sigment(P p1,P p2,P p3)
int polygonarea(vector<P>vt)
int dot(P u,P v)
double pointvalue(P v)
double angleABC(P a,P b,P c)
P rotate(P a,double angle)
void pointinpolygon(vector<P>vt,P p1)
void polygonlatticePoints(vector<P>vt)
void segmentintersetpoint()
vector<P> convex_hall(vector<P>points)
int sgn(int val)
 bool pointInTriangle(P a,P b,P c,P point)
 bool check_if_point_belongs_to_the_convex_polygon(vector<P>points,P Poin)
*/
using namespace std;
struct P
{
    double  x,y;
    void read()
    {
        cin>>x>>y;
    }
    P operator - (const P& b) const
    {
        return P{x-b.x,y-b.y};
    }
    int operator *(const P& b) const
    {
        return x*b.y-y*b.x;
    }
    P operator + (const P &b ) const
    {
        return P{x+b.x,y+b.y};
    }
    int tringle(const P&b,const P&c) const
    {
        return (b-*this) * (c-*this);
    }
    bool operator <(const P& b) const
    {
        return make_pair(x,y)<make_pair(b.x,b.y);
    }
};

bool Line_Segment_Intersection(P p1,P p2,P p3,P p4)
{

    if((p2-p1)*( p4-p3)==0)
    {
        if(p1.tringle(p2,p3)!=0)
            return false;
        else
        {
            int f=0;
            for(int i=0; i<2; i++)
            {
                if(max(p1.x,p2.x)<min(p3.x,p4.x)|| max(p1.y,p2.y)<min(p3.y,p4.y))
                {
                    return false;
                }
                swap(p1,p3);
                swap(p2,p4);
            }
            return true;
        }
    }
    else
    {
        int f=0;
        for(int i=0; i<2; i++)
        {
            int a=(p2-p1)*(p3-p1);
            int b= (p2-p1)*(p4-p1);
            if((a<0&&b<0)||(a>0&&b>0))
            {
                return false;
            }
            swap(p1,p3);
            swap(p2,p4);
        }
        return true;
    }

}
bool check_p3onp1andp2sigment(P p1,P p2,P p3)
{
    if(p3.tringle(p1,p2)) return false;
    if(min(p1.x,p2.x)<=p3.x&&max(p1.x,p2.x)>=p3.x&&min(p1.y,p2.y)<=p3.y&&max(p1.y,p2.y)>=p3.y) return true;
    return false;
}
int polygonarea(vector<P>vt)
{
    int n=vt.size();
    pair<int,int>pr[n+2];
    for(int i=1; i<=n; i++) pr[i].first=vt[i-1].x,pr[i].second=vt[i-1].y;
    int ans = pr[n].first*pr[1].second-pr[n].second*pr[1].first;
    for(int i=1; i<n; i++)
    {
        ans=ans+pr[i].first*pr[i+1].second-pr[i].second*pr[i+1].first;
    }
    ans=abs(ans);
    return ans/2;

}
int dot(P u,P v)
{
    return u.x*v.x+u.y*v.y;
}
double pointvalue(P v)
{
    double p=sqrtl((v.x*1LL*v.x+v.y*1LL*v.y)*1LL);
    return p;
}
double redian(double angle)
{
    return (angle*acos(-1)/180.00);
}
double angleABC(P a,P b,P c)
{
    P u=a-b;
    P v=c-b;
    double ua=pointvalue(u);
    double va=pointvalue(v);
    double ang=(acos(dot(u,v)*1LL)/(ua*va*1LL));
    return ang;

}
P rotate( P a,double angle)
{
    P p;
    p.x= a.x*cos(redian(angle))-a.y*sin(redian(angle));
    p.y=a.y*cos(redian(angle))+a.x*sin(redian(angle));
    return p;
}
void pointinpolygon(vector<P>vt,P p1)//poligon and point
{
    P p2;
    p2.x=p1.x+1;
    p2.y=1e9+100;
    int cnt =0;
    int f=0;
    int n=vt.size();
    for(int i=0; i<n; i++)
    {
        if(i==n-1)
        {
            if(check_p3onp1andp2sigment(vt[n-1],vt[0],p1))
            {
                cout<<"BOUNDARY"<<endl;
                f=1;
            }
            if(Line_Segment_Intersection(vt[n-1],vt[0],p1,p2)) cnt++;
        }
        else
        {
            if(check_p3onp1andp2sigment(vt[i],vt[i+1],p1))
            {
                cout<<"BOUNDARY"<<endl;
                f=1;
            }
            if(Line_Segment_Intersection(vt[i],vt[i+1],p1,p2)) cnt++;
        }
        if(f) break;
    }
    if(f) return;
    if(cnt%2==0) cout<<"OUTSIDE"<<endl;
    else cout<<"INSIDE"<<endl;

}

void polygonlatticePoints(vector<P>vt)
{
    int n=vt.size();
    int ans =0;
    for(int i=0; i<n; i++)
    {
        if(i==n-1)
        {
            int x= vt[i].x-vt[0].x;
            int y = vt[i].y-vt[0].y;
            int gcd=__gcd(abs(x),abs(y));
            ans=ans+gcd;

        }
        else
        {
            int x=vt[i].x-vt[i+1].x;
            int y = vt[i].y-vt[i+1].y;
            int gcd=__gcd(abs(x),abs(y));
            ans=ans+gcd;
        }
    }
    int area = polygonarea(vt);
    int ans2=(2*area-ans+2)/2;//interior= (2*area-boundary+2)/2
    cout<<ans2<<' '<<ans<<endl;
}

const double EPS = 1E-9;

struct pt
{
    long  double x, y;

    bool operator<(const pt& p) const
    {
        return x < p.x - EPS || (abs(x - p.x) < EPS && y < p.y - EPS);
    }
};

struct line
{
    long double a, b, c;

    line() {}
    line(pt p, pt q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }

    void norm()
    {
        long   double z = sqrt(a * a + b * b);
        if (abs(z) > EPS)
            a /= z, b /= z, c /= z;
    }

    long  double dist(pt p) const
    {
        return a * p.x + b * p.y + c;
    }
};

long double det(long double a,long  double b,long  double c,long  double d)
{
    return a * d - b * c;
}

inline bool betw(long double l,long double r,long  double x)
{
    return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}

inline bool intersect_1d(long double a,long  double b,long  double c,long  double d)
{
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d) + EPS;
}
bool intersect(pt a, pt b, pt c, pt d, pt& left, pt& right)
{
    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
        return false;
    line m(a, b);
    line n(c, d);
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS)
    {
        if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS)
            return false;
        if (b < a)
            swap(a, b);
        if (d < c)
            swap(c, d);
        left = max(a, c);
        right = min(b, d);
        return true;
    }
    else
    {
        left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
        left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
        return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
               betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
    }
}
void segmentintersetpoint()
{
    pt ans1,ans2;
    long double inff=1e9+2;
    ans1.x=inff;
    ans1.y=inff;
    ans2.x=inff;
    ans2.y=inff;
    pt p1,p2,p3,p4;
    cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y;
    int x=intersect(p1,p2,p3,p4,ans1,ans2);
    if(x==0)
    {
        cout<<"none"<<endl;
        return ;
    }
    if(ans1.x==-0.00) ans1.x=abs(ans1.x);
    if(ans1.y==-0.00) ans1.y=abs(ans1.y);
    if(ans2.x==-0.00) ans2.x=abs(ans2.x);
    if(ans2.y==-0.00) ans2.y=abs(ans2.y);
    if(ans1.x==ans2.x&&ans1.y==ans2.y) cout<<ans1.x<<' '<<ans1.y<<endl;
    else
    {
        if(ans1.x<ans2.x) cout<<ans1.x<<' '<<ans1.y<<' '<<ans2.x<<' '<<ans2.y<<endl;
        else if(ans1.x>ans2.x) cout<<ans2.x<<' '<<ans2.y<<' '<<ans1.x<<' '<<ans1.y<<endl;
        else if(ans1.y<ans2.y)  cout<<ans1.x<<' '<<ans1.y<<' '<<ans2.x<<' '<<ans2.y<<endl;
        else cout<<ans2.x<<' '<<ans2.y<<' '<<ans1.x<<' '<<ans1.y<<endl;
    }
}
vector<P> convex_hall(vector<P>points)
{
    sort(points.begin(),points.end());
    vector<P>hall;
    for(int i=0; i<2; i++)
    {
        int sz=hall.size();
        for(auto c:points)
        { 
            while(hall.size()-sz>=2)
            {
                P a=hall.end()[-2];
                P b=hall.end()[-1];
                if(a.tringle(b,c)<=0) break;
                hall.pop_back();
            }
            hall.push_back(c);
        }
        hall.pop_back();
        reverse(points.begin(),points.end());
    }
    return hall;
}
int sgn(int val)
{
    return val>0?1:(val==0?0:-1);
}
 bool pointInTriangle(P a,P b,P c,P point)
 {
     int s1=abs(a.tringle(b,c));
     int s2=abs(point.tringle(a,b))+abs(point.tringle(b,c))+abs(point.tringle(c,a));
     return s1==s2;
 }
int hall_sz;
vector<P>seq;
 void init(vector<P>points)
 {
    seq.resize(hall_sz-1);
    for (int i = 0; i < points.size() - 1; i++)
    {
        seq[i] = points[i + 1] - points[0];
    }
 }
int check_if_point_belongs_to_the_convex_polygon(P Poin,P k)
{
    int n = seq.size();
    Poin = Poin - k;
    if (seq[0] * (Poin) != 0 && sgn(seq[0] * (Poin)) != sgn(seq[0] * (seq[n - 1])))
        return false;
    if (seq[n - 1] * (Poin) != 0 && sgn(seq[n - 1] * (Poin)) != sgn(seq[n - 1] * (seq[0])))
        return false;


    int l = 0;
    int r = n - 1;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        int pos = mid;
        if (seq[pos] * (Poin) >= 0)
            r = mid;
        else
            l = mid;
    }
    int pos = l;
    P p;
    p.x = 0, p.y = 0;
    if(check_p3onp1andp2sigment(p,seq[0],Poin)) return 2;
    if(check_p3onp1andp2sigment(p,seq[n-1],Poin)) return 2;
    int x = pointInTriangle(seq[pos], seq[pos + 1], p, Poin);
    if (x == 0)
        return 0;
    else
    {
        if (check_p3onp1andp2sigment(seq[pos], seq[pos + 1], Poin))
            return 2;
        return 1;
    }
}
int32_t main()
{
    int n;
   cout<<fixed<<setprecision(8);
    P a;
     double angle;
     cin>>angle;
    a.read();
     P b;
     b=rotate(a,angle);
     cout<<b.x<<' '<<b.y<<endl;
     return 0;
    cin >> n;
    int q, k;
    vector<P> point;
    set<P>st;
    for (int i = 0; i < n; i++)
    {
         P p;
         p.read();
         st.insert(p);
    }
    for(auto x: st) point.push_back(x);
    vector<P> points = convex_hall(point);
    hall_sz=points.size();
    init(points);

    int cnt = 0;
    cin >> q;
    while (q--)
    {
        P p;
        p.read();
        int x =check_if_point_belongs_to_the_convex_polygon(p,points[0]);
        if (x == 1)
            cout << "IN" << endl;
        if (x == 2)
            cout << "ON" << endl;
        if (x == 0)
            cout << "OUT" << endl;
    }
}