#include"GeneralList.h"


void Test()
{
	GeneralList g1("()");
	g1.Print();
	GeneralList g2("(a,b)");
	g2.Print();
	GeneralList g3("(a,b,(c,d))");
	GeneralList g4("(a,b,(c,d,(e),f),g)");
	
	
	g3.Print();
	g4.Print();

	cout <<"g4.Size:"<< g4.Size() << endl;
	cout << "g4.Depth:"<<g4.Depth() << endl;
}

int main()
{
	Test();
	system("pause");
	return 0;
}