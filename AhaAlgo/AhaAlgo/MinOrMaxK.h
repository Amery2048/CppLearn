#include <set>
#include <algorithm>
//greater functinal头文件定义了一个可扩展的模板集合，用来创建可用于算法和容器的函数对象。
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