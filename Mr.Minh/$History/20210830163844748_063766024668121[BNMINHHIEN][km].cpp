#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "km"
const int maxk = 5005, maxn = 105;

using namespace std;

struct dl {
    int x, y, z, id;
    bool operator < (const dl& x) const {
        return y < x.y;
    }
};

int n, m, k, t, b[maxn][maxn], L[maxn],
    c[maxn][maxn], res, id, pre[maxn], re[maxn];
dl a[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, k){
        cin >> a[i].x >> a[i].y >> a[i].z; //c.h, t.g, g.t
        a[i].id = i;
    }
    a[0] = {n+1, 0, 0, 0};
    a[k+1] = {n+1, m, 0, k+1};
    sort(a+1, a+k+1);
    fi(i, 1, n+1){
        fi(j, 1, n+1){
            cin >> b[i][j]; //tg
        }
    }
    fi(i, 1, n+1){
        fi(j, 1, n+1){
            cin >> c[i][j]; //chi phi
        }
    }
    fi(i, 1, k+1){
        //L[i] = -1e9;
        fi(j, 0, i-1){
            if (a[j].y + b[j][i] <= a[i].y){
                L[i] = max(L[i], L[j] + a[i].z - c[a[j].x][a[i].x]);
                pre[i] = j;
            }
        }
    }
    cout << L[k+1] << '\n';
    int i = k+1;
    while (i > 0){
        re[++t] = a[i].id;
        i = pre[i];
    }
    fid(i, t, 2){
        cout << re[i] << ' ';
    }
}
