#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "a"
const int maxn = 1005;
using namespace std;

int n;
vector<int> a[maxn];
int res[maxn * maxn];
int c[maxn], m;

bool cmp(int i, int j){
    return a[i].size() < a[j].size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n * n){
        int x;
        cin >> x;
        a[x].pb(i);
    }
    fi(i, 1, n){
        m = 0;
        fi(j, 1, n + 1){
            if (a[j].size()){
            c[++m] = j;
            }
        }
        sort(c + 1, c + m + 1, cmp);
        if (a[c[1]].size() >= n){
            fi(j, 1, n){
                res[a[c[1]].back()] = i;
                a[c[1]].pop_back();
            }
        }
        else {
            if (a[c[1]].size() + a[c[m]].size() < n){
                cout << "NO";
                exit(0);
            }
            fi(j, 1, n - a[c[1]].size()){
                res[a[c[m]].back()] = i;
                a[c[m]].pop_back();
            }
            while (a[c[1]].size()){
                res[a[c[1]].back()] = i;
                a[c[1]].pop_back();
            }
        }
    }
    cout << "YES\n";
    fi(i, 1, n * n) cout << res[i] << ' ';
}
