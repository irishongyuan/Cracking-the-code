#include<iostream>
using namespace std;

typedef long long ll;

//recursion version
ll fib1(int n) {
	if(n <= 0) {
		return 0;
	}
	else if(n == 1 || n == 2) {
		return 1;
	}
	else {
		return fib1(n-1) + fib1(n-2);
	}
}

//unrecursion version
ll fib2(int n) {
	if(n <= 0) {
		return 0;
	}
	else if(n == 1 || n == 2) {
		return 1;
	}
	else {
		ll a = 1, b = 1;
		while(n-- > 2) {
			ll c = a + b;
			a = b;
			b = c;
		}
		return b;
	}
}

mul(ll c[2][2], ll b[2][2], ll a[2][2]) {
	ll t[4];
	t[0] = b[0][0] * a[0][0] + b[0][1] * a[1][0];
	t[1] = b[0][0] * a[0][1] + b[0][1] * a[1][1];
	t[2] = b[1][0] * a[0][0] + b[1][1] * a[1][0];
	t[3] = b[1][0] * a[0][1] + b[1][1] * a[1][1];
	c[0][0] = t[0];
	c[0][1] = t[1];
	c[1][0] = t[2];
	c[1][1] = t[3];	
}

pow(ll b[2][2], ll a[2][2], int n){
	while(n > 0) {
		if(n & 1) {
			mul(b, b, a);
		}
		mul(a, a, a);
		n >>= 1;
	}
}

//matrix version
ll fib3(int n) {
	if(n <= 0) {
		return 0;
	}
	else if(n == 1 || n == 2) {
		return 1;
	}
	else {
		ll a[2][2] = {{1,1}, {1,0}};
		ll b[2][2] = {{1,1}, {1,0}};
		pow(b, a, n-3);
		return b[0][0] + b[0][1];
	}
} 

int main() {
	ll a = fib1(5);
	ll b = fib2(5);
	ll c = fib3(5);
	cout << a << " " << b << " " << c;
}
