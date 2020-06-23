#include "MethodUtils.h"
#include "DetachTrapUtils.h"
#include <thread>
#include <string>

/*
传递临时对象作为线程参数
*/
void invokeByTemp() {
	int mvar = 1;
	int mvr = 1;
	int& mvary = mvar;
	char mybuf[] = "this is a test!";
	//思考:mybuf在什么时候隐式转换成string？
	thread  mytobj(myprint_2, mvar, string(mybuf));

	//mytobj.join();//子线程和主线程同时运行
	mytobj.detach();//子线程和主线程分别执行
	cout << "I Love China!" << endl;
}

/*
传递临时类作为线程参数
*/
void invokeByClass() {
	int mvar = 1;
	int mysecondpar = 12;
	thread  mytobj(myprint_4, mvar, MyObject(mysecondpar));//mybuf在什么时候转换成string
	//mytobj.join();
	mytobj.detach();
}