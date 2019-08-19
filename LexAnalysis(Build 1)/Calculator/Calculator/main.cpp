/////////////////////////////////////////
//                                     //
//   项目名称（Project Name):          //
//   计算器（Calculator）              //                     
//   制作人（Creator):                 //
//   相子骏（TinxG）                   //
//   创建时间（Create Time）:          //
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
	cout << "请输入一个计算式子" << endl;
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