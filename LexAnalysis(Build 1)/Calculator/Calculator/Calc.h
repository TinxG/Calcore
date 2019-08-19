#pragma once
#include "symbols.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;


typedef pair<Symbol, long int> psli;	
typedef vector<psli> vp;

bool ifAllNum(char& cnum);
vp LexAnalysis(string sc,bool& SUCCESS);
void outputSymbol(int index);
void ifSuc(bool& SUCCESS);