#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]//leave this as is
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    CK2CharacterModdingApplication::[FORM NAME] form;
    Application::Run(%form);
}