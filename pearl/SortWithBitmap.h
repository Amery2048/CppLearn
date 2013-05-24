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
ʹ��char����ʵ��
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
		//��ʼ��bset����λΪ0 ������alloc�Զ���ʼ��Ϊ0
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
	//����
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
��C++ ����bitsetʵ�֣�ȱ�ݣ�bitset��ʼ��ʱ����ȷ��λ����
��ջ�з���ռ䣬λ������̫�࣬1ǧ���λʱ��ջ�����
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
	//���maxN̫�󣬻�ջ���,��ζ�̬���䣿
	bitset<maxN> bset;
};
