#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "mthcn"
const int maxn = 1005, maxm = 2005;
using namespace std;

int n, m, p[maxm], nex[maxn], b[maxn], res;
ll a[maxn][maxn];
int st[maxn], top;
vector<ll> primes;

bool scp(ll a){
    int i = sqrt(a);
    while (1ll * i * i <= a){
        if (a == 1ll * i * i) return true;
        i++;
    }
    return false;
}

void Erathosenes(){
    fi(i, 2, 43) if (!p[i]){
        for (int j = i * i; j <= maxm - 5; j += i){
            p[j] = 1;
        }
    }
    fi(i, 2, maxm - 5) if (!p[i]){
        primes.pb(1ll * i * i * i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    Erathosenes();
    cin >> n >> m;
    fi(i, 1, m){
        int x, u, v, k;
        cin >> x >> u >> v >> k;
        a[x][u] += k;
        a[x][v + 1] -= k;
    }
    fi(i, 1, n){
        fi(j, 1, n) a[i][j] += a[i][j - 1];
    }
    //fi(i, 1, n) {fi(j, 1, n) cout << a[i][j] << ' '; cout << endl;}
    fi(i, 1, n) fi(j, 1, n){
        if (scp(a[i][j])) a[i][j] = 1;
        else {
            int y = *lower_bound(primes.begin(), primes.end(), a[i][j]);
            if (y == a[i][j]) a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    //fi(i, 1, n) {fi(j, 1, n) cout << b[i][j]; cout << endl;}
    fi(i, 1, n){
        fi(j, 1, n){
            if (a[i][j]) b[j]++;
            else b[j] = 0;
        }
        top = 0, st[top] = n + 1;
        fid(j, n, 1){
            while (top > 0 && b[j] <= b[st[top]]) top--;
            nex[j] = st[top];
            st[++top] = j;
        }
        top = 0, st[top] = 0;
        fi(j, 1, n){
            while (top > 0 && b[j] <= b[st[top]]) top--;
            res = max(res, b[j] * (nex[j] - st[top] - 1));
            st[++top] = j;
        }
    }
    cout << res;
}
