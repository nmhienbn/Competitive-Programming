#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "tower"
const int maxn = 1e6+5;

using namespace std;

struct dl {
    int a, b, h, id;
    bool operator < (const dl& x) const{
        return a > x.a;
    }
};

int n, bit[maxn], pre[maxn], id, re[maxn], m;
ll L[maxn], maxl[maxn];
dl a[maxn];

void update(int x, int vt){
    while (x > 0){
        if (L[vt] > L[bit[x]]) bit[x] = vt;
        x -= x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x <= 1e6){
        if (L[bit[x]] > L[ans]) ans = bit[x];
        x += x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].a >> a[i].b >> a[i].h;
        a[i].id = i;
    }
    sort(a+1, a+n+1);
    a[0] = {(int)1e9, (int)1e9, 0, 0};
    fi(i, 1, n){
        int vt = get(a[i].b);
        L[i] = L[vt] + a[i].h;
        pre[i] = vt;
        update(a[i].a, i);
        if (L[i] > L[id]) id = i;
    }
    cout << L[id] << '\n';
    //fi(i, 1, n) cout << pre[i] << ' ';
    while (id > 0){
        re[++m] = a[id].id;
        id = pre[id];
    }
    fid(i, m, 1) cout << re[i] << ' ';
}
