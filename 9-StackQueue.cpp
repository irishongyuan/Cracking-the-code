#include<iostream>
#include<stack>
using namespace std;

template <typename T>

class StackQueue {
	public:
		StackQueue(int MaxStackSize) {
			this->maxStacksize = MaxStackSize;
		}
		~StackQueue() {	
		}
		
		void push(T node) {
			if(m_sin.size() >= maxStacksize && m_sout.size() >= maxStacksize) {
				cout << "队列已满，无法入队！" << endl; 
				return;
			}
			if(m_sin.size() >= maxStacksize) {
				move(m_sin, m_sout);
			}			
			m_sin.push(node);
			cout << "入队列为" << m_sin.top() << "，成功。" << endl; 		
		}
		
		void pop() {
			move(m_sin, m_sout);
			if(m_sout.empty()) {
				cout << "队列已空，无法出队！" << endl; 
			}
			else {
				cout << "出队列为" << m_sout.top() << "，成功。" << endl; 
				m_sout.pop();
			}		
		}
		
		T* front() {
			if (m_sin.empty() && m_sout.empty()) {
				cout << "当前队已空！" << endl;
				return NULL; 
			}
			
			move(m_sin, m_sout);
			//cout << "队列头为" << m_sout.top() << endl;
			return &m_sout.top();
		}
		
		T* back() {
			if (m_sin.empty() && m_sout.empty()) {
				cout << "当前队已空！" << endl;
				return 	NULL; 
			}
			
			move(m_sout, m_sin);
			//cout << "队列尾为" << m_sin.top() << endl; 
			return &m_sin.top();
		}
		
		int size() {
			return m_sin.size() + m_sout.size();
		}
		
		bool empty() {
			return m_sin.empty() && m_sout.empty();
		}
		
		void move(stack<T> &ssrc, stack<T> &sdst) {
			if(sdst.empty() && !ssrc.empty()) {
				while(!ssrc.empty() && sdst.size() < maxStacksize) {
					T node = ssrc.top();
					ssrc.pop();
					sdst.push(node);
				}
			}
		}
		
	private:
		stack<T> m_sin, m_sout;
		int maxStacksize;
};

int main() {
	StackQueue<int> queue(2);
	queue.push(1);
	queue.push(2);
	queue.push(3);
	cout << "当前队列长度为：" << queue.size() << endl;
	int *pqback = queue.back();
	cout << "当前队尾是" <<  *pqback << endl;
	queue.push(4);
	queue.push(5);
	int *pqfront = queue.front();
	cout << "当前队头是" <<  *pqfront << endl;
	queue.front();
	queue.pop();
	queue.pop();
	queue.push(5);
	pqback = queue.back();
	cout << "当前队尾是" <<  *pqback << endl;	
	queue.pop();
	queue.pop();
	cout << "当前队空：" << queue.empty() << " (1-true；0-false)" << endl;
	cout << "当前队列长度为：" << queue.size() << endl;
	queue.pop();
	queue.front();
}
