#include <iostream>
#include <math.h>
#include<stdio.h>
using namespace std;
const int StackSize=100;
template <class DataType>
class SeqStack{
private:
    DataType data[StackSize];
    int top;
public:
    SeqStack(){top=-1;}
    ~SeqStack(){}
    void push(DataType x);  //入栈操作，将元素x入栈
    void pop();  //出栈操作
    DataType Gettop();  //取栈顶元素
    int Empty(){return top==-1?1:0;} //判断栈是否为空
    int getSize(){return top;}  //返回栈的长度
};
template<class DataType>
void SeqStack<DataType>::push(DataType x){
if(top==-1)
    {
        data[0]=x;
        top=0;
    }
    else{data[top+1]=x;top++;}

}
template<class DataType>
void  SeqStack<DataType>::pop(){
 data[top]=0;
    top--;

}
template<class DataType>
DataType  SeqStack<DataType>::Gettop(){
    if(top==-1) cout<<"empty";
    else
        return data[top];
}
bool Number(char ch)//判断是否为数字，是则返回true
{
if(ch<='9'&&ch>='0')
    return 1;
 else
    return 0;

}

void InPut(char*& str)//接收输入的中缀表达式的函数，并简单判断是否合法
{
    //cout << "Please Enter What You Want To calculation:" << endl;
    while (1)
    {
        cin >> str;

        if (Number(str[0]))//中缀表达式的第一个必定是数字，如果不是，则非法
        {
            break;
        }
        else
        {
            cout << "Illegal Input,Please Input Again:";
            delete[] str;
        }
    }
}

int GetPriority(char sy)//设置各个操作符的优先级
{
    switch (sy)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 3;
    case '*':
    case '/':
        return 5;
    case ')':
        return 6;
    default:
        return -1;
    }
}


void AddSpace(char*& arr)//给转成的后缀表达式的数字和符号添加空格，区分每个字符
{
    *arr = ' ';
    arr++;
}

char* GetBack()//获取后缀表达式的函数
{
    char* middle = new char[30];
    char* back = new char[30];
    char* backend = back;
    InPut(middle);
    SeqStack<char> s;
    s.push('#');
    while (*middle)
    {
        if (Number(*middle) || *middle == '.')//如果是数字或者小数的话，直接输出
        {
            *back = *middle;
            back++, middle++;
        }
        else
        {
            if (Number(*(back - 1)))//只有他的上一个时数字的话，才继续给空格
                                    //否则遇到多个操作符，则输出域会存在多个空格
            {
                //*back = ' ';
                //back++;
                AddSpace(back);
            }
            if (*middle == ')')//如果右括号的话，输出所有操作符直到遇到左括号，并抛弃相对应的一堆括号
            {
                while (s.Gettop() != '(')
                {
                    *back = s.Gettop();
                    s.pop();
                    back++;
                    AddSpace(back);
                }
                middle++;
                s.pop();//抛弃左括号
            }
            else if (*middle == '(')//遇到左括号，则进入栈
            {
                s.push(*middle); middle++;
            }
            else if (GetPriority(*middle) > GetPriority(s.Gettop()))//如果栈内的操作符优先级高于栈外的优先级，则入栈
            {
                s.push(*middle); middle++;
            }
            else if (GetPriority(*middle) <= GetPriority(s.Gettop()))
                                                     //如果栈内的操作符优先级低于或等于栈外的优先级，输出栈内的符号，并入栈栈外的符号
            {
                *back = s.Gettop();
                s.pop();
                s.push(*middle);
                back++; middle++;
                AddSpace(back);
            }
        }
    }
    while (s.Gettop() != '#')//中缀表达式遍历完成，但是=栈中还有符号存在，一一出栈输出
    {
        AddSpace(back);
        *back = s.Gettop();
        s.pop(); back++;
    }
    *back = '\0';
    //cout << "The Back Is: " << backend << endl;
    return backend;
}

double GetNumber(char*& arr)
{
    //因为输出为char*，所以可能两位数以上的数字被拆开，此函数为正确得到数字
    double sum[10] = { 0 }; int i = 0; double result = 0;
    while (*arr != ' ')
    {
        sum[i] = *arr-48;
        i++;
        arr++;
    }
    int k = i - 1;
    for (int j = 0; j < i; j++,k--)
    {
        result += (sum[j] * pow(10, k));
    }
    return result;
}

double Cauculate(char ch, double left, double right)//各个操作符对应的操作
{
    switch (ch)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        return left / right;
    default:
        return 0;
        break;
    }
}

double CountBack(char* back)
{
    SeqStack<double> s;
    while (*back)
    {
        if (Number(*back))//遇到数字
        {
            s.push(GetNumber(back));//将正确的数字入栈
        }
        else if (*back == ' ')
        {
            back++;//遇到空格跳过
        }
        else
        {
            double a = s.Gettop();
            s.pop();
            double b = s.Gettop();
            s.pop();
            s.push(Cauculate(*back, b, a));//遇到符号时，取栈顶的第二个数和第一个数求解，并入栈
            back++;
        }
    }
    while (s.getSize() >= 2)//最终栈内存在的数大于2时，继续计算，直到只剩下一个数
    {
        double a = s.Gettop();
        s.pop();
        double b = s.Gettop();
        s.pop();
        s.push(Cauculate(*back, b, a));
    }
    //返回这个数字，既是最终结果
    return s.Gettop();
}
int main()
{
    cout<<CountBack(GetBack())<<endl;;
    return 0;
}

