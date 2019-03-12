#include<iostream> 
#include<cstring>
using namespace std;

void removeDuplicate1(string &s) {
	int n = s.length();
	if(n < 2) return;
	
	int p = 0;
	for (int i = 0; i < n; i++) {	
		if(s[i] != '\0') {
			s[p++] = s[i];
			for (int j = i+1; j < n; j++) {
				if(s[i] == s[j]) s[j] = '\0';
			}
		}	
	}
	s = s.substr(0,p);
	//s[p] = '\0';
}

void removeDuplicate2(string &s) {
	int n = s.length();
	if(n < 2) return;
	
	int a[8];
	int p = 0;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++) {
		int d = (int)s[i]; 
		int index = d / 32;
		int shift = d % 32;
		if(!(a[index] & 1 << shift)) {
			a[index] |= 1 << shift;
			s[p++] = s[i];
		}
	}
	s = s.substr(0,p);
}

int main() {
	string s1 = "abccdcdcde";
    string s2 = "abcdefabfgkad";
    string s3 = "";
    string s4 = "aaaaaaaa";
    string s5 = "abababababaABAB";
	string s6 = " ";
	string s7 = "ccccccdddd";
    removeDuplicate1(s1);
    removeDuplicate2(s2);
    removeDuplicate2(s3);
    removeDuplicate2(s4);
    removeDuplicate2(s5);
    removeDuplicate1(s6);
    removeDuplicate1(s7);
    cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<s5<<" "<<s6<<" "<<s7<<endl;
    return 0;
}

