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
			std::cout << "Введите ответ: ";
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
	Stack<int>* stack = nullptr;
	while (isActive)
	{
		int answer = -1;
		std::wcout << "Выберите действие" << std::endl
			<< "[1] Создать стек" << std::endl
			<< "[2] Проверить стек на пустоту" << std::endl
			<< "[3] Добавить элемент в стек" << std::endl
			<< "[4] Получить элемент на вершине" << std::endl
			<< "[5] Удалить элемент с вершины стека" << std::endl
			<< "[6] Прочитать стек из файла" << std::endl
			<< "[7] Записать стек в файл" << std::endl
			<< "[8] Очистить стек" << std::endl
			<< "[9] Разрушить стек" << std::endl
			<< "[10] Заполнить стек случайными числами " << std::endl
			<< "[11] Вывести содержимое стека" << std::endl
			<< "[12] Выйти" << std::endl << std::endl;
		std::cout << "Введите ответ: ";
		std::cin >> answer;
		switch (answer)
		{
		case 1:
			if (!stack)
			{
				stack = new Stack<int>();
				system("cls");
				std::wcout << "[ Система ] Стек успешно создан" << std::endl << std::endl;
			}
			else
			{
				system("cls");
				std::wcout << "[ Система ] Стек уже создан" << std::endl << std::endl;
			}
			break;
		case 2:
			if (!stack)
			{
				system("cls");
				std::wcout << "[ Система ] Стек не создан" << std::endl << std::endl;
			}
			else
			{
				if (stack->isEmpty())
				{
					system("cls");
					std::wcout << "[ Система ] Стек пуст" << std::endl << std::endl;
				}
				else
				{
					system("cls");
					std::wcout << "[ Система ] Стек не пуст" << std::endl << std::endl;
				}
			}
			break;
		case 3:
			if (!stack)
			{
				system("cls");
				std::wcout << "[ Система ] Стек не создан" << std::endl << std::endl;
			}
			else
			{
				int answer = -1;
				std::wcout << "[ Система ] Введите элемент , который нужно добавить в стек" << std::endl << std::endl;
				std::cout << "Введите ответ: ";
				std::cin >> answer;
				system("cls");
				stack->push(answer);
				std::wcout << "[ Cистема ] Элемент " << answer << " успешно добавлен в стек" << std::endl << std::endl;
			}
			break;
		case 4:
			if (!stack)
			{
				system("cls");
				std::wcout << "[ Система ] Стек не создан" << std::endl << std::endl;
			}
			else
			{
				try
				{
					system("cls");
					std::wcout << "[ Cистема ] Элемент на вершине стека : " << stack->getTop() << std::endl << std::endl;
				}
				catch (StackException & e)
				{
					system("cls");
					std::wcout << "[ Cистема ] Cтек пуст " << std::endl << std::endl;
				}
			}
			break;
		case 5:
			if (!stack)
			{
				system("cls");
				std::wcout << "[ Система ] Стек не создан" << std::endl << std::endl;
			}
			else
			{
				try
				{
					system("cls");
					stack->pop();
					std::wcout << "[ Cистема ] Элемент на вершине стека удален " << std::endl << std::endl;
				}
				catch (StackException & e)
				{
					system("cls");
					std::wcout << "[ Cистема ] Cтек пуст " << std::endl << std::endl;
				}
			}
			break;
		case 6:
		{
			std::wcout << "[ Система ] Введите название файла , из которого нужно прочитать стек" << std::endl << std::endl;
			std::wcout << "Введите ответ: ";
			std::string fileName;
			std::cin >> fileName;
			std::ifstream fin(fileName + ".txt");
			if (!fin.is_open())
			{
				system("cls");
				std::wcout << "[ Cистема ] Файл с таким названием не существует" << std::endl << std::endl;
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
				std::wcout << "[ Система ] Cтек не создан " << std::endl << std::endl;
				break;
			}
			std::wcout << "[ Система ] Введите название файла , в который нужно записать стек " << std::endl << std::endl;
			std::wcout << "Введите ответ: ";
			std::string fileName;
			std::cin >> fileName;
			int result;
			std::ofstream out(fileName + ".txt", std::ios_base::trunc);
			if (!out.is_open())
			{
				system("cls");
				std::wcout << "[ Cистема ] Ошибка при открытии потока" << std::endl << std::endl;
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
				std::wcout << "[ Cистема ] Cтек разрушен " << std::endl << std::endl;
			}
			else
			{
				system("cls");
				std::wcout << "[ Cистема ] Стек не создан " << std::endl << std::endl;
			}
			break;
		case 10:
		{
			std::wcout << "[ Система ] Введите размер стека " << std::endl << std::endl;
			std::wcout << "Введите ответ: ";
			int stackSize = 0;
			std::cin >> stackSize;
			if (stackSize < 1) 
			{ 
				system("cls");
				std::wcout << "[ Система ] Ошибка ввода.Размер стека должен быть ненулевым значением" << std::endl << std::endl;
				break;
			}
			std::wcout << "[ Система ] Введите верхнее значение диапазона случайных чисел" << std::endl << std::endl;
			std::wcout << "Введите ответ: ";
			int upValue;
			std::cin >> upValue;
			for (int i = 0; i < stackSize; ++i)
			{
				stack->push(std::rand() % upValue);
			}
			system("cls");
			std::wcout<< "[ Система ] Стек упешно заполнен случайными числами" << std::endl << std::endl;
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
