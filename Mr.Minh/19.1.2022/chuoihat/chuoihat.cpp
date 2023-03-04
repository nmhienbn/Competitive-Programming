#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "chuoihat"
const int maxn = 255;
using namespace std;

int n, a[maxn];
string k, res, gt[maxn];

string operator + (string a, string b){
    string c;
    while (a.size() > b.size()) b = '0' + b;
    while (b.size() > a.size()) a = '0' + a;
    int rem = 0;
    fid(i, int(a.size()) - 1, 0){
        int d = a[i] + b[i] - '0' * 2 + rem;
        if (d > 9) rem = 1, d -= 10;
        else rem = 0;
        c = char(d + '0') + c;
    }
    if (rem) c = '1' + c;
    return c;
}

string operator * (string a, int b){
    string c;
    int rem = 0;
    fid(i, int(a.size()) - 1, 0){
        int d = (a[i] - '0') * b + rem;
        c = char(d % 10 + '0') + c;
        rem = d / 10;
    }
    while (rem){
        c = char(rem % 10 + '0') + c;
        rem /= 10;
    }
    return c;
}

bool operator >= (string a, string b){
    if (a.size() != b.size()) return a.size() > b.size();
    fi(i, 0, int(a.size()) - 1){
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return true;
}

void ql(int i){
    if (i > n){
        fi(i, 1, n) cout << a[i] << ' ';
        exit(0);
    }
    fi(j, a[i - 1] + 1, i * 2){
        if (res + gt[n - i] >= k) a[i] = j, ql(i + 1);
        else res = res + gt[n - i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    gt[0] = "1";
    fi(i, 1, n) gt[i] = gt[i - 1] * i;
    ql(1);
}
