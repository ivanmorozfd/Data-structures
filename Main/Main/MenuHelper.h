#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
using std::string;
class MenuHelper
{
public:
	MenuHelper()
	{
		createMainMenuInstance();
	}
private:
	void createMainMenuInstance();
	void createStackMenuInstance();
	void createQueueMenuInstance();
	void createDequeMenuInstance();
	void createDlistMenuInstance();
	void createBheapMenuInstance();
	void createMatrixMenuInstance();
	void createAvlTreeMenuInstance();
	void createBstMenuInstance();
	void createRbTreeMenuInstance();
	void clearConsole();
};

