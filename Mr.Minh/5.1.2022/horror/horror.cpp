#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "horror"
const int maxn = 10;
using namespace std;

int n, a[maxn], b[maxn], c[maxn], vt[maxn], res, sca = 74;
bool kt[maxn];

void ql(int i){
    fi(j, 0, n - 1) if (!kt[j]){
        c[i] = j;
        if (sca >= b[i]){
            if (sca + 47 >= a[i])
        }

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 0, n-1) cin >> a[i] >> b[i];
    ql(0);
    fi(i, 1, n) cout << vt[i] - 1 << '\n';
}
