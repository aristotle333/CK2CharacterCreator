#include "characterForm.h"
#include <fstream>
#include <Windows.h>
using std::ofstream;

using namespace System;
using namespace System::Windows::Forms;

[STAThread]//leave this as is
int main(array<String^>^ args) {

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    CK2CharacterModdingApplication::characterForm form;
    Application::Run(%form);

    //ofstream os("test.txt");
    //os << "Hi I am first";
    //os.close();

    return 0;
}