#include <bits/stdc++.h>
using namespace std;
#define ll	long long

/*
	Approach :-

	Given x, y we can write

	x = ((10**(x_len/2))*a + b)
	y = ((10**(y_len/2))*c + d)

	then x*y can be computed as

	x*y = (((10**(x_len/2)) * (10**(y_len/2))) * (a*c)) + (b*d) + ((10**(x_len/2))* (a*d)) + ((10**(y_len/2))* (b*c))

	Each product like a*b can be recursively be computed.
*/

ll cnt(ll n){
	ll len(0);

	while(n > 0){
		n /= 10;
		len++;
	}

	return len;
}

ll divide(ll x, ll y){
	ll x_len = cnt(x), y_len = cnt(y);
	if(x_len == 1 || y_len == 1) return (x*y);
	ll a, b, c, d;

	b = x % (ll)(pow(10,(x_len/2))+0.5);
	a = (x-b) / (ll)(pow(10,(x_len/2))+0.5);

	d = y % (ll)(pow(10,(y_len/2))+0.5);
	c = (y-d) / (ll)(pow(10,(y_len/2))+0.5);

	ll p1 = (ll)(pow(10,((x_len/2)+(y_len/2)))+0.5)*divide(a,c);
	ll p2 = (ll)(pow(10,(x_len/2))+0.5)*divide(a,d);
	ll p3 = (ll)(pow(10,(y_len/2))+0.5)*divide(b,c);
	ll p4 = divide(b,d);

	return (p1+p2+p3+p4); 
}

int32_t main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll x, y;

	cout << "Enter the first number : ";
	cin >> x;
	cout << endl << "Enter the second number : ";
	cin >> y;

	cout << "Product using recursive approach : " << divide(x,y) << endl;
	cout << "Original Product : " << x*y << endl;
	
	return 0;
}