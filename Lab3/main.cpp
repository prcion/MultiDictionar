#include "TestScurt.h"
#include "TestLung.h"
#include <stdlib.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
int main()
{
	testAll();
	testAllExtins();
	//_CrtDumpMemoryLeaks();
	//system("pause");
	return 0;
}