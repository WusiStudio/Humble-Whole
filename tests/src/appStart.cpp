#include "testApp.h"
#include <iostream>

int main(int argc, char ** argv)
{
	IMSTACK
    
    ws::testApp & app = ws::testApp::Create();

    std::getchar();

    return 0;
}