#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <ll, int>
#define pb push_back
#define Irelia "clocks"
const int maxn = 1e6+5;
using namespace std;

struct da {
    int a[4], w;
};

int k, id, bd, mu[20], kt;
da g[20];
ll L[maxn];
priority_queue<pii, vector<pii>, greater<pii>> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    mu[0] = 1;
    fi(i, 1, 10) mu[i] = mu[i-1] * 4;
    fi(i, 1, 9){
        int x;
        cin >> x;
        bd += (x/3-1) * mu[i-1];
        kt = kt * 4 + 3;
    }
    fi(i, 0, maxn-1) L[i] = 1e18;
    L[bd] = 0;
    cin >> k;
    fi(i, 1, k){
        fi(j, 0, 3) cin >> g[i].a[j];
        cin >> g[i].w;
    }
    q.push({0, bd});
    while (q.size()){
        int u = q.top().second;
        if (u == kt){
            cout << L[u];
            return 0;
        }
        q.pop();
        fi(i, 1, k){
            int v = u;
            fi(j, 0, 3){
                int vt = g[i].a[j];
                int tg = u / mu[vt-1] % 4;
                if (tg > 0) v -= mu[vt-1];
                else v += mu[vt-1] * 3;
            }
            if (L[v] > L[u] + g[i].w){
                L[v] = L[u] + g[i].w;
                q.push({L[v], v});
            }
        }
    }
    cout << -1;
}
