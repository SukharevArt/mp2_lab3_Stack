
#include<string>

#include "HTStack.h"
#include "Calculator.h"

using namespace std;

int main() {
	TCalculator t;
	t.SetExpr("2+(3*2)^(2-2*1+1)*(3-1)");// = 2+2*6^1=14
	t.ToPostfix();
	cout << t.GetExpr() << "\n";
	cout << t.GetPostfix() << "\n";
	cout << t.Calc() << "\n";

	t.SetExpr("36+4*50-56");//=36+200-56=180
	t.ToPostfix();
	cout << t.GetExpr() << "\n";
	cout << t.GetPostfix() << "\n";
	cout << t.Calc() << "\n";

	t.SetExpr("2^4-45+300*(3-7)");//=16-45-1200=-1229
	t.ToPostfix();
	cout << t.GetExpr() << "\n";
	cout << t.GetPostfix() << "\n";
	cout << t.Calc() << "\n";
	
	t.SetExpr("(30-4)*(3-2)+5-8*1*3");//=26+5-24=7
	t.ToPostfix();
	cout << t.GetExpr() << "\n";
	cout << t.GetPostfix() << "\n";
	cout << t.Calc() << "\n";
	
	t.SetExpr("(30-4)*(3-1*1)-(1+3^2)*(2*2-1)");//=26*2-10*3=22
	t.ToPostfix();
	cout << t.GetExpr() << "\n";
	cout << t.GetPostfix() << "\n";
	cout << t.Calc() << "\n";

}

// тесты стек:
// заданный размер
// полонота пустота
// положить,извлечь
// копирование

// тест калькулятор:
// создание
// добавление строк в калькулятор
// проверка правильности скобок
// может подсчитать
// может ли подсчитать все 