#pragma once
#include "MultiDataList.h"
/*!
	Static class functions library
	\brief Use to work with MultiDataList 
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class MultiDataListHelper {
private:
	MultiDataListHelper() = default;
	~MultiDataListHelper() = default;
private:
	static std::pair<std::string, size_t> getDataFromStr(std::string dataStr) {
		size_t splitPos = dataStr.find(";");
		return std::make_pair(dataStr.substr(0, splitPos),
			std::stoi(dataStr.substr(splitPos + 1, dataStr.npos)));
	}
public:
	static void printOrderByTelephoneInc(const MultiDataList* list) {
		if (list->isEmpty())
			throw MultiDataListException("List is empty");

		Field* tmp = list->begin_mark->nextTelephone;
		while (tmp != list->end_mark) {
			std::cout << tmp->telephone->getContent() << " ";
			tmp = tmp->nextTelephone;
		}
	}
	static void printOrderByTelephoneDec(const MultiDataList* list) {
		if (list->isEmpty())
			throw MultiDataListException("List is empty");

		Field* tmp = list->end_mark->prevTelephone;
		while (tmp != list->begin_mark) {
			std::cout << tmp->telephone->getContent() << " ";
			tmp = tmp->prevTelephone;
		}
	}
	static void printOrderBySecondNameInc(const MultiDataList* list) {
		if (list->isEmpty())
			throw MultiDataListException("List is empty");

		Field* tmp = list->begin_mark->nextSecondName;
		while (tmp != list->end_mark) {
			std::cout << tmp->secondName->getContent() << " ";
			tmp = tmp->nextSecondName;
		}
	}
	static void printOrderBySecondNameDec(const MultiDataList* list) {
		if (list->isEmpty())
			throw MultiDataListException("List is empty");

		Field* tmp = list->end_mark->prevSecondName;
		while (tmp != list->begin_mark) {
			std::cout << tmp->secondName->getContent() << " ";
			tmp = tmp->prevSecondName;
		}
	}
	static MultiDataList* readMultiDataListFromFile(std::ifstream& inputStream) {
		MultiDataList* list = new MultiDataList();
		std::string buff{};
		while (!inputStream.eof()) {
			std::getline(inputStream,buff);
			list->push(getDataFromStr(std::string(buff)));
		}
		return list;
	}
	static void writeMultiDataListToFile(const MultiDataList* list,std::ofstream& outputStream) {
		if (list->isEmpty())
			throw MultiDataListException("List is empty");

		Field* temp = list->begin_mark->nextSecondName;
		while(temp!= list->end_mark){
			outputStream << temp->secondName->getContent() 
				<< ";" 
				<< temp->telephone->getContent() 
				<< std::endl;
			temp = temp->nextSecondName;
		}
	}
};