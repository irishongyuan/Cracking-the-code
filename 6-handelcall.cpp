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

//为了实现多线程，忍痛割爱掉父类，有机会想到更好的方式再补充 
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
				cout << "主管" << this->mDirId << " 号 is handling " << caller->getName() << "'s call." << endl;
				sleep(2);
				cout << "主管 " << this->mDirId << " 号服务完毕." << endl;	
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
				cout << "经理 " << this->mManId << " 号 is handling " << caller->getName() << "'s call." << endl;
				sleep(2);
				cout << "经理 " << this->mManId << " 号服务完毕." << endl;	
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

//多线程调用函数参数只能是一个void*，多参数只能用struct封装 
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
				cout << "接线员 " << *id << " 号 is handling " << caller->getName() << "'s call" << endl;
				sleep(1);
				cout << "接线员 " << *id << " 号服务完毕." << endl;	
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
				//有待改善 ： 
				//本来想用多线程完成接电话处理，但是创建多线程只能调用全局函数，即类中的static函数，
				//但是这里的 handelcall是虚函数，不能再定义为静态函数 ，故而取舍不继承，不要虚函数了
				int i=0;
				for (i = 0; i < respondents.size(); i++) {
					if(respondents_available[i]) {
						respondents_available[i] = false;
						Caller* caller = &(*callers.begin());
						cout << caller->getName() << "打来电话"<< endl;
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
					cout << "接线员忙请等待" << endl;
				} 
			}
			
			//父进程结束等待线程pId的完成
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
	
	//如何动态增加拨打电话的客户还需修改 
	callcenter.addCaller("张三", other);
//	callcenter.addCaller("李四", junior);
//	callcenter.addCaller("王五", junior);
//	callcenter.addCaller("赵六", junior);
	callcenter.addCaller("李四", junior);
	callcenter.addCaller("王五", middle);
	callcenter.addCaller("赵六", junior);
	callcenter.addCaller("孙七", senior);
	callcenter.addCaller("钱八", other);
	
	//如何根据客户增加而动态循环执行handel 有待后续补充 
	callcenter.handel();

	return 0;
}
