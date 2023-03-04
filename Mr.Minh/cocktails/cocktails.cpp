#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "cocktails"
const int maxn = 2e5 + 5, maxm = 3005, INF = 1e9;
using namespace std;

int n, q;
int ma[maxn], id;
int a[maxm][maxm];
bool ok = 1;

void minimize(int& x, int y){
    if (x > y) x = y;
}
void maximize(int& x, int y){
    if (x < y) x = y;
}

void sub1(){
    while (q--){
        int typ, l, r, x;
        cin >> typ >> l >> r;
        if (typ == 1){
            cin >> x;
            if (!ma[x]) ma[x] = ++id;
            x = ma[x];
            fi(i, l, r) a[i][x]++;
        }
        else {
            bool flag = 1;
            fi(k, 1, id){
                fi(i, l, r){
                    fi(j, i + 1, r){
                        if (a[i][k] != a[j][k]){
                            flag = 0;
                            goto print;
                        }
                    }
                }
            }
            print :
            cout << flag << '\n';
        }
    }
    exit(0);
}

struct dl {
    int f, s, t;
};

dl st[maxn * 4];

void point1(int id, int val){
    st[id] = {val, val, val};
}
void point2(int id, int val){
    st[id].f += val;
    st[id].s += val;
    st[id].t += val;
}
void lazy1(int id){
    fi(j, id * 2, id * 2 + 1){
        st[j].f = st[id].t;
        st[j].s = st[id].t;
        st[j].t = st[id].t;
    }
    st[id].t = 0;
}
void lazy2(int id){
    fi(j, id * 2, id * 2 + 1){
        st[j].f += st[id].t;
        st[j].s += st[id].t;
        st[j].t += st[id].t;
    }
    st[id].t = 0;
}

dl merge(dl a, dl b){
    return {min(a.f, b.f), max(a.s, b.s), 0};
}

void update(int id, int l, int r, int d, int c, int val, bool typ){
    if (r < d || l > c || d > c) return;
    if (d <= l && r <= c){
        if (typ) point2(id, val);
        else point1(id, val);
        return;
    }
    int m = (l + r) >> 1;
    if (st[id].t){
        if (typ) lazy2(id);
        else lazy1(id);
    }
    update(id * 2, l, m, d, c, val, typ);
    update(id * 2 + 1, m + 1, r, d, c, val, typ);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

dl get(int id, int l, int r, int d, int c, bool typ){
    if (r < d || l > c || d > c) return {INF, -INF, 0};
    if (d <= l && r <= c) return st[id];
    int m = (l + r) >> 1;
    if (st[id].t){
        if (typ) lazy2(id);
        else lazy1(id);
    }
    return merge(get(id * 2, l, m, d, c, typ),
                 get(id * 2 + 1, m + 1, r, d, c, typ));
}

struct query {
    int typ, l, r, x;
} E[maxn];

void sub45(){
    fi(i, 1, q){
        int typ, l, r, x = 0;
        cin >> typ >> l >> r;
        if (typ == 1){
            cin >> x;
            if (x != 1) ok = 0;
        }
        E[i] = {typ, l, r, x};
    }
    fi(i, 1, q){
        int typ, l, r;
        typ = E[i].typ;
        l = E[i].l;
        r = E[i].r;
        if (typ == 1){
            update(1, 1, n, l, r, E[i].x, ok);
        }
        else {
            dl A = get(1, 1, n, l, r, ok);
            cout << (A.f == A.s) << '\n';
        }
    }
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q;
    if (n <= 1000) sub1();
    sub45();
}
