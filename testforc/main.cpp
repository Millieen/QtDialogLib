#include <iostream>

using namespace std;

#include "dialoglib.h"
int main()
{
    cout << "Hello World!" << endl;

    int ret = Initialize();
    cout << "Initialize() return " << ret << endl;
    ret = ShowMessageDialog("Title from C call", "show 'Default' image text");
    cout << "ShowMessageDialog() return " << ret << endl;
    ret = Finalize();
    cout << "Finalize() return " << ret << endl;


    ret = Initialize("otherresource.rcc");
    cout << "Initialize(\"otherresource.rcc\") return " << ret << endl;
    ret = ShowMessageDialog("Title from C call", "show 'A' image text");
    cout << "ShowMessageDialog() return " << ret << endl;
    ret = Finalize();
    cout << "Finalize() return " << ret << endl;

    return 0;
}

