#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "egroup"
const int maxn = 3e4 + 5;
using namespace std;

int n, a[maxn], s1[maxn], s2[maxn], s3[maxn], mins, res = 1e9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n){
        s1[i] = s1[i - 1] + (a[i] != 1);
        s2[i] = s2[i - 1] + (a[i] != 2);
        s3[i] = s3[i - 1] + (a[i] != 3);
    }
    fi(i, 0, n){
        mins = min(mins, s1[i] - s2[i]);
        res = min(res, s2[i] + s3[n] - s3[i] + mins);
    }
    mins = 0;
    fi(i, 0, n){
        mins = min(mins, s3[i] - s2[i]);
        res = min(res, s1[n] - s1[i] + s2[i] + mins);
    }
    cout << max(res, 0);
}
