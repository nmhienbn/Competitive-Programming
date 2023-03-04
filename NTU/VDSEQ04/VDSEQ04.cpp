#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "VDSEQ04"
const int maxn = 1005;
using namespace std;

int n, a[maxn];
unordered_set<int> cnt;
bool cl[maxn];
int res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n){
        fi(j, 1, n) if (!cl[j]){
            if (cnt.find(a[j] * 3 - a[i]) != cnt.end()){
                cl[j] = 1;
            }
        }
        fi(j, 1, i - 1){
            cnt.insert(a[i] + a[j]);
        }
    }
    fi(i, 1, n) res += cl[i];
    cout << res;
}
