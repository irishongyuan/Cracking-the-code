#include<iostream> 
using namespace std;

//int i = 520;
//namespace love{
//	int i = 1314;
//	void loveyou() {
//		cout << "main i is: " << ::i << endl;
//		cout << "love i is: " << i << endl;
//		bool i = true;
//		cout << "love i is: " << love::i << endl;
//		cout << "loveyou i is: " << i << endl;
//	}
//}
//void WomenDay() {
//	cout << "happy women's day!" << endl;
//}
//
//void WomenDay(double day) {
//	cout << "happy " << day << " women's day!" << endl;
//}
//
//namespace Women{
//	void WomenDay() {
//		::WomenDay();
//		double d = 3.8;
//		::WomenDay(d);
//		cout << "Today is women's day!" << endl;
//	}
//}

class Women {
	public:
		Women(){};
		void WomenDay() {
			cout << "happy women's day!" << endl;
		}
		void WomenDay(double day) {
			cout << "happy " << day << " women's day!" << endl;
		}
};

class Girl: public Women {
	public:
		Girl(){};
		using Women::WomenDay;
		void WomenDay(){
			cout << "Today is women's day!" << endl;
		}
};

int main() {
	Women* w = new Girl();
	w->WomenDay();
	double d = 3.8;
	w->WomenDay(d);
	
	Girl g;
	g.WomenDay();
	return 0;
}
