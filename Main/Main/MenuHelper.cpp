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
void MenuHelper::createMainMenuInstance()
{
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		while (true)
		{
			int answer = -1;
			std::wcout << "�������� ����������� ��������� ������" << std::endl
				<< "[1] ����" << std::endl
				<< "[2] �������" << std::endl
				<< "[3] ���" << std::endl
				<< "[4] ����������� ������" << std::endl
				<< "[5] ���������� ������" << std::endl
				<< "[6] �������� ����" << std::endl
				<< "[7] ����������� �������" << std::endl
				<< "[8] ���-������" << std::endl
				<< "[9] �������� ������ ������" << std::endl
				<< "[10] ������-������ ������ " << std::endl
				<< "[11] �����" << std::endl << std::endl;
			std::cout << "������� �����: ";
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
				system("cls");
				std::cout << "������ �����.������� ����� � ��������� �� 1 �� 11" << std::endl << std::endl;
				break;
			}
		}
	}
}

void MenuHelper::createStackMenuInstance()
{
	system("cls");
	bool isActive = true;
	Stack<int>* stack = nullptr;
	while (isActive)
	{
		int answer = -1;
		std::wcout << "�������� ��������" << std::endl
			<< "[1] ������� ����" << std::endl
			<< "[2] ��������� ���� �� �������" << std::endl
			<< "[3] �������� ������� � ����" << std::endl
			<< "[4] �������� ������� �� �������" << std::endl
			<< "[5] ������� ������� � ������� �����" << std::endl
			<< "[6] ��������� ���� �� �����" << std::endl
			<< "[7] �������� ���� � ����" << std::endl
			<< "[8] �������� ����" << std::endl
			<< "[9] ��������� ����" << std::endl
			<< "[10] ��������� ���� ���������� ������� " << std::endl
			<< "[11] ������� ���������� �����" << std::endl
			<< "[12] �����" << std::endl << std::endl;
		std::cout << "������� �����: ";
		std::cin >> answer;
		switch (answer)
		{
		case 1:
			if (!stack)
			{
				stack = new Stack<int>();
				system("cls");
				std::wcout << "[ ������� ] ���� ������� ������" << std::endl << std::endl;
			}
			else
			{
				system("cls");
				std::wcout << "[ ������� ] ���� ��� ������" << std::endl << std::endl;
			}
			break;
		case 2:
			if (!stack)
			{
				system("cls");
				std::wcout << "[ ������� ] ���� �� ������" << std::endl << std::endl;
			}
			else
			{
				if (stack->isEmpty())
				{
					system("cls");
					std::wcout << "[ ������� ] ���� ����" << std::endl << std::endl;
				}
				else
				{
					system("cls");
					std::wcout << "[ ������� ] ���� �� ����" << std::endl << std::endl;
				}
			}
			break;
		case 3:
			if (!stack)
			{
				system("cls");
				std::wcout << "[ ������� ] ���� �� ������" << std::endl << std::endl;
			}
			else
			{
				int answer = -1;
				std::wcout << "[ ������� ] ������� ������� , ������� ����� �������� � ����" << std::endl << std::endl;
				std::cout << "������� �����: ";
				std::cin >> answer;
				system("cls");
				stack->push(answer);
				std::wcout << "[ C������ ] ������� " << answer << " ������� �������� � ����" << std::endl << std::endl;
			}
			break;
		case 4:
			if (!stack)
			{
				system("cls");
				std::wcout << "[ ������� ] ���� �� ������" << std::endl << std::endl;
			}
			else
			{
				try
				{
					system("cls");
					std::wcout << "[ C������ ] ������� �� ������� ����� : " << stack->getTop() << std::endl << std::endl;
				}
				catch (StackException & e)
				{
					system("cls");
					std::wcout << "[ C������ ] C��� ���� " << std::endl << std::endl;
				}
			}
			break;
		case 5:
			if (!stack)
			{
				system("cls");
				std::wcout << "[ ������� ] ���� �� ������" << std::endl << std::endl;
			}
			else
			{
				try
				{
					system("cls");
					stack->pop();
					std::wcout << "[ C������ ] ������� �� ������� ����� ������ " << std::endl << std::endl;
				}
				catch (StackException & e)
				{
					system("cls");
					std::wcout << "[ C������ ] C��� ���� " << std::endl << std::endl;
				}
			}
			break;
		case 6:
		{
			std::wcout << "[ ������� ] ������� �������� ����� , �� �������� ����� ��������� ����" << std::endl << std::endl;
			std::wcout << "������� �����: ";
			std::string fileName;
			std::cin >> fileName;
			std::ifstream fin(fileName + ".txt");
			if (!fin.is_open())
			{
				system("cls");
				std::wcout << "[ C������ ] ���� � ����� ��������� �� ����������" << std::endl << std::endl;
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
			system("cls");

			break;
		}
		case 7:
		{
			if (!stack)
			{
				std::wcout << "[ ������� ] C��� �� ������ " << std::endl << std::endl;
				break;
			}
			std::wcout << "[ ������� ] ������� �������� ����� , � ������� ����� �������� ���� " << std::endl << std::endl;
			std::wcout << "������� �����: ";
			std::string fileName;
			std::cin >> fileName;
			int result;
			std::ofstream out(fileName + ".txt", std::ios_base::trunc);
			if (!out.is_open())
			{
				system("cls");
				std::wcout << "[ C������ ] ������ ��� �������� ������" << std::endl << std::endl;
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
			break;
		}
		case 8:
			stack->clear();
			break;
		case 9:
			if (stack)
			{
				delete stack;
				stack = nullptr;
				system("cls");
				std::wcout << "[ C������ ] C��� �������� " << std::endl << std::endl;
			}
			else
			{
				system("cls");
				std::wcout << "[ C������ ] ���� �� ������ " << std::endl << std::endl;
			}
			break;
		case 10:
		{
			std::wcout << "[ ������� ] ������� ������ ����� " << std::endl << std::endl;
			std::wcout << "������� �����: ";
			int stackSize = 0;
			std::cin >> stackSize;
			if (stackSize < 1) 
			{ 
				system("cls");
				std::wcout << "[ ������� ] ������ �����.������ ����� ������ ���� ��������� ���������" << std::endl << std::endl;
				break;
			}
			std::wcout << "[ ������� ] ������� ������� �������� ��������� ��������� �����" << std::endl << std::endl;
			std::wcout << "������� �����: ";
			int upValue;
			std::cin >> upValue;
			for (int i = 0; i < stackSize; ++i)
			{
				stack->push(std::rand() % upValue);
			}
			system("cls");
			std::wcout<< "[ ������� ] ���� ������ �������� ���������� �������" << std::endl << std::endl;
			break;
		}
		case 11:
		{
			//todo	
			break;
		}
		case 12:
			isActive = false;
			break;
		default:
			break;
		}
	}
	system("cls");
}

void MenuHelper::createQueueMenuInstance()
{
}

void MenuHelper::createDequeMenuInstance()
{
}

void MenuHelper::createListMenuInstance()
{
}

void MenuHelper::createDlistMenuInstance()
{
}

void MenuHelper::createBheapMenuInstance()
{
}

void MenuHelper::createMatrixMenuInstance()
{
}

void MenuHelper::createAvlTreeMenuInstance()
{
}

void MenuHelper::createBstMenuInstance()
{
}

void MenuHelper::createRbTreeMenuInstance()
{
}
