#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "ballgmvn"
const int maxn = 1005;
using namespace std;

struct dl {
    int a, b, id;
    bool operator < (const dl & x) const {
        return a == x.a ? (b == x.b ? id < x.id : b < x.b) : a < x.a;
    }
};

int n;
pii a[maxn], b[maxn];
dl c[maxn];

pii rg(pii a){
    if (a.first < 0) a = {-a.first, -a.second};
    int tmp = __gcd(a.first, a.second);
    if (tmp){
        a = {a.first / tmp, a.second / tmp};
    }
    return a;
}

pii operator - (pii a, pii b){
    return {a.first - b.first, a.second - b.second};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(Irelia".inp", "r", stdin);
    //freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].first >> a[i].second;
    fi(i, 1, n) cin >> b[i].first >> b[i].second;
    fi(i, 1, n){
        fi(j, 1, n){
            pii tmp = rg(a[i] - b[j]);
            c[j] = {tmp.first, tmp.second, j + n};
        }
        sort(c + 1, c + n + 1);
        fi(j, 2, n){
            if (c[j].a == c[j - 1].a && c[j].b == c[j - 1].b){
                cout << i << ' ' << c[j - 1].id << ' ' << c[j].id;
                exit(0);
            }
        }
    }
    fi(i, 1, n){
        fi(j, 1, n){
            pii tmp = rg(b[i] - a[j]);
            c[j] = {tmp.first, tmp.second, j};
        }
        sort(c + 1, c + n + 1);
        fi(j, 2, n){
            if (c[j].a == c[j - 1].a && c[j].b == c[j - 1].b){
                cout << c[j - 1].id << ' ' << c[j].id << ' ' << i + n;
                exit(0);
            }
        }
    }
    cout << -1;
}
