#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <thread>
#include <stdio.h>
using namespace std;



void myprint() {
	cout << "我的线程开始执行\n" << endl;
	cout << "我的线程执行完毕\n" << endl;
}

class TA {
public:
	int& m_i;

	TA(int& i) :m_i(i) {
		cout << "TA 构造函数被执行" << endl;
		cout << "m_i的值:" << m_i << endl;
	};

	TA(const TA& ta) :m_i(ta.m_i) {
		cout << "TA 拷贝构造函数被执行" << endl;
	};

	~TA() {
		cout << "TA 析构函数被执行" << endl;
	};

	void operator()() {
		cout << "我的线程operator()开始执行\n" << endl;
		cout << "m_i1的值:" << m_i << endl;
		cout << "m_i2的值:" << m_i << endl;
		cout << "m_i3的值:" << m_i << endl;
		cout << "m_i4的值:" << m_i << endl;
		cout << "m_i5的值:" << m_i << endl;
		cout << "m_i6的值:" << m_i << endl;
		cout << "我的线程operator()执行完毕\n" << endl;
	}
};
//方法执行顺序不能改变
int main() {
	cout << "主线程开始执行\n" << endl;
	//#######################################使用方法实现线程调用执行
	//thread mythread(myprint);
	////mythread.join();
	//cout << mythread.joinable() << endl;
	//mythread.detach();
	//cout << mythread.joinable() << endl;
	//mythread.joinable();
	//#####################################使用类对象实现线程调用执行
	int m_i = 6;
	//这里牵扯到value的copy
	//TA ta(m_i);
	//thread mythread2(ta);
	//mythread2.join();
	//mythread2.detach();
	//###################################使用lambda表达式实现线程调用执行
	//匿名函数
	auto mylambda = [] {
		cout << "我的线程3开始执行了" << endl;
	};
	thread mylambdathread(mylambda);
	mylambdathread.join();
	cout << "主线程执行完毕\n" << endl;
	return 0;
}