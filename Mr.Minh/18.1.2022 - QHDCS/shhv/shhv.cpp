#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "shhv"
const int maxn = 15;
using namespace std;

int n, a[maxn], p, res, gt[maxn], b[maxn];
bool cl[maxn];

void ql(int i){
    if (i > n){
        cout << res + 1 << '\n';
        return;
    }
    fi(j, 1, n) if (!cl[j]){
        if (j < a[i]) res += gt[n - i];
        else {
            cl[j] = 1;
            ql(i + 1);
            break;
        }
    }
}

void bt(int i){
    if (i > n){
        fi(i, 1, n) cout << b[i] << ' ';
        exit(0);
    }
    fi(j, 1, n) if (!cl[j]){
        if (res + gt[n - i] >= p) b[i] = j, cl[j] = 1, bt(i + 1);
        else res += gt[n - i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    while (cin >> p) a[++n] = p;
    n--;
    gt[0] = 1;
    fi(i, 1, n) gt[i] = gt[i - 1] * i;
    ql(1);
    res = 0;
    fi(i, 1, n) cl[i] = 0;
    bt(1);
}
