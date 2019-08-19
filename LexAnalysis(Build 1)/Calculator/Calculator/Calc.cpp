#include "Calc.h"

//ASCII:
//48 '0'
//57 '9'
//func ifAllNum() ����ifAllNum()
//check the char cnum is or isn't a number
bool ifAllNum(char& cnum)
{
	return ((cnum >= 48) && (cnum <= 57));
}

//func LexAnalysis() �ʷ���������

/*
 * typedef pair<Symbol,long int> psli;
 * typedef vector<psli> vp;
 */

//������������tokensװ��vector<pair<Symbol,long int>>��
//tokens into vp,and return vp;
//sc is "string to Calculate"
//SUCCESS �洢�Ƿ�ɹ�
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
		//�����������
		if (ifAllNum(c))
		{
			//insertNum=ab,wanna be abc,so *10+c;
			//����ʮ���ƹ���,���ab����abc��ab*10+c
			insertNum = insertNum * 10 + (c - '0');
			//no next char
			//û����һ���ַ�
			if (sc.length() - 1 == i)
			{
				tmap.push_back(psli(NUMBER, insertNum));
				insertNum = 0L;
			}
			//����һ��
			//have next char
			else
			{
				//��һ���ַ�����һ�����֣��ٷ���һ��
				//next char is a number,Analysis number again
				if (ifAllNum(sc[i + 1]))
				{
					i++;
					goto INSERTNUMBER;
				}
				//û����һ������
				//no next number
				else
				{
					//push��vector
					//push into vector
					tmap.push_back(psli(NUMBER, insertNum));
					insertNum = 0L;
					//����
					//continue
					goto CTN;
				}
			}
		}
		//�����ַ�
		//Analysis char
		switch (c)
		{
			//���ӿո�
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
			//�ַ��Ƿ�
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

//func outputSymbol() ������ź���
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
		cerr << "�Ƿ�ʽ��" << endl;
		exit(1);
	}
}
