// AhaAlgo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MinOrMaxK.h"
#include <vector>
#include <iostream>
#include <iterator>

#define Arr_Len(arr) sizeof(arr)/sizeof(arr[0])


using namespace std;

typedef int HeapType;
int _tmain(int argc, _TCHAR* argv[])
{
	/*
	vector<int> intVect;
	intVect.push_back(1);
	intVect.push_back(2);

	cout << intVect[0]<<endl;
	cout << intVect[1]<<endl;

	cout <<  "hello" <<endl;
	*/

	
	HeapType a[]={4,5,2,6,7,8,1,5,2,6,7,8,1};
	std::ostream_iterator<int,char> out_iter (cout," ") ;//string 表示输入到流的类型,char表示流输出的类型（一个可能的值为wchar_t)

	void AdjustHeap(HeapType *H,int s,int e);
	void HeapSort(HeapType *H,int size);
	/*
	cout << Arr_Len(a)<< endl;
	for (int i=Arr_Len(a)/2;i>=0;i--)
	{
		AdjustHeap(a,i,Arr_Len(a)-1);
	}
	for(int i=Arr_Len(a)-1;i>0;i--)
	{
		cout << "test"<<endl;
		HeapType temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		AdjustHeap(a,0,i-1);
	}
	*/

	copy(a,a+Arr_Len(a),out_iter);
	cout << endl;
	HeapSort(a,Arr_Len(a));
	copy(a,a+Arr_Len(a),out_iter);
	cout << endl;

	system("pause");
	return 0;
}
void AdjustHeap(HeapType *H,int s,int e)
{
	if(s>=e) return;//
	HeapType rc=H[s];
	int j=2*s;
	while(j<=e-1)
	{
		if(H[j]<H[j+1]) j=j+1;
		if(rc >= H[j] ) break;
		H[s]=H[j];s=j;j=2*s;
	}
	H[s]=rc;
}
void HeapSort(HeapType *H,int len)
{
	for (int i=len/2;i>=0;i--)
	{
		AdjustHeap(H,i,len-1);
	}
	for(int i=len-1;i>0;i--)
	{
		HeapType temp=H[0];
		H[0]=H[i];
		H[i]=temp;
		AdjustHeap(H,0,i-1);
	}
}