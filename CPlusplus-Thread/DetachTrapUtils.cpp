#include "MethodUtils.h"
#include "DetachTrapUtils.h"
#include <thread>
#include <string>

/*
������ʱ������Ϊ�̲߳���
*/
void invokeByTemp() {
	int mvar = 1;
	int mvr = 1;
	int& mvary = mvar;
	char mybuf[] = "this is a test!";
	//˼��:mybuf��ʲôʱ����ʽת����string��
	thread  mytobj(myprint_2, mvar, string(mybuf));

	//mytobj.join();//���̺߳����߳�ͬʱ����
	mytobj.detach();//���̺߳����̷ֱ߳�ִ��
	cout << "I Love China!" << endl;
}

/*
������ʱ����Ϊ�̲߳���
*/
void invokeByClass() {
	int mvar = 1;
	int mysecondpar = 12;
	thread  mytobj(myprint_4, mvar, MyObject(mysecondpar));//mybuf��ʲôʱ��ת����string
	//mytobj.join();
	mytobj.detach();
}