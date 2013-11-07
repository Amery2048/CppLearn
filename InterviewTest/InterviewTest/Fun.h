//判断字符是不是在a-z A-Z之间的宏
#ifndef isWordChar
#define isWordChar(x) (((x)>='a'&&(x)<='z')||((x)>='A'&&(x)<='Z'))?true:false
#endif

#ifndef MAX_LEN
#define MAX_LEN 100
#endif

#ifndef Arr_Len 
#define Arr_Len(arr) sizeof(arr)/sizeof(arr[0])
#endif

void convert(const char *input,char * output);
void convert1(const char *input,char * output);
void word_Index(char input[],char output[]);
void Decrease(char *input1, char*input2, char *output);
void Decrease1(char *input1, char*input2, char *output);
//约瑟夫问题
void array_iterate(int len,int input[],int m,int output[]);
//简单四则运算
int calculate(int len,char *expStr);
//扑克牌组成
int poker(int a[],int len);

//快速排序
template<typename T> void quiksort(T * arr,int len);

//关于元音字母
void sortVowel (char* input, char* output);

//求数组中最大和最小两个数之和
int SumOfMaxMin(int *nums,int len);

std::string getMaxSubStr(std::string strs[],int len);

//KMP
int my_find(char *str,char *substr);
