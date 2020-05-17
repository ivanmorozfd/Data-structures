#include "MenuHelper.h"
#include "Stack.h"
#include "Queue.h"
#include "DoubleLinkedList.h"
#include "BinaryHeap.h"
#include "SparseMatrix.h"
#include "AvlTree.h"
#include "BinarySearchTree.h"
#include "RBTree.h"
#include <fstream>
#include <random>
#include "MenuConsts.h"
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
				<< menuDequeName 
				<< menuSListName  
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
				//
				break;
			case 5:
				this->createDlistMenuInstance();
				break;
			case 6:
				this->createBheapMenuInstance();
				break;
			case 7:
				this->createMatrixMenuInstance();
				break;
			case 8:
				this->createAvlTreeMenuInstance();
				break;
			case 9:
				this->createBstMenuInstance();
				break;
			case 10:
				this->createRbTreeMenuInstance();
				break;
			case 11:
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
		case 5:
		{
			if (!stack)
			{
				clearConsole();
				std::wcout << stackNotCreated;
			}
			else
			{
				try
				{
					clearConsole();

					stack->pop();
					std::wcout << stackPopMessage;
				}
				catch (StackException & e)
				{
					clearConsole();
					std::wcout << stackIsEmpty;
				}
			}
			break;
		}
		case 6:
		{
			std::wcout << stackReadFileMessage;
			std::wcout << enterAnswer;
			std::string fileName;
			std::cin >> fileName;
			std::ifstream fin(fileName + ".txt");
			if (!fin.is_open())
			{
				clearConsole();
				std::wcout << stackReadFileErrMessage;
				break;
			}
			else
			{
				if (stack)
				{
					delete stack;
					stack = nullptr;
					stack = new Stack<int>();
				}
				else
					stack = new Stack<int>();

				while (!fin.eof())
				{
					int a;
					fin >> a;
					stack->push(a);

				}
			}
			clearConsole();

			std::wcout << stackReadFileSuccessMessage;
			break;
		}
		case 7:
		{
			if (!stack)
			{
				std::wcout << stackNotCreated;
				break;
			}
			std::wcout << stackWriteFileMessage;
			std::wcout << enterAnswer;

			std::string fileName;
			std::cin >> fileName;

			int result;
			std::ofstream out(fileName + ".txt", std::ios_base::trunc);
			if (!out.is_open())
			{
				clearConsole();
				std::wcout << stackWriteFileErrMessage;
				break;
			}
			else
			{
				while (!stack->isEmpty())
				{
					result = stack->peek();
					stack->pop();
					out << result;
					out << " ";
				}
			}
			out.close();

			std::wcout << stackWriteFileSuccess;
			break;
		}
		case 8:
		{
			stack->clear();
			std::wcout << stackClearSucces;
			break;
		}
		case 9:
		{
			if (stack)
			{
				delete stack;
				stack = nullptr;
				clearConsole();
				std::wcout << stackDestroyedMessage;
			}
			else
			{
				clearConsole();
				std::wcout << stackNotCreated;
			}
			break;
		}
		case 10:
		{
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
		case 11:
		{
			//todo	
			break;
		}
		case 12:
		{
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
		switch (answer)
		{
			case 1:
			{
				if (!queue) {
					queue = new Queue<int>();
					clearConsole();
					std::cout << queueCreateSuccess;
				}
				else {
					clearConsole();
					std::cout << queueCreateFailure;
				}
				break;
			}
			case 2: {
				if (!queue) {
					clearConsole();
					std::cout << queueNotCreated;
				}
				else {
					if (queue->isEmpty()) {
						clearConsole();
						std::cout << queueIsEmpty;
					}
					else {
						clearConsole();
						std::cout << queueIsNotEmpty;
					}
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
				if (!queue) {
					clearConsole();
					std::cout << queueNotCreated;
				}
				else {
					if (queue->isEmpty()) {
						clearConsole();
						std::cout << queueIsEmpty;
					}
					else {
						clearConsole();
						std::cout << queuePeekMessage
							<< queue->peek();
					}
				}
				break;
			}
			case 5: {
				if (!queue) {
					clearConsole();
					std::cout << queueNotCreated;
				}
				else {
					clearConsole();
					try {
						queue->pop();
					}
					catch (QueueException & e) {

						std::cout << queueIsEmpty;
					}
				}
				break;
			}
			case 6:
			{
				std::wcout << queueReadFileMessage;
				std::wcout << enterAnswer;
				std::string fileName;
				std::cin >> fileName;
				std::ifstream fin(fileName + ".txt");
				if (!fin.is_open())
				{
					clearConsole();
					std::wcout << queueReadFileErrMessage;
					break;
				}
				else
				{
					if (queue)
					{
						delete queue;
						queue = nullptr;
						queue = new Queue<int>();
					}
					else
						queue = new Queue<int>();

					while (!fin.eof())
					{
						int a;
						fin >> a;
						queue->push(a);

					}
				}
				clearConsole();

				std::wcout << queueReadFileSuccessMessage;
				break;
			}
			case 7:
			{
				if (!queue)
				{
					std::wcout << queueNotCreated;
					break;
				}
				std::wcout << queueWriteFileMessage;
				std::wcout << enterAnswer;

				std::string fileName;
				std::cin >> fileName;

				int result;
				std::ofstream out(fileName + ".txt", std::ios_base::trunc);
				if (!out.is_open())
				{
					clearConsole();
					std::wcout << queueWriteFileErrMessage;
					break;
				}
				else
				{
					while (!queue->isEmpty())
					{
						result = queue->peek();
						queue->pop();
						out << result;
						out << " ";
					}
				}
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
				for (int i = 0; i < queueSize; ++i)
				{
					queue->push(std::rand() % upValue);
				}
				clearConsole();
				std::wcout << queueRandomizeSuccess;
				break;
			}
		case 9:
			break;
		case 10: {
			if (!queue) {
				clearConsole();
				std::cout << queueNotCreated;
			}
			else {
				clearConsole();
				queue->clear();
			}
			break;
		}
		case 11: {
			if (queue) {
				clearConsole();
				std::cout << queueDestroyedMessage;
				delete queue;
				queue = nullptr;
			}
			else {
				clearConsole();
				std::cout << queueNotCreated;
			}
			break;
		}
		case 12:
			isActive = false;
			break;
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
				else
					list = new DoubleLinkedList<int>();

				while (!fin.eof()) {
					int a;
					fin >> a;

					list->push_back(a);

				}
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
				int result = 0;
				while (!list->isEmpty()) {
					result = list->front();
					list->pop_back();

					out << result;
					out << " ";
				}
			}
			out.close();

			std::wcout << dlistWriteFileSuccess;
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
			for (DoubleLinkedList<int>::iterator it = list->begin(); it != list->end(); ++it) {
				std::cout << *it;
			}
			break;
		}
		case 13: {
			clearConsole();

			list->clear();

			std::cout << dlistClearSucces;
			break;
		}
		case 14: {
			if (!list) {
				clearConsole();
				std::cout << dlistNotCreated;
			}
			else {
				clearConsole();
				std::cout << dlistDestroyedMessage;
				delete list;
				list = nullptr;
			}
			break;
		}
		case 15: {
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
			else {
				if (heap) {
					delete heap;
					heap = nullptr;
					heap = new BinaryHeap<int>();
				}
				else
					heap = new BinaryHeap<int>();

				while (!fin.eof()) {
					int a;
					fin >> a;

					heap->addItem(a);

				}
			}

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
			else {
				int result = 0;
				while (!heap->isEmpty()) {
					result = heap->getmax();

					out << result;
					out << " ";
				}
			}
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
			isActive = false;
			break;
		}
		default:
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
			<< sMatrixMenuRandomize
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
			
			break;
		}
		case 3: {

			break;
		}
		case 4: {

			break;
		}
		case 5: {

			break;
		}
		case 6: {

			break;
		}
		case 7: {

			break;
		}
		case 8: {

			break;
		}
		case 9: {

			break;
		}
		case 10: {

			break;
		}
		case 11: {

			break;
		}
		case 12: {

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
			break;
		}
		case 5: {
			break;
		}
		case 6: {
			break;
		}
		case 7: {
			break;
		}
		case 8: {
			break;
		}
		case 9: {
			break;
		}
		case 10: {
			break;
		}
		case 11: {
			break;
		}
		case 12: {
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
			break;	
		}
		case 2: {
			break;
		}
		case 3: {
			break;
		}
		case 4: {
			break;
		}
		case 5: {
			break;
		}
		case 6: {
			break;
		}
		case 7: {
			break;
		}
		case 8: {
			break;
		}
		case 9: {
			break;
		}
		case 10: {
			break;
		}
		case 11: {
			break;
		}
		case 12: {
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
			break;
		}
		case 2: {
			break;
		}
		case 3: {
			break;
		}
		case 4: {
			break;
		}
		case 5: {
			break;
		}
		case 6: {
			break;
		}
		case 7: {
			break;
		}
		case 8: {
			break;
		}
		case 9: {
			break;
		}
		case 10: {
			break;
		}
		case 11: {
			break;
		}
		case 12: {
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
