#include "MethodUtils.h"
#include "ThreadUtils.h"
#include <thread>
/*
使用方法实现线程调用执行
*/
void invokeByMethod() {
	thread mythread(myprint_1);
	//mythread.join();
	cout << mythread.joinable() << endl;
	mythread.detach();
	cout << mythread.joinable() << endl;
	mythread.joinable();
}
/*
使用类对象实现线程调用执行
*/
void invokeByClass() {
	int m_i = 6;
	//牵扯到value的copy
	TObject ta(m_i);
	thread mythread(ta);
	//mythread.join();
	mythread.detach();
}

/*
使用lambda表达式实现线程调用执行
*/
void invokeByLambda() {
	//匿名函数
	auto mylambda = [] {
		cout << "我的线程3开始执行了" << endl;
	};
	thread mylambdathread(mylambda);
	mylambdathread.join();
}