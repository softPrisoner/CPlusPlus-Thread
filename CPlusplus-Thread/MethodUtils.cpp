#include "MethodUtils.h"

/*
�޲κ�������
*/
void myprint_1() {

}
/*
����ָ�����
*/
void myprint_2(const int& i, char* pmybuf) {
	cout << THREAD_START << endl;
	cout << i << endl;
	cout << &pmybuf << endl;
	cout << THREAD_STOP << endl;
	return;
}
/*
�����ַ�������
*/
void myprint_3(const int& i, const string& pmybuf) {
	cout << THREAD_START << endl;
	cout << i << endl;
	cout << &pmybuf << endl;
	cout << THREAD_STOP << endl;
	return;
}
/*
���������
*/
void myprint_4(const int i, const MyObject& pmybuf) {
	cout << THREAD_START << endl;
	cout << i << endl;
	cout << &pmybuf << endl;
	cout << THREAD_STOP << endl;
	return;
}