#include <set>
#include <algorithm>
//greater functinalͷ�ļ�������һ������չ��ģ�弯�ϣ����������������㷨�������ĺ�������
#include <functional>

template<class T,int K>
class MinOrMaxK
{
public:
	virtual void getNums(T)=0;
	virtual void getNums(T [])=0;
	virtual void printK()=0;
};
template<class T,int K>
class MinK : public MinOrMaxK<T,K>
{
public:
	virtual void getNums(T)=0;
	virtual void getNums(T [])=0;
	virtual void printK()=0;
	virtual void printMinK()=0;
};
template<class T,int K>
class MaxK : public MinOrMaxK<T,K>
{
public:
	virtual void getNums(T)=0;
	virtual void getNums(T [])=0;
	virtual void printK()=0;
	virtual void printMaxK()=0;
};

template<class T,int K>
class MinKWithMultiSet : public MinK<T,K>
{
public:
	virtual void getNums(T);
	virtual void getNums(T []);
	void printK(){printMinK();};
	virtual void printMinK();
private:
	std::multiset<T,std::greater<T> > numSet;
};