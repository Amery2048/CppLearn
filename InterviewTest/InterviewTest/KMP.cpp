#include "stdafx.h"
#include "Fun.h"
using namespace std;
int my_find(char * str,char * substr)
{
	int substrLen=strlen(substr);
	int strLen=strlen(str);
	vector<int> maxLen(substrLen);
	//maxLen[j]Ϊ�Ӵ�substr[0..j](0<=j<=strlen(substr)-1) һ��ǰ׺�ĳ���,
	//��ǰ׺ͬ���ִ���һ����׺��ͬ,ǰ׺�ͺ�׺�ıȽϲ����ƥ��
	int j;
	maxLen[0]=0;
	for(j=1;j<substrLen;j++)
	{
		int k=j-1;
		int z=maxLen[k];
		while(z>=0)
		{
			if(substr[j]==substr[z]) { maxLen[j]=maxLen[k]+1; break; }
			else if(z==0) { maxLen[j]=0; break; }
			k=z-1;
			z=maxLen[k];
		}
	}
	/*
	ostream_iterator<int,char>out(cout," ");
	copy(maxLen.begin(),maxLen.end(),out);
	cout <<endl;
	*/
	//ƥ��
	int i=0;
	j=0;
	for(;i<strLen;i++)
	{
		for(;j<substrLen;)
		{
			if(str[i]!=substr[j]) 
			{
				if (j==0) break;
				j=maxLen[j-1];
				continue;
			}
			j++;i++;
		}
		if(j==substrLen) break;
	}
	return i-substrLen;
}