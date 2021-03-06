#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2) {
	sort(&s1[0], &s1[0]+s1.length());
	sort(&s2[0], &s2[0]+s2.length());
	return s1 < s2;
} 

int main() {
	string s[] = {"abc", "eebbb", "cba", "bbbee", "ccc"};
	int size = sizeof(s) / sizeof(string);
	sort(s, s+size, cmp);
    for(int i=0; i<size; ++i)
        cout<<s[i]<<endl;
    return 0;
}
