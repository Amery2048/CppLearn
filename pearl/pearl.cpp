#include <iostream>
#include <cstdlib>
#include <set>
#include <fstream>
#include <ctime>
#include <list>
#include <algorithm>
#include "helper.h"
#include "SortWithBitmap.h"
#define  N 100000 
using namespace std;
void getfloyd(int m,int n,ofstream& fout){
	set<int> s;
	set<int>::iterator i;
	for (int j=n-m; j<n;j++)
	{
		int t =mybigrand()%(j+1);
		if (s.find(t)==s.end())
		{
			fout << t <<endl;
			s.insert(t);
		}
		else {
			fout << j << endl;
			s.insert(j);
		}
	}
	/*
	for(i=s.begin();i!=s.end();i++)
		fout << *i << endl;
		*/
}
void getUnsortedN(unsigned int n){
	set<int> s;
	set<int>::iterator i;
	while (s.size() < n){
		int current=mybigrand()%n;
		if (s.find(current)==s.end())
		{
			cout << current << endl;
			s.insert(current);
		}
	}
	for(i=s.begin();i!=s.end();i++)
		cout << *i << endl;
}
void swp(int s[],int i,int j){
	int temp=s[i];
	s[i]=s[j];
	s[j]=temp;
}
void getUnsortedWithDisturbArray(int n,ofstream& fout){ //1вк 172s
	int *s;
	s=(int *)malloc(sizeof(int)*n);
	int i;
	for (i=0;i<n;i++)
	{
		s[i]=i;
	}
	for (i=0;i<n;i++)
	{
		int j=randint(i,n);
		swp(s,i,j);
	}
	for (i=0;i<n;i++)
	{
		fout << s[i] << endl;
	}
}
void CharArrarySortTest(){
	/*

	CharArrarySort charSort(10);
	charSort.setSize();

	it=intList.begin();
	while(it!=intList.end()){
		cout << *it <<endl;
		charSort.getNums(*it);
		it++;
	}
	*/
	//charSort.setTest();
	
	CharArrarySort charSort(N);
	ifstream fin;
	fin.open("data_nums.txt",ios::in);
	//fin.open("f2.txt",ios::in);
	ofstream fout;
	fout.open("sorted_data.txt",ios::out);
	/*
	int nu;
	while(fin >> nu)
	{
		charSort.getNums(nu);
	}
	*/

	//for_each(intList.begin(),intList.end(),&CharArrarySort::getNums);
	cout << "getNums"<<endl;
	charSort.getNums(fin);
	cout << "printSortedNums"<<endl;
	charSort.printSortedNums(fout);
	fin.close();
	fout.close();
}
void BitSetSortTest(){
	//sort
	BitSetSort a(N);
	a.getNums(30);
	a.getNums(20);
	a.getNums(50);
	a.printSortedNums();
	a.clean();
	ifstream fin;
	fin.open("data_nums.txt",ios::in);
	//fin.open("f2.txt",ios::in);
	ofstream fout;
	fout.open("sorted_data.txt",ios::out);
	a.getNums(fin);
	a.printSortedNums(fout);
	fin.close();
	fout.close();
}
void sortTest(SortWithBitmap& s){
	time_t start;
	time_t end;
	time(&start);
	s.getNums(30);
	s.getNums(20);
	s.getNums(50);
	s.printSortedNums();
	s.clean();
	ifstream fin;
	//fin.open("data_nums.txt",ios::in);
	fin.open("data.txt",ios::in);
	ofstream fout;
	fout.open("sorted_data.txt",ios::out);
	s.getNums(fin);
	s.printSortedNums(fout);
	fin.close();
	fout.close();
	time(&end);
	cout << "sort time: "<< difftime(end,start)<< endl;
}
void genData(){
	cout << "gen data"<< endl;
	//getUnsortedN(n);
	//getfloyd(n,n,fout);
	ofstream fout;
	fout.open("data.txt",ios::out);
    getUnsortedWithDisturbArray(N,fout);
}
void printInt(int a){
	cout << a << endl;
}
int main(){
	/*
	cout << RAND_MAX <<endl<<rand()<<endl<<mybigrand()<<endl;
	int l=5000;
	int u=50000;
	cout << l << endl<<u<<endl<<randint(l,u)<<endl;
	
	int m=0;
	while(m<100){
		cout << mybigrand() << endl;
		m++;
	}
	*/
	int i=0;
	/*
	for(;i<100;i++){
		cout << randint(0,5) << endl;
	}
	*/
	int n=N;
	time_t start;
	time_t end;
	time(&start);
	genData();
	time(&end);
	cout << "gen data time: "<< difftime(end,start)<< endl;

	BitSetSort s(N);
	CharArrarySort s1(N);
	//s1.setTest();
	sortTest(s);
	sortTest(s1);
	list<int> a;
	a.insert(a.begin(),23);
	a.insert(a.begin(),25);
	a.insert(a.begin(),22);
	for_each(a.begin(),a.end(),printInt);

	//fout.close();
	char proEnd;
	cin >> proEnd;
	return 0;
}