#pragma once
#include "core.h"
#include "Container.h"
#include <algorithm>
#include "MultiDataListException.h"
#include <string>
/*!
	Data field in multiDataList
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
struct Field {
	/*!
		Telephone number field
		Contain telephone number
		\author ivanmorozfd
		\version 1.0
		\date April 2020
	*/
	struct TelephoneNumber {
	private:
		std::string content;//!< use to storage number
	public:
		void setContent(std::string content) { this->content = content; }
		std::string getContent() const { return this->content; }
		static void swap (TelephoneNumber* lhs, TelephoneNumber* rhs) { std::swap(lhs->content, rhs->content); }
	public:
		TelephoneNumber() :content(std::string())  { }
	}*telephone;
	/*!
		Second name field
		Contain user's second name number
		\author ivanmorozfd
		\version 1.0
		\date April 2020
	*/
	struct SecondName {
	private:
		std::string content;//!< use to storage second name
	public:
		void setContent(std::string content) { this->content = content; }
		std::string getContent() const { return this->content; }
		static void swap( SecondName* lhs, SecondName* rhs) { std::swap(lhs->content, rhs->content); }
	public:
		SecondName() :content(std::string()) { }
	}*secondName;
public:
	Field* nextTelephone;//!< pointer to next telephone
	Field* nextSecondName;//!< pointer to next second name
	Field* prevTelephone;//!< pointer to prev telephone
	Field* prevSecondName;//!< pointer to prev second name
public:
	Field():secondName(),
		telephone(),
		nextTelephone(nullptr),
		nextSecondName(nullptr),
		prevSecondName(nullptr),
		prevTelephone(nullptr){ }
};
/*!
	MultiDataList
	use to store two sorted data lists
	\author ivanmorozfd
	\version 1.0
	\date April 2020
*/
class MultiDataList : public Container {
private:
	friend class MultiDataListHelper;
	using FieldPtr = Field*;
	using FieldRef = Field&;
private:
	FieldPtr begin_mark;//!< contain min telephone number and min second name
	FieldPtr end_mark;//!<contain max telephone number pointer and second name
	size_t count;//!< elements count in list
private:
	/*!
		Insert telephone  to telephone thread
		works like insertion sort
		\param[in] pointer to placement
	*/
	void insertTelephone(FieldPtr pointer) {
		FieldPtr temp = begin_mark->nextTelephone;
		if (temp->telephone->getContent() > pointer->telephone->getContent()) {
			// check for first item
			pointer->nextTelephone = temp;
			pointer->prevTelephone = begin_mark;

			temp->nextTelephone = end_mark;
			temp->prevTelephone = pointer;
			
			begin_mark->nextTelephone = pointer;
			return;
		}
		//iter by list and compare items
		while (temp->nextTelephone != end_mark) {
			if (temp->telephone->getContent() > pointer->telephone->getContent()) {

				pointer->prevTelephone = temp->prevTelephone;
				pointer->nextTelephone = temp;

				temp->prevTelephone->nextTelephone = pointer;
				temp->nextTelephone->prevTelephone = pointer;
				return;
			}
			else
				temp = temp->nextTelephone;
		}
		if (temp->telephone->getContent() > pointer->telephone->getContent()) {

			pointer->prevTelephone = temp->prevTelephone;
			pointer->nextTelephone = temp;

			temp->prevTelephone->nextTelephone = pointer;
			temp->nextTelephone->prevTelephone = pointer;
			return;
		}
		//we reach end,need new end mark
		temp->nextTelephone = pointer;
		pointer->nextTelephone = end_mark;
		pointer->prevTelephone = temp;
		end_mark->prevTelephone = pointer;
	}
	/*!
		Insert second name  to second name thread
		works like insertion sort
		\param[in] pointer to placement
	*/
	void insertSecondName(FieldPtr pointer) {
		//method works like telephone insert
		FieldPtr temp = begin_mark->nextSecondName;
		if (temp->secondName->getContent() > pointer->secondName->getContent()) {

			pointer->nextSecondName = temp;
			pointer->prevSecondName = begin_mark;

			temp->prevSecondName = pointer;

			begin_mark->nextSecondName = pointer;
			return;
		}
		while (temp->nextSecondName != end_mark) {
			if (temp->secondName->getContent() > pointer->secondName->getContent()) {

				pointer->prevSecondName = temp->prevSecondName;
				pointer->nextSecondName = temp;

				temp->prevSecondName->nextSecondName = pointer;
				temp->nextSecondName->prevSecondName = pointer;
				return;
			}
			else
				temp = temp->nextSecondName;
		}
		if (temp->secondName->getContent() > pointer->secondName->getContent()) {

			pointer->prevSecondName = temp->prevSecondName;
			pointer->nextSecondName = temp;

			temp->prevSecondName->nextSecondName = pointer;
			temp->nextSecondName->prevSecondName = pointer;
			return;
		}
		temp->nextSecondName = pointer;
		pointer->nextSecondName = end_mark;
		pointer->prevSecondName = temp;
		end_mark->prevSecondName = pointer;
	}
	/*!
		Remove node from multilist
		\param[in] pointer to remove
	*/
	void removeNode(FieldPtr node) {
		//capture prev and next node
		auto prevNodeTel = node->prevTelephone;
		auto nextNodeTel = node->nextTelephone;
		//Swap telephone pointers
		prevNodeTel->nextTelephone = nextNodeTel;
		nextNodeTel->prevTelephone = prevNodeTel;
		//capture secondname pointers
		auto prevNodeSecondName = node->prevSecondName;
		auto nextNodeSecondName = node->nextSecondName;
		//swap second name pointers
		prevNodeSecondName->nextSecondName = nextNodeSecondName;
		nextNodeSecondName->prevSecondName = prevNodeSecondName;
		//free field memory
		delete node;
	}
public:
	/*!
		Checks whether the container is empty
		\param[out] bool True,if MultiDataList is empty,otherwise False
	*/
	bool isEmpty() const override {
		return !begin_mark || ( begin_mark->nextSecondName == end_mark );
	}
public:
	/*!
		push new field to MultiDataList
		\param[in] pair<name,number> data
	*/
	void push(std::pair<std::string, std::string> data) {
		//allocate memory for new field
		FieldPtr fieldPointer = new Field();
		//allocate memory for secondname and telephone subfields
		fieldPointer->secondName = new Field::SecondName();
		fieldPointer->telephone = new Field::TelephoneNumber();
		//set field content
		fieldPointer->telephone->setContent(data.second);
		fieldPointer->secondName->setContent(data.first);
		//if list is emtpy,create front and back pointers	
		if (!begin_mark) {
			begin_mark = new Field();

			begin_mark->secondName = new Field::SecondName();
			begin_mark->telephone = new Field::TelephoneNumber();
			begin_mark->nextTelephone = fieldPointer;
			begin_mark->nextSecondName = fieldPointer;
			begin_mark->prevTelephone = nullptr;

			end_mark = new Field();
			end_mark->prevTelephone = fieldPointer;
			end_mark->prevSecondName = fieldPointer;
			end_mark->nextTelephone = nullptr;

			end_mark->secondName = new Field::SecondName();
			end_mark->telephone = new Field::TelephoneNumber();

			fieldPointer->nextSecondName = end_mark;
			fieldPointer->nextTelephone = end_mark;
			fieldPointer->prevSecondName = begin_mark;
			fieldPointer->prevTelephone = begin_mark;
			return;
		}
		//if list is not empty use insert sort to telephone number and secondname thread
		insertTelephone(fieldPointer);
		insertSecondName(fieldPointer);
	}
	/*!
		Find telephone by second name in sorted thread
		\param[out] string telephone
		\param[in] string secondName
	*/
	std::string findBySecondName(std::string secondName) const {
		if (isEmpty())
			throw MultiDataListException("List is empty");

		auto temp = begin_mark->nextSecondName;
		bool isFound = false;
		while (temp != end_mark) {
			if (temp->secondName->getContent() == secondName) {
				isFound = true;
				break;
			}
			else 
				temp = temp->nextSecondName;
		}
		if (isFound) 
			return temp->telephone->getContent();
		else {
			throw MultiDataListException("Field not exist");
		}
	}
	/*!
		Find second name by telephone in sorted thread
		\param[out] string second name
		\param[in] string telephone
	*/
	std::string findByTelelephoneNumber(std::string telephone) const {
		if (isEmpty())
			throw MultiDataListException("List is empty");

		auto temp = begin_mark->nextTelephone;
		bool isFound = false;
		while (temp != end_mark) {
			if (temp->telephone->getContent() == telephone) {
				isFound = true;
				break;
			}
			else
				temp = temp->nextTelephone;
		}
		if (isFound)
			return temp->secondName->getContent();
		else {
			throw MultiDataListException("Field not exist");
		}
	}
	/*!
		Remove field by second name
		\param[in] string second name
	*/
	void removeBySecondName(std::string secondName) {
		if (isEmpty())
			throw MultiDataListException("List is empty");
		auto temp = begin_mark->nextSecondName;
		bool isFound = false;
		while (temp != end_mark) {
			if (temp->secondName->getContent() == secondName) {
				isFound = true;
				break;
			}
			else
				temp = temp->nextSecondName;
		}
		if (isFound) {
			removeNode(temp);
		}
		else {
			throw MultiDataListException("Field not exist");
		}
	}
	/*!
		Remove field by telephone
		\param[in] string telephone
	*/
	void removeByTelephone(std::string telephone) {
		if (isEmpty())
			throw MultiDataListException("List is empty");
		auto temp = begin_mark->nextTelephone;
		bool isFound = false;
		while (temp != end_mark) {
			if (temp->telephone->getContent() == telephone) {
				isFound = true;
				break;
			}
			else
				temp = temp->nextTelephone;
		}
		if (isFound) {
			removeNode(temp);
		}
		else {
			throw MultiDataListException("Field not exist");
		}
	}
	/*!
		Clear MultiDataList
	*/
	void clear() {
		auto temp = begin_mark->nextSecondName;
		while (temp != end_mark) {
			removeBySecondName(temp->secondName->getContent());
			temp = temp->nextSecondName;
		}
	}
	/*!
		Print second name thread
	*/
	friend void printOrderedBySecondName(MultiDataList* list) {
		auto temp = list->begin_mark->nextSecondName;
		while (temp != list->end_mark) {
			std::cout << temp->telephone->getContent() << " " << temp->secondName->getContent() << std::endl;
			temp = temp->nextSecondName;
		}
	}
	/*!
		Print telephone thread
	*/
	friend void printOrderedByTelephone(MultiDataList* list) {
		auto temp = list->begin_mark->nextTelephone;
		while (temp != list->end_mark) {
			std::cout << temp->telephone->getContent() << " " << temp->secondName->getContent() << std::endl;
			temp = temp->nextTelephone;
		}
	}
public:
	MultiDataList():begin_mark(nullptr),
		end_mark(nullptr),
		count(0) {

	}
	MultiDataList(std::initializer_list<std::pair<std::string,std::string>>& data) :begin_mark(nullptr),
		end_mark(nullptr),
		count(0) {
		for (auto& i : data) {
			this->push(i);
		}
	}
};