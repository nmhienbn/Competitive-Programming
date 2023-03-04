#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "colorec"
const int maxn = 1e5 + 5;
using namespace std;

int n;
int a[405][405], f[20];
ll res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int x, y, c;
        cin >> x >> y >> c;
        a[x + 200][y + 200] = 1 << (c - 1);
    }
    fi(i, 1, 400) fi(j, 0, i - 1){
        fi(k, 0, 15) f[k] = 0;
        fi(k, 0, 400){
            int u = a[i][k] | a[j][k];
            res += f[15 ^ u];
            f[u]++;
        }
    }
    cout << res;
}
