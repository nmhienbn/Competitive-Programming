#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "catalan"
const int maxn = 34;
using namespace std;

int n, a[maxn], b[maxn];
ll cat[maxn];
ll k;
bool cl[maxn];

void ql(int i){
    int vt = 0;
    fi(j, 1, n) if (!cl[j]){
        vt = j;
        b[j] = 1;
    }
    fi(j, vt + 1, n) if (!cl[j]){

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    n *= 2;
    fi(i, 1, n) cin >> a[i];
    fid(i, n, 1) a[i] = a[i] - a[i - 1];
    cin >> k;
    cat[1] = 1;
    fi(i, 2, n / 2){
        cat[i] = cat[i - 1] * 2 * (2 * n - 1) / (n + 1);
        cout << cat[i] << ' ';
    }
    ql(1);
}
