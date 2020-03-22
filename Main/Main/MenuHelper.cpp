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
			std::wcout << "Выберите тестируемую структуру данных" << std::endl
				<< "[1] Стэк" << std::endl
				<< "[2] Очередь" << std::endl
				<< "[3] Дэк" << std::endl
				<< "[4] Односвязный список" << std::endl
				<< "[5] Двусвязный список" << std::endl
				<< "[6] Двоичная куча" << std::endl
				<< "[7] Разреженная матрица" << std::endl
				<< "[8] АВЛ-дерево" << std::endl
				<< "[9] Бинарное дерево поиска" << std::endl
				<< "[10] Красно-черное дерево " << std::endl
				<< "[11] Выйти" << std::endl << std::endl;
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
				std::cout << "Ошибка ввода.Введите число в диапазоне от 1 до 11" << std::endl << std::endl;
				break;
			}
		}
	}
}

void MenuHelper::createStackMenuInstance()
{
	system("cls");
	bool isActive = true;
	while (isActive)
	{
		int answer = -1;
		std::wcout <<"Выберите действие"<< std::endl
			<< "[1] Создать стек" << std::endl
			<< "[2] Проверить стек на пустоту" << std::endl
			<< "[3] Добавить элемент в стек" << std::endl
			<< "[4] Получить элемент на вершине" << std::endl
			<< "[5] Прочитать стек из файла" << std::endl
			<< "[6] Записать стек в файл" << std::endl
			<< "[7] Очистить стек" << std::endl
			<< "[8] Удалить стек" << std::endl
			<< "[9] Выйти" << std::endl << std::endl;
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
