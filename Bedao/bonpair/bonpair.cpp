#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define all(a) a.begin(), a.end()
#define pb push_back
#define ll long long
#define Irelia "bonpair"
const int maxn = 1e7 + 5;
using namespace std;

int n, x;
int a[maxn];
ll res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> x;
    fi(i, 1, n){
        cin >> a[i];
    }
    int j = n;
    for (int i = 1; i < j; i++){
        while (a[i] + a[j] > x && j > i) j--;
        if (i < j) res += j - i;
    }
    cout << res;
}
