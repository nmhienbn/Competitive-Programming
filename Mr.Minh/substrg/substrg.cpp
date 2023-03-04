#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "substrg"
const int maxn = 1e5 + 5;

using namespace std;

int n, k, cnt[26];
int res, pos;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k >> s;
    s = ' ' + s;
    int j = 1;
    fi(i, 1, n){
        int now = s[i] - 'a';
        cnt[now]++;
        while (cnt[now] > k){
            cnt[s[j] - 'a']--;
            j++;
        }
        if (i - j + 1 > res){
            res = i - j + 1;
            pos = j;
        }
    }
    cout << res << ' ' << pos;
}
