/////////////////////////////////////////
//                                     //
//   ��Ŀ���ƣ�Project Name):          //
//   ��������Calculator��              //                     
//   �����ˣ�Creator):                 //
//   ���ӿ���TinxG��                   //
//   ����ʱ�䣨Create Time��:          //
//   2019/8/7                          //
//                                     //
/////////////////////////////////////////

/*                 Ver 1                   *               LexAnalysis              */

#include "Calc.h"

vp tokens;
bool SUCCESS = true;

//just a test function main()
//not the final program
int main()
{
	string calc;
	cout << "please input a string to calculate(+ - * / ( ) number)" << endl;
	cout << "������һ������ʽ��" << endl;
	getline(cin, calc);
	tokens = LexAnalysis(calc, SUCCESS);
	ifSuc(SUCCESS);
	for (vp::iterator vpi=tokens.begin();vpi!=tokens.end();vpi++)
	{
		outputSymbol(int(vpi->first));
		cout << "," << vpi->second << endl;
	}
	system("pause");
	return 0;
}