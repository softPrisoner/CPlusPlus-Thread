#include "MethodUtils.h"

/*
无参函数对象
*/
void myprint_1() {

}
/*
传递指针参数
*/
void myprint_2(const int& i, char* pmybuf) {
	cout << THREAD_START << endl;
	cout << i << endl;
	cout << &pmybuf << endl;
	cout << THREAD_STOP << endl;
	return;
}
/*
传递字符串引用
*/
void myprint_3(const int& i, const string& pmybuf) {
	cout << THREAD_START << endl;
	cout << i << endl;
	cout << &pmybuf << endl;
	cout << THREAD_STOP << endl;
	return;
}
/*
传递类对象
*/
void myprint_4(const int i, const MyObject& pmybuf) {
	cout << THREAD_START << endl;
	cout << i << endl;
	cout << &pmybuf << endl;
	cout << THREAD_STOP << endl;
	return;
}