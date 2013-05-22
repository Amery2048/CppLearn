#include <fstream>
#include <iostream>
#include "SortWithBitmap.h"
using namespace std;
void BitSetSort::getNums(int a)
{
	if(a>=0 && a<N) bset.set(a);
	else cout << "out of bound!" << endl;
}
void BitSetSort::getNums(ifstream& fin)
{
	cout << "read num from file..."<< endl;
	int nu;
	int i=0;
	while(fin >> nu && i<N)
	{
		getNums(nu);
		i++;
	}
	if(!fin.eof()){
		cout << "this file have more numbers than this class can deal!"<< endl;
		return;
	}
}
void BitSetSort::printSortedNums()
{
	for(int i=0;i<N;i++)
	{
		if(bset[i]==1)
		{
			cout << i <<endl;
		}else
		{
			continue;
		}
	}
}
void BitSetSort::printSortedNums(ofstream& fout)
{
	for(int i=0;i<N;i++)
	{
		if(bset[i]==1)
		{
			fout << i <<endl;
		}else
		{
			continue;
		}
	}
	cout << "The sorted secquence has been written to file" << endl;
}
void BitSetSort::clean(){
	bset.reset();
}

void CharArrarySort::getNums(int a)
{
	if(a>=0 && a<N) set(a);
	else cout << "out of bound!" << endl;
}
void CharArrarySort::getNums(ifstream& fin)
{
	cout << "read num from file..."<< endl;
	int nu;
	while(fin >> nu)
	{
		getNums(nu);
	}
}
void CharArrarySort::printSortedNums()
{
	for(int i=0;i<N;i++){
		if(isSeted(i)){ cout << i << endl;}
		else continue;
	}
}

void CharArrarySort::printSortedNums(ofstream& fout)
{
	for(int i=0;i<N;i++){
		if(isSeted(i)){ fout << i << endl;}
		else continue;
	}
	cout << "The sorted secquence has been written to file" << endl;
}
void CharArrarySort::clean(){
	int charSize=sizeof(unsigned char);
	memset(bset,0,charSize*(N/charSize+1));
}
void CharArrarySort::set(int position){
	int upOffset=position/8;
	int subOffset=position%8;
	unsigned char mask=1;
	mask = mask<<(7-subOffset);
	bset[upOffset]=bset[upOffset]|mask;
}
bool CharArrarySort::isSeted(int position){
	int upOffset=position/8;
	int subOffset=position%8;
	/*
	unsigned char mask=1;
	mask=mask << (7-subOffset);
	mask=mask&bset[upOffset];
	*/
	unsigned char mask=1<<7;
	mask >>=subOffset;
	mask &=bset[upOffset];

	if(mask==0) return false;
	else return true;
}