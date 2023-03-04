#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "shelves"
const int maxn = 2e5 + 5;

using namespace std;

struct dl {
    int f, s, t;
    bool operator < (const dl& x) const {
        return s < x.s;
    }
};

int n, m, k, f[maxn], pre[maxn];
int n1, m1;
bool kt[maxn];
dl a[maxn];
pii L[maxn];

void nhap(){
    int vt = 0;
    fi(i, 1, n){
        int x;
        cin >> x;
        a[i].f = vt;
        a[i].s = vt + x;
        vt += x;
        a[i].t = i;
    }
    vt = 0;
    fi(i, n + 1, n + m){
        int x;
        cin >> x;
        a[i].f = vt;
        a[i].s = vt + x;
        vt += x;
        a[i].t = i;
    }
    k = n + m;
    sort(a + 1, a + k + 1);
}

void QHD(){
    fi(i, 1, k){
        int d = 0, c = i - 1;
        while (d <= c){
            int g = (d + c) >> 1;
            if (a[g].s <= a[i].f) d = g + 1;
            else c = g - 1;
        }
        f[i] = L[c].first + 1;
        pre[i] = L[c].second;
        L[i] = L[i - 1];
        if (f[i] > L[i].first){
            L[i] = {f[i], i};
        }
    }
}

void trace(){
    int last = L[k].second;
    fi(i, 1, L[k].first){
        if (a[last].t <= n) n1++;
        else m1++;
        kt[a[last].t] = 1;
        last = pre[last];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    nhap();
    QHD();
    trace();
    cout << n1 << ' ' << m1 << '\n';
    fi(i, 1, n) if (kt[i]) cout << i << ' ';
    cout << '\n';
    fi(i, n + 1, n + m) if (kt[i]) cout << i - n << ' ';
}
