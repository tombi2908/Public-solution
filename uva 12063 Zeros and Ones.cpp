#include<bits/stdc++.h>
#define int long long

using namespace std;
using ll=long long;

int n, k;
ll lt[102];
ll dp[102][102][102];

void compute(){
    lt[1]=1;
    for(int i=2; i<=100; i++){
        lt[i]=lt[i-1]*2%k;
    }
}

void solve(){
	if(n%2 || k==0){
		cout << 0 << '\n';
		return;
	}
	memset(dp, 0, sizeof(dp));
    dp[0][0][0]=1;
    for(int i=1; i<=n; i++){
    	for(int s=0; s<=n/2; s++){
        	for(int j=0; j<k; j++){
	        	int cc=j-lt[i];
	            cc%=k;
	            while(cc<0) cc+=k;
	            if(s>0) dp[i][j][s]=dp[i-1][cc][s-1];
	            if(i!=n) dp[i][j][s]+=dp[i-1][j][s];
        	}
        }
    }
    cout << dp[n][0][n/2] << '\n';
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    for(int p=1; p<=q; p++){
    	cout << "Case " << p << ": ";
        cin >> n >> k;
        if(k==0){
        	cout << 0 << '\n';
        	continue;
        }
        compute();
        solve();
    }
}