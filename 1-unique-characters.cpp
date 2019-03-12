#include<iostream> 
#include<cstring>
using namespace std;

bool isUniquel1(string s) {
	int a[256];
	memset(a, 0, sizeof(a));
	int len = s.length();
	for(int i = 0; i < len; i++) {
		int v = (int)s[i];
		if(a[v]) return false;
		else
			a[v]=1;
	} 
	return true;
}

bool isUniquel2(string s) {
	int a[8];
	memset(a, 0, sizeof(a));
	int len = s.length();
	for(int i = 0; i < len; i++) {
		int v = (int)s[i];
		int index = v/32;
		int shift = v%32;
		if(a[index] & 1<<shift) return false;
		else
			a[index] |= 1<<shift;
	} 
	return true;
}

int main(){
	string s1="jkZABHEJ";
	string s2="jkZABHEJj";
	printf("%d\n", isUniquel1(s1));
	printf("%d\n", isUniquel1(s2));
	printf("%d\n", isUniquel2(s1));
	printf("%d\n", isUniquel2(s2));
	return 0;
}
