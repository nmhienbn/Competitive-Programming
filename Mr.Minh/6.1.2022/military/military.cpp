    #include <bits/stdc++.h>

    using namespace std;

    #define taskName "TRILAND"
    #define odd(a) ((a) % 2)
    #define sz(a) int(a.size())

    typedef long long ll;

    struct TPoint { ll x, y; };

    const int maxN = 50005;

    int n;
    ll ans = 0;
    TPoint p[maxN];
    vector<TPoint> h;

    template <typename T>
    void maximize (T &a, T b) { if (a < b) a = b; }

    ll area(TPoint a, TPoint b, TPoint c)
    {
        return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    }

    bool isCW(TPoint a, TPoint b, TPoint c) { return area(a, b, c) < 0; }

    bool isCCW(TPoint a, TPoint b, TPoint c) { return area(a, b, c) > 0; }

    void convexHull(vector<TPoint> &a)
    {
        vector<TPoint> u, d;
        u.push_back(p[1]); d.push_back(p[1]);
        for (int i = 1; i <= n; ++i)
        {
            if (i == n || isCW(p[1], p[i], p[n]))
            {
                while (sz(u) > 1 && !isCW(u[sz(u) - 2], u[sz(u) - 1], p[i])) u.pop_back();
                u.push_back(p[i]);
            }
            if (i == n || isCCW(p[1], p[i], p[n]))
            {
                while (sz(d) > 1 && !isCCW(d[sz(d) - 2], d[sz(d) - 1], p[i])) d.pop_back();
                d.push_back(p[i]);
            }
        }
        for (int i = 0; i < sz(u); ++i) a.push_back(u[i]);
        for (int i = sz(d) - 2; i > 0; --i) a.push_back(d[i]);
    }

    void solve()
    {
        for (int i = 0; i < sz(h) - 2; ++i)
        {
            int k = i + 2;
            for (int j = i + 1; j < sz(h) - 1; ++j)
            {
                if (j >= k) k = j + 1;
                ll cur = abs(area(h[i], h[j], h[k]));
                while (k < sz(h) - 1)
                {
                    ll tmp = abs(area(h[i], h[j], h[k + 1]));
                    if (cur < tmp) cur = tmp, ++k;
                    else break;
                }
                maximize(ans, cur);
            }
        }
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
            cin >> n;
            ans = 0;
            h.clear();
            for (int i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;
            sort(p + 1, p + n + 1, [](TPoint a, TPoint b)
            {
                if (a.x == b.x) return a.y < b.y;
                return a.x < b.x;
            });
            convexHull(h);
            solve();
            cout << (ans >> 1LL) << (odd(ans) ? ".50\n" : ".00\n");
        return 0;
    }
