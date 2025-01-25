#include "MyForm.h"
#include <string>

using namespace System;
using namespace System::Windows::Forms;
using namespace std;


void main()
{

    Application::EnableVisualStyles();

    Application::SetCompatibleTextRenderingDefault(false);

    MapTileGenerator::MyForm form;

    Application::Run(% form);

}



