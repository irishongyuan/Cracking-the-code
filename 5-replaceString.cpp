#include<iostream>
#include<cstring>
using namespace std;

void replaceString(char* c) {
	int n = strlen(c);
	int nblock = 0;
	for(int i = 0; i < n; i++) {
		if(c[i] == ' ') {
			nblock++;
		}
	}
	int p = n + nblock * 2;
	char* newc = new char[p]; 
	newc[p--] = '\0';
	for(int i = n-1; i >=0; i--) {
		if(c[i] == ' ') {
			newc[p--] = '0';
			newc[p--] = '2';
			newc[p--] = '%';
		}
		else {
			newc[p--] = c[i];
		}
	}
	strcpy(c, newc);
}

int main() {
	char c[] = "ab cd d ";
	replaceString(c);
	cout << c << endl;
}
