#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "chip"
const int maxn = 505;
using namespace std;

int n, m, h;
int a[maxn], b[maxn], d[maxn][maxn], f[maxn], vt[maxn];
char t[] = {'*', '+', '|'};

bool cmp(int i, int j){
    return b[i] == b[j] ? i > j : b[i] < b[j];
}

void except(){
    cout << "inconsistent";
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n >> h;
    fi(i, 1, m) cin >> a[i];
    fi(i, 1, n) cin >> b[i];
    fi(i, 1, n) vt[i] = i;
    fi(i, 1, m){
        int j;
        sort(vt + 1, vt + n + 1, cmp);
        fi(rep, 1, n){
            j = vt[rep];
            if (d[i][j] == 0){
                if (a[i] > 0) a[i]--;
                else {
                    if (b[j] == 0 || i > m - h + 1) except();
                    b[j]--;
                    d[i][j] = 1;
                    fi(k, i + 1, i + h - 2){
                        d[k][j] = 2;
                    }
                    d[i + h - 1][j] = 1;
                }
            }
        }
        if (a[i] > 0) except();
    }
    fi(i, 1, n){
        if (b[i] > 0) except();
    }
    fi(i, 1, m){
        fi(j, 1, n) cout << t[d[i][j]];
        cout << '\n';
    }
}
