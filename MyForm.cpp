#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ arg) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	osn::MyForm myForm;
	Application::Run(%myForm);
}