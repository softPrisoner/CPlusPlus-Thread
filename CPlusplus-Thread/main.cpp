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
		cout << "A ���캯����ִ��" << endl;
		cout << "m_i��ֵ:" << m_i << endl;
	};
	A(const A& a) :m_i(a.m_i) {
		cout << "A �������캯����ִ��" << endl;
	};
	~A() {
		cout << "A ����������ִ��" << endl;
	};
};

//void myprint(const int& i, char* pmybuf) {
//void myprint(const int& i, const string& pmybuf) {
void myprint(const int i, const A& pmybuf) {
	cout << "�ҵ��߳̿�ʼִ��\n" << endl;
	cout << i << endl;
	cout << &pmybuf << endl;
	cout << "�ҵ��߳�ִ�����\n" << endl;
	return;
}

class TA {
public:
	int& m_i;

	TA(int& i) :m_i(i) {
		cout << "TA ���캯����ִ��" << endl;
		cout << "m_i��ֵ:" << m_i << endl;
	};

	TA(const TA& ta) :m_i(ta.m_i) {
		cout << "TA �������캯����ִ��" << endl;
	};

	~TA() {
		cout << "TA ����������ִ��" << endl;
	};

	void operator()() {
		cout << "�ҵ��߳�operator()��ʼִ��\n" << endl;
		cout << "m_i1��ֵ:" << m_i << endl;
		cout << "m_i2��ֵ:" << m_i << endl;
		cout << "m_i3��ֵ:" << m_i << endl;
		cout << "m_i4��ֵ:" << m_i << endl;
		cout << "m_i5��ֵ:" << m_i << endl;
		cout << "m_i6��ֵ:" << m_i << endl;
		cout << "�ҵ��߳�operator()ִ�����\n" << endl;
	}
};
//����ִ��˳���ܸı�
int main() {
	cout << "���߳̿�ʼִ��\n" << endl;
	//#######################################ʹ�÷���ʵ���̵߳���ִ��
	//thread mythread(myprint);
	////mythread.join();
	//cout << mythread.joinable() << endl;
	//mythread.detach();
	//cout << mythread.joinable() << endl;
	//mythread.joinable();
	//#####################################ʹ�������ʵ���̵߳���ִ��
	int m_i = 6;
	//����ǣ����value��copy
	//TA ta(m_i);
	//thread mythread2(ta);
	//mythread2.join();
	//mythread2.detach();
	//###################################ʹ��lambda���ʽʵ���̵߳���ִ��
	//��������
	//auto mylambda = [] {
	//	cout << "�ҵ��߳�3��ʼִ����" << endl;
	//};
	//thread mylambdathread(mylambda);
	//mylambdathread.join();
	//cout << "���߳�ִ�����\n" << endl;
	//return 0;

//#############################################detach����
	//������ʱ������Ϊ�̲߳���
	//��1.1��Ҫ���������
	//int mvar = 1;
	//int mvr = 1;
	//int& mvary = mvar;
	//char mybuf[] = "this is a test!";
	//thread  mytobj(myprint, mvar, string(mybuf));//mybuf��ʲôʱ��ת����string
	////mytobj.join();//���̺߳����߳�ͬʱ����
	//mytobj.detach();//���̺߳����̷ֱ߳�ִ��
	//cout << "I Love China!" << endl;
	//#####################################ģ�����
	int mvar = 1;
	int mysecondpar = 12;
	thread  mytobj(myprint, mvar, A(mysecondpar));//mybuf��ʲôʱ��ת����string
}
