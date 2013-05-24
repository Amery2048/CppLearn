#include <bitset>
#include <iostream>
//#define NDEBUG
#include <cassert>
using namespace std;
class SortWithBitmap
{
public:
		virtual void getNums(int)=0;
		virtual void getNums(ifstream& fin)=0;
		virtual void printSortedNums()=0;
		virtual void printSortedNums(ofstream& fout)=0;
		virtual void clean()=0;
};
/*
使用char数组实现
*/
class CharArrarySort:public SortWithBitmap
{
public:
	CharArrarySort(int n){
		N=n;
		int charSize=sizeof(unsigned char);
		bset =(unsigned char *)malloc(charSize*(N/charSize+1));
		if(bset==NULL) 
		{
			cout << "malloc failed"<< endl;
			exit(1);
		}
		//初始化bset所有位为0 或者用alloc自动初始化为0
		memset(bset,0,charSize*(N/charSize+1));
	}
	void setSize(){
		cout << "set size: " << N << endl;
	}
	virtual ~CharArrarySort(){
		cout << "destroy CharArrarySort" << endl;
		free(bset);
	}
	void getNums(int);
	void getNums(ifstream& fin);
	void printSortedNums();
	void printSortedNums(ofstream& fout);
	void clean();
	//测试
	void setTest(){
		//bset[0]=0;
		//bset[1]=0;
		set(2);
		set(2+8);
		assert(bset[1]==32);
		assert(isSeted(2)==true);
		assert(isSeted(3)==false);
		cout <<(int)bset[0]<<endl;
	}
private:
	int N;
	unsigned char* bset;
	void set(int position);
	bool isSeted(int position);
};

/*
用C++ 容器bitset实现，缺陷，bitset初始化时必须确定位数，
在栈中分配空间，位数不能太多，1千万个位时，栈溢出。
*/
class BitSetSort:public SortWithBitmap
{
public:
	enum{maxN=100000};
	BitSetSort(int n){
		if(n>maxN){
			cout << "SortWithBitmap w: N must smaller or eq than: "<< maxN<<endl;
			N=maxN;
		}
		else N=n;
	}
	void getNums(int);
	void getNums(ifstream& fin);
	void printSortedNums();
	void printSortedNums(ofstream& fout);
	void clean();
	void setSize(){cout << bset.size() << endl;}
private:
	int N;
	//如果maxN太大，会栈溢出,如何动态分配？
	bitset<maxN> bset;
};
