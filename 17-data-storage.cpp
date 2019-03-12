#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	freopen("C:/Users/Iris/Desktop/12.3.in", "r", stdin);
	
	int total_num = 20000;
	int block_size = 2000;
	int block_num = total_num / block_size;
	int block_count[block_num] = {0};
	int int_len = sizeof(int) * 8;
	int block[block_size/int_len] = {0};
	
	int v;
	while(scanf("%d", &v) != EOF) {
		++block_count[v/block_size]; 
	}
	fclose(stdin);
	
	int i;
	for(i = 0; i < block_num; i++) {
		if(block_count[i] != block_size) {
			cout << i << endl;
			break;
		}
	}
	
	freopen("C:/Users/Iris/Desktop/12.3.in", "r", stdin);
	while(scanf("%d", &v) != EOF) {
		if(v >= (block_size * i) && v < (block_size * (i+1))) {
			block[(v % block_size)/int_len] |= (1 << (v % block_size)%int_len);
		}
	}
	
	bool bfind = false;
	for(int j = 0; j < block_size/int_len; j++) {
		for(int k = 0; k < int_len; k++) {
			if((block[j] & (1 << k)) == 0) {
				cout << block_size * i + int_len * j +k << endl;
				bfind = true;
				break;
			}
		}
		if(bfind) {
			break;
		}
	}
	
//	//int_len is the num of every int can storage bit
//	//and bit_len is how many int we need
//	int int_len = sizeof(int) * 8;
//	int bit_len = 0xFFFFFFFF / int_len; 
//	int* bit = new int[bit_len];
//	
//	int v;
//	while(scanf("%d", &v) != EOF) {
//		bit[v / int_len] |= 1 << (v % int_len);
//	}
//	
//	bool bfind = false;
//	for(int i = 0; i < bit_len; i++) {
//		for(int j = 0; j < int_len; j++) {
//			if((bit[i] & (1 << j)) == 0) {
//				cout << i*int_len+j << endl;
//				bfind = true;
//				break;
//			}
//		}
//		if(bfind) {
//			break;
//		}
//	}
//	
//	delete[] bit;
	fclose(stdin);
	return 0;
}
