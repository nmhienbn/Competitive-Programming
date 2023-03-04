#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define gb(x, i) (((x) >> (i)) & 1)
#define pb push_back
#define NunuAndWillump "pin"
const int maxn = 5e4+5;
using namespace std;

int n, d;
ll res;
int a[16][maxn];
char b[4];
int ma[255], base;
int f[5];
int C[5][5];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    fi(i, '0', '9') ma[i] = base++;
    fi(i, 'a', 'z') ma[i] = base++;
    cin >> n >> d;
    fi(i, 1, n){
        fi(j, 0, 3) cin >> b[j];
        fi(x, 1, 15){
            fi(j, 0, 3) if (gb(x, j)){
                a[x][i] = a[x][i] * base + ma[b[j]];
            }
        }
    }
    fi(i, 1, 15) sort(a[i] + 1, a[i] + n + 1);
    fi(i, 1, 15){
        int k = 4 - __builtin_popcount(i);
        a[i][0] = -1;
        int cnt = 0;
        fi(j, 1, n){
            if (a[i][j] != a[i][j - 1]) cnt = 1;
            else {
                f[k] += cnt;
                cnt++;
            }
        }
    }
    fi(i, 0, 4){
        C[i][0] = 1;
        fi(j, 1, i){
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    //f[i] la so cap khac nhau o toi da i vi tri
    f[4] = 1ll * n * (n - 1) / 2;
    fi(i, 1, d){
        fi(j, 0, i - 1){
            f[i] -= f[j] * C[4 - j][4 - i];
        }
    }
//    f[1] -= f[0] * 4;
//    f[2] -= f[1] * 3 + f[0] * 6;
//    f[3] -= f[2] * 2 + f[1] * 3 + f[0] * 4;
//    f[4] -= f[3] + f[2] + f[1] + f[0];
    cout << f[d];
}
