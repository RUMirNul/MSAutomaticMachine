# [RU] Автомат(распознаватель) с магазинной памятью 
## Теория
АМП в качестве рабочей памяти использует стек, называемый также магазином. 
Данная память поддерживает только ограниченные операции доступа, в то же время достаточные для решения сложных задач, включая и задачи распознавания цепочек.
Автомат с магазинной памятью определяется следующими пятью объектами:
1. Конечным __множеством входных символов__, включающим концевой маркер (|)
2. Конечным __множеством магазинных символов__, включающим маркер дна (#)
3. Конечным __множеством переходов__, включающим начальное состояние
4. __Устройством управления__ (__УУ__), которое каждой комбинации входного символа, магазинного символа ставит в соответствие выход или переход. 
Переход, в отличие от выхода, заключается в выполнении операций над магазином и входом. 
Операции, запрашивающие входной символ после концевого маркера или выталкивания из магазина после маркера дна, а также операция вталкивания маркера дна, исключаются.

Автомат с магазинной памятью называется __распознавателем__, если у него 2 выхода: "Допустить" и "Отвергнуть".

__Пример таблицы переходов__ для обработки равеновесия скобок:
|Магазинные символы| Входные символы:|(|)|
|---|---|---|----|
|A| |?, A| A, ?|
|#| |?, A| A, ?|


## Работа программы
__Для работы автомата требуется:__
1. Список переходов
2. Строка(цепочка символов)

__Возможные результаты работы программы:__
1. "Correct!"
2. "Uncorrected character chain!"
3. [Ошибка](#Обрабатываемые-ошибки)

__В main.cpp реализован простой интерфейс для пользователя__    
Для простоты объяснения опустим опсиание проверок входных данных
1. Запрашивается вариант ввода данных
   * 1.1 Ручной ввод. Требуется ввести переходы и строку(цепочку символов) для анализа
   * 1.2 [Заготовленный ввод](#заготовленная-программа). Заранее заготовлен алгоритм проверки скобок
2. Запрашивается строка(цепочка символов)

## Входные данные
#### Ввод переходов
Параметры каждого перехода вводятся через один пробел.
Все переходы вводятся с раздилителем переноса строки (Enter).    
Данные вводятся в формате: 
"Символ строки(цепочки символов)" "Символ стека" "Удаляемый символ из стека"* "Добавялемый символ в стек"**    

Пояснение:
* \* - можно ставить любой символ так как удаляется верхний символ стека. Если ничего удалять из стека не требуется поставьте "?"
* ** - Если никакой символ добавлять не надо, то поставьте "?"

#### Ввод строки(цепочки символов) для анализа
Вводится цепочка символов без пробелов.

## Руководство пользователя
1. Выберите вариант ввода данных
  * 0 - Ручной ввод
  * 1 - [заготовленный ввод](#заготовленная-программа)
2. Введите требуемые данные
  * Переходы
  * Строку(цепочку символов) для анализа
3. Ожидайте результат работы программы

## Обрабатываемые ошибки
1. Введён выбор ввода данных не представленный в программе ("Incorrect input option!")
2. Не был найден нужный переход ("The desired state was not found!")
3. Неверно введён переход ("Uncorrected input line of state!")
4. Не получилось добавить переход в список переходов ("Failed to add a state to the states array!")
5. Стек пуст ("Stack is empty")

## Примеры работы программы
:white_check_mark:__Пример 1:__ 
***Корректный ввод***    
Select an input option:    
0 - manual entry || 1 - prepared version    
Enter: 1    
The entered chain:    
( A ? A    
( # ? A    
) A # ?    
) # A ?    
Enter analyse text:(())    

Correct! - ***Результат работы***    

:negative_squared_cross_mark:__Пример 2:__    
***Некорректный ввод строки(цепочки символов)***    
Select an input option:    
0 - manual entry || 1 - prepared version    
Enter: 1    
The entered chain:    
( A ? A    
( # ? A    
) A # ?    
) # A ?    
Enter analyse text:(()(    

Uncorrected character chain! - ***Результат работы***    

:negative_squared_cross_mark:__Пример 3:__    
***Некорректный переход***    
Select an input option:    
0 - manual entry || 1 - prepared version    
Enter:0    

Enter the states line by line.    
In the form of "Visible_character_chains Visible_character_stack Delete_character_in_stack Add_character_in_stack"    
If you do not need to remove the symbol from the stack, put '?'    
If you do not need to add a symbol to the stack, put '?'    
Optional end marker: '|'    
To complete, enter '#'    
Enter states line:    
A ( ) A    
( A A B )    ***Тут ошибка ввода перехода***    
\#
Enter analyse text:(()))    

Uncorrected input line of state! - ***Результат работы***        
Failed to add a state to the states array! - ***Результат работы***        
The desired state was not found! - ***Результат работы***        
Uncorrected character chain! - ***Результат работы***            

## Заготовленная программа
Заготовленные переходы обрабатывают равновесие скобок.    
Если видим "(" из строки и "A" символ в стеке, то ничего не удаляем("?") и добавляем в стек "A".    
Если видим "(" из строки и "#" символ в стеке, то ничего не удаляем("?") и добавляем в стек "A".    
Если видим ")" из строки и "A" символ в стеке, то удаляем "A" и ничего не добавялем в стек("?").    
Если видим ")" из строки и "#" символ в стеке, то удаляем "A" и ничего не добавялем в стек("?").*    
\* На самом деле программа сама обработает вариант, что достигнуто дно стека и ничего удалить мы не можем и выведет ошибку.     
Если цепочка символов закончилась и стек пустой(содержит только символ дна), то это корректная цепочка и программа выведет "Correct!".   
__В программе__ это выглядит так:    
( A ? A    
( # ? A    
) A # ?    
) # A ?    

__В виде таблицы__ переходов можно представить так:    
|Магазинные символы| Входные символы:|(|)|
|---|---|---|----|
|A| |?, A| A, ?|
|#| |?, A| A, ?|

## Структура программы
* main.cpp - класс откуда запускается программа и содержится интерфейс для пользователя.
* automatM.cpp - главный класс. Занимается анализом строки(цепочки символов), отвечает за взаимодействие всей программы и работу со стеком.
* stateList.cpp - класс отвечающий за хранение и работу со списком переходов.
* state.cpp - объект для удобного хранения объекта перехода.
* utils.cpp - вспомогательный класс. Содержит метод для получения подстроки из строки
