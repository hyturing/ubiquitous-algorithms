/* author: hyturing - Hemant Kumar Yadav */
#include "bits/stdc++.h"
using namespace std;

bool prime(int n){
	if (n<2) return false;

	for(int i = 2; i*i <= n; i++){
		if(n%i == 0) return false;
	}

	return true;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//code here
	int n;
	cin >> n;

	cout << (prime(n) ? "Yes": "No") << endl;

	return 0;
}
