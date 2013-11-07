// OrdinaryTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>


class A{
public:
	void test(){}
};
int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	int k=2;
	int m=(k++)+(++k);
	cout << m << endl;
	char a[]="123abcd";
	int i=0;
	for (i = 0; i < strlen(a); i++) {
		a[i]=a[i]*2+10;
		if(a[i]>120)a[i]=a[i]/3;
	}
	i=0;
	int j=strlen(a);
	while(i<j)
	{
		char temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;j--;
	}
	for (i = 0; i < strlen(a); i++) {
		cout << a[i]<< " "<< endl;
	}

	getchar();
	return 0;
}

