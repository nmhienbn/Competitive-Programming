#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "chnrest"
const int maxm = 35, maxn = 15;

using namespace std;

int m, n, a[maxm];
int mu[maxn], F[maxm][60000];
bool b[maxm][maxn];

void nhap(){
    mu[0] = 1;
    fi(i, 1, 10){
        mu[i] = 3 * mu[i - 1];
    }
    cin >> m >> n;
    fi(i, 0, m-1) cin >> a[i];
    cin.ignore();
    fi(i, 0, n-1){
        string s;
        getline(cin, s);
        istringstream iss(s);
        int t;
        while (iss >> t){
            b[t-1][i] = 1;
        }
    }
    memset(F, -1, sizeof(F));
}

int calc(int u, int tt) {
    if(u == m) {
        if(tt == mu[n] - 1) return 0;
        else return 1e9;
    }
    if(F[u][tt] != -1) return F[u][tt];
    int res = calc(u + 1, tt);
    bool flag = 1;
    fi(i, 0, n-1){
        if(b[u][i] && tt / mu[i] % 3 == 2) {
            flag = 0;
            break;
        }
    }
    if (flag){
        int nn = tt;
        fi(i, 0, n-1){
            if(b[u][i]){
                nn += mu[i];
            }
        }
        res = min(res, a[u] + calc(u + 1, nn));
    }
    return F[u][tt] = res;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    nhap();
    int best = calc(0, 0);
    cout << (best < 1e9 ? best : -1);
}
