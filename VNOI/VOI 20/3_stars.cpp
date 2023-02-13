#include <bits/stdc++.h>

using namespace std;
const int offset = 3e6 + 1;
#define TPoint pair<int, int> 
#define x first
#define y second
struct TSegment{
    int x, l, r, typ;
    bool operator < (const TSegment &other) {
        return x < other.x;
    }
};
struct TNode{
    int val, cntCover;
} st[offset << 4];
vector<TSegment> Seg;
void Rotate(vector<TPoint> &P) {
    //rotate (x, y) with angle = a
    //x' = x * cos(a) - y * sin(a)
    //y' = x * sin(a) + y * cos(a)
    //a = 270
    //cos(a) = 0, sin(a) = -1)
    //x' = y
    //y' = -x
    TPoint F = P[0];
    for (int i = 1; i < P.size(); ++i) {
        P[i].x -= F.x;
        P[i].y -= F.y;
        P[i] = {P[i].y, -P[i].x};
        P[i].x += F.x;
        P[i].y += F.y;
    }
}
#define ADD 1
#define REMOVE -1
void Split(int L, int R, vector<pair<int, int> > &ans, const set<int> &myset) {
    assert(L != R);
    auto it = myset.upper_bound(L);
    int last = L;
    while (*it != R) {
        ans.push_back({last, *it});
        last = *it;
        ++it;
    }
    ans.push_back({last, R});
}
vector<int> adj[105];
map<pair<TPoint, TPoint>, int> SIGN;
void GetSign(vector<TPoint> &P) {
    #define Ttmp tuple<int, int, int> 
    vector<Ttmp> Q(P.size());
    //meo meo meo
    for (int i = 0; i < Q.size(); ++i) {
        Q[i] = make_tuple(P[i].x, P[i].y, i);
        adj[i].clear();
    }
    sort(Q.begin(), Q.end());
    for (int i = 0; i < Q.size(); i += 2) {
        int u = get<2>(Q[i]);
        int v = get<2>(Q[i + 1]);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = get<2> (Q[0]);
    // meo meomeo
    for (int i = 0; i < Q.size(); ++i) {
        Q[i] = make_tuple(P[i].y, P[i].x, i);
    }
    sort(Q.begin(), Q.end());
    for (int i = 0; i < Q.size(); i += 2) {
        int u = get<2>(Q[i]);
        int v = get<2>(Q[i + 1]);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < Q.size(); ++i) 
        assert(adj[i].size() == 2);
    SIGN.clear();
    int u = root;
    int pre = -1;
    do {
        int nxt = -1;
        for (int v : adj[u]) if (v != pre) {
            nxt = v;
            break;
        }
        int typ = REMOVE;
        if (P[u].y < P[nxt].y) typ = ADD;
        SIGN[{P[u], P[nxt]}] = typ;
        SIGN[{P[nxt], P[u]}] = typ;
        pre = u;
        u = nxt;
        //infinity loop
        assert(SIGN.size() <= P.size() * 2); 

    } while (u != root);
}
void AddSegment(vector<TPoint> &P) {
    sort(P.begin(), P.end());
    GetSign(P);
    set<int> myset;
    for (TPoint p : P) {
        myset.insert(p.y);
    }

    for (int i = 0; i < P.size(); i += 2) {
        assert(P[i].x == P[i + 1].x);
        assert(P[i].y < P[i + 1].y);
        vector<pair<int, int> > minisize;
        Split(P[i].y, P[i + 1].y, minisize, myset);
        int sign = SIGN[{P[i], P[i + 1]}];
        // cerr << P[i].x << ' '  << P[i].y << ' ' << P[i + 1].y << ' ' << sign << endl;
        if (sign == ADD) {
            for (pair<int, int> s : minisize)
                Seg.push_back({P[i].x, s.x, s.y - 1, ADD});
        }
        else {
            for (pair<int, int> s : minisize)
                Seg.push_back({P[i].x, s.x, s.y - 1, REMOVE});
        }
    }
}
void Update(int id, int l, int r, int u, int v, int typ) {
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
        if (typ == ADD) {
            ++st[id].cntCover;
            st[id].val = r - l + 1;
        }
        else {
            --st[id].cntCover;
            if (st[id].cntCover == 0) {
                if (l == r) st[id].val = 0;
                else st[id].val = st[id << 1].val + st[id << 1 | 1].val;
            }
        }
        return;
    }
    int mid = l + r >> 1;
    Update(id << 1, l, mid, u, v, typ);
    Update(id << 1 | 1, mid + 1, r, u, v, typ);
    if (st[id].cntCover == 0)
        st[id].val = st[id << 1].val + st[id << 1 | 1].val;
}
void Area() {
    #define N 6e6 + 1
    sort(Seg.begin(), Seg.end());
    for (auto &x: Seg) {
        x.l += offset;
        x.r += offset;
    }
    Update(1, 1, N, Seg[0].l, Seg[0].r, Seg[0].typ);
    long long res = 0;
    for (int i = 1; i < Seg.size(); ++i) {
        res += 1ll * (Seg[i].x - Seg[i - 1].x) * st[1].val;
        Update(1, 1, N, Seg[i].l, Seg[i].r, Seg[i].typ);
    }
    cout << res << endl;
}
int main() {
#ifdef LDT
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else 
    freopen("stars.inp", "r", stdin);
    freopen("stars.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        int m, deg;
        cin >> m >> deg;
        deg = deg * d % 360;
        vector<TPoint> P(m);
        for (TPoint &p : P) {
            cin >> p.x >> p.y;
        }
        for (int cur = 90; cur <= deg; cur += 90)
            Rotate(P);
        AddSegment(P);
    }
    Area();
    return 0;
}
1
