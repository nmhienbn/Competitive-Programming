#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "trip"
const int maxn = 85;
using namespace std;

int n, m, f[maxn][maxn], len;
char res[maxn];
string a, b;

int lcs(int i, int j){
	int &ret = f[i][j];
	if (i > n || j > m)
		return ret = 0;
	if (ret != -1)
		return ret;
	ret = 0;
	if (a[i] == b[j]){
		ret = lcs(i+1, j+1) + 1;
	}
	else {
		ret = max(lcs(i+1, j), lcs(i, j+1));
	}
	return ret;
}

void print(int id1, int id2, int now){
	if (now == len){
		fi(i, 0, len - 1) cout << res[i];
		cout << '\n';
		return;
	}
	if (id1 > n || id2 > m) return;
	for (char ch = 'a'; ch <= 'z'; ch++){
		bool ok = false;
		fi(i, id1, n){
			if (ch == a[i]){
                fi(j, id2, m){
                    if (ch == b[j] && f[i][j] == len-now){
                        res[now] = ch;
                        print(i+1, j+1, now+1);
                        ok = true;
                        break;
                    }
                }
			}
			if (ok) break;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> a >> b;
    n = a.size();
    m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    memset(f, -1, sizeof f);
    len = lcs(1, 1);
    print(1, 1, 0);
}
