/* author: hyturing - Hemant Kumar Yadav */
#include "bits/stdc++.h"
using namespace std;

int power[100000]={0};

bool prime(int n){
	if (n<2) return false;

	for(int i = 2; i*i <= n; i++){
		if(n%i == 0) return false;
	}
	return true;
}

vector<int> factors(int n){
	vector<int> f;
	for(int i = 2; i*i <= n; i++){
		while(n%i == 0){
			f.push_back(i);
			n /= i;
			power[i]++;
		}
	}

	if(n > 1){f.push_back(n); power[n]++;}

	return f;
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//code here
	int n;
	cin >> n;

	cout << (prime(n) ? "Yes": "No") << endl;

	vector<int> f;

	f = factors(n);
	for(auto x: f) cout << x << " "; cout << endl;
	// for(auto x: power) if(x!=0) cout << x << " ";
	
	return 0;
}
