#include "stdafx.h"
#include "Fun.h"
using namespace std;

string getMaxSubStr(string strs[],int len)
{
	int i=0;
	int j=0;
	size_t minLen=0;
	while(i<len)//���ҵ���̵��ַ���
	{
		if(minLen<strs[i].size()){minLen=strs[i].size();j=i;}
		i++;
	}
	string substr;//�洢��̵��Ǹ��ַ������ִ���������ִ���ʼ�鿴�Ƿ��Ǹ�����N���ַ����Ĺ����ִ�
	size_t n;
	size_t m=n=minLen;

	i=0;
	int k=0;
	while(m>0)
	{
		while((i+m)<=minLen)
		{
			substr=strs[j].substr(i,m);
			while(k<len)//���õ����ִ��Ƿ��Ǹ���N���ַ����Ĺ����ִ���
			{
				if(k==j){k++;continue;}
				if(strs[k].find(substr)==string::npos) break;
				k++;
			}
			if(k==len)return substr;//�õ�������ִ������ء�
			else k=0;
			i++;
		}
		i=0;m--;
	}
	return "";
}

//����������С������ֵ֮�͡�
int SumOfMaxMin(int *nums,int len)
{
	int max=*nums,min=*nums;
	int i=1;
	while(i<len)
	{
		if(max<nums[i])max=nums[i];
		else if(min>nums[i])min=nums[i];
		i++;
	}
	return max+min;
}

/*
��һ���ַ�����Ԫ����ĸ���Ƶ���һ���ַ�����������30�֣�����������multiset?��
������������һ�ַ�����������ܰ���Ӣ����ĸ����д��Сд�������֡������ַ���
������Ҫʵ��һ�����������ַ����е�Ԫ����ĸ��ѡ������������һ���ַ����У�
�����ַ����е���ĸ���д�С���������Сд��Ԫ����ĸ��ǰ����д��Ԫ����ĸ�ں��������򣩡�
˵����1�� Ԫ����ĸ��a,e,i,o,u,A,E,I,O,U�� 2�� ɸѡ������Ԫ����ĸ������Ҫ���أ�
����������ַ�����СдԪ����ĸ����ǰ�棬��дԪ����ĸ���ں��棬��������
Ҫ��ʵ�ֺ�����void sortVowel (char* input, char* output);
*/
void sortVowel (char* input, char* output)
{
	multiset<char,less<char>>vowSet;
	char *cur=input;
	while(*cur!='\0')//��Ԫ����ĸ���η���multiset�У���������
	{
		switch(*cur)
		{
		case 'a': case 'e': case 'i':
		case 'o': case 'u': case 'A':
		case 'E': case 'I': case 'O':
		case 'U':{vowSet.insert(*cur);}
		default:
			break;
		}
		cur++;
	}
	multiset<char>::iterator start;
	multiset<char>::iterator it;

	start=vowSet.begin();//��λ��дԪ����ĸ��ʼ��λ��
	while(*start<'a')
		start++;
	it=start;
	int i=0;
	while(it!=vowSet.end())//��СдԪ����ĸ���
	{
		output[i]=*it;
		i++;it++;
	}
	it=vowSet.begin();
	while(it!=start)//����дԪ����ĸ���
	{
		output[i]=*it;
		i++;it++;
	}
	output[i]='\0';
}

//�˿����
int poker(int a[],int len)
{
	multiset<int> pokerSet;
	int i=0;
	while(len>i)
	{
		pokerSet.insert(a[i]);
		i++;
	}
	vector<int> sortedPoker;
	copy(pokerSet.begin(),pokerSet.end(),insert_iterator<vector<int>>(sortedPoker,sortedPoker.begin()));
	multiset<int> s;
	int m=0,n=sortedPoker.size()-1;
	while(n>m)
	{
		int k=1;
		while(sortedPoker[n]==sortedPoker[n-1])
		{
			k++;n--;
		}
		s.insert(k); n--;k=1;
		while(sortedPoker[m]==sortedPoker[m+1])
		{
			k++;m++;
		}
		s.insert(k); m++;
	}
	multiset<int>::reverse_iterator bit=s.rbegin();
	switch (*bit)
	{
	case 4: cout << "����"<<endl;return 1;
	case 3: 
		{
			bit++;
			if(*bit==2) {cout <<"����һ��"<<endl;return 2;} 
			else {cout <<"��������"<<endl;return 3;}
			break;
		}
	case 2:
		{
			bit++;
			if(*bit==2) {cout <<"����"<<endl;return 4;}
			else {cout<<"һ��"<<endl;return 7;}
			break;
		}
	default:
		int i=0,j=1;
		while(j<len)
		{
			if(sortedPoker[j]!=sortedPoker[i]+1) break;
			i++;j++;
		}
		if(j>=len) {cout << "˳��"<<endl;return 5;}
		else {cout << "ʲô������"<<endl;return 6;}
		break;
	}
}
//����������
int calculate(int len,char *expStr)
{
	stack<char> Op;//��¼������
	stack<int>Num;//��¼������
	char *cur=expStr;
	//�Ƚ��г˳�������
	while (*cur!='\0')
	{
		switch (*cur)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			{Op.push(*cur); break; }//��������ջ
		default://���������
			if(*cur>='0'&& *cur<='9')
			{
				if(!Op.empty() && (Op.top()=='*'||Op.top()=='/'))//����˷����߳��������ѹջ.
				{
					int a=Num.top(); Num.pop();
					Op.top()=='*' ? a*=(*cur-'0'):a/=(*cur-'0');
					Num.push(a); Op.pop();
				}
				else Num.push(*cur-'0');
			}
			break;
		}
		cur++;
	}
	//����ʣ�µļӷ�����
	int result=Num.top();
	Num.pop();
	while(!Op.empty())
	{
		char op=Op.top();
		op=='+'?result+=Num.top():result=Num.top()-result;//ע�⸺��ʱ�ļ���
		Num.pop();
		Op.pop();
	}
	return result;
}
//Լɪ������
void array_iterate(int len,int input[],int m,int output[])
{
	//��ԭ�����У���0����Ѿ����е�λ�á�
	int i=0,j=0;//i����ѳ��и���,j����ѭ��������������
	while(i<len)
	{
		if(input[j]>0)
		{
			if(m==1)
			{
				m=input[j];
				output[i]=m;
				input[j]=0;//��0����Ѿ����е���
				i++;
			}
			else
				m--;
		}
		j=(j+1)%len;
	}
}
/*
3 ��������
����������    
�������ⳤ�ȵ�����������������������Դ�С���㣬Ҳ���������������������� 
������ַ����У�������ֳ���������С������������� �ַ���������ֶ��С��
���Լ�С�����ڵ�һ���ַ���λ�õȷǷ���������Կ����ĳ��������뿼�������
��ֵ�ַ����Ƿ�������� 
��ϸҪ���Լ�Լ����
1.�����Ϊ���������������Ϊ������ 
2.���������Ϊ�ַ�����ʽ��
3.����������������Ҫ�����ţ����Ϊ������������Ľ���ַ�����Ҫ������
���磺2.2-1.1 ֱ�����Ϊ��1.1����1.1-2.2 ����Ҫ���Ϊ��-1.1��
 4.����Ľ���ַ�����Ҫ���˵�����λǰ�Լ�С��λ����Ч��0��С��λΪȫ0�ģ�ֱ���������λ
����������Ϊ11.345������ֵǰ��������Դ�0����011.345�����ߡ�0011.34500���ȵ�ǰ�����Ч0�ľ���Ϊ���� ���������1.1-1.1���Ϊ0.0����ֱ�����0��
Ҫ��ʵ�ֺ�����
void Decrease(char *input1, char*input2, char *output)
�����롿 char *iinput1 ������ char*nput2 ���� 
������� char *output �������
�����ء� ��
ʾ��
���룺char *input1="2.2" 
char *input2="1.1"
�����char*output="1.1"
���룺char *input1="1.1" 
char *input2="2.2"
�����char *output="-1.1"
*/
int numAfterDot(char *input);
void Decrease1(char *input1,char *input2,char *output)
{
	//��ǽ������
	bool underZero=false;

	string a(input1);
	string b(input2);
	string out;
	string::reverse_iterator riter_l;
	string::reverse_iterator riter_r;

	//�õ�С�������λ��
	int aftDotLen1=numAfterDot(input1);
	int aftDotLen2=numAfterDot(input2);

	//�õ�С����ǰλ��,���ڱȽϲ������Ĵ�С
	int preDot1Len=aftDotLen1?strlen(input1)-aftDotLen1-1:strlen(input1);
	int preDot2Len=aftDotLen2?strlen(input2)-aftDotLen2-1:strlen(input2);

	//С���㲹��
	if(aftDotLen1<aftDotLen2)
	{
		if(aftDotLen1==0)
			a.append(".");
		for(int i=aftDotLen2;i>aftDotLen1;i--)
			a.append("0");
	}
	else if(aftDotLen2<aftDotLen1)
	{
		if(aftDotLen2==0)
			b.append(".");
		for(int i=aftDotLen1;i>aftDotLen2;i--)
			b.append("0");
	}

	//lָ�����,rָ��С��
	string *l=&a;
	string *r=&b;
	if(preDot2Len>preDot1Len||(preDot1Len==preDot2Len&&strcmp(input2,input1)>0))
	{
		l=&b;r=&a;
		underZero=true;//input2����input1 ����λ��
	}

	//�������
	riter_l=l->rbegin();
	riter_r=r->rbegin();
	while(riter_r!=r->rend())
	{
		if(*riter_r!='.')
		{
			if(*riter_l>=*riter_r)
				*riter_l='0'+(*riter_l-*riter_r);
			else
			{
				*riter_l='9'+(*riter_l-*riter_r)+1;

				string::reverse_iterator it=riter_l+1;
				while(*it=='0'||*it=='.'&&it!=l->rend())
				{
					if(*it!='.') 
						*it='0';
					it++;
				}
				*it=*it-1;
			}
		}
		riter_l++;
		riter_r++;
	}

	//ȥ�����˶����'0'
	string result=(*l).substr((*l).find_first_not_of('0'),(*l).find_last_not_of('0')+1);

	//������
	char * o=output;
	if (underZero) 
	{
		*o='-' ; o++;
	}
	if (result[0]=='.')
	{
		*o='0'; o++;
	}
	string::iterator oiter; 
	for(oiter=result.begin();oiter!=result.end();oiter++)
	{
		*o=*oiter; o++;
	}
	*o='\0';
}
static int numAfterDot(char *input)
{
	int num=0;
	int len=strlen(input);
	num=input+len- find(input,input+len,'.');//find �ҵ�С����λ��
	if(num) num-=1;
	return num;
}

//���������ַ�����ʽ�Ĳ�����ת����������ʽ�Ĳ�������[artful!;���ǣ��ڲ������ܳ����������δ���]
void Decrease(char *input1, char*input2, char *output)
{
	stringstream ss;
	double l;//�������
	double r;//�Ҳ�����
	double result;

	//�ַ�����ʾ�Ĳ�������������
	ss << input1 << " ";
	ss << input2;
	//��������ȡ���Ҳ�����
	ss >> l;
	ss >> r;

	result =l-r;

	cout <<result<< endl;
	ss.clear();
	ss <<" "<< result;

	cout << ss.str() <<endl;
	ss >> output;
}

/*
�ڸ����ַ������ҳ����ʣ� �����ʡ��ɴ�д��ĸ��Сд��ĸ�ַ����ɣ���������ĸ�ַ���Ϊ���ʵļ������ո��ʺš����ֵȵȣ�
���ⵥ����ĸ���㵥�ʣ����ҵ����ʺ󣬰��ճ��Ƚ��н������򣬣�����ʱ���������ͬ���򰴳��ֵ�˳��������У���
Ȼ�������һ���µ��ַ����У����ĳ�������ظ����ֶ�Σ���ֻ���һ�Σ��������������ַ�����û���ҵ����ʣ�������մ���
����ĵ���֮��ʹ��һ�����ո񡱸��������һ�����ʺ󲻼ӿո�
void my_word(charinput[], char output[])
�����롿  char input[], ������ַ���
�������  char output[]��������ַ���
�����ء� ��
ʾ��
���룺charinput[]="some local buses, some1234123drivers" ��
�����charoutput[]="drivers local buses some"
���룺charinput[]="%A^123 t 3453i*()" ��
�����charoutput[]=""
*/
void getWord(char input[] ,vector<string> &words);
void  sortWordByLength(vector<string> &words);
void bubbleSort(vector<string>&words);//ð�����򣬣��ȶ��ԣ�
void word_Index(char input[],char output[])
{
	vector<string> words;
	ostream_iterator<string,char> out(cout," ");

	//��ȡ����
	getWord(input,words);

	//����
	//sortWordByLength(words); //�ȶ�����Σ�
	bubbleSort(words);

	//ȥ��
	stringstream ss;
	string prevs="";
	string cur;
	vector<string>::iterator it;
	for(it=words.begin();it!=words.end();it++)
	{
		cur=*it;
		if(*it!=prevs)
		{
			ss << cur << " ";
			prevs=cur;
		}
	}
	ss.getline(output,ss.str().size());
}

int cmpByLength(const string &l,const string &r)
{
	return l.size()>r.size() ;
}
static void bubbleSort(vector<string>&words)//ð�����򣬣��ȶ��ԣ�.Sort��������ʲô�㷨���ȶ�����Σ�
{
	bool flag=false;
	vector<string>::iterator i;
	vector<string>::iterator j;
	for(i=words.begin();i!=words.end();i++)
	{
		for(j=words.end()-1;j!=i;j--)
		{
			if(cmpByLength(*j,*(j-1)))
			{
				string temp=*j;
				*j=*(j-1);
				*(j-1)=temp;
				flag=true;
			}
		}
		if(flag==false)//ĳ��δ����Ԫ�أ������ź���
		{
			break;
		}
		flag=false;
	}
}
static void  sortWordByLength(vector<string> &words)//��sort�㷨����
{
	sort(words.begin(),words.end(),cmpByLength);
}
struct myCmp
{
	bool operator()(const string &l,const string  &r)
	{
		return l.size()>r.size();
	}
};
static void getWord(char input[] , vector<string> &words)
{
	set<string,myCmp>wordSet;//ָ��set���ݵ��ʳ�������Ļ���set����һЩ����һ���ĵ��ʣ���ʹ��Щ���ʱ�����ܲ�ͬ��
	string word;
	int n=0;
	char *cur=input;

	while(*cur!='\0')
	{
		char curC=*cur;
		if(isWordChar(*cur))
		{
			word+=*cur;
		}
		else
		{
			if(word.size()>1)
			{
				//����find������ظ����ʵ�vector��vector<string>::iterator it=find(words.begin(),words.end(),word);
				words.push_back(word);
				wordSet.insert(word);
			}
			word.clear();
		}
		cur++;
	}
	words.push_back(word);
	wordSet.insert(word);

	/*
	ostream_iterator<string,char> out(cout," ");
	cout << "sort with set:" <<endl;
	copy(wordSet.begin(),wordSet.end(),out);
	cout << endl;
	*/
}
/*
��������ַ������ַ���������Сд��ĸ��a������z�������������¹���ѭ��ת���������a->b,b->c,��,y->z,z->a��
��������ַ�����������������ĸ��ͬʱ����һ����ĸ��Ҫ����ת��2�Ρ����磺aa ת��Ϊ bc��zz ת��Ϊ ab��
��������ͬ��ĸ��������ʱ�����������ֵ���ĸ����һ�γ����㡣
*/

//Done by myself
//��input�е��ַ�ת���������output
void convert(const char * input,char * output)
{
	int a=0;
	char prev='\0';//�洢��һ�ִ�����ַ�,��ʼΪ'\0'

	while(input[a]!='\0')
	{
		char cur=input[a];
		if(cur!=prev)//��ǰ�ַ���ǰһ�ַ���ͬ
		{
			output[a]=(cur-'a'+1)%26+'a';
			prev=cur;
		}
		else{//��ǰ�ַ���ǰһ�ַ���ͬ��prev����
			output[a]=(cur-'a'+2)%26+'a';
			prev='\0';//��Ϊ��\0'��ʾ������һ���ַ��Ƿ���ڵ�ǰ�ַ�����������һ�γ���
		}
		a++;
	}
	output[a]='\0';
}
//http://blog.csdn.net/lanyan822/article/details/7983832
void convert1(const char *input,char *output)  
{  
	char c='\0';  
	int tag=0;  
	int len=strlen(input);  
	for(int i=0;i<len;i++)  
	{  
		if(input[i]!=c)//��ǰ�ַ���ǰһ���ַ�����ȣ�����ַ�+1  
		{  
			output[i]=(input[i]-'a'+1)%26+'a';  
			c=input[i];  
			tag=1;  
		}else  
		{  
			if(tag==1)//��ǰ�ַ���ǰһ���ַ����,��ǰ��ֻ��һ���ַ���ͬ  
			{  
				output[i]=(input[i]-'a'+2)%26+'a';  
				c='\0';  
				tag=0;  
			}else//��ǰ�ַ���ǰһ���ַ����,��ǰ������2n���ַ���ͬ���򰴵�һ�γ�����  
			{  
				output[i]=(input[i]-'a'+1)%26+'a';  
				c=output[i];  
				tag=1;  
			}  
		}  
	}  
}   