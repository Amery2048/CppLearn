// OrdinaryTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
class A
{
public:
	//A(){cout << "hey" << endl;}
	A(int n=0):a(n){cout << "hey" << endl;}
	void print(){
		cout <<"a: "<< a<<endl;
	}
private:
	int a;
};

/*
//���ܰ������ķ�ʽ������ĳ��ȡ�
template <typename T>
int array_length(const T &arr[])
{
	return sizeof(arr)/sizeof(T);
};
*/
//���԰���ķ�ʽ��
#define Array_Length(arr,type) sizeof(arr)/sizeof(type);

int _tmain(int argc, _TCHAR* argv[])
{
	//char a='a';
	//char b;
	//const char *p=&a;  //const decrate that the content of p is constant
	//char * const p=&a; //const decrate that the pointer p itself is constant
	
	/*
	wchar_t c =L'��';
	locale loc=wcout.imbue(std::locale("chs"));//���õ���chs ��ʾ�й���ʹ��wcout�ܹ���������ַ�
	wcout << c << endl;
	A aInstance;

	string str;

	char a[20];
	cin.getline(a,10);
	//getline(cin,str);

	int num=1;
	void change(int &);
	change(num);//change �������ã����change�������Ըı�num��ֵ
	cout << num;
	*/
	/**********���С�˲���**********/
	/*
	char s[]="123456789";//{'0','1','2','3','4','5','6','7','8','9'};
	for (int i=0;i<(int)strlen(s);i++)
		cout << (int)&s[i]<<": "<<s[i]<<endl;
	int a=(12<<8)+16;
	char * b;

	b=(char *)&a;


	cout << (int)&b<<": "<<endl;

	cout << (int)b<<": "<<(int)(*b)<<endl;
	cout << (int)(b+1)<<": "<<(int)*(b+1)<<endl;
	*/
	/**********���С�˲���**********/
	/**********���캯������**********/
	//A a;
	//a.print();
	/**********���캯������**********/
	/**********��������**********/
	
	string strs[]={"pig","cat","Cat","dog","pie","pig"};
	cout << Array_Length(strs,string);
	cout << endl;

	int len=sizeof(strs)/sizeof(string);

	vector<string> strVector(len);
	vector<string> wordsArr;
	/*
	string input;

	while(cin >> input && input!="quit")
		wordsArr.push_back(input);
		*/

	ostream_iterator<string,char> out_iter (cout," ") ;//string ��ʾ���뵽��������,char��ʾ����������ͣ�һ�����ܵ�ֵΪwchar_t)

	//copy(&strs[0],&strs[0]+sizeof(strs)/sizeof(string),
	//	strVector.begin());//strVector����Ϊ�գ�����������ʱ�����ָ����С,�����ø��ò����������

	copy(&strs[0],&strs[0]+sizeof(strs)/sizeof(string),
		insert_iterator<vector<string>>(wordsArr,wordsArr.begin()));//strVector����Ϊ�գ�����������ʱ�����ָ����С,�����ø��ò����������

	cout <<"origenal strings: "<<endl;
	copy(wordsArr.begin(),wordsArr.end(),out_iter);
	cout <<endl;
	cout <<endl;

	set<string> wordSet;
	string & ToLower(string &);
	transform(wordsArr.begin(),wordsArr.end(),
		insert_iterator<set<string>>(wordSet,wordSet.begin()),ToLower);
	cout <<"tolower and unique: "<<endl;
	copy(wordSet.begin(),wordSet.end(),out_iter);
	cout <<endl;
	cout <<endl;

	map<string,int> wordCount;
	set<string>::iterator it;
	for(it=wordSet.begin();it!=wordSet.end();it++)
		wordCount.insert(
		pair<string,int>(*it, count(wordsArr.begin(),wordsArr.end(),*it)));
	//wordCount[*it]=count(wordsArr.begin(),wordsArr.end(),*it)
	cout<<"world count:"<<endl;

	for(it=wordSet.begin();it!=wordSet.end();it++)
		cout << *it<< ": "<<wordCount[*it]<<endl;

	/*
	vector<string>::iterator it;
	for(it=wordsArr.begin();it!=wordsArr.end();it++)
		cout << *it<<endl;
		*/
	 
	/**********��������**********/

	cin.clear();
	getchar();
	getchar();
	return 0;
}

void change(int &a){
	a=2;
}
string & ToLower(string & st)
{
	transform(st.begin(),st.end(),st.begin(),tolower);
	return st;
}
