#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "charcnt"
const int maxn = 5e5 + 5;
using namespace std;

int n, q, bit[26][maxn];

void update(int x, int y, int val){
    while (y <= n){
        bit[x][y] += val;
        y += y & -y;
    }
}

int get(int x, int y){
    int ans = 0;
    while (y > 0){
        ans += bit[x][y];
        y -= y & -y;
    }
    return ans;
}

string s;
int typ, l, r;
char c;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    //freopen(Irelia".inp", "r", stdin);
    //freopen(Irelia".out", "w", stdout);
    cin >> n >> s;
    s = ' ' + s;
    fi(i, 1, n){
        update(s[i] - 'a', i, 1);
    }
    cin >> q;
    while (q--){
        cin >> typ;
        if (typ == 1){
            cin >> l >> c;
            update(s[l] - 'a', l, -1);
            s[l] = c;
            update(s[l] - 'a', l, 1);
        }
        else {
            int cnt = 0;
            cin >> l >> r;
            fi(i, 0, 25) cnt += (get(i, r) > get(i, l - 1));
            cout << cnt << '\n';
        }
    }

}
