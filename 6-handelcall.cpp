#include<iostream>
#include<vector>
#include<string>
#include<map>
#include <pthread.h>
#include <unistd.h>
using namespace std;

class Caller {
	public:
		Caller(string name, int rank) {
			this->mCallername = name;
			this->mRank = rank;
		};
	
		int getRank(){
			return mRank;
		};
	
		string getName() {
			return mCallername;
		};
		
		~Caller(){};
	
	private:
		string mCallername;
		int mRank;
};

//Ϊ��ʵ�ֶ��̣߳���ʹ������࣬�л����뵽���õķ�ʽ�ٲ��� 
//class Woker {
//	public:
//		Woker() {};
//		virtual void* handelcall(void* data) = 0;
//		virtual ~Woker(){};		
//};

class Director {
	public:
		Director(int id) {this->mDirId = id;};
		void* handelcall(void* data){
			Caller *caller = (Caller *)data;
			if(caller->getRank() == 2) {
				cout << "����" << this->mDirId << " �� is handling " << caller->getName() << "'s call." << endl;
				sleep(2);
				cout << "���� " << this->mDirId << " �ŷ������." << endl;	
			}
			else {
				cout << "Sorry we can't answer " << caller->getName() << "'s question." << endl;
			}
		};
		virtual ~Director(){};
	
	private:
		int mDirId;
};

class Manager {
	public:
		Manager(int id) {this->mManId = id;};
		virtual void* handelcall(void* data){
			Caller *caller = (Caller *)data;
			if(caller->getRank() == 1) {
				cout << "���� " << this->mManId << " �� is handling " << caller->getName() << "'s call." << endl;
				sleep(2);
				cout << "���� " << this->mManId << " �ŷ������." << endl;	
			}
			else {
				Director* directorwoker = new Director(1);
				directorwoker->handelcall(caller);
				delete directorwoker;
			}
		};
		virtual ~Manager(){};
		
	private:
		int mManId;
};

//���̵߳��ú�������ֻ����һ��void*�������ֻ����struct��װ 
struct myParam{
	Caller* caller;
	int* id;
};

class Respondent {
	public:
		Respondent() {};
		static void* handelcall(void* data){
			myParam *calldata = (myParam *)data;
			Caller* caller = calldata->caller;
			int* id = calldata->id;
			if(caller->getRank() == 0) {
				cout << "����Ա " << *id << " �� is handling " << caller->getName() << "'s call" << endl;
				sleep(1);
				cout << "����Ա " << *id << " �ŷ������." << endl;	
			}
			else {
				Manager* managerwoker = new Manager(1);
				managerwoker->handelcall(caller);
				delete managerwoker;
			}
		};
		virtual ~Respondent() {};
};

class CallCenter {
	public:
		CallCenter(int nRes = 0, int nMan = 0, int nDir = 0) {
			respondents.resize(nRes);
	        //managers.resize(nMan);
        	//directors.resize(nDir);
			respondents_available.resize(nRes);
			managers_available.resize(nMan);
			directors_available.resize(nDir);
			fill(respondents_available.begin(), respondents_available.end(), true);
			fill(managers_available.begin(), managers_available.end(), true);
			fill(directors_available.begin(), directors_available.end(), true);
		}
		
		void handel() {
			pthread_t tids[respondents.size()];
			while(!callers.empty()) {
				//�д����� �� 
				//�������ö��߳���ɽӵ绰�������Ǵ������߳�ֻ�ܵ���ȫ�ֺ����������е�static������
				//��������� handelcall���麯���������ٶ���Ϊ��̬���� ���ʶ�ȡ�᲻�̳У���Ҫ�麯����
				int i=0;
				for (i = 0; i < respondents.size(); i++) {
					if(respondents_available[i]) {
						respondents_available[i] = false;
						Caller* caller = &(*callers.begin());
						cout << caller->getName() << "�����绰"<< endl;
						Respondent res = respondents[i];
						struct myParam calldata;
						calldata.caller = caller;
						calldata.id = &i;
						int ret = pthread_create(&tids[i], NULL, res.handelcall, &calldata);
						if (ret != 0)
	        			{
	           				cout << "pthread_create error: error_code=" << ret << endl;
	        			}
						callers. erase(callers.begin());
						respondents_available[i] = true;
						if(callers.empty()) {
							break;
						}
					}
				} 
				if(i >= respondents.size()) {
					cout << "����Աæ��ȴ�" << endl;
				} 
			}
			
			//�����̽����ȴ��߳�pId�����
			printf("father thread finishhed but will exit when child pthread is over\n");
			for(int i = 0; i < respondents.size(); i++) {
				pthread_join(tids[i],NULL);
			}
			printf("father thread  exit\n");
		}
		
		void addCaller(string name, int rank) {
			Caller* calleradd = new Caller(name, rank);
			callers.push_back(*calleradd);
		}
	
	private:
		vector<Respondent> respondents;
		vector<Manager> managers;
	    vector<Director> directors;
	    vector<Caller> callers;
	    map<Respondent*, Caller*> mapCall;
	    vector<bool> respondents_available;
	    vector<bool> managers_available;
	    vector<bool> directors_available;
	    
};

int main() {
	
	enum rank{
		junior,
		middle,
		senior,
		other
	}; 
	
	CallCenter callcenter(3,2,1);
	
	//��ζ�̬���Ӳ���绰�Ŀͻ������޸� 
	callcenter.addCaller("����", other);
//	callcenter.addCaller("����", junior);
//	callcenter.addCaller("����", junior);
//	callcenter.addCaller("����", junior);
	callcenter.addCaller("����", junior);
	callcenter.addCaller("����", middle);
	callcenter.addCaller("����", junior);
	callcenter.addCaller("����", senior);
	callcenter.addCaller("Ǯ��", other);
	
	//��θ��ݿͻ����Ӷ���̬ѭ��ִ��handel �д��������� 
	callcenter.handel();

	return 0;
}
