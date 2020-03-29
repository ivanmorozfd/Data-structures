#pragma once
const char* menuTitle = "Выберите тестируемую структуру данных\n";
const char* menuStackName = "\n[1] Стэк";
const char* menuQueueName = "\n[2] Очередь";
const char* menuDequeName = "\n[3] Дэк";
const char* menuSListName = "\n[4] Односвязный список";
const char* menuDListName = "\n[5] Двусвязный список";
const char* menuBHeapName = "\n[6] Двоичная куча";
const char* menuMatrixName = "\n[7] Разреженная матрица";
const char* menuAvlTreeName = "\n[8] АВЛ - дерево";
const char* menuBstName = "\n[9] Бинарное дерево поиска";
const char* menuRbTreeName = "\n[10] Красно - черное дерево";
const char* menuExitName = "\n[11] Выйти";
const char* menuInputError = "Ошибка ввода.Введите число в диапазоне от 1 до 11 \n\n";
const char* enterAnswer = "\nВведите ответ: ";


const char* stackMenuSelectAction = "Выберите действие\n";
const char* stackMenuCreateStack = "\n[1] Создать стек";
const char* stackMenuEmptyTest = "\n[2] Проверить стек на пустоту";
const char* stackMenuPushItem = "\n[3] Добавить элемент в стек";
const char* stackMenuPeekTop = "\n[4] Получить элемент на вершине";
const char* stackMenuPopItem = "\n[5] Удалить элемент с вершины стека";
const char* stackMenuReadFromFile = "\n[6] Прочитать стек из файла";
const char* stackMenuWriteToFile = "\n[7] Записать стек в файл";
const char* stackMenuClear = "\n[8] Очистить стек";
const char* stackMenuDestroy =  "\n[9] Разрушить стек";
const char* stackMenuRandomize = "\n[10] Заполнить стек случайными числами ";
const char* stackMenuPrint =  "\n[11] Вывести содержимое стека";
const char* stackMenuExit =  "\n[12] Выйти";

const char* stackCreateSuccess = "[ Система ] Стек успешно создан\n\n";
const char* stackCreateFailure = "[ Система ] Стек уже создан\n\n";
const char* stackNotCreated = "[ Система ] Стек не создан\n\n";
const char* stackIsEmpty = "[ Система ] Стек пуст\n\n";
const char* stackIsNotEmpty = "[ Система ] Стек не пуст\n\n";
const char* stackPushMessage01 = "[ Система ] Введите элемент , который нужно добавить в стек\n\n";
const char* stackPushMessage02 = "[ Cистема ] Элемент ";
const char* stackPushMessage03 = " успешно добавлен в стек\n\n";
const char* stackPeekMessage = "[ Cистема ] Элемент на вершине стека : ";
const char* stackPopMessage = "[ Cистема ] Элемент на вершине стека удален\n\n";
const char* stackReadFileMessage = "[ Система ] Введите название файла , из которого нужно прочитать стек\n\n";
const char* stackReadFileErrMessage = "[ Cистема ] Файл с таким названием не существует\n\n";
const char* stackReadFileSuccessMessage = "[ Система ] Успешное чтение стека из файла\n\n";
const char* stackWriteFileMessage = "[ Система ] Введите название файла , в который нужно записать стек\n\n";
const char* stackWriteFileErrMessage = "[ Cистема ] Ошибка при открытии потока\n\n";
const char* stackWriteFileSuccess = "[ Система ] Успешная запись стека в файл\n\n";
const char* stackClearSucces = "[ Система ] Стек успешно очищен\n\n";
const char* stackDestroyedMessage = "[ Система ] Стек успешно разрушен\n\n";
const char* stackRandomizeMessage = "[ Система ] Введите размер стека\n\n";
const char* stackRandomizeErrorMessage = "[ Система ] Ошибка ввода.Размер стека должен быть ненулевым значением\n\n";
const char* stackRandomizeUpRangeMessge = "[ Система ] Введите верхнее значение диапазона случайных чисел\n\n";
const char* stackRandomizeSuccess = "[ Система ] Стек упешно заполнен случайными числами\n\n";


const char* queueMenuSelectAction = "Выберите действие\n";
const char* queueMenuCreate = "\n[1] Создать очередь";
const char* queueMenuEmptyTest = "\n[2] Проверить очередь на пустоту";
const char* queueMenuPushItem = "\n[3] Добавить элемент очередь";
const char* queueMenuPeek = "\n[4] Получить элемент в начале очереди";
const char* queueMenuPopItem = "\n[5] Удалить элемент очереди";
const char* queueMenuReadFromFile = "\n[6] Прочитать очередь из файла";
const char* queueMenuWriteToFile = "\n[7] Записать очередь в файл";
const char* queueMenuRandomize = "\n[8] Заполнить очередь случайными числами ";
const char* queueMenuPrint = "\n[9] Вывести содержимое очереди";
const char* queueMenuClear = "\n[10] Очистить очередь";
const char* queueMenuDestroy = "\n[11] Удалить оередь";
const char* queueMenuExit = "\n[12] Выйти";


const char* dequeMenuSelectAction = "Выберите действие\n";
const char* dequeMenuCreate = "\n[1] Создать очередь";
const char* dequeMenuIsEmpty = "\n[2] Проверить очередь на пустоту";
const char* dequeMenuPushFront = "\n[3] Добавить элемент в начало очереди";
const char* dequeMenuPushBack = "\n[4] Добавить элемент в конец очереди";
const char* dequeMenuPeekFront = "\n[5] Получить элемент в начале очереди";
const char* dequeMenuPeekBack = "\n[6] Получить элемент в конце очереди";
const char* dequeMenuPopFront = "\n[7] Удалить элемент в начале очереди";
const char* dequeMenuPopBack = "\n[8] Удалить элемент в конце очереди";
const char* dequeMenuReadFromFile = "\n[9] Прочитать очередь из файла";
const char* dequeMenuWriteToFile = "\n[10] Записать очередь в файл";
const char* dequeMenuRandomize =  "\n[11] Заполнить очередь случайными числами ";
const char* dequeMenuPrint =  "\n[12] Вывести содержимое очереди";
const char* dequeMenuClear = "\n[13] Очистить очередь";
const char* dequeMenuDestroy = "\n[14] Удалить очередь";
const char* dequeMenuExit = "\n[15] Выйти" ;


const char* listMenuSelectAction = "Выберите действие\n";
const char* listMenuCreate = "\n[1] Создать список";
const char* listMenuIsEmpty = "\n[2] Проверить список на пустоту";
const char* listMenuPushItem = "\n[3] Добавить элемент в список";
const char* listMenuPeek = "\n[4] Получить элемент из списка";
const char* listMenuPopItem = "\n[5] Удалить элемент из списка";
const char* listMenuReadFromFile = "\n[6] Прочитать список из файла";
const char* listMenuWriteToFile = "\n[7] Записать список в файл";
const char* listMenuRandomize = "\n[8] Заполнить список случайными числами ";
const char* listMenuPrint = "\n[9] Вывести содержимое списка";
const char* listMenuClear = "\n[10] Очистить список";
const char* listMenuDestroy = "\n[11] Удалить список";
const char* listMenuExit = "\n[12] Выйти";


const char* dlistMenuSelectAction = "Выберите действие\n";
const char* dlistMenuCreate = "\n[1] Создать список";
const char* dlistMenuIsEmpty = "\n[2] Проверить список на пустоту";
const char* dlistMenuPushBack = "\n[3] Добавить элемент в конец списка";
const char* dlistMenuPushFront = "\n[4] Добавить элемент в начало списка";
const char* dlistMenuPeekFront = "\n[5] Получить элемент в начале списка";
const char* dlistMenuPeekBack = "\n[6] Получить элемент в конце списка";
const char* dlistMenuPopFront = "\n[7] Удалить элемент в начале списка";
const char* dlistMenuPopBack = "\n[8] Удалить элемент в конце списка";
const char* dlistMenuReadFromFile = "\n[9] Прочитать список из файла";
const char* dlistMenuWriteToFile = "\n[10] Записать список в файл";
const char* dlistMenuRandomize = "\n[11] Заполнить список случайными числами ";
const char* dlistMenuPrint = "\n[12] Вывести содержимое списка";
const char* dlistMenuClear = "\n[13] Очистить список";
const char* dlistMenuDestroy = "\n[14] Удалить список";
const char* dlistMenuExit = "\n[15] Выйти";


const char* bheapMenuSelectAction =  "Выберите действие\n";
const char* bheapMenuCreate = "\n[1] Создать кучу";
const char* bheapMenuIsEmpty = "\n[2] Проверить кучу на пустоту";
const char* bheapMenuAddItem = "\n[3] Добавить элемент в кучу";
const char* bheapMenuMax = "\n[4] Получить элемент максимальный элемент в куче";
const char* bheapMenuRemove = "\n[5] Удалить элемент из кучи";
const char* bheapMenuReadFromFile = "\n[6] Прочитать кучу из файла";
const char* bheapMenuWriteToFile = "\n[7] Записать кучу в файл";
const char* bheapMenuRandomize = "\n[8] Заполнить кучу случайными числами ";
const char* bheapMenuPrint = "\n[9] Вывести содержимое кучи";
const char* bheapMenuClear = "\n[10] Очистить кучу";
const char* bheapMenuDestroy = "\n[11] Удалить кучу";
const char* bheapMenuExit = "\n[12] Выйти";


const char* sMatrixMenuSelectAction = "Выберите действие\n";
const char* sMatrixMenuCreate = "\n[1] Создать разреженную матрицу";
const char* sMatrixMenuIsEmpty = "\n[2] Проверить разреженную матрицу на пустоту";
const char* sMatrixMenuAddItem = "\n[3] Добавить элемент в разреженную матрицу";
const char* sMatrixMenuGetByPos = "\n[4] Получить элемент из разреженной матрицы";
const char* sMatrixMenuRemoveByPos = "\n[5] Удалить элемент из разреженной матрицыу";
const char* sMatrixMenuReadFromFile = "\n[6] Прочитать разреженную матрицу из файла";
const char* sMatrixMenuWriteToFile = "\n[7] Записать разреженную матрицу в файл";
const char* sMatrixMenuRandomize = "\n[8] Заполнить разреженную матрицу случайными числами ";
const char* sMatrixMenuPrint = "\n[9] Вывести содержимое разреженную матрицы";
const char* sMatrixMenuClear = "\n[10] Очистить разреженную матрицу";
const char* sMatrixMenuDestroy = "\n[11] Удалить разреженную матрицу";
const char* sMatrixMenuExit = "\n[12] Выйти"; 


const char* avlMenuSelectAction = "Выберите действие\n";
const char* avlMenuCreate = "\n[1] Создать АВЛ дерево";
const char* avlMenuIsEmpty = "\n[2] Проверить АВЛ дерево на пустоту";
const char* avlMenuAddItem = "\n[3] Добавить элемент в АВЛ дерево";
const char* avlMenuFind = "\n[4] Проверить , существует ли элемент в дереве";
const char* avlMenuRemove = "\n[5] Удалить элемент из АВЛ дерева";
const char* avlMenuReadFromFile = "\n[6] Прочитать АВЛ дерево из файла";
const char* avlMenuWriteToFile = "\n[7] Записать АВЛ дерево в файл";
const char* avlMenuRandomize = "\n[8] Заполнить АВЛ дерево случайными числами ";
const char* avlMenuPrint = "\n[9] Вывести содержимое АВЛ дерева";
const char* avlMenuClear = "\n[10] Очистить разреженную матрицу";
const char* avlMenuDestroy = "\n[11] Удалить разреженную матрицу";
const char* avlMenuExit = "\n[12] Выйти";


const char* bstMenu = "Выберите действие\n";
const char* bstMenu = "\n[1] Создать бинарное дерево поиска";
const char* bstMenu = "\n[2] Проверить бинарное дерево поиска на пустоту";
const char* bstMenu = "\n[3] Добавить элемент в бинарное дерево поиска";
const char* bstMenu = "\n[4] Проверить , существует ли элемент в бинарном дереве поиска";
const char* bstMenu = "\n[5] Удалить элемент из бинарного дерева поиска";
const char* bstMenu = "\n[6] Прочитать бинарное дерево поиска из файла";
const char* bstMenu = "\n[7] Записать бинарное дерево поиска в файл";
const char* bstMenu = "\n[8] Заполнить бинарное дерево поиска случайными числами ";
const char* bstMenu = "\n[9] Вывести содержимое бинарного дерева поиска";
const char* bstMenu = "\n[10] Очистить бинарное дерево поиска";
const char* bstMenu = "\n[11] Удалить бинарное дерево поиска";
const char* bstMenu = "\n[12] Выйти";