#include "String.h"

void main()
{
	String str1('f', 6);
	//str1.writeToStr();
	str1.printStr();

	String str2("ffffff");
	str2.printStr();

	cout << String::Compare(str1,str2) << endl;
}