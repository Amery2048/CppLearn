#include "stdafx.h"
#include "Fun.h"
using namespace std;

string getMaxSubStr(string strs[],int len)
{
	int i=0;
	int j=0;
	size_t minLen=0;
	while(i<len)//先找到最短的字符串
	{
		if(minLen<strs[i].size()){minLen=strs[i].size();j=i;}
		i++;
	}
	string substr;//存储最短的那个字符串的字串，从最长的字串开始查看是否是给定的N个字符串的公共字串
	size_t n;
	size_t m=n=minLen;

	i=0;
	int k=0;
	while(m>0)
	{
		while((i+m)<=minLen)
		{
			substr=strs[j].substr(i,m);
			while(k<len)//检查得到的字串是否是给定N个字符串的公共字串。
			{
				if(k==j){k++;continue;}
				if(strs[k].find(substr)==string::npos) break;
				k++;
			}
			if(k==len)return substr;//得到最长公共字串，返回。
			else k=0;
			i++;
		}
		i=0;m--;
	}
	return "";
}

//求数组中最小和最大的值之和。
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
将一个字符串的元音字母复制到另一个字符串，并排序（30分）（快速排序，multiset?）
问题描述：有一字符串，里面可能包含英文字母（大写、小写）、数字、特殊字符，
现在需要实现一函数，将此字符串中的元音字母挑选出来，存入另一个字符串中，
并对字符串中的字母进行从小到大的排序（小写的元音字母在前，大写的元音字母在后，依次有序）。
说明：1、 元音字母是a,e,i,o,u,A,E,I,O,U。 2、 筛选出来的元音字母，不需要剔重；
最终输出的字符串，小写元音字母排在前面，大写元音字母排在后面，依次有序。
要求实现函数：void sortVowel (char* input, char* output);
*/
void sortVowel (char* input, char* output)
{
	multiset<char,less<char>>vowSet;
	char *cur=input;
	while(*cur!='\0')//将元音字母依次放入multiset中，进行排序
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

	start=vowSet.begin();//定位大写元音字母开始的位置
	while(*start<'a')
		start++;
	it=start;
	int i=0;
	while(it!=vowSet.end())//将小写元音字母输出
	{
		output[i]=*it;
		i++;it++;
	}
	it=vowSet.begin();
	while(it!=start)//将大写元音字母输出
	{
		output[i]=*it;
		i++;it++;
	}
	output[i]='\0';
}

//扑克组成
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
	case 4: cout << "四条"<<endl;return 1;
	case 3: 
		{
			bit++;
			if(*bit==2) {cout <<"三带一对"<<endl;return 2;} 
			else {cout <<"三带两张"<<endl;return 3;}
			break;
		}
	case 2:
		{
			bit++;
			if(*bit==2) {cout <<"两对"<<endl;return 4;}
			else {cout<<"一对"<<endl;return 7;}
			break;
		}
	default:
		int i=0,j=1;
		while(j<len)
		{
			if(sortedPoker[j]!=sortedPoker[i]+1) break;
			i++;j++;
		}
		if(j>=len) {cout << "顺子"<<endl;return 5;}
		else {cout << "什么都不是"<<endl;return 6;}
		break;
	}
}
//简单四则运算
int calculate(int len,char *expStr)
{
	stack<char> Op;//记录操作符
	stack<int>Num;//记录操作数
	char *cur=expStr;
	//先进行乘除法运算
	while (*cur!='\0')
	{
		switch (*cur)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			{Op.push(*cur); break; }//操作符入栈
		default://处理操作数
			if(*cur>='0'&& *cur<='9')
			{
				if(!Op.empty() && (Op.top()=='*'||Op.top()=='/'))//计算乘法或者除法，结果压栈.
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
	//进行剩下的加法运算
	int result=Num.top();
	Num.pop();
	while(!Op.empty())
	{
		char op=Op.top();
		op=='+'?result+=Num.top():result=Num.top()-result;//注意负号时的计算
		Num.pop();
		Op.pop();
	}
	return result;
}
//约瑟夫问题
void array_iterate(int len,int input[],int m,int output[])
{
	//在原数组中，用0标记已经出列的位置。
	int i=0,j=0;//i标记已出列个数,j用来循环遍历输入数组
	while(i<len)
	{
		if(input[j]>0)
		{
			if(m==1)
			{
				m=input[j];
				output[i]=m;
				input[j]=0;//用0标记已经出列的数
				i++;
			}
			else
				m--;
		}
		j=(j+1)%len;
	}
}
/*
3 正数减法
问题描述：    
两个任意长度的正数相减，这两个正数可以带小数点，也可以是整数，请输出结果。 
输入的字符串中，不会出现除了数字与小数点以外的其它 字符，不会出现多个小数
点以及小数点在第一个字符的位置等非法情况，所以考生的程序中无须考虑输入的
数值字符串非法的情况。 
详细要求以及约束：
1.输入均为正数，但输出可能为负数； 
2.输入输出均为字符串形式；
3.如果输出是正数则不需要带符号，如果为负数，则输出的结果字符串需要带负号
例如：2.2-1.1 直接输出为“1.1”，1.1-2.2 则需要输出为“-1.1”
 4.输出的结果字符串需要过滤掉整数位前以及小数位后无效的0，小数位为全0的，直接输出整数位
例如相减结果为11.345，此数值前后均不可以带0，“011.345”或者“0011.34500”等等前后带无效0的均视为错误 输出。例如1.1-1.1结果为0.0，则直接输出0。
要求实现函数：
void Decrease(char *input1, char*input2, char *output)
【输入】 char *iinput1 被减数 char*nput2 减数 
【输出】 char *output 减法结果
【返回】 无
示例
输入：char *input1="2.2" 
char *input2="1.1"
输出：char*output="1.1"
输入：char *input1="1.1" 
char *input2="2.2"
输出：char *output="-1.1"
*/
int numAfterDot(char *input);
void Decrease1(char *input1,char *input2,char *output)
{
	//标记结果符号
	bool underZero=false;

	string a(input1);
	string b(input2);
	string out;
	string::reverse_iterator riter_l;
	string::reverse_iterator riter_r;

	//得到小数点后面位数
	int aftDotLen1=numAfterDot(input1);
	int aftDotLen2=numAfterDot(input2);

	//得到小数点前位数,用于比较操作数的大小
	int preDot1Len=aftDotLen1?strlen(input1)-aftDotLen1-1:strlen(input1);
	int preDot2Len=aftDotLen2?strlen(input2)-aftDotLen2-1:strlen(input2);

	//小数点补齐
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

	//l指向大者,r指向小数
	string *l=&a;
	string *r=&b;
	if(preDot2Len>preDot1Len||(preDot1Len==preDot2Len&&strcmp(input2,input1)>0))
	{
		l=&b;r=&a;
		underZero=true;//input2大于input1 符号位负
	}

	//计算减法
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

	//去掉两端多余的'0'
	string result=(*l).substr((*l).find_first_not_of('0'),(*l).find_last_not_of('0')+1);

	//输出结果
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
	num=input+len- find(input,input+len,'.');//find 找到小数点位置
	if(num) num-=1;
	return num;
}

//利用流将字符串形式的操作数转换成数字形式的操作数；[artful!;但是，在操作数很长的情况下如何处理？]
void Decrease(char *input1, char*input2, char *output)
{
	stringstream ss;
	double l;//左操作数
	double r;//右操作数
	double result;

	//字符串表示的操作数放入流中
	ss << input1 << " ";
	ss << input2;
	//从流中提取左右操作数
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
在给定字符串中找出单词（ “单词”由大写字母和小写字母字符构成，其他非字母字符视为单词的间隔，如空格、问号、数字等等；
另外单个字母不算单词）；找到单词后，按照长度进行降序排序，（排序时如果长度相同，则按出现的顺序进行排列），
然后输出到一个新的字符串中；如果某个单词重复出现多次，则只输出一次；如果整个输入的字符串中没有找到单词，请输出空串。
输出的单词之间使用一个“空格”隔开，最后一个单词后不加空格。
void my_word(charinput[], char output[])
【输入】  char input[], 输入的字符串
【输出】  char output[]，输出的字符串
【返回】 无
示例
输入：charinput[]="some local buses, some1234123drivers" ，
输出：charoutput[]="drivers local buses some"
输入：charinput[]="%A^123 t 3453i*()" ，
输出：charoutput[]=""
*/
void getWord(char input[] ,vector<string> &words);
void  sortWordByLength(vector<string> &words);
void bubbleSort(vector<string>&words);//冒泡排序，（稳定性）
void word_Index(char input[],char output[])
{
	vector<string> words;
	ostream_iterator<string,char> out(cout," ");

	//提取单词
	getWord(input,words);

	//排序
	//sortWordByLength(words); //稳定性如何？
	bubbleSort(words);

	//去重
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
static void bubbleSort(vector<string>&words)//冒泡排序，（稳定性）.Sort排序是用什么算法？稳定性如何？
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
		if(flag==false)//某趟未交换元素，则已排好序
		{
			break;
		}
		flag=false;
	}
}
static void  sortWordByLength(vector<string> &words)//用sort算法排序
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
	set<string,myCmp>wordSet;//指定set根据单词长度排序的话，set丢弃一些长度一样的单词，即使这些单词本身可能不同。
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
				//可用find不添加重复单词到vector：vector<string>::iterator it=find(words.begin(),words.end(),word);
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
将输入的字符串（字符串仅包含小写字母‘a’到‘z’），按照如下规则，循环转换后输出：a->b,b->c,…,y->z,z->a；
若输入的字符串连续出现两个字母相同时，后一个字母需要连续转换2次。例如：aa 转换为 bc，zz 转换为 ab；
当连续相同字母超过两个时，第三个出现的字母按第一次出现算。
*/

//Done by myself
//将input中的字符转换后输出到output
void convert(const char * input,char * output)
{
	int a=0;
	char prev='\0';//存储上一轮处理的字符,初始为'\0'

	while(input[a]!='\0')
	{
		char cur=input[a];
		if(cur!=prev)//当前字符跟前一字符不同
		{
			output[a]=(cur-'a'+1)%26+'a';
			prev=cur;
		}
		else{//当前字符跟前一字符相同。prev重置
			output[a]=(cur-'a'+2)%26+'a';
			prev='\0';//设为‘\0'表示不论下一个字符是否等于当前字符，都当做第一次出现
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
		if(input[i]!=c)//当前字符与前一个字符不相等，则该字符+1  
		{  
			output[i]=(input[i]-'a'+1)%26+'a';  
			c=input[i];  
			tag=1;  
		}else  
		{  
			if(tag==1)//当前字符与前一个字符相等,且前面只有一个字符相同  
			{  
				output[i]=(input[i]-'a'+2)%26+'a';  
				c='\0';  
				tag=0;  
			}else//当前字符与前一个字符相等,且前面已有2n个字符相同。则按第一次出现算  
			{  
				output[i]=(input[i]-'a'+1)%26+'a';  
				c=output[i];  
				tag=1;  
			}  
		}  
	}  
}   