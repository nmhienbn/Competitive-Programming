#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "ndccard"
const int maxn = 10005;

using namespace std;

int n, m, res;
int a[maxn];

void maximize(int& x, int y){
    if (x < y) x = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    fi(i, 1, n){
        int k = n;
        fi(j, i + 1, n){
            while (a[i] + a[j] + a[k] > m && k > j) k--;
            if (k == j) break;
            maximize(res, a[i] + a[j] + a[k]);
        }
    }
    cout << res;
}
