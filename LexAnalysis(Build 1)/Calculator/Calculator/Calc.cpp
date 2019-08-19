#include "Calc.h"

//ASCII:
//48 '0'
//57 '9'
//func ifAllNum() 函数ifAllNum()
//check the char cnum is or isn't a number
bool ifAllNum(char& cnum)
{
	return ((cnum >= 48) && (cnum <= 57));
}

//func LexAnalysis() 词法分析函数

/*
 * typedef pair<Symbol,long int> psli;
 * typedef vector<psli> vp;
 */

//将分析出来的tokens装在vector<pair<Symbol,long int>>中
//tokens into vp,and return vp;
//sc is "string to Calculate"
//SUCCESS 存储是否成功
//if SUCCESS(sc is correct),succeed
vp LexAnalysis(string sc,bool& SUCCESS)
{
	vp tmap;
	long int insertNum = 0L;
	for (int i=0;i<sc.length();i++)
	{
	INSERTNUMBER:
		char& c = sc[i];
		//if all number
		//如果都是数字
		if (ifAllNum(c))
		{
			//insertNum=ab,wanna be abc,so *10+c;
			//根据十进制规则,如果ab想变成abc，ab*10+c
			insertNum = insertNum * 10 + (c - '0');
			//no next char
			//没有下一个字符
			if (sc.length() - 1 == i)
			{
				tmap.push_back(psli(NUMBER, insertNum));
				insertNum = 0L;
			}
			//有下一个
			//have next char
			else
			{
				//下一个字符又是一个数字，再分析一次
				//next char is a number,Analysis number again
				if (ifAllNum(sc[i + 1]))
				{
					i++;
					goto INSERTNUMBER;
				}
				//没有下一个数字
				//no next number
				else
				{
					//push进vector
					//push into vector
					tmap.push_back(psli(NUMBER, insertNum));
					insertNum = 0L;
					//继续
					//continue
					goto CTN;
				}
			}
		}
		//分析字符
		//Analysis char
		switch (c)
		{
			//无视空格
			//ignore [space]
		case ' ':
			goto CTN;
		case '(':
			tmap.push_back(psli(LB, NULL));
			break;
		case ')':
			tmap.push_back(psli(RB, NULL));
			break;
		case '+':
			tmap.push_back(psli(PLUS, NULL));
			break;
		case '-':
			tmap.push_back(psli(MINUS, NULL));
			break;
		case '*':
			tmap.push_back(psli(TIMES, NULL));
			break;
		case '/':
			tmap.push_back(psli(DIVIDE, NULL));
			break;
		default:
			//字符非法
			//the char is invalid/illegal
			SUCCESS = false;
			//did't succeed
			return tmap;
		}
	CTN:
		continue;
	}
	//succeed
	return tmap;
}

//func outputSymbol() 输出符号函数
void outputSymbol(int index)
{
	switch (index)
	{
	case 0:
		cout << "LB (";
		break;
	case 1:
		cout << "RB )";
		break;
	case 2:
		cout << "PLUS +";
		break;
	case 3:
		cout << "MINUS -";
		break;
	case 4:
		cout << "TIMES *";
		break;
	case 5:
		cout << "DIVIDE /";
		break;
	case 6:
		cout << "NUMBER";
		break;
	}
}

void ifSuc(bool& SUCCESS)
{
	if (!SUCCESS)
	{
		cerr << "invalid/illegal calc string" << endl;
		cerr << "非法式子" << endl;
		exit(1);
	}
}
