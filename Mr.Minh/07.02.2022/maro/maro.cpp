#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "maro"
const int maxn = 1 << 20, N = 20;
using namespace std;

int n, m, q;
int flip[N + 5];
ll f[N + 5][2];
pii a[maxn + 5];

struct node {
    int child[2];
    int deg;
} T[maxn * 20];
int cnt;

void add(int vt){
    int x = 0;
    fid(i, n - 1, 0){
        bool now = gb(vt, i);
        if (!T[x]. child[now]) T[x].child[now] = ++cnt;
        x = T[x].child[now];
        T[x].deg++;
    }
}

void xuly(int vt){
    int x = 0;
    fid(i, n - 1, 0){
        bool now = gb(vt, i);
        if (!T[x]. child[now]) T[x].child[now] = ++cnt;
        f[i][now ^ 1] += T[T[x].child[now ^ 1]].deg;
        x = T[x].child[now];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    m = (1 << n);
    fi(i, 0, m - 1){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + m, greater<pii>());
    int j = 0;
    fi(i, 0, m - 1){
        while (a[j].first != a[i].first){
            add(a[j].second);
            j++;
        }
        xuly(a[i].second);
    }
    cin >> q;
    while (q--){
        int x;
        ll res = 0;
        cin >> x;
        fi(i, 0, x - 1) flip[i] ^= 1;
        fi(i, 0, n - 1) res += f[i][flip[i]];
        cout << res << '\n';
    }
}
