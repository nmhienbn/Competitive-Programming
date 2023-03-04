#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bt1"
const int maxn = 105, mod = 1e5;
const ll maxr = 1e10;
using namespace std;

string operator * (string a, int b){
    string res;
    int rem = 0;
    fid(i, a.size() - 1, 0){
        int d = (a[i] - '0') * b + rem;
        res = char(d % 10 + '0') + res;
        rem = d / 10;
    }
    while (rem > 0){
        res = char(rem % 10 + '0') + res;
        rem /= 10;
    }
    return res;
}

string operator / (string a, int b){
    string res;
    int rem = 0;
    for (char c : a){
        int d = rem * 10 + c - '0';
        if (d >= b || res.size()){
            res += char(d / b + '0');
        }
        rem = d % b;
    }
    return res;
}

int n;
string f[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    f[1] = "1";
    fi(i, 2, 50){
        f[i] = (f[i - 1] * (i * 4 - 2)) / (i + 1);
    }
    while (cin >> n){
        n /= 2;
        if (f[n].size() <= 10) cout << f[n] << '\n';
        else {
            fi(i, 0, 4) cout << f[n][i];
            cout << "...";
            fi(i, f[n].size() - 5, f[n].size() - 1) cout << f[n][i];
            cout << '\n';
        }
    }
}
