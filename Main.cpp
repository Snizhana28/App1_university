#include "String.h"

int main()
{
    String str1("123.45");
    String str2("World");

    String result = str1 + String(" ") + str2;

    result.printFormat();

    if (str1 == str2) {
        cout << "Strings are equal.\n";
    }
    else {
        cout << "Strings are not equal.\n";
    }
    cout << "str1.toNumber<int>() = " << str1.toNumber<int>() << "\n";
    cout << "str1.toNumber<double>() = " << str1.toNumber<double>() << "\n";
    cout << "str1.toNumber<float>() = " << str1.toNumber<float>() << "\n";

    
    String str3 = str1;
    str3.printFormat();
    str3 += str2;
    str3.printFormat();
    str3 = str1 + String(" ") + str2;
    str3.printFormat();

	return 0;
}
