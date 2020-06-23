#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <thread>
#include <stdio.h>
using namespace std;


class A {
	int& m_i;
public:
	A(int& i) :m_i(i) {
		cout << "A 构造函数被执行" << endl;
		cout << "m_i的值:" << m_i << endl;
	};
	A(const A& a) :m_i(a.m_i) {
		cout << "A 拷贝构造函数被执行" << endl;
	};
	~A() {
		cout << "A 析构函数被执行" << endl;
	};
};

//void myprint(const int& i, char* pmybuf) {
//void myprint(const int& i, const string& pmybuf) {
void myprint(const int i, const A& pmybuf) {
	cout << "我的线程开始执行\n" << endl;
	cout << i << endl;
	cout << &pmybuf << endl;
	cout << "我的线程执行完毕\n" << endl;
	return;
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
	//auto mylambda = [] {
	//	cout << "我的线程3开始执行了" << endl;
	//};
	//thread mylambdathread(mylambda);
	//mylambdathread.join();
	//cout << "主线程执行完毕\n" << endl;
	//return 0;

//#############################################detach陷阱
	//传递临时对象作为线程参数
	//（1.1）要避免的陷阱
	//int mvar = 1;
	//int mvr = 1;
	//int& mvary = mvar;
	//char mybuf[] = "this is a test!";
	//thread  mytobj(myprint, mvar, string(mybuf));//mybuf在什么时候转换成string
	////mytobj.join();//子线程和主线程同时运行
	//mytobj.detach();//子线程和主线程分别执行
	//cout << "I Love China!" << endl;
	//#####################################模拟过程
	int mvar = 1;
	int mysecondpar = 12;
	thread  mytobj(myprint, mvar, A(mysecondpar));//mybuf在什么时候转换成string
}
