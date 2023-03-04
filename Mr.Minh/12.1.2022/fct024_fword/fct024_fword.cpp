#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fct024_fword"
const int maxn = 505, INF = 1e9 + 1;
using namespace std;

int n, m, k, now, b[maxn], x;
ll mu[maxn];
string s, t[maxn];

void init(){
    mu[0] = 1;
    fi(i, 1, m){
        mu[i] = mu[i - 1] * k;
        if (mu[i] > INF) mu[i] = INF;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k >> x;
    init();
    cin >> s;
    fi(i, 1, m) cin >> t[i], sort(t[i].begin(), t[i].end());
    int i = 1;
    for (char& c : s) if (c == '#'){
        fi(j, 0, k - 1){
            c = t[i][j];
            if (x <= now + mu[m - i]) break;
            else now += mu[m - i];
        }
        i++;
    }
    cout << s;
}
