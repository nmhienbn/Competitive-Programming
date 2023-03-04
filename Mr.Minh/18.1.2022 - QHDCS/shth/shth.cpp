#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "shth"
const int maxn = 305;
const ll INF = 1e18;
using namespace std;

int k, n;
string s, res = "0";
bool cl[maxn];
int a[maxn], b[maxn];
string C[maxn][maxn];

string add(string a, string b){
    string c;
    while (a.size() < b.size()) a = '0' + a;
    while (a.size() > b.size()) b = '0' + b;
    int rem = 0;
    fid(i, int(a.size()) - 1, 0){
        int d = a[i] + b[i] - '0' * 2 + rem;
        c = char(d % 10 + '0') + c;
        if (d > 9) rem = 1;
        else rem = 0;
    }
    if (rem) c = '1' + c;
    return c;
}

bool cmp(string a, string b){
    while (a.size() < b.size()) a = '0' + a;
    while (a.size() > b.size()) b = '0' + b;
    fi(i, 0, int(a.size()) - 1){
        if (a[i] < b[i]) return false;
        else if (a[i] > b[i]) return true;
    }
    return true;
}

void ql(int i){
    if (i > k){
        fi(i, 1, k) cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    fi(j, a[i - 1] + 1, n) if (!cl[j]){
        if (cmp(add(res, C[n - j][k - i]), s)){
            a[i] = j;
            cl[j] = 1;
            ql(i + 1);
            break;
        }
        else res = add(res, C[n - j][k - i]);
    }
}

void bt(int i){
    if (i > k){
        cout << add(res, "1");
        exit(0);
    }
    fi(j, a[i - 1] + 1, n) if (!cl[j]){
        if (j < a[i]){
            res = add(res, C[n - j][k - i]);
        }
        else {
            cl[j] = 1;
            bt(i + 1);
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k >> s;
    C[0][0] = "1";
    fi(i, 1, n){
        C[i][0] = "1";
        fi(j, 1, n){
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
        }
    }
    ql(1);
    fi(i, 1, n) cl[i] = 0;
    fi(i, 1, n) cin >> a[i];
    res = "0";
    //cout << add("9", "") << ' ';
    bt(1);
}
