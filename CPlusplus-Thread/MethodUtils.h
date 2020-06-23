#pragma once
#include <iostream>
using namespace std;
#define THREAD_START "�ҵ��߳̿�ʼִ��\n"

#define THREAD_STOP "�ҵ��߳�ִ�����\n"
/*
�̴߳��ݶ���
*/
class MyObject {
	int& m_i;
public:
	MyObject(int& i) :m_i(i) {
		cout << "MyObject ���캯����ִ��" << endl;
		cout << "m_i��ֵ:" << m_i << endl;
	};
	//����󿽱�����
	MyObject(const MyObject& a) :m_i(a.m_i) {
		cout << "MyObject �������캯����ִ��" << endl;
	};

	~MyObject() {
		cout << "MyObject ����������ִ��" << endl;
	};
};

class TObject {
public:
	int& m_i;

	TObject(int& i) :m_i(i) {
		cout << "TObject ���캯����ִ��" << endl;
		cout << "m_i��ֵ:" << m_i << endl;
	};

	TObject(const TObject& ta) :m_i(ta.m_i) {
		cout << "TObject �������캯����ִ��" << endl;
	};

	~TObject() {
		cout << "TObject ����������ִ��" << endl;
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
/*
�޲κ�������
*/
void myprint_1();
/*
����ָ�����
*/
void myprint_2(const int& i, char* pmybuf);
/*
�����ַ�������
*/
void myprint_3(const int& i, const string& pmybuf);
/*
���������
*/
void myprint_4(const int& i, const MyObject& pmybuf);

