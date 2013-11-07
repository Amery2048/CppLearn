//�ж��ַ��ǲ�����a-z A-Z֮��ĺ�
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
//Լɪ������
void array_iterate(int len,int input[],int m,int output[]);
//����������
int calculate(int len,char *expStr);
//�˿������
int poker(int a[],int len);

//��������
template<typename T> void quiksort(T * arr,int len);

//����Ԫ����ĸ
void sortVowel (char* input, char* output);

//��������������С������֮��
int SumOfMaxMin(int *nums,int len);

std::string getMaxSubStr(std::string strs[],int len);

//KMP
int my_find(char *str,char *substr);
