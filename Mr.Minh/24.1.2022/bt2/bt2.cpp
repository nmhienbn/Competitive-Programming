#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bt2"
const int maxn = 105, mod = 1e5;
const ll maxr = 1e10;
using namespace std;

string operator + (string a, string b){
    string res;
    while (a.size() > b.size()) b = '0' + b;
    while (a.size() < b.size()) a = '0' + a;
    int rem = 0;
    fid(i, a.size() - 1, 0){
        int d = rem + a[i] + b[i] - '0' * 2;
        if (d > 9) d -= 10, rem = 1;
        else rem = 0;
        res = char(d + '0') + res;
    }
    if (rem) res = '1' + res;
    return res;
}

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

string operator * (string a, string b){
    string res;
    fi(i, 0, b.size() - 1){
        res = res * 10 + a * (b[i] - '0');
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

int n, k;
string C[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    C[0][0] = "1";
    fi(i, 1, 50){
        C[i][0] = "1";
        fi(j, 1, i)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    while (cin >> n >> k){
        n /= 2;
        cout << C[n][k - 1] * C[n - 1][k - 1] / k << '\n';
    }
}
