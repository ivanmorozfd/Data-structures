#pragma once
#include "MultiDataList.h"

class MultiDataListHelper {
private:
	MultiDataListHelper() = default;
	~MultiDataListHelper() = default;
private:
	static std::pair<std::string, std::string> getDataFromStr(std::string dataStr) {
		size_t splitPos = dataStr.find(";");
		return std::make_pair(dataStr.substr(0, splitPos),
			dataStr.substr(splitPos + 1, dataStr.npos));
	}
public:
	static void printOrderByTelephone(const MultiDataList* list) {
		Field* tmp = list->begin_mark->nextTelephone;
		while (tmp != list->end_mark) {
			std::cout << tmp->telephone->getContent() << " ";
		}
	}
	static void printOrderBySecondName(const MultiDataList* list) {
		Field* tmp = list->begin_mark->nextSecondName;
		while (tmp != list->end_mark) {
			std::cout << tmp->secondName->getContent() << " ";
		}
	}
	static MultiDataList& readMultiDataListFromFile(std::ifstream& inputStream) {
		MultiDataList* list = new MultiDataList();
		char* buff;
		while (!inputStream.eof()) {
			inputStream.getline(buff,100);
			list->push(getDataFromStr(std::string(buff)));
		}
	}
	static void writeMultiDataListToFile(const MultiDataList* list,std::ofstream& outputStream) {
		Field* temp = list->begin_mark->nextSecondName;
		do {
			outputStream << temp->secondName->getContent() 
				<< ";" 
				<< temp->telephone->getContent() 
				<< std::endl;
		} while (temp = temp->nextSecondName);
	}
};