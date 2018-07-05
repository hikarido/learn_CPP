//
// Created by hikarido on 7/4/18.
//
#include <iostream>
#include <string>

using namespace std;

struct Logger{
	Logger(const string & attrib):
	attribute(attrib)
	{
		cout << "+: " << this->attribute << endl;
	}

	~Logger(){
		cout << "-: " << attribute << endl;
	}

	const string attribute;
};

struct Fruit{
	Fruit(const string & new_name="Fruit", int w=10):
	name(new_name),
	weight(w),
	l(name)
	{}
	int weight;
	const string name;
	const Logger l;
};

struct Apple: Fruit{
	Apple():
	Fruit("Fruit", 15),
	l("Apple")
	{}

	Apple(const string & name):
	Fruit("Fruit", 15),
	l(name)
	{}

	const Logger l;
};

struct Orange: Fruit{
	Orange():
	Fruit("Orange", 20)
	{}
};

class Animal{
public:

	Animal(const string & type = "animal"):
	type(type)
	{}

	void Eat(const Fruit& fruit) const{
		cout << type << " was eated the " << fruit.name << endl;
	}
	const string type;
};

class Cat: public Animal{
public:
	Cat(): Animal("cat")
	{}
};

class Dog: public Animal{
public:
	Dog(): Animal("dog")
	{}
};

void doMeal(const Animal & entity, const Fruit & eat){
	entity.Eat(eat);
}

/**
 * Наследование в действии
 */
void test_1(){
	Animal a{};
	Apple ap{};
	Orange o{};


	doMeal(a, ap);
	doMeal(a, o);

	Dog d{};
	doMeal(d, ap);
	doMeal(d, o);

	Cat c{};
	doMeal(c, ap);
	doMeal(c, o);
}

struct AppleTree{
	AppleTree():
	l("AppleTree"),
	a1("Apple 1"),
	a2("Apple 2")
	{}

	const Logger l;
	Apple a1;
	Apple a2;
};

/**
 * Не смотря на то, что данный класс  содержит такой же как и в AppleTree
 * список инициализации
 * Последовательность вызовов конструктуоров и деструкторов элементов класса будет другоой
 */
struct RevertedAppleTree{
	RevertedAppleTree():
	l("RevertedAppleTree"),
	a1("Apple 1"),
	a2("Apple 2")
	{}

	Apple a2;
	Apple a1;
	const Logger l;
};

/**
 * Из данного теста видно что
 * * Список инициализации не определяет порядка вызова конструкторов агрегируемых классом объектов
 * * Порядок инициалицации определяется  порядком объявления полей в теле класса (Сверху в низ)
 * * ПРи иерархии наследования первым вызывается деструктор самого низкого класса, последним самый абстрактный в иерархии
 * * Вызов деструкторов обратен порядку вызова конструкторов, соответсвенно, жизнь объектов в С++ работает по правилу
 * * LIFO стека
 */
void test_2(){
	{
		Fruit f{};
		//+: Fruit
		//-: Fruit
	}

	{
		Apple ap{};
		//+: Fruit
		//+: Apple
		//-: Apple
		//-: Fruit
	}

	cout << "=======AT==========" << endl;
	{
		AppleTree ap{};
		//=======AT==========
		//+: AppleTree
		//+: Fruit
		//+: Apple 1
		//+: Fruit
		//+: Apple 2
		//-: Apple 2
		//-: Fruit
		//-: Apple 1
		//-: Fruit
		//-: AppleTree
		//=======AT==========
	}
	cout << "=======AT==========" << endl;

	cout << "=======RAT==========" << endl;
	{
		RevertedAppleTree rat{};
		//=======RAT==========
		//+: Fruit
		//+: Apple 2
		//+: Fruit
		//+: Apple 1
		//+: RevertedAppleTree
		//-: RevertedAppleTree
		//-: Apple 1
		//-: Fruit
		//-: Apple 2
		//-: Fruit
		//=======RAT==========

	}
	cout << "=======RAT==========" << endl;


}
int main(){
	test_2();
	return 0;
}
