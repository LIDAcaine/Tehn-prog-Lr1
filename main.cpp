#include <iostream>
#include "queue_1.h"
#include "queue_2.h"
#include "queue_3.h"
using namespace std;

int main() 
{
	int flag = 0;
	setlocale(LC_ALL, "Rus");
	Queue_3 Myqueue; //основная очередь
	Queue_3 copys; //очередь для копии
	Queue_3 Mq; //очередь для слияния
	Queue_3 Free; //итог слияния
	int n = 1;
	while (n != 0)
	{
		cout << "1) Добавить элемент\n2) Удалить элемент\n3) Вывести очередь\n4) Математическая операция\n5) Сделать копию\n6) Слияние очередей\n7) Завершение работы" << endl;
		cout << "Ваш выбор: ";
		cin >> n;
		if (n == 1) {
			system("cls");
			flag = 1;
			//элемент, который добавится в очередь
			int value;
			cout << "Элемент для добавления: ";
			cin >> value;
			Myqueue.insert(value);
			cout <<  endl;
		}
		else if (n == 2) {
			system("cls");
			//удаление элемента
			Myqueue.remove();
			cout << "Новая очередь: ";
			Myqueue.printQueue();
			cout << endl;
		}
		else if (n == 3) {
			system("cls");
			//вывод очереди на консоль
			cout << "Ваша очередь: ";
			Myqueue.printQueue();
			cout<< endl;
		}
		else if (n == 4) {
			system("cls");
			//математическая операция соответствует заданию по номеру варианта
			int count = Myqueue.math_operation();
			if (count == -1)
			{
				cout << "Недостаточное количесто элементов\n" << endl;
			}
			else
			{
				cout << "Число элементов, превышающих значение предыдущего элемента: "<< Myqueue.math_operation()<< "\n" << endl;
			}
		}
		else if (n == 5) {
			system("cls");
			//копия очереди
			Myqueue.COPs();
			cout << "Копия успешно сделана\n" << endl;;

		}
		else if (n == 6) {
			system("cls");
			//слияние двух очередей
			if (flag == 0)
			{
				cout << "Очередь не найдена. Заполните очередь.\n" << endl;
				continue;
			}
			cout << "Создайте вторую очередь" << endl;
			int p = 1;
			while (p != 0)
			{
				int value;
				cout << "Введите элемент: ";
				cin >> value;
				Mq.insert(value);
				cout << "Хотите добавить ещё один  элемент? 1 - да, 0 - нет\n Ваш выбор: " ;
				cin >> p;
			}
			Queue* copyMyqueue = Myqueue.COPs();
			Queue* copyMyqueue_1 = Mq.COPs();
			Queue* copyMyqueue_2 = Free.COPs();
			cout << "Итоговая очередь: ";
			Free.merge(copyMyqueue, copyMyqueue_1, copyMyqueue_2);
			cout << endl;
			//Myqueue.printQueue();
		}
		else if (n == 7) {
			system("cls");
			cout << "Работа завершена\n";
			//close program
			return 0;
		}
	}

	return 0;
}
