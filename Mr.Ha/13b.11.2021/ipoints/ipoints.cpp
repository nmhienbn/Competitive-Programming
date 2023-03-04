#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "ipoints"
const int maxn = 1005;
using namespace std;

int n, cnt[maxn][maxn], res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a += 500;
        b += 500;
        c += 500;
        d += 500;
        int gcd = __gcd(abs(a-c), abs(b-d));
        int d1 = (c-a)/gcd, d2 = (d-b)/gcd;
        fi(i, 0, gcd){
            cnt[a][b]++;
            a += d1;
            b += d2;
        }
    }
    fi(i, 0, 1000) fi(j, 0, 1000) res += cnt[i][j] > 0;
    cout << res;

}
