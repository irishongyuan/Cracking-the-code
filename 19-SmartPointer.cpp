#include<iostream>
using namespace std;

template <typename T>
class SmartPointer {
	public:
		SmartPointer(T* p) {
			sp = p;
			count = new unsigned(1);
		}
		SmartPointer(SmartPointer<T> &sptr) {
			sp = sptr.sp;
			count = sptr.count;
			++(*count);
		}
		SmartPointer<T>& operator=(SmartPointer<T> &sptr) {
			if(this != &sptr) {
				//没有更多的指针指向这块内存时才清空指向的内存
				if(--(*count) == 0) {
					cout << "SmartPointer " << *sp;
					clear();
					cout << " operator = cleear" << endl;
				}
				sp = sptr.sp;
				count = sptr.count;
				++(*count);
			}
			return *this;
		}
		~SmartPointer() {
			cout << "delete a pointer point to " << *sp << endl;
			//没有更多的指针指向这块内存时才清空指向的内存
			if(--(*count) == 0) {
				cout << "~SmartPointer " << *sp;
				clear();
				cout << " cleear" << endl;
			}
		}
		T* operator->() {
			return sp;
		}
		T& operator*() {
			return *sp;
		}
		unsigned GetCount() {
			return *count;
		}
	
	private:
		void clear() {
			delete sp;
			delete count;
			sp = NULL;//避免成为迷途指针 
			count = NULL;
		}
	
	protected:
		T* sp;
		unsigned* count;
}; 

int main() {
	int *p1 = new int(11);
	int *p2 = new int(22);
	SmartPointer<int> p3(p1);
	cout << "p3 is " << *p3 << ", and count is " << p3.GetCount() << endl;
	SmartPointer<int> p4(p2);
	cout << "p4 is " << *p4 << ", and count is " << p4.GetCount() << endl;
	SmartPointer<int> p5(p3);
	*p5 = 33;
	cout << "p5 is " << *p5 << ", and count is " << p5.GetCount() << endl;
	cout << "p3 is " << *p3 << ", and count is " << p3.GetCount() << endl;
	p3 = p4;
	cout << "p3 is change, but now operator = cleear not happend." << endl;
	cout << "p5 is " << *p5 << ", and count is " << p5.GetCount() << endl;
	p5 = p4;
	cout << "p5 is " << *p5 << ", and count is " << p5.GetCount() << endl;
	return 0;
	
} 
