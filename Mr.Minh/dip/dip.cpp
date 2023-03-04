#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "dip"
const int maxn = 1e5 + 5;

using namespace std;

int n, m, a[maxn], nex[maxn], now[maxn], len[maxn];
pii b[maxn];

void enter(){
    fi(i, 1, n){
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b + 1, b + n + 1);

    int id = 1;
    a[b[1].second] = 1;
    fi(i, 2, n){
        if (b[i].first != b[i - 1].first) id++;
        a[b[i].second] = id;
    }
}

void maximize(int& x, int y){
    if (x < y) x = y;
}

void jump(){
    fi(i, 1, n) now[i] = n + 1;
    nex[n + 1] = n + 1;
    len[n + 1] = 1e9;
    fid(i, n, 1){
        len[i] = min(len[i + 1] + 1, now[a[i]] - i);
        now[a[i]] = i;
        int j = i + 1;
        while (len[i] >= len[j]){
            j = nex[j];
        }
        nex[i] = j;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    enter();
    jump();
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        u++;
        v++;
        int res = 0;
        while (u <= v){
            maximize(res, min(len[u], v - u + 1));
            u = nex[u];
        }
        cout << res << '\n';
    }


}
