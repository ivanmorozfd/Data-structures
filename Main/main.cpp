#include <iostream>
#include "Main/MultiDataList.h"
#include <vector>
int main() {
	MultiDataList list;
	list.push({ "Ivan3","8902" });
	list.push({ "Ivan2","8901" });

	list.push({ "Ivan4","8903" });
	list.push({ "Ivan1","8905" });
	list.push({ "Ivan5","8904" });
	list.printDebug();
	return 0;
}