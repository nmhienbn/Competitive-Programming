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

int n, a[maxn], b[maxn], m, x, k;
string s;

void xuli(int t){
    fi(i, t + 1, k) b[i] = 0;
    fi(i, 1, k){
        if (b[i] > a[i]){
            cout << n << '=' << b[1];
            fi(i, 2, t) cout << '+' << b[i];
            exit(0);
        }
        if (b[i] < a[i]) return;
    }
}

void calc(int n, int i){
    fi(j, b[i - 1], min(9, n)){
        b[i] = j;
        if (n > j) calc(n - j, i + 1);
        else xuli(i);
    }
}

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
    b[0] = 1;
//    cout << 10000 << '=' << 1;
//    fi(i, 1, 9999) cout << '+' << 1;
    calc(n, 1);
    cout << "No solution";
}
