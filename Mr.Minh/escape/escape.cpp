#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define getbit(x, t) (((x) >> (t)) & 1)
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "escape"
const int maxn = 20;

using namespace std;

int a[maxn][10], sum[10], res = 0;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    int n;
    cin >> n;
    fi(i, 0, n-1){
        int x;
        cin >> x;
        fid(j, 8, 1){
            a[i][j] = x%10;
            x /= 10;
        }
    }
    int th = (1 << n) - 1;
    fi(x, 1, th){
        int ss = __builtin_popcount(x);
        bool flag = 1;
        if (ss <= res) continue;
        fi(i, 1, 8) sum[i] = 0;
        fi(i, 0, n-1){
            if (getbit(x, i)){
                fid(j, 8, 1){
                    sum[j] += a[i][j];
                    if (sum[j] > 9){
                        flag = 0;
                        goto kq;
                    }
                }
            }
        }
        if (flag) res = ss;
        kq : continue;
    }
    cout << res;
}
