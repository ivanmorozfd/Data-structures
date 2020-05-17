#pragma once
#include "core.h"
#include "Container.h"
#include <algorithm>
#include <string>
#include <regex>
struct Field {
	struct TelephoneNumber {
	private:
		std::string content;
	public:
		void setContent(std::string content) { this->content = content; }
		std::string getContent() const { return this->content; }
		static void swap (TelephoneNumber* lhs, TelephoneNumber* rhs) { std::swap(lhs->content, rhs->content); }
	public:
		TelephoneNumber() :content(std::string())  { }
	}*telephone;
	struct SecondName {
	private:
		std::string content;
	public:
		void setContent(std::string content) { this->content = content; }
		std::string getContent() const { return this->content; }
		static void swap( SecondName* lhs, SecondName* rhs) { std::swap(lhs->content, rhs->content); }
	public:
		SecondName() :content(std::string()) { }
	}*secondName;
public:
	Field* nextTelephone;
	Field* nextSecondName;
	Field* prevTelephone;
	Field* prevSecondName;
public:
	Field():secondName(),
		telephone(),
		nextTelephone(nullptr),
		nextSecondName(nullptr),
		prevSecondName(nullptr),
		prevTelephone(nullptr){ }
};
class MultiDataList : public Container {
	using FieldPtr = Field*;
	using FieldRef = Field&;
private:
	FieldPtr begin_mark;//!< contain min telephone number and min second name
	FieldPtr end_mark;//!<contain max telephone number pointer and second name
	size_t count;
private:
	void insertTelephone(FieldPtr pointer) {
		FieldPtr temp = begin_mark->nextTelephone;
		if (temp->telephone->getContent() > pointer->telephone->getContent()) {
			
			pointer->nextTelephone = temp;
			pointer->prevTelephone = begin_mark;

			temp->nextTelephone = end_mark;
			temp->prevTelephone = pointer;
			
			begin_mark->nextTelephone = pointer;
			return;
		}
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
		temp->nextTelephone = pointer;
		pointer->nextTelephone = end_mark;
		pointer->prevTelephone = temp;
		end_mark->prevTelephone = pointer;
	}
	void insertSecondName(FieldPtr pointer) {
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
public:
	bool isEmpty() const override {
		return !begin_mark;
	}
public:
	void push(std::pair<std::string, std::string> data) {
		FieldPtr fieldPointer = new Field();

		fieldPointer->secondName = new Field::SecondName();
		fieldPointer->telephone = new Field::TelephoneNumber();

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
		insertTelephone(fieldPointer);
		insertSecondName(fieldPointer);
	}
	void printDebug() {
		auto temp = begin_mark->nextTelephone;
		while (temp != end_mark) {
			std::cout << temp->telephone->getContent() << " " <<temp->secondName->getContent() << std::endl;
			temp = temp->nextTelephone;
		}
			// std::cout << begin_mark->telephone->getContent() << begin_mark->secondName->getContent() << std::endl;
			// std::cout << end_mark->telephone->getContent() << end_mark->secondName->getContent() << std::endl;
	}
	void clear() {

	}
public:
	MultiDataList():begin_mark(nullptr),
		end_mark(nullptr),
		count(0) {

	}
	MultiDataList(std::initializer_list<std::pair<std::string,std::string>>& data) :begin_mark(nullptr),
		end_mark(nullptr),
		count(0) {

	}
};