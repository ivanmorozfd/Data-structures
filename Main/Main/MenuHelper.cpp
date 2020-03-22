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
			<< "[9] ������� ����" << std::endl
			<< "[10] �����" << std::endl << std::endl;
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
			    std::wcout<<"[ ������� ] ������� ������� , ������� ����� �������� � ����" << std::endl << std::endl;
				std::cout << "������� �����: ";
				std::cin >> answer;
				system("cls");
				stack->push(answer);
				std::wcout << "[ C������ ] ������� "<<answer<<" ������� �������� � ����" << std::endl << std::endl;
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
				system("cls");
				std::wcout << "[ C������ ] ������� �� ������� ����� : " << stack->getTop() << std::endl << std::endl;
			}
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
