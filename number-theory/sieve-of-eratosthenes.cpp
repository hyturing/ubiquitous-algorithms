/* author: hyturing - Hemant Kumar Yadav */
#include "bits/stdc++.h"
using namespace std;

// calculating all the prime less than of equal to n

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//code here
	vector<int> sieve(100000);
	int n;
	cin >> n;
	for(int i=2; i <= n; i++){
		if(sieve[i]) continue;
		for(int j = 2*i; j <= n; j+=i) sieve[j] = 1;
	}

	// test cases
	for(int i = 2; i <= n; i++){
		if(sieve[i]) continue;
		else cout << i << " ";
	}
	return 0;
}
