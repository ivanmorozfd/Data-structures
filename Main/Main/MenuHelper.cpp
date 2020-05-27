#include "MenuHelper.h"
#include "Stack.h"
#include "Queue.h"
#include "DoubleLinkedList.h"
#include "BinaryHeap.h"
#include "SparseMatrix.h"
#include "AvlTree.h"
#include "BinarySearchTree.h"
#include "RBTree.h"
#include <random>
#include "MenuConsts.h"

#include "StackHelper.h"
#include "QueueHelper.h"
#include "DoubleLinkedListHelper.h"
#include "SparseMatrixHelper.h"
#include "BinaryHeapHelper.h"
#include "MultiDataListHelper.h"
#include "BinarySearchTreeHelper.h"
#include "AvlTreeHelper.h"
#include "RBTreeHelper.h"
void MenuHelper::createMainMenuInstance()
{
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		while (true)
		{
			int answer = -1;
			std::wcout << menuTitle 
				<< menuStackName 
				<< menuQueueName 
				<< menuMListName  
				<< menuDListName 
				<< menuBHeapName 
				<< menuMatrixName 
				<< menuAvlTreeName 
				<< menuBstName
				<< menuRbTreeName 
				<< menuExitName;
			std::cout << enterAnswer;
			std::cin >> answer;
			switch (answer)
			{
			case 1:
				this->createStackMenuInstance();
				break;
			case 2:
				this->createQueueMenuInstance();
				break;
			case 3:
				this->createMultiDataListInstance();
				break;
			case 4:
				this->createDlistMenuInstance();
				break;
			case 5:
				this->createBheapMenuInstance();
				break;
			case 6:
				this->createMatrixMenuInstance();
				break;
			case 7:
				this->createAvlTreeMenuInstance();
				break;
			case 8:
				this->createBstMenuInstance();
				break;
			case 9:
				this->createRbTreeMenuInstance();
				break;
			case 10:
				exit(EXIT_SUCCESS);
			default:
				clearConsole();
				std::cout << menuInputError;

				break;
			}
		}
	}
}

void MenuHelper::createStackMenuInstance() {
	clearConsole();

	bool isActive = true;
	Stack<int>* stack = nullptr;
	while (isActive) {
		int answer = -1;

		std::wcout << stackMenuSelectAction
			<< stackMenuCreateStack
			<< stackMenuEmptyTest
			<< stackMenuPushItem
			<< stackMenuPeekTop
			<< stackMenuPopItem
			<< stackMenuReadFromFile
			<< stackMenuWriteToFile
			<< stackMenuClear
			<< stackMenuDestroy
			<< stackMenuRandomize
			<< stackMenuPrint
			<< stackMenuExit;

		std::cout << enterAnswer;
		std::cin >> answer;
		switch (answer) {
		case 1: {
			clearConsole();
			if (!stack) {
				stack = new Stack<int>();
				std::wcout << stackCreateSuccess;
			}
			else
				std::wcout << stackCreateFailure;
			break;
		}
		case 2: {
			clearConsole();
			if (!stack)
				std::wcout << stackNotCreated;
			else {
				if (stack->isEmpty())
					std::wcout << stackIsEmpty;
				else
					std::wcout << stackIsNotEmpty;
			}
			break;
		}
		case 3: {
			clearConsole();
			if (!stack)
				std::wcout << stackNotCreated;
			else {
				int answer = -1;

				std::wcout << stackPushMessage01;
				std::wcout << enterAnswer;
				std::cin >> answer;

				stack->push(answer);

				std::wcout << stackPushMessage02
					<< answer
					<< stackPushMessage03;
			}
			break;
		}
		case 4: {
			clearConsole();
			if (!stack)
				std::wcout << stackNotCreated;
			else {
				try {
					std::wcout << stackPeekMessage
						<< stack->peek()
						<< std::endl
						<< std::endl;
				}
				catch (StackException & e) {
					std::wcout << stackIsEmpty;
				}
			}
			break;
		}
		case 5:{
			if (!stack){
				clearConsole();
				std::wcout << stackNotCreated;
			}
			else{
				clearConsole();
				try {
					stack->pop();
					std::wcout << stackPopMessage;
				}
				catch (StackException & e){
					std::wcout << stackIsEmpty;
				}
			}
			break;
		}
		case 6: {
			std::wcout << stackReadFileMessage;
			std::wcout << enterAnswer;
			std::string fileName;
			std::cin >> fileName;
			std::ifstream fin(fileName + ".txt");
			clearConsole();
			if (!fin.is_open()) {
				std::wcout << stackReadFileErrMessage;
				break;
			}
			else
			{
				if (stack) {
					delete stack;
					stack = nullptr;
					stack = new Stack<int>();
				}
				stack = StackHelper::readFromFile<int>(fin);
			}
			std::wcout << stackReadFileSuccessMessage;
			break;
		}
		case 7: {
			if (!stack){
				std::wcout << stackNotCreated;
				break;
			}
			std::wcout << stackWriteFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			std::ofstream out(fileName + ".txt", std::ios_base::trunc);
			
			clearConsole();

			if (!out.is_open()){
				std::wcout << stackWriteFileErrMessage;
				break;
			}
			else 
				StackHelper::writeToFile(stack, out);

			out.close();

			std::wcout << stackWriteFileSuccess;
			break;
		}
		case 8: {
			clearConsole();
			stack->clear();
			std::wcout << stackClearSucces;
			break;
		}
		case 9:{
			clearConsole();
			if (stack){
				delete stack;
				stack = nullptr;
				std::wcout << stackDestroyedMessage;
			}
			else
				std::wcout << stackNotCreated;
			break;
		}
		case 10: {
			std::wcout << stackRandomizeMessage;
			std::wcout << enterAnswer;
			int stackSize = 0;
			std::cin >> stackSize;
			if (stackSize < 1) 
			{ 
				clearConsole();
				std::wcout << stackRandomizeErrorMessage;
				break;
			}
			std::wcout << stackRandomizeUpRangeMessge;
			std::wcout << enterAnswer;
			int upValue;
			std::cin >> upValue;
			for (int i = 0; i < stackSize; ++i)
			{
				stack->push(std::rand() % upValue);
			}
			clearConsole();
			std::wcout<< stackRandomizeSuccess;
			break;
		}
		case 11: {
			clearConsole();
			StackHelper::print_stack(stack);
			break;
		}
		case 12: {
			clearConsole();
			delete stack;
			isActive = false;
			break;
		}
		default:
			break;
		}
	}
	clearConsole();
}

void MenuHelper::createQueueMenuInstance()
{
	clearConsole();
	bool isActive = true;
	Queue<int>* queue = nullptr;
	while (isActive)
	{
		int answer = -1;
		std::wcout << queueMenuSelectAction
			<< queueMenuCreate
			<< queueMenuEmptyTest
			<< queueMenuPushItem
			<< queueMenuPeek
			<< queueMenuPopItem
			<< queueMenuReadFromFile
			<< queueMenuWriteToFile
			<< queueMenuRandomize
			<< queueMenuPrint
			<< queueMenuClear
			<< queueMenuDestroy
			<< queueMenuExit;

		std::cout << enterAnswer;
		std::cin >> answer;
		switch (answer){
			case 1:{
				clearConsole();
				if (!queue) {
					queue = new Queue<int>();
					std::cout << queueCreateSuccess;
				}
				else
					std::cout << queueCreateFailure;
				break;
			}
			case 2: {
				clearConsole();
				if (!queue) {
					std::cout << queueNotCreated;
				}
				else {
					if (queue->isEmpty()) 
						std::cout << queueIsEmpty;
					else 
						std::cout << queueIsNotEmpty;
				}
				break;
			}
			case 3: {
				if (!queue) {
					clearConsole();
					std::cout << queueNotCreated;
				}
				else {
					int answer = -1;

					std::cout << queuePushMessage01;
					std::wcout << enterAnswer;
					std::cin >> answer;

					clearConsole();
					queue->push(answer);

					std::wcout << queuePushMessage02
						<< answer
						<< queuePushMessage03;

				}
				break;
			}	
			case 4: {
				clearConsole();
				if (!queue) {
					std::cout << queueNotCreated;
				}
				else {
					if (queue->isEmpty())
						std::cout << queueIsEmpty;
					else {
						std::cout << queuePeekMessage
							<< queue->peek();
					}
				}
				break;
			}
			case 5: {
				clearConsole();
				if (!queue) 
					std::cout << queueNotCreated;
				else {
					try {
						queue->pop();
					}
					catch (QueueException & e) {
						std::cout << queueIsEmpty;
					}
				}
				break;
			}
			case 6:{
				std::wcout << queueReadFileMessage;
				std::wcout << enterAnswer;
				
				std::string fileName;
				std::cin >> fileName;
				std::ifstream fin(fileName + ".txt");
				
				clearConsole();
				
				if (!fin.is_open()){
					std::wcout << queueReadFileErrMessage;
					break;
				}
				else{
					if (queue){
						delete queue;
						queue = nullptr;
						queue = new Queue<int>();
					}
					queue = QueueHelper::readFromFile<int>(fin);
				}
				std::wcout << queueReadFileSuccessMessage;
				break;
			}
			case 7: {
				if (!queue) {
					clearConsole();
					std::wcout << queueNotCreated;
					break;
				}
				std::wcout << queueWriteFileMessage;
				std::wcout << enterAnswer;

				std::string fileName;
				std::cin >> fileName;

				std::ofstream out(fileName + ".txt", std::ios_base::trunc);
				if (!out.is_open()) {
					clearConsole();
					std::wcout << queueWriteFileErrMessage;
					break;
				}
				else 
					QueueHelper::writeToFile<int>(queue,out);
				
				out.close();
				std::wcout << queueWriteFileSuccess;
				break;
			}
			case 8: {
				std::wcout << queueRandomizeMessage;
				std::wcout << enterAnswer;
				int queueSize = 0;
				std::cin >> queueSize;
				if (queueSize < 1)
				{
					clearConsole();
					std::wcout << queueRandomizeErrorMessage;
					break;
				}
				std::wcout << queueRandomizeUpRangeMessge;
				std::wcout << enterAnswer;
				int upValue;
				std::cin >> upValue;
				for (int i = 0; i < queueSize; ++i) {
					queue->push(std::rand() % upValue);
				}
				clearConsole();
				std::wcout << queueRandomizeSuccess;
				break;
			}
			case 9: {
				clearConsole();
				QueueHelper::print_queue(queue);
				break;
			}
		case 10: {
			clearConsole();
			if (!queue) {
				std::cout << queueNotCreated;
			}
			else
				queue->clear();
			break;
		}
		case 11: {
			clearConsole();
			if (queue) {
				std::cout << queueDestroyedMessage;
				delete queue;
				queue = nullptr;
			}
			else 
				std::cout << queueNotCreated;
			break;
		}
		case 12:
			clearConsole();
			delete queue;
			isActive = false;
			break;
		default:
			break;	
		}
	}
	clearConsole();
}

void MenuHelper::createMultiDataListInstance()
{
	clearConsole();
	bool isActive = true;
	MultiDataList* list = nullptr;
	while (isActive) {
		int answer = -1;
		std::cout << mlistMenuSelectAction
			<< mlistMenuCreate
			<< mlistMenuIsEmpty
			<< mlistMenuPush
			<< mlistMenuRemoveBySecondName
			<< mlistMenuRemoveByTelephone
			<< mlistMenuPrintOrderBySecondNameDec
			<< mlistMenuPrintOrderBySecondNameInc
			<< mlistMenuPrintOrderByTelephoneDec
			<< mlistMenuPrintOrderByTelephoneInc
			<< mlistMenuReadFromFile
			<< mlistMenuWriteToFile
			<< mlistMenuClear
			<< mlistMenuDestroy
			<< mlistMenuExit;
		std::cout << enterAnswer;
		std::cin >> answer;
		switch (answer) {
		case 1: {
			clearConsole();
			if (list)
				std::cout << mlistCreateFailure;
			else {
				std::cout << mlistCreateSuccess;
				list = new MultiDataList();
			}
			break;
		}
		case 2: {
			clearConsole();
			if (!list)
				std::cout << mlistNotCreated;
			else {
				if (list->isEmpty())
					std::cout << mlistIsEmpty;
				else
					std::cout << mlistIsNotEmpty;
			}
			break;
		}
		case 3: {
			if (!list)
				std::cout << mlistNotCreated;
			else {
				std::string name = "";
				std::string telephone = "";

				std::cout << mlistPushMessage01;
				std::cout << enterAnswer;
				std::cin >> name >> telephone;
				
				clearConsole();

				list->push({ name, telephone });

				std::cout << name 
					<< " : " 
					<< telephone 
					<< mlistPushMessage02;
			}
			break;
		}
		case 4: {
			if (!list)
				std::cout << mlistNotCreated;
			else {
				std::string secName = "";

				std::cout << mlistRemoveBySecondNameMessage01
					<< enterAnswer;

				std::cin >> secName;
				try {
					list->removeBySecondName(secName);
					std::cout << mlistRemoveBySecondNameMessage02;
				}
				catch (MultiDataListException & e) {
					break;
				}
			}
			break;
		}
		case 5: {
			if (!list)
				std::cout << mlistNotCreated;
			else {
				std::string telephone = "";

				std::cout << mlistRemoveByTelephoneMessage01
					<< enterAnswer;

				std::cin >> telephone;
				try {
					list->removeBySecondName(telephone);
					std::cout << mlistRemoveByTelephoneMessage02;
				}
				catch (MultiDataListException & e) {
					break;
				}
			}
			break;
		}
		case 6: {
			break;
		}
		case 7: {
			break;
		}
		case 8: {
			clearConsole();
			if (!list)
				std::cout << mlistNotCreated;
			else {
				try {
					std::cout << mlistPrintOrderBySecondName << mlistPrintDec;
					MultiDataListHelper::printOrderBySecondNameDec(list);
				}
				catch (MultiDataListException & e) {
					break;
				}
			}
			break;
		}
		case 9: {
			clearConsole();
			if (!list)
				std::cout << mlistNotCreated;
			else {
				try {
					std::cout << mlistPrintOrderBySecondName << mlistPrintInc;
					MultiDataListHelper::printOrderBySecondNameInc(list);
				}
				catch (MultiDataListException & e) {
					break;
				}
			}
			break;
		}
		case 10: {
			clearConsole();
			if (!list)
				std::cout << mlistNotCreated;
			else {
				try {
					std::cout << mlistPrintOrderByTelephone << mlistPrintDec;
					MultiDataListHelper::printOrderByTelephoneDec(list);
				}
				catch (MultiDataListException & e) {
					break;
				}
			}
			break;
		}
		case 11: {
			clearConsole();
			if (!list)
				std::cout << mlistNotCreated;
			else {
				try {
					std::cout << mlistPrintOrderByTelephone << mlistPrintInc;
					MultiDataListHelper::printOrderByTelephoneInc(list);
				}
				catch (MultiDataListException & e) {
					break;
				}
			}
			break;
		}
		case 12: {
			if (!list)
				std::cout << mlistNotCreated;
			else {
				std::wcout << mlistReadFileMessage;
				std::wcout << enterAnswer;

				std::string fileName;
				std::cin >> fileName;

				std::ifstream fin(fileName + ".txt");

				if (!fin.is_open()) {
					std::wcout << mlistReadFileErrMessage;
					break;
				}
				else {
					if (list) {
						delete list;
						list = nullptr;
						list = new MultiDataList;
					}
					list = MultiDataListHelper::readMultiDataListFromFile(fin);
				}

				std::wcout << mlistReadFileSuccessMessage;
			}
			break;
		}
		case 13: {
			clearConsole();
			if (!list) {
				std::wcout << mlistNotCreated;
				break;
			}
			std::wcout << mlistWriteFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			std::ofstream out(fileName + ".txt",
				std::ios_base::trunc);

			if (!out.is_open()) {
				std::wcout << mlistWriteFileErrMessage;
				break;
			}
			else {
				MultiDataListHelper::writeMultiDataListToFile(list, out);
			}
			out.close();

			std::wcout << mlistWriteFileSuccess;
			break;
		}
		case 14: {
			clearConsole();
			if (!list) {
				std::wcout << mlistNotCreated;
				break;
			}
			list->clear();
			std::cout << mlistClearSucces;
			break;
		}
		case 15: {
			clearConsole();
			if (!list) {
				std::wcout << mlistNotCreated;
				break;
			}
			else {
				std::cout << mlistDestroyedMessage;
				delete list;
				list = nullptr;
			}
			break;
		}
		case 16: {
			clearConsole();
			delete list;
			isActive = false;
			break;
		}
		default:
			break;
		}
	}
}

void MenuHelper::createDlistMenuInstance()
{
	clearConsole();
	bool isActive = true;
	DoubleLinkedList<int>* list = nullptr;
	while (isActive)
	{
		int answer = -1;
		std::wcout << dlistMenuSelectAction
			<< dlistMenuCreate
			<< dlistMenuIsEmpty
			<< dlistMenuPushBack
			<< dlistMenuPushFront
			<< dlistMenuPeekFront
			<< dlistMenuPeekBack
			<< dlistMenuPopFront
			<< dlistMenuPopBack
			<< dlistMenuReadFromFile
			<< dlistMenuWriteToFile
			<< dlistMenuRandomize
			<< dlistMenuPrint
			<< dlistMenuClear
			<< dlistMenuDestroy
			<< dlistMenuExit;
		std::cout << enterAnswer;
		std::cin >> answer;
		switch (answer) {
		case 1: {
			clearConsole();
			if (list) 
				std::cout << dlistCreateFailure;
			else {
				std::cout << dlistCreateSuccess;
				list = new DoubleLinkedList<int>();
			}
			break;
		}
		case 2: {
			clearConsole();
			if (!list)
				std::cout << dlistNotCreated;
			else {
				if (list->isEmpty())
					std::cout << dlistIsEmpty;
				else
					std::cout << dlistIsNotEmpty;
			}
			break;
		}
		case 3: {
			clearConsole();
			if (!list)
				std::cout << dlistNotCreated;
			else {
				int answer = -1;

				std::cout << dlistPushBackMessage01;
				std::cout << enterAnswer;

				std::cin >> answer;

				list->push_back(answer);

				std::cout << dlistPushBackMessage02
					<< answer
					<< dlistPushBackMessage03;
			}
			break;
		}
		case 4: {
			clearConsole();
			if (!list)
				std::cout << dlistNotCreated;
			else {
				int answer = -1;

				std::cout << dlistPushFrontMessage01;
				std::cout << enterAnswer;

				std::cin >> answer;

				list->push_back(answer);

				std::cout << dlistPushFrontMessage02
					<< answer
					<< dlistPushFrontMessage03;
			}
			break;
		}
		case 5: {
			clearConsole();
			if (!list)
				std::cout << dlistNotCreated;
			else {
				try {
					std::cout << dlistPeekFrontMessage << list->front();
				}
				catch(DoubleLinkedListException& e) {
					std::cout << dlistIsEmpty;
				}
			}
			break;
		}
		case 6:
		{
			clearConsole();
			if (!list)
				std::cout << dlistNotCreated;
			else {
				try {
					std::cout << dlistPeekBackMessage << list->back();
				}
				catch (DoubleLinkedListException & e) {
					std::cout << dlistIsEmpty;
				}
			}
			break;
		}
		case 7:	{
			clearConsole();
			if (!list)
				std::cout << dlistNotCreated;
			else {
				try {
					list->pop_front();
					std::cout << dlistPopFrontMessage;
				}
				catch (DoubleLinkedListException & e) {
					std::cout << dlistIsEmpty;
				}
			}
			break;
		}
		case 8: {
			clearConsole();
			if (!list)
				std::cout << dlistNotCreated;
			else {
				try {
					list->pop_back();
					std::cout << dlistPopBackMessage;
				}
				catch (DoubleLinkedListException & e) {
					std::cout << dlistIsEmpty;
				}
			}
			break;
		}
		case 9: {
			clearConsole();

			std::wcout << dlistReadFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			std::ifstream fin(fileName + ".txt");

			if (!fin.is_open()) {
				std::wcout << dlistReadFileErrMessage;
				break;
			}
			else {
				if (list) {
					delete list;
					list = nullptr;
					list = new DoubleLinkedList<int>();
				}
				list = DoubleLinkedListHelper::readFromFile<int>(fin);
			}

			std::wcout << dlistReadFileSuccessMessage;
			break;
		}
		case 10: {
			clearConsole();
			if (!list) {
				std::wcout << dlistNotCreated;
				break;
			}
			std::wcout << dlistWriteFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			std::ofstream out(fileName + ".txt",
				std::ios_base::trunc);

			if (!out.is_open()) {
				std::wcout << dlistWriteFileErrMessage;
				break;
			}
			else {
				DoubleLinkedListHelper::writeToFile(list, out);
			}
			out.close();

			std::wcout << dlistWriteFileSuccess;
			break;
		}
		case 11: {
			clearConsole();

			std::wcout << dlistRandomizeMessage;
			std::wcout << enterAnswer;

			int listSize = 0;
			std::cin >> listSize;

			if (listSize < 1) {
				std::wcout << dlistRandomizeErrorMessage;
				break;
			}

			std::wcout << dlistRandomizeUpRangeMessge;
			std::wcout << enterAnswer;

			int upValue;
			std::cin >> upValue;

			for (int i = 0; i < listSize; ++i)
				list->push_back(std::rand() % upValue);

			std::wcout << dlistRandomizeSuccess;
			break;
		}
		case 12: {
			clearConsole();
			DoubleLinkedListHelper::print_list(list);
			break;
		}
		case 13: {
			clearConsole();
			list->clear();
			std::cout << dlistClearSucces;
			break;
		}
		case 14: {
			clearConsole();
			if (!list) {
				std::cout << dlistNotCreated;
			}
			else {
				std::cout << dlistDestroyedMessage;
				delete list;
				list = nullptr;
			}
			break;
		}
		case 15: {
			clearConsole();
			delete list;
			isActive = false;
			break;
		}
		default:
			break;
		}
	}
}

void MenuHelper::createBheapMenuInstance()
{
	clearConsole();
	bool isActive = true;
	BinaryHeap<int>* heap = nullptr;
	while (isActive)
	{
		int answer = -1;
		std::wcout << bheapMenuSelectAction
			<< bheapMenuCreate
			<< bheapMenuIsEmpty
			<< bheapMenuAddItem
			<< bheapMenuMax
			<< bheapMenuRemove
			<< bheapMenuReadFromFile
			<< bheapMenuWriteToFile
			<< bheapMenuRandomize
			<< bheapMenuPrint
			<< bheapMenuClear
			<< bheapMenuDestroy
			<< bheapMenuExit;
		std::cout << enterAnswer;
		std::cin >> answer;
		switch (answer) {
		case 1: {
			clearConsole();
			
			if (heap)
				std::cout << bheapCreateFailureMessage;
			else {
				heap = new BinaryHeap<int>();
				std::cout << bheapCreateSuccessMessage;
			}
			break;
		}
		case 2: {
			clearConsole();
			if (!heap)
				std::cout << bheapNotCreatedMessage;
			else {
				if (heap->isEmpty())
					std::cout << bheapIsEmptyMessage;
				else
					std::cout << bheapIsNotEmptyMessage;
			}
			break;
		}
		case 3: {
			clearConsole();
			if (!heap)
				std::cout << bheapNotCreatedMessage;
			else {
				int answer = -1;

				std::cout << bheapAddItemMessage01;
				std::cin >> answer;

				heap->addItem(answer);

				std::cout << bheapAddItemMessage02
					<< answer
					<< bheapAddItemMessage03;
			}
			break;
		}
		case 4: {
			clearConsole();
			if (!heap)
				std::cout << bheapNotCreatedMessage;
			else {
				if (heap->isEmpty())
					std::cout << bheapIsEmptyMessage;
				else {
					std::cout << bheapPeekMaxMessage01
						<< heap->getmax() 
						<< std::endl;
				}
			}
			break;
		}
		case 5: {
			break;
		}
		case 6: {
			clearConsole();

			std::wcout << bheapReadFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			std::ifstream fin(fileName + ".txt");

			if (!fin.is_open()) {
				std::wcout << bheapReadFileErrMessage;
				break;
			}
			if (heap) {
				delete heap;
				heap = nullptr;
				heap = new BinaryHeap<int>();
			}
			heap = BinaryHeapHelper::readFromFile<int>(fin);

			std::wcout << bheapReadFileSuccessMessage;
			break;
		}
		case 7: {
			clearConsole();

			if (!heap) {
				std::wcout << bheapNotCreatedMessage;
				break;
			}
			std::wcout << bheapWriteFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			std::ofstream out(fileName + ".txt",
				std::ios_base::trunc);

			if (!out.is_open()) {
				std::wcout << bheapWriteFileErrMessage;
				break;
			}
			BinaryHeapHelper::writeToFile<int>(heap, out);
			out.close();

			std::wcout << dlistWriteFileSuccess;
			break;
		}
		case 8: {
			clearConsole();

			std::wcout << bheapRandomizeMessage;
			std::wcout << enterAnswer;

			int heapSize = 0;
			std::cin >> heapSize;

			if (heapSize < 1) {
				std::wcout << bheapRandomizeErrorMessage;
				break;
			}

			std::wcout << bheapRandomizeUpRangeMessge;
			std::wcout << enterAnswer;

			int upValue;
			std::cin >> upValue;

			for (int i = 0; i < heapSize; ++i)
				heap->addItem(std::rand() % upValue);

			std::wcout << bheapRandomizeSuccess;
			break;
		}
		case 9: {
			//
			break;
		}
		case 10: {
			clearConsole();

			if (!heap) {
				std::wcout << bheapNotCreatedMessage;
				break;
			}
			
			heap->clear();
			break;
		}
		case 11: {
			clearConsole();
			if (!heap) {
				std::cout << bheapNotCreatedMessage;
			}
			else {
				std::cout << bheapDestroyedMessage;
				delete heap;
				heap = nullptr;
			}
			break;
		}
		case 12: {
			clearConsole();
			isActive = false;
			break;
		}
		default:
			delete heap;
			break;
		}
	}
}

void MenuHelper::createMatrixMenuInstance() {
	clearConsole();
	bool isActive = true;
	SparseMatrix<int>* matrix = nullptr;
	int answer;
	while (isActive) {
		answer = -1;
		std::wcout << sMatrixMenuSelectAction
			<< sMatrixMenuCreate
			<< sMatrixMenuIsEmpty
			<< sMatrixMenuAddItem
			<< sMatrixMenuGetByPos
			<< sMatrixMenuRemoveByPos
			<< sMatrixMenuReadFromFile
			<< sMatrixMenuWriteToFile
			<< sMatrixMenuPrint
			<< sMatrixMenuClear
			<< sMatrixMenuDestroy
			<< sMatrixMenuExit;
		std::cout << enterAnswer;
		std::cin >> answer;
		switch (answer) {
		case 1: {
			clearConsole();

			if (!matrix) {
				matrix = new SparseMatrix<int>();
				matrixCreateSuccessMessage;
			}
			else 
				std::cout << matrixCreateFailureMessage;
			break;
		}
		case 2: {
			if (!matrix) {
				std::wcout << matrixNotCreatedMessage;
				break;
			}
			else {
				if (matrix->isEmpty())
					std::cout << matrixIsEmptyMessage;
				else
					std::cout << matrixIsNotEmptyMessage;
			}
			break;
		}
		case 3: {
			if (!matrix) {
				std::wcout << matrixNotCreatedMessage;
				break;
			}
			else {
				std::wcout << matrixAddItemMessage01;
				
				int answer = -1;
				int i = -1;
				int j = -1;
			
				std::cin >> answer >> i >> j;
				clearConsole();
				try {
					matrix->set(answer, i, j);
				}
				catch (SparseMatrixException & e) {
					break;
				}
				std::cout << matrixAddItemMessage02
					<< answer
					<< matrixAddItemMessage03
					<<i << " " << j << "\n\n";
			}
			break;
		}
		case 4: {
			if (!matrix) {
				clearConsole();
				std::wcout << matrixNotCreatedMessage;
				break;
			}
			else {
				int i = 0;
				int j = 0;
				std::wcout << matrixGetByPos01;
				std::cin >> i >> j;
				clearConsole();
				try {
					std::cout << matrixGetByPos02
						<< i << " " << j
						<< matrixGetByPos03
						<< matrix->get(i, j);
				}
				catch (SparseMatrixException& e) {
					break;
				}
			}
			break;
		}
		case 5: {
			if (!matrix) {
				clearConsole();
				std::wcout << matrixNotCreatedMessage;
				break;
			}
			else {
				int i = 0;
				int j = 0;
				std::wcout << matrixRemoveByPosMessage01;
				std::cin >> i >> j;
				clearConsole();
				try {
					matrix->set(0, i, j);
					std::cout << matrixRemoveByPosMessage02
						<< matrix->get(i, j)
						<< matrixGetByPos03
						<< i << j;
				}
				catch (SparseMatrixException & e) {
					break;
				}
			}
			break;
		}
		case 6: {
			clearConsole();

			std::wcout << matrixReadFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			std::ifstream fin(fileName + ".txt");

			if (!fin.is_open()) {
				std::wcout << matrixReadFileErrMessage;
				break;
			}
			if (matrix) {
				delete matrix;
				matrix = nullptr;
				matrix = new SparseMatrix<int>();
			}
			matrix = SparseMatrixHelper::readFromFile<int>(fin);

			std::wcout << matrixReadFileSuccessMessage;
			break;
		}
		case 7: {
			clearConsole();

			if (!matrix) {
				std::wcout << matrixNotCreatedMessage;
				break;
			}
			std::wcout << matrixWriteFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			std::ofstream out(fileName + ".txt",
				std::ios_base::trunc);

			if (!out.is_open()) {
				std::wcout << matrixWriteFileErrMessage;
				break;
			}
			SparseMatrixHelper::writeToFile<int>(matrix, out);
			out.close();

			std::wcout << matrixWriteFileSuccess;
			break;
		}
		case 8: {
			clearConsole();

			if (!matrix) {
				std::wcout << matrixNotCreatedMessage;
				break;
			}
			else {
				SparseMatrixHelper::print_matrix(matrix);
			}
			break;
		}
		case 9: {
			clearConsole();

			if (!matrix) {
				std::wcout << matrixNotCreatedMessage;
				break;
			}
			matrix->clear();
			std::cout << matrixClearSuccess;
			break;
		}
		case 10: {
			clearConsole();

			if (!matrix) {
				std::wcout << matrixNotCreatedMessage;
				break;
			}
			delete matrix;
			matrix = nullptr;
			std::cout << matrixDestroySuccess;
			break;
		}
		case 11: {
			clearConsole();
			delete matrix;
			isActive = false;
			break;
		}
		default:
			break;
		}
	}
}

void MenuHelper::createAvlTreeMenuInstance() {
	clearConsole();
	bool isActive = true;
	AvlTree<int>* avlTree = nullptr;
	while (isActive) {
		int answer = -1;
		std::wcout << avlMenuSelectAction
			<< avlMenuCreate
			<< avlMenuIsEmpty
			<< avlMenuAddItem
			<< avlMenuFindMin
			<< avlMenuRemove
			<< avlMenuReadFromFile
			<< avlMenuWriteToFile
			<< avlMenuRandomize
			<< avlMenuPrint
			<< avlMenuClear
			<< avlMenuDestroy
			<< avlMenuExit;
		std::cout << enterAnswer;
		std::cin >> answer;
		switch (answer) {
		case 1: {
			if (avlTree) {
				avlTree = new AvlTree<int>();
				std::cout << avlTreeCreateSuccessMessage;
			}
			else
				std::cout << avlTreeCreateFailureMessage;
			break;
		}
		case 2: {
			clearConsole();

			if (!avlTree)
				std::cout << avlTreeNotCreatedMessage;
			else {
				if (avlTree->isEmpty())
					std::cout << avlTreeIsEmptyMessage;
				else
					std::cout << avlTreeIsNotEmptyMessage;
			}
			break;
		}
		case 3: {
			clearConsole();
			if(!avlTree)
				std::cout << avlTreeNotCreatedMessage;
			else {
				int answer = -1;
				
				std::cout << avlTreeAddItemMessage01
					<< enterAnswer;
				
				std::cin >> answer;

				avlTree->insert(answer);

				std::cout << avlTreeAddItemMessage02
					<< answer
					<< avlTreeAddItemMessage03;
			}
			break;
		}
		case 4: {
			clearConsole();
			if(!avlTree)
				std::cout << avlTreeNotCreatedMessage;
			else {
				if (!avlTree->isEmpty()) {
					std::cout << avlTreeFindItemMessage01 <<
						avlTree->getMin()
						<< avlTreeFindItemMessage02;
				}
				else {
					std::cout << avlTreeIsEmptyMessage;
				}
			}
			break;
		}
		case 5: {
			clearConsole();
			if (!avlTree)
				std::cout << avlTreeNotCreatedMessage;
			else {
				if (!avlTree->isEmpty()) {
					int answer = -1;
					std::cout << avlTreeRemoveItemMessage01
						<< enterAnswer;
					std::cin >> answer;
					avlTree->remove(answer);
				}
				else {
					std::cout << avlTreeIsEmptyMessage;
				}
			}
			break;
		}
		case 6: {
			clearConsole();

			std::wcout << avlTreeReadFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			std::ifstream fin(fileName + ".txt");

			if (!fin.is_open()) {
				std::wcout << avlTreeReadFileErrMessage;
				break;
			}
			if (avlTree) {
				delete avlTree;
				avlTree = nullptr;
				avlTree = new AvlTree<int>();
			}
			avlTree = AvlTreeHelper::readFromFile<int>(fin);

			std::wcout << avlTreeReadFileSuccessMessage;
			break;
		}
		case 7: {
			clearConsole();

			if (!avlTree) {
				std::wcout << avlTreeNotCreatedMessage;
				break;
			}
			std::wcout << avlTreeWriteFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			std::ofstream out(fileName + ".txt",
				std::ios_base::trunc);

			if (!out.is_open()) {
				std::wcout << avlTreeWriteFileErrMessage;
				break;
			}
			AvlTreeHelper::writeToFile<int>(avlTree, out);
			out.close();

			std::wcout << avlTreeWriteFileSuccess;
			break;
		}
		case 8: {
			clearConsole();

			if (!avlTree) {
				std::wcout << avlTreeNotCreatedMessage;
				break;
			}
			std::wcout << avlTreeRandomizeMessage;
			std::wcout << enterAnswer;

			int elementCount = 0;
			std::cin >> elementCount;

			if (elementCount < 1) {
				std::wcout << avlTreeRandomizeErrorMessage;
				break;
			}

			std::wcout << avlTreeRandomizeUpRangeMessge;
			std::wcout << enterAnswer;

			int upValue;
			std::cin >> upValue;

			for (int i = 0; i < elementCount; ++i)
				avlTree->insert(std::rand() % upValue);

			std::wcout << avlTreeRandomizeSuccess;
			break;
		}
		case 9: {
			if (!avlTree) {
				clearConsole();
				std::wcout << avlTreeNotCreatedMessage;
				break;
			}
			std::cout << avlTreePrintMessage01
				<< avlTreePrintMessage02
				<< avlTreePrintMessage03
				<< avlTreePrintMessage04;
			int answer = int();
			std::cin >> answer;
			clearConsole();
			switch (answer) {
				case 0: {
					AvlTreeHelper::printInOrder(avlTree);
					break;
				}
				case 1: {
					AvlTreeHelper::printPreOrder(avlTree);
					break;
				}
				case 2: {
					AvlTreeHelper::printPostOrder(avlTree);
					break;
				}
				default: {
					std::cout << "\n Input fail";
					break;
				}
			}
			break;
		}
		case 10: {
			clearConsole();

			if (!avlTree) {
				std::wcout << avlTreeNotCreatedMessage;
				break;
			}
			avlTree->clear();
			std::cout << avlTreeClearMessage;
			break;
		}
		case 11: {
			clearConsole();

			if (!avlTree) {
				std::wcout << avlTreeNotCreatedMessage;
				break;
			}
			delete avlTree;
			avlTree = nullptr;
			std::cout << avlTreeDestroyMessage;
			break;
		}
		case 12: {
			clearConsole();
			delete avlTree;
			isActive = false;
			break;
		}
		default:
			break;
		}
	}
}

void MenuHelper::createBstMenuInstance() {
	clearConsole();
	bool isActive = true;
	BinarySearchTree<int>* bst = nullptr;
	while (isActive) {
		int answer = -1;
		std::wcout << bstMenuSelectAction
			<< bstMenuCreate
			<< bstMenuIsEmpty
			<< bstMenuAddItem
			<< bstMenuFind
			<< bstMenuRemove
			<< bstMenuReadFromFile
			<< bstMenuWriteToFile
			<< bstMenuRandomize
			<< bstMenuPrint
			<< bstMenuClear
			<< bstMenuDestroy
			<< bstMenuExit;
		std::cout << enterAnswer;
		std::cin >> answer;
		switch (answer) {
		case 1: {
			if (bst) {
				bst = new BinarySearchTree<int>();
				std::cout << bstreeCreateSuccessMessage;
			}
			else
				std::cout << bstreeCreateFailureMessage;
			break;
		}
		case 2: {
			clearConsole();

			if (!bst)
				std::cout << bstreeNotCreatedMessage;
			else {
				if (bst->isEmpty())
					std::cout << bstreeIsEmptyMessage;
				else
					std::cout << bstreeIsNotEmptyMessage;
			}
			break;
		}
		case 3: {
			clearConsole();
			if (!bst)
				std::cout << bstreeNotCreatedMessage;
			else {
				int answer = -1;

				std::cout << bstreeAddItemMessage01
					<< enterAnswer;

				std::cin >> answer;

				bst->addLeaf(answer);

				std::cout << bstreeAddItemMessage02
					<< answer
					<< bstreeAddItemMessage03;
			}
			break;
		}
		case 4: {
			clearConsole();
			if (!bst)
				std::cout << bstreeNotCreatedMessage;
			else {
				if (!bst->isEmpty()) {
					std::cout << bstreeFindItemMessage01 
						<< bst->findMin()
						<< bstreeFindItemMessage02;
				}
				else {
					std::cout << bstreeIsEmptyMessage;
				}
			}
			break;
		}
		case 5: {
			clearConsole();
			if (!bst)
				std::cout << bstreeNotCreatedMessage;
			else {
				if (!bst->isEmpty()) {
					int answer = -1;
					std::cout << bstreeRemoveItemMessage01
						<< enterAnswer;
					std::cin >> answer;
					bst->removeByKey(answer);
				}
				else {
					std::cout << bstreeIsEmptyMessage;
				}
			}
			break;
		}
		case 6: {
			clearConsole();

			std::wcout << bstreeReadFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			std::ifstream fin(fileName + ".txt");

			if (!fin.is_open()) {
				std::wcout << bstreeReadFileErrMessage;
				break;
			}
			if (bst) {
				delete bst;
				bst = nullptr;
				bst = new BinarySearchTree<int>();
			}
			bst = BinarySearchTreeHelper::readFromFile<int>(fin);

			std::wcout << bstreeReadFileSuccessMessage;
			break;
		}
		case 7: {
			clearConsole();

			if (!bst) {
				std::wcout << bstreeNotCreatedMessage;
				break;
			}
			std::wcout << bstreeWriteFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			std::ofstream out(fileName + ".txt",
				std::ios_base::trunc);

			if (!out.is_open()) {
				std::wcout << bstreeWriteFileErrMessage;
				break;
			}
			BinarySearchTreeHelper::writeToFile<int>(bst, out);
			out.close();

			std::wcout << bstreeWriteFileSuccess;
			break;
		}
		case 8: {
			clearConsole();

			if (!bst) {
				std::wcout << bstreeNotCreatedMessage;
				break;
			}
			std::wcout << bstreeRandomizeMessage;
			std::wcout << enterAnswer;

			int elementCount = 0;
			std::cin >> elementCount;

			if (elementCount < 1) {
				std::wcout << bstreeRandomizeErrorMessage;
				break;
			}

			std::wcout << bstreeRandomizeUpRangeMessge;
			std::wcout << enterAnswer;

			int upValue;
			std::cin >> upValue;

			for (int i = 0; i < elementCount; ++i)
				bst->addLeaf(std::rand() % upValue);

			std::wcout << bstreeRandomizeSuccess;
			break;
		}
		case 9: {
			if (!bst) {
				clearConsole();
				std::wcout << bstreeNotCreatedMessage;
				break;
			}
			std::cout << bstreePrintMessage01
				<< bstreePrintMessage02
				<< bstreePrintMessage03
				<< bstreePrintMessage04;
			int answer = int();
			std::cin >> answer;
			clearConsole();
			switch (answer) {
			case 0: {
				BinarySearchTreeHelper::printInOrder(bst);
				break;
			}
			case 1: {
				BinarySearchTreeHelper::printPreOrder(bst);
				break;
			}
			case 2: {
				BinarySearchTreeHelper::printPostOrder(bst);
				break;
			}
			default: {
				std::cout << "\n Input fail";
				break;
			}
			}
			break;
		}
		case 10: {
			clearConsole();

			if (!bst) {
				std::wcout << bstreeNotCreatedMessage;
				break;
			}
			bst->clear();
			std::cout << bstreeClearMessage;
			break;
		}
		case 11: {
			clearConsole();

			if (!bst) {
				std::wcout << bstreeNotCreatedMessage;
				break;
			}
			delete bst;
			bst = nullptr;
			std::cout << bstreeDestroyMessage;
			break;
		}
		case 12: {
			clearConsole();
			delete bst;
			isActive = false;
			break;
		}
		default:
			break;
		}
	}
}

void MenuHelper::createRbTreeMenuInstance() {
	clearConsole();
	bool isActive = true;
	RBTree<int>* rbtree  = nullptr;
	while (isActive) {
		int answer = -1;
		std::wcout << rbTreeMenuSelectAction
			<< rbTreeMenuCreate
			<< rbTreeMenuIsEmpty
			<< rbTreeMenuAddItem
			<< rbTreeMenuFind
			<< rbTreeMenuRemove
			<< rbTreeMenuReadFromFile
			<< rbTreeMenuWriteToFile
			<< rbTreeMenuRandomize
			<< rbTreeMenuPrint
			<< rbTreeMenuClear
			<< rbTreeMenuDestroy
			<< rbTreeMenuExit;
		std::cout << enterAnswer;
		std::cin >> answer;
		switch (answer) {
		case 1: {
			if (rbtree) {
				rbtree = new RBTree<int>();
				std::cout << rbtreeCreateSuccessMessage;
			}
			else
				std::cout << rbtreeCreateFailureMessage;
			break;
		}
		case 2: {
			clearConsole();

			if (!rbtree)
				std::cout << rbtreeNotCreatedMessage;
			else {
				if (rbtree->isEmpty())
					std::cout << rbtreeIsEmptyMessage;
				else
					std::cout << rbtreeIsNotEmptyMessage;
			}
			break;
		}
		case 3: {
			clearConsole();
			if (!rbtree)
				std::cout << rbtreeNotCreatedMessage;
			else {
				int answer = -1;

				std::cout << rbtreeAddItemMessage01
					<< enterAnswer;

				std::cin >> answer;

				rbtree->addItem(answer);

				std::cout << rbtreeAddItemMessage02
					<< answer
					<< rbtreeAddItemMessage03;
			}
			break;
		}
		case 4: {
			clearConsole();
			if (!rbtree)
				std::cout << rbtreeNotCreatedMessage;
			else {
				if (!rbtree->isEmpty()) {
					std::cout << rbtreeFindItemMessage01
						<< rbtree->getMin()
						<< rbtreeFindItemMessage02;
				}
				else {
					std::cout << rbtreeIsEmptyMessage;
				}
			}
			break;
		}
		case 5: {
			clearConsole();
			if (!rbtree)
				std::cout << rbtreeNotCreatedMessage;
			else {
				if (!rbtree->isEmpty()) {
					int answer = -1;
					std::cout << rbtreeRemoveItemMessage01
						<< enterAnswer;
					std::cin >> answer;
					rbtree->remove(answer);
				}
				else {
					std::cout << rbtreeIsEmptyMessage;
				}
			}
			break;
		}
		case 6: {
			clearConsole();

			std::wcout << rbtreeReadFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			std::ifstream fin(fileName + ".txt");

			if (!fin.is_open()) {
				std::wcout << rbtreeReadFileErrMessage;
				break;
			}
			if (rbtree) {
				delete rbtree;
				rbtree = nullptr;
				rbtree = new RBTree<int>();
			}
			rbtree = RBTreeHelper::readFromFile<int>(fin);

			std::wcout << rbtreeReadFileSuccessMessage;
			break;
		}
		case 7: {
			clearConsole();

			if (!rbtree) {
				std::wcout << rbtreeNotCreatedMessage;
				break;
			}
			std::wcout << rbtreeWriteFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			std::ofstream out(fileName + ".txt",
				std::ios_base::trunc);

			if (!out.is_open()) {
				std::wcout << rbtreeWriteFileErrMessage;
				break;
			}
			RBTreeHelper::writeToFile<int>(rbtree, out);
			out.close();

			std::wcout << rbtreeWriteFileSuccess;
			break;
		}
		case 8: {
			clearConsole();

			if (!rbtree) {
				std::wcout << rbtreeNotCreatedMessage;
				break;
			}
			std::wcout << rbtreeRandomizeMessage;
			std::wcout << enterAnswer;

			int elementCount = 0;
			std::cin >> elementCount;

			if (elementCount < 1) {
				std::wcout << rbtreeRandomizeErrorMessage;
				break;
			}

			std::wcout << rbtreeRandomizeUpRangeMessge;
			std::wcout << enterAnswer;

			int upValue;
			std::cin >> upValue;

			for (int i = 0; i < elementCount; ++i)
				rbtree->addItem(std::rand() % upValue);

			std::wcout << rbtreeRandomizeSuccess;
			break;
		}
		case 9: {
			if (!rbtree) {
				clearConsole();
				std::wcout << rbtreeNotCreatedMessage;
				break;
			}
			std::cout << rbtreePrintMessage01
				<< rbtreePrintMessage02
				<< rbtreePrintMessage03
				<< rbtreePrintMessage04;
			int answer = int();
			std::cin >> answer;
			clearConsole();
			switch (answer) {
			case 0: {
				RBTreeHelper::printInOrder(rbtree);
				break;
			}
			case 1: {
				RBTreeHelper::printPreOrder(rbtree);
				break;
			}
			case 2: {
				RBTreeHelper::printPostOrder(rbtree);
				break;
			}
			default: {
				std::cout << "\n Input fail";
				break;
			}
			}
			break;
		}
		case 10: {
			clearConsole();

			if (!rbtree) {
				std::wcout << rbtreeNotCreatedMessage;
				break;
			}
			rbtree->clear();
			std::cout << rbtreeClearMessage;
			break;
		}
		case 11: {
			clearConsole();

			if (!rbtree) {
				std::wcout << rbtreeNotCreatedMessage;
				break;
			}
			delete rbtree;
			rbtree = nullptr;
			std::cout << rbtreeDestroyMessage;
			break;
		}
		case 12: {
			clearConsole();
			delete rbtree;
			isActive = false;
			break;
		}
		default:
			break;
		}
	}
}

void MenuHelper::clearConsole() {
#ifdef __linux__ 
	system("clear");
#elif _WIN32
	system("cls");
#else
#endif
}
