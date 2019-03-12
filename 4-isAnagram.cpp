#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool isAnagram1(string &s, string &t) {
	int n1 = s.length();
	int n2 = t.length();
	if(n1 != n2) {
		return false;
	}
	if(s.compare(t) == 0) {
		return false;
	}
	
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	if(s.compare(t) == 0) {
		return true;
	}
} 

bool isAnagram2(string &s, string &t) {
	int n1 = s.length();
	int n2 = t.length();
	if(n1 != n2) {
		return false;
	}
	if(s.compare(t) == 0) {
		return false;
	}
	
	int a[256];
	memset(a, 0, sizeof(a));
	for(int i = 0; i < n1; i++) {
		int d = (int)s[i];
		int v = (int)t[i];
		a[d]++;
		a[v]--;
	}
	for(int i = 0; i < 256; i++) {
		if(a[i] != 0){
			return false;
		}			
	}
	return true;
} 

int main() {
	string s1 = "abcc";
	string t1 = "abcc";
	string s2 = "abcd";
	string t2 = "abcc";
	string s3 = "abcd";
	string t3 = "adbc";
	string s4 = "abcde";
	string t4 = "adbc";
//	printf("%d\n", isAnagram1(s1,t1));
//	printf("%d\n", isAnagram1(s2,t2));
//	printf("%d\n", isAnagram1(s3,t3));
//	printf("%d\n", isAnagram1(s4,t4));
	printf("%d\n", isAnagram2(s1,t1));
	printf("%d\n", isAnagram2(s2,t2));
	printf("%d\n", isAnagram2(s3,t3));
	printf("%d\n", isAnagram2(s4,t4));

}
