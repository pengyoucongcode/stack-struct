// prog_stack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
#define STACK_INIT_SIZE 11
#define MAXSIZE 100

struct Data
{
	int num;
	char c=' ';
};

typedef struct 
{
	Data *base;
	Data *top;
	int sqsize;
}TranSqstack;

void InitStack(TranSqstack &s)
{
	s.base = new Data[MAXSIZE];
	if (!s.base)
	{
		cout << "空间分配失败！" << endl;
		exit(0);
	}
	else
	{
		s.top = s.base;
		s.sqsize = MAXSIZE;
	}
}

void Push(TranSqstack &s, int e)
{
	if (s.top - s.base == s.sqsize)
	{
		cout << "栈满，无法再进行压栈操作！" << endl;
	}
	else
	{
		s.top->num = e;
		s.top++;
	}
}
void PushC(TranSqstack &s, char c)
{
	if (s.top - s.base == s.sqsize)
	{
		cout << "栈满，无法再进行压栈操作！" << endl;
	}
	else
	{
		s.top->c = c;
		s.top++;
	}
}
bool IsEmpty(TranSqstack s)
{
	if (s.top == s.base)
	{
		
		return true;
	}
	else
	{
		return false;
	}
}

int GetTop(TranSqstack s)
{
	s.top--;
	return s.top->num;
}

void TraverseStack(TranSqstack s)
{
	cout << "当前栈中的情况：";
	while (s.top != s.base)
	{
		s.top--;
		if (s.top->num>=0)
		{
			cout << s.top->num;
		}
		else if (s.top->c!=' ')
		{
			cout << s.top->c;
		}

	}
	cout << endl;
}

bool Pop(TranSqstack &s,int &e,char &str)
{//将栈顶元素出栈，并移动栈顶指针
	if (s.top == s.base)
	{
		return false;
	}
	else
	{
		s.top--;
		if (s.top->num >= 0)
		{
			e = s.top->num;
		}
		else if (s.top->c != ' ')
		{
			str = s.top->c;
		}
		return true;
	}
}

void DestroyStack(TranSqstack &s)
{
	s.sqsize = -1;
	s.base = s.top = NULL;
	cout << "栈销毁成功！" << endl;
}

TranSqstack* transfer(int  x,int base)
{
	TranSqstack t;
	InitStack(t);
	int num;
	int temp;
	int i = 0;
	switch (base)
	{
	case 2:
		temp = x;
		while (temp != 0)
		{
			num = temp % 2;
			Push(t, num);
			temp = temp / 2;
			i++;
		}
		while (i % 4 != 0)
		{
			Push(t, 0);
			i++;
		}
		break;
	case 8:
		temp = x;
		while (temp != 0)
		{
			num = temp % 8;
			Push(t, num);
			temp = temp / 8;
		}
		Push(t, 0); 
		break;
	case 16:
		temp = x;
		while (temp != 0)
		{
			num = temp % 16;
			if (num > 9)
			{
				switch (num)
				{
				case 10:
					PushC(t, 'A');
					break;
				case 11:
					PushC(t, 'B');
					break;
				case 12:
					PushC(t, 'C');
					break;
				case 13:
					PushC(t, 'D');
					break;
				case 14:
					PushC(t, 'E');
					break;
				case 15:
					PushC(t, 'F');
					break;
				}
			}
			else
				Push(t, num);
			temp = temp / 16;
		}
		PushC(t, 'x');
		Push(t, 0);
		break;
	default:
		cout << "进制错误！" << endl;
		exit(0);
	}
	return &t;
}
int main()
{
	TranSqstack num;
	int x, base;
	while (true)
	{
		cout << "请输入目标进制：";
		cin >> base;
		cout << "请输入该10进制数：";
		cin >> x;
		num = *transfer(x, base);
		TraverseStack(num);
		int i=-1;
		char s=' ';
		cout << "出栈：";
		while (Pop(num, i, s))
		{
			if (i>=0)
				cout << i;
			if (s != ' ')
				cout << s;
			i = -1;
			s = ' ';
		}
		cout << endl;
		DestroyStack(num);
		char key;
		cout << "是否继续，y/n:"<<endl;
		cin >> key;
		if (key == 'n')
			break;
	}
	return 0;
}


