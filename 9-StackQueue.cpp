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
				cout << "�����������޷���ӣ�" << endl; 
				return;
			}
			if(m_sin.size() >= maxStacksize) {
				move(m_sin, m_sout);
			}			
			m_sin.push(node);
			cout << "�����Ϊ" << m_sin.top() << "���ɹ���" << endl; 		
		}
		
		void pop() {
			move(m_sin, m_sout);
			if(m_sout.empty()) {
				cout << "�����ѿգ��޷����ӣ�" << endl; 
			}
			else {
				cout << "������Ϊ" << m_sout.top() << "���ɹ���" << endl; 
				m_sout.pop();
			}		
		}
		
		T* front() {
			if (m_sin.empty() && m_sout.empty()) {
				cout << "��ǰ���ѿգ�" << endl;
				return NULL; 
			}
			
			move(m_sin, m_sout);
			//cout << "����ͷΪ" << m_sout.top() << endl;
			return &m_sout.top();
		}
		
		T* back() {
			if (m_sin.empty() && m_sout.empty()) {
				cout << "��ǰ���ѿգ�" << endl;
				return 	NULL; 
			}
			
			move(m_sout, m_sin);
			//cout << "����βΪ" << m_sin.top() << endl; 
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
	cout << "��ǰ���г���Ϊ��" << queue.size() << endl;
	int *pqback = queue.back();
	cout << "��ǰ��β��" <<  *pqback << endl;
	queue.push(4);
	queue.push(5);
	int *pqfront = queue.front();
	cout << "��ǰ��ͷ��" <<  *pqfront << endl;
	queue.front();
	queue.pop();
	queue.pop();
	queue.push(5);
	pqback = queue.back();
	cout << "��ǰ��β��" <<  *pqback << endl;	
	queue.pop();
	queue.pop();
	cout << "��ǰ�ӿգ�" << queue.empty() << " (1-true��0-false)" << endl;
	cout << "��ǰ���г���Ϊ��" << queue.size() << endl;
	queue.pop();
	queue.front();
}
