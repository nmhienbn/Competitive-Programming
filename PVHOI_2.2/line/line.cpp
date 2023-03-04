#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "line"
const int maxn = 105;
using namespace std;

int n, m, a[maxn];
ll k, cnt, gt[maxn];
bool kt[maxn][maxn], cl[maxn];

void GT(){
    gt[0] = 1;
    fi(i, 1, n){
        if (gt[i - 1] <= k / i)
            gt[i] = gt[i - 1] * i;
        else
            gt[i] = k + 1;
    }
}

void sub1(int i){
    fi(j, 1, n) if (!cl[j] && !kt[j][a[i - 1]]){
        cl[j] = 1;
        a[i] = j;
        if (i < n) sub1(i + 1);
        else if (++cnt == k){
            fi(t, 1, n){
                cout << a[t] << ' ';
            }
            exit(0);
        }
        cl[j] = 0;
    }
}

void sub3(int i){
    if (i > n){
        fi(t, 1, n){
            cout << a[t] << ' ';
        }
        exit(0);
    }
    fi(j, 1, n) if (!cl[j]){
        if (cnt + gt[n - i] >= k) a[i] = j, cl[j] = 1, sub3(i + 1);
        else cnt += gt[n - i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        kt[u][v] = kt[v][u] = 1;
    }
    if (n <= 11 || k <= 1e5) sub1(1);
    if (m == 0){
        GT();
        sub3(1);
    }
}
