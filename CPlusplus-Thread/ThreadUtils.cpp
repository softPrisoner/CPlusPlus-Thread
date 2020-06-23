#include "MethodUtils.h"
#include "ThreadUtils.h"
#include <thread>
/*
ʹ�÷���ʵ���̵߳���ִ��
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
ʹ�������ʵ���̵߳���ִ��
*/
void invokeByClass() {
	int m_i = 6;
	//ǣ����value��copy
	TObject ta(m_i);
	thread mythread(ta);
	//mythread.join();
	mythread.detach();
}

/*
ʹ��lambda���ʽʵ���̵߳���ִ��
*/
void invokeByLambda() {
	//��������
	auto mylambda = [] {
		cout << "�ҵ��߳�3��ʼִ����" << endl;
	};
	thread mylambdathread(mylambda);
	mylambdathread.join();
}