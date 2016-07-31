#include "characterForm.h"
#include "settingsParser.h"
#include <fstream>
#include <Windows.h>
using std::ofstream;

using namespace System;
using namespace System::Windows::Forms;

[STAThread]//leave this as is
int main(array<String^>^ args) {

    readSettingsFile();

    // Form Related Functions
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    CK2CharacterModdingApplication::characterForm form;
    Application::Run(%form);

    return 0;
}