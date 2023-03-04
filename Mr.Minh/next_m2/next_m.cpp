#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "next_m"
const int maxn = 1e5 + 5;
using namespace std;

int n, a[maxn], m, x, k;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s;
    s += ' ';
    m = s.size();
    fi(i, 0, m - 1){
        if ('0' <= s[i] && s[i] <= '9'){
            x = x * 10 + s[i] - '0';
        }
        else {
            if (s[i] == '=') n = x;
            else a[++k] = x;
            x = 0;
        }
    }
    if (k == 1){
        cout << "No solution";
        exit(0);
    }
    if (a[k - 1] >= a[k] - 1){
        a[k - 1] += a[k];
        k--;
    }
    else {
        int x = a[k-1] + 1;
        int y = a[k] + a[k-1];
        k = k - 2;
        while (y >= x * 2){
            a[++k] = x;
            y -= x;
        }
        a[++k] = y;
    }
    cout << n << '=' << a[1];
    fi(i, 2, k) cout << '+' << a[i];
}
