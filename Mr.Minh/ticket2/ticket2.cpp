#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <ll, int>
#define f first
#define s second
#define pb push_back
#define Irelia "ticket2"
using namespace std;

ll N;
ll mu[15];
int k;

pii F[111][15][111];

pii calc(int total, int len, int curk) {
	if(len == 0) {
		if(curk + total > k) return {1, 0};
		else return {0, curk + total};
	}
	pii &ret = F[total][len][curk];
	if(ret.f != -1) return ret;
	ret = {0,curk};
	fi(ad, 0, 9){
		pii tmp = calc( total + ad, len - 1, ret.s);
		ret.f += tmp.f;
		ret.s = tmp.s;
	}
	return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
	cin >> N >> k;
	memset(F, -1, sizeof(F));
	mu[0] = 1;
	fi(i, 1, 14) mu[i] = mu[i - 1] * 10;
	ll now = 1;
	pii cur = {0, 0};
	while (now <= N) {
        cout << now << '\n';
		fid(i, 14, 0) if (now % mu[i] == 0 && now + mu[i] - 1 <= N){
			int z = 0;
			fi(j, 0, 14) z += (now / mu[j]) % 10;
			pii tmp = calc( z, i, cur.s);
			cur.f += tmp.f;
			cur.s = tmp.s;
			now += mu[i];
			break;
		}
	}
	cout << cur.f + (cur.s != 0);
	return 0;
}
