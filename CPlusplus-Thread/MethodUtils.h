#pragma once
#include <iostream>
using namespace std;
#define THREAD_START "我的线程开始执行\n"

#define THREAD_STOP "我的线程执行完毕\n"
/*
线程传递对象
*/
class MyObject {
	int& m_i;
public:
	MyObject(int& i) :m_i(i) {
		cout << "MyObject 构造函数被执行" << endl;
		cout << "m_i的值:" << m_i << endl;
	};
	//类对象拷贝函数
	MyObject(const MyObject& a) :m_i(a.m_i) {
		cout << "MyObject 拷贝构造函数被执行" << endl;
	};

	~MyObject() {
		cout << "MyObject 析构函数被执行" << endl;
	};
};

class TObject {
public:
	int& m_i;

	TObject(int& i) :m_i(i) {
		cout << "TObject 构造函数被执行" << endl;
		cout << "m_i的值:" << m_i << endl;
	};

	TObject(const TObject& ta) :m_i(ta.m_i) {
		cout << "TObject 拷贝构造函数被执行" << endl;
	};

	~TObject() {
		cout << "TObject 析构函数被执行" << endl;
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
/*
无参函数对象
*/
void myprint_1();
/*
传递指针参数
*/
void myprint_2(const int& i, char* pmybuf);
/*
传递字符串引用
*/
void myprint_3(const int& i, const string& pmybuf);
/*
传递类对象
*/
void myprint_4(const int& i, const MyObject& pmybuf);

