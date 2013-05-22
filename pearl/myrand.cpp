#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int mybigrand(){
	static int r;
	/*
	time_t t=time(0); //在很短时间内，time(NULL)返回相同值
	cout << t;
	*/
	r=RAND_MAX*rand()+rand();
	srand((unsigned)r);
	return r;
}
int randint(int l,int u){
	static int r;
	r=rand()*RAND_MAX+rand();
	srand((unsigned)r);
	return(l+r%(u-l));
}