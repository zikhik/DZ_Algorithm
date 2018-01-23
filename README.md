# DZ_Algorithm_Binary_VS_Binomial_Heaps_MegaFight
***
### Формат входных данных и выходных данных.
***
На стандартном потоке ввода задаётся последовательность команд. Пустые строки игнорируются.
Команды: Insert, GetMin, Print,  ExtractMin.
Каждая строка содержит ровно одну команду command [key]  где command — заданные операции для данной структуры.
key — ключ, целое число;

Имена входных и выходных файлов задаются через аргументы командной строки. В моей реализации в качестве аргументов командной строки подаются строки, содержащие имя входного, выходного файлов, а также режим работы.
Шаблоны аргументов ком. строки:
	"in.txt", "out.txt", "file_test» - обработка команд из файла in.txt с последующей информационной записью в out.txt.
	"in.txt", "out.txt", "correct_test» - запуск тестов корректности с информационной записью об успешном тестировании в файлы 001.txt и 002.txt (согласно шаблону задания)
	"in.txt", "out.txt", «speed_test" - запуск тестов скорости с информационной записью о скорости сценариев(см. ниже) в файл out.txt
### Логика программы
Программа состоит из 5 файлов: 
•	BinHeap.h - реализация Binary Heap;
•	 funcbinom.h- реализация Binomial Heap;
•	speed_test.h - код тестов сценария (на скорость)
•	correct_test.h - тесты корректности.
•	work_with_file.h- набор функций для считывания команд из файла.
•	main.cpp - файл содержащий функцию main().
С него начинается работа с программой. Необходимо задать нужные аргументы командной строки.
Первый и второй аргумент - произвольные, третий - строго из предложенных выше команд.

Описание тестов-сценариев.
	Для описания тестов смоделируем ситуацию(сценарий их использования).  Так как исследуемые структуры данных используются для моделирования очередей с приоритетом, то наша задача будет звучать следующим образом «Я - студент. Через несколько дней у меня начинаются каникулы. Я решил составить список дел на каникулярное время, с назначением приоритета каждой запланированной задаче. »

## Тесты
### Тест №1
**Описание:** 
Итак, представим, что до начала каникул осталось 14 дней, и каждую минуту в течении этих двух недель буду записывать по 1-му запланированному делу. То есть за 14 дней я запишу 14*24*60 = 20160 дел.
**Конкретная реализация:** вставка 20160 элементов в кучу с диапазоном значений приоритетности 500000000.

### Тест №2:
**Описание:** Я понял, что носить всегда с собой тяжелую записную книжку неудобно. Поэтому я решил записывать каждый день новые задачи на новом листе а потом в начале каникул объеденю все свои «маленькие списки» в один «большой» 14 - «маленьких списков» по 1440 задач в каждой .
**Конкретная реализация:** вставка по 1440 элементов в 14 куч с диапазоном значений - 500000000, с последующим слиянием всех куч в одну.

### Тест №3:
**Описание:** Я прикинул в голове, что дел много, а со своим графиком, я не успею записать их все, поэтому решил ускориться и записывать дела каждую секунду - 1209600 дел за две недели.
 **Конкретная реализация:** вставка 1209600 элементов в кучу с диапазоном значений  приоритетности - 500000000.

### Тест №4:
**Oписание:**  В конечном итоге у меня получился список дел на каникул с заданными приоритетами. Я начинаю исходя из приоритетности(дела с меньшим значение приоритета - выполняю раньше) решать запланированные задачи. Вычеркивая из списка, каждое выполненное дело.
Времени на каникулах оказалось не так много, поэтому я успел сделать только 11111 дел из списка.
**Конкретная реализация:** Последовательное извлечение 11111 минимумов из кучи.


***
# Результаты сценарных тестов:

## *********** Start first test ********
## ************* Result: ****************
## ***** BinHeap - 0.000709 second *************
## ************* Result: ****************
## ***** BinomHeap - 0.002661 second *************


## *********** Start second test ********
## ************* Result: ****************
## ***** BinHeap - 1.48779 second *************
## ***** BinomHeap - 0.001702 second *************
## *********** END second test ********


## *********** Start third test ********
## ************* Result: ****************
## ***** BinHeap - 0.103274 second *************
## ***** BinomHeap - 0.204596 second *************
## *********** END third test ********


## *********** Start fourth test ********
## ************* Result: ****************
## ***** BinHeap - 0.008365 second *************
## ***** BinomHeap - 0.060755 second *************
## *********** END fourth test ********


## Вывод: 
### В результате был сделан вывод, что использование структуры данных «Биномиальная куча» дает значительный прирост скорости в тех задачах, когда нам необходимо сливать множество куч в одну.



