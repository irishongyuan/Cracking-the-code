#include <iostream>
#include <cstring>
using namespace std;

void swap(char &a, char &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

void reverse1(char *s){
   if(!s) return;
   char *p = s, *q = s;
   while(*++q) {
   }
   q--;
   while(p < q) {
   		swap(*p++, *q--);
   }			
}

void reverse2(char *s){
    int n = strlen(s);
    for(int i = 0; i < n/2; i++) {
    	swap(s[i], s[n-i-1]);
	}
}

void reverse3(string &s){
    int n = s.length();
    for(int i = 0; i < n/2; i++) {
    	swap(s[i], s[n-i-1]);
	}
}

int main(){
    char s[] = "123456789";
    reverse1(s);
	//reverse2(s);
    printf("%s\n", s);
    string s1 = "123456789";
    reverse3(s1); 
    printf("%s\n", s1.c_str());
    return 0;
}
