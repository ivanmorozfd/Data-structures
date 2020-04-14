#include "MenuHelper.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "SingleLinkedList.h"
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
				this->createDequeMenuInstance();
				break;
			case 4:

				this->createListMenuInstance();
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

void MenuHelper::createStackMenuInstance()
{
	clearConsole();

	bool isActive = true;
	Stack<int>* stack = nullptr;
	while (isActive)
	{
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
		switch (answer)
		{
		case 1:
		{
			if (!stack)
			{
				stack = new Stack<int>();
				clearConsole();
				std::wcout << stackCreateSuccess;
			}
			else
			{
				clearConsole();
				std::wcout << stackCreateFailure;
			}
			break;
		}
		case 2:
		{
			if (!stack)
			{
				clearConsole();
				std::wcout << stackNotCreated;
			}
			else
			{
				if (stack->isEmpty())
				{
					clearConsole();
					std::wcout << stackIsEmpty;
				}
				else
				{
					clearConsole();
					std::wcout << stackIsNotEmpty;
				}
			}
			break;
		}
		case 3:
		{
			if (!stack)
			{
				clearConsole();
				std::wcout << stackNotCreated;
			}
			else
			{
				int answer = -1;

				std::wcout << stackPushMessage01;
				std::wcout << enterAnswer;
				std::cin >> answer;

				clearConsole();
				stack->push(answer);

				std::wcout << stackPushMessage02
					<< answer
					<< stackPushMessage03;
			}
			break;
		}
		case 4:
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

					std::wcout << stackPeekMessage
						<< stack->getTop()
						<< std::endl
						<< std::endl;
				}
				catch (StackException & e)
				{
					clearConsole();
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
					result = stack->getTop();
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
							<< queue->back();
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
						result = queue->front();
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

void MenuHelper::createDequeMenuInstance()
{
	clearConsole();
	bool isActive = true;
	Deque<int>* deque = nullptr;
	while (isActive)
	{
		int answer = -1;
		std::wcout << dequeMenuSelectAction
			<< dequeMenuCreate
			<< dequeMenuIsEmpty
			<< dequeMenuPushBack
			<< dequeMenuPushFront
			<< dequeMenuPeekBack
			<< dequeMenuPeekFront
			<< dequeMenuPopBack
			<< dequeMenuPopFront
			<< dequeMenuReadFromFile
			<< dequeMenuWriteToFile
			<< dequeMenuRandomize
			<< dequeMenuPrint
			<< dequeMenuClear
			<< dequeMenuDestroy
			<< dequeMenuExit;
		std::cout << enterAnswer;
		std::cin >> answer;
		switch (answer)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			break;
		}
		case 12:
		{
			break;
		}
		case 13:
		{
			break;
		}
		case 14:
		{
			break;
		}
		case 15:
		{
			break;
		}
		default:
			break;
		}
	}
}

void MenuHelper::createListMenuInstance()
{
	clearConsole();
	bool isActive = true;
	SingleLinkedList<int>* list = nullptr;
	while (isActive)
	{
		int answer = -1;
		std::wcout << listMenuSelectAction
			<< listMenuSelectAction
			<< listMenuCreate
			<< listMenuIsEmpty
			<< listMenuPushItem
			<< listMenuPeek
			<< listMenuPopItem
			<< listMenuReadFromFile
			<< listMenuWriteToFile
			<< listMenuRandomize
			<< listMenuPrint
			<< listMenuClear
			<< listMenuDestroy
			<< listMenuExit;
		std::cout << enterAnswer;
		std::cin >> answer;
		switch (answer)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
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
	SingleLinkedList<int>* list = nullptr;
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
		switch (answer)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			break;
		}
		case 12:
		{
			break;
		}
		case 13:
		{
			break;
		}
		case 14:
		{
			break;
		}
		case 15:
		{
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
		switch (answer)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			break;
		}
		case 12:
		{
			break;
		}
		default:
			break;
		}
	}
}

void MenuHelper::createMatrixMenuInstance()
{
	clearConsole();
	bool isActive = true;
	SparseMatrix<int>* matrix = nullptr;
	while (isActive)
	{
		int answer = -1;
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
		switch (answer)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			break;
		}
		case 12:
		{
			break;
		}
		default:
			break;
		}
	}
}

void MenuHelper::createAvlTreeMenuInstance()
{
	clearConsole();
	bool isActive = true;
	AvlTree<int>* avlTree = nullptr;
	while (isActive)
	{
		int answer = -1;
		std::wcout << avlMenuSelectAction
			<< avlMenuCreate
			<< avlMenuIsEmpty
			<< avlMenuAddItem
			<< avlMenuFind
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
		switch (answer)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			break;
		}
		case 12:
		{
			break;
		}
		default:
			break;
		}
	}
}

void MenuHelper::createBstMenuInstance()
{
	clearConsole();
	bool isActive = true;
	BinarySearchTree<int>* bst = nullptr;
	while (isActive)
	{
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
		switch (answer)
		{
		case 1:
		{
			break;	
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
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
}

void MenuHelper::createRbTreeMenuInstance()
{
	clearConsole();
	bool isActive = true;
	RBTree<int>* rbtree = nullptr;
	while (isActive)
	{
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
		switch (answer)
		{
		case 1:
		{
			
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			break;
		}
		case 12:
		{
			break;
		}
		default:
			break;
		}
	}
}

void MenuHelper::clearConsole()
{
	system("cls");
}
