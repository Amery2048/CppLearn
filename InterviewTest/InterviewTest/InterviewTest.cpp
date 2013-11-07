// InterviewTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Fun.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	/*
	string strs[]={"sdkksdflocal_user","sdkllocal_useralskdf","akdklocal_userkd"};
	//copy(strs,strs+Arr_Len(strs),ostream_iterator<string,char>(cout,"\n"));
	cout <<"最大公共字串: "<< getMaxSubStr(strs,Arr_Len(strs))<<endl;
	string strs1[MAX_LEN];
	int i=0;
	while(i<MAX_LEN && !cin.fail())
	{
		cin >>strs1[i];
		i++;
	}
	i--;
	copy(strs1,strs1+i,ostream_iterator<string,char>(cout,"\n"));
	cout <<"最大公共字串: "<< getMaxSubStr(strs1,i)<<endl;
	//
	*/
	/*
	int nums[MAX_LEN];
	int i=0;
	while(i<MAX_LEN && !cin.fail())
	{
		cin >> nums[i++];
	}
	i--;
	copy(nums,nums+i,ostream_iterator<int,char>(cout," "));
	cout << endl;
	cout << SumOfMaxMin(nums,i) << endl;
	*/
	/*
	将一个字符串的元音字母复制到另一个字符串，并排序（30分）（快速排序，multiset?）
	问题描述：有一字符串，里面可能包含英文字母（大写、小写）、数字、特殊字符，
	现在需要实现一函数，将此字符串中的元音字母挑选出来，存入另一个字符串中，
	并对字符串中的字母进行从小到大的排序（小写的元音字母在前，大写的元音字母在后，依次有序）。
	说明：1、 元音字母是a,e,i,o,u,A,E,I,O,U。 2、 筛选出来的元音字母，不需要剔重；
	最终输出的字符串，小写元音字母排在前面，大写元音字母排在后面，依次有序。
	要求实现函数：void sortVowel (char* input, char* output);
	*/
	/*
	char str[]="HaJsdStOoAOeINaPQaWEiAIiO";
	char s[20];
	sortVowel (str,s);
	copy(s,s+strlen(s),ostream_iterator<char,char>(cout," "));
	cout <<endl;
	*/

	/***********快速排序Start**********/
	/*
	int a[] ={3,7,2,4,5};
	copy(a,a+Arr_Len(a),ostream_iterator<int,char>(cout," "));
	cout << endl;
	quiksort(a,Arr_Len(a));
	copy(a,a+Arr_Len(a),ostream_iterator<int,char>(cout," "));
	cout << endl;
	*/
	/***********快速排序End**********/
	/***********扑克牌组成Start**********/
	/*
	第五题：一副牌中发五张扑克牌给你：让你判断数字的组成：有以下几种情况：
	1：四条：即四张一样数值的牌（牌均不论花色）  2：三条带一对
	3：三条带两张不相同数值的牌 4：两对   5：顺子  包括 10，J，Q，K，A
	6：什么都不是  7：只有一对 
	*/
	/*
	int a[]={1,7,3,4,5};
	int result= poker(a,Arr_Len(a));
	cout <<result<<endl;
	*/
	/***********扑克牌组成End**********/

	/***********简单四则运算Start**********/
	/*
	问题描述： 
	输入一个只包含个位数字的简单四则运算表达式字符串，计算该表达式的值
	注： 1、表达式只含 +, -, *, / 四则运算符，不含括号
	2、表达式数值只包含个位整数(0-9)，且不会出现0作为除数的情况
	3、要考虑加减乘除按通常四则运算规定的计算优先级
	4、除法用整数除法，即仅保留除法运算结果的整数部分。比如8/3=2。输入表达式保证无0作为除数情况发生
	5、输入字符串一定是符合题意合法的表达式，其中只包括数字字符和四则运算符字符，除此之外不含其它任何字符，不会出现计算溢出情况
	• 要求实现函数：
	int calculate(int len,char *expStr)
	【输入】 int len: 字符串长度；
	char *expStr: 表达式字符串；
	【输出】 无
	【返回】 计算结果
	• 示例 
	1） 输入：char *expStr = “1+4*5-8/3” 函数返回：19
	2） 输入：char *expStr = “8/3*3”     函数返回：6 
	简化版的四则运算：没有括号，只有加减乘除四种运算
	*/
	/*
	char *expStr="1+4*5-8/3";
	cout << calculate(strlen(expStr),expStr)<< endl;
	*/

	/***********简单四则运算End**********/
	/***********约瑟夫问题Start**********/
	/*
	int input_array[]={3,1,2,4};
	int len=Arr_Len(input_array);
	int m=7;
	int output[4];
	array_iterate(len,input_array,m,output);
	ostream_iterator<int,char>out(cout," ");
	copy(output,output+len,out);
	*/

	/***********约瑟夫问题End**********/
	/***********KMP算法，字符串模式匹配Start**********/
	/*
	给定一个字符串和一个字串，求字串在给定字符串中首次出现的的位置
	int my_find(char *str,char *substr);
	*/
	/*
	char str[]="ababcabaabcacbab";
	char substr[]="abaabcac";
	int index=my_find(str,substr);
	assert(index==5);
	//expect 5 in this example
	cout << index <<endl;
	*/
	/***********KMP算法，字符串模式匹配End**********/

	/***********字符转换2012 华为上机测试3Start**********/
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
	/*
	char input1[]="2.2"; 
	char input2[]="1.1";
	char output[MAX_LEN];
	//Decrease(input1,input2,output);
	Decrease1(input1,input2,output);

	cout << "result: "<<endl;
	cout << output <<endl;
	*/

	/***********字符转换2012 华为上机测试3End**********/

	/***********字符转换2012 华为上机测试2Start**********/
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
	//about istringstream ostringstream stringstream
	/*
	int a=1234;
	ostringstream oss;
	oss << a;
	string str =oss.str();
	cout << oss.str();
	cout <<endl;

	string n="1234";
	stringstream iss;
	iss << n;
	int nn;
	iss >> nn; 
	cout << nn<<endl;

	stringstream ss;
	ss<<"hello world";
	cout << ss.str()<<endl;
	*/

	//关于vector去重
	/*
	int ints[] ={2,3,1,1,3,2};
	vector<int> intVec;
	copy(ints,ints+Arr_Len(ints),back_inserter(intVec));
	vector<int>::iterator is=unique(intVec.begin(),intVec.end());
	cout << *is<<endl;
	intVec.erase(is,intVec.end());
	copy(intVec.begin(),intVec.end(),ostream_iterator<int,char>(cout," "));
	cout <<endl;
	*/
	/*
	char input[]="some local buses, some1234123drivers";
	//char input[]="%A^123 t 3453i*()" ;
	cout << input <<endl;
	char output[MAX_LEN];
	word_Index(input,output);

	cout << "result:"<<endl;
	cout << output<< endl;
	*/

	/***********字符转换2012 华为上机测试2End**********/


	/***********字符转换2012 华为上机测试Start**********/
	/*
	将输入的字符串（字符串仅包含小写字母‘a’到‘z’），按照如下规则，循环转换后输出：a->b,b->c,…,y->z,z->a；
	若输入的字符串连续出现两个字母相同时，后一个字母需要连续转换2次。例如：aa 转换为 bc，zz 转换为 ab；
	当连续相同字母超过两个时，第三个出现的字母按第一次出现算。
	*/
	/*
	enum {MAX_Len=100};
	char str[]="abcdzzzzzz";
	//char output[MAX_Len];
	ostream_iterator <char,char> char_out(cout," ");
	size_t len =strlen(str);
	char *output=new char[len+1];//'\0'

	copy(str,str+len,char_out);
	cout << endl;

	convert(str,output);
	copy(output,output+len,char_out);
	cout << endl;

	convert1(str,output);
	copy(output,output+len,char_out);
	cout << endl;
	*/
	/***********字符转换2012 华为上机测试End**********/

	system("pause");
	return 0;
}
template<typename T>
static int Partition(T * arr,int low,int high)
{
	//copy(arr+low,arr+high+1,ostream_iterator<int,char>(cout," "));
	//cout <<endl;
	//cout << "low: "<< low<< " "<<"high: "<<high<<endl;
	T key=arr[low];
	while(low<high)
	{
		while(low<high && key<=arr[high]) high--;
		arr[low]=arr[high];
		while(low<high && key>=arr[low]) low++;
		arr[high]=arr[low];
	}
	arr[low]=key;
	return low;
}
template <typename T>
static void QSort(T * arr,int low,int high)
{
	if(low<high){
		int location=Partition(arr,low,high);
		QSort(arr,low ,location-1);
		QSort(arr,location+1,high);
	}

}

template<typename T>
void quiksort(T * arr,int len)
{
	QSort(arr,0,len-1);
}