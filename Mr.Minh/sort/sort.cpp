#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "sort"
const int maxn = 1e5+10;

using namespace std;

int n, a, b, k;
int s[maxn], A[maxn], B[maxn];
ll mu[20];

bool cmp(int a, int b){
    string aa = to_string(a);
    string bb = to_string(b);
    fi(i, 0, min(aa.size(), bb.size()) - 1){
        if (aa[i] != bb[i]){
            return aa[i] < bb[i];
        }
    }
    return aa.size() < bb.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> a >> b;
    n = b - a + 1;
    fi(i, 1, n){
        s[i] = a + i - 1;
    }
    sort(s + 1, s + n + 1, cmp);
    //fi(i, 1, n) cout << s[i] << ' ';
    fi(i, 1, n) A[i] = s[i] - a + 1;
    fi(i, 1, n){
        int d = upper_bound(B+1, B+k+1, A[i]) - B;
        if (d == k + 1) B[++k] = 1e9;
        B[d] = min(B[d], A[i]);
    }
    cout << n - k;
}
