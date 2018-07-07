//
// Created by hikarido on 7/4/18.
//
#include <iostream>
#include <string>
#include <type_traits>
#include <memory>


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
 * Если метод в базовом классе виртуальный то он может быть переопределен в потомке и тогда при
 * адресации через базовый указатель, будет вызван метод потомка
 *
 * Если метод в потомке не переопределён то будет вызвана имплементация базового класса
 *
 * Если метод в базовом чисто виртуальный то в потомке обзан быть переопределен этот метод
 *
 * Если в классе есть хотябы один чисто виртуальный метод то он считается абстрактным и его инстанс создать нельзя
 */
class Printer{
public:
	virtual void print(const string & str) const{
		cout << str << endl;
	}

	void other_fn(){

	}
};

/**
 * Использование override позволяет проверить есть ли такой вистуальный метод в базовам классе
 */
class BeautyPrinter: public Printer{
public:
	void print(const string & str) const override {
		cout << "\"" << str << "\"" << endl;
	}
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

void polymorphic_for_printer(const Printer & p){
	p.print("polymorphic here");
}

/**
 * Счетчик ссылок не увеличится
 * * @param p
 */
void polymorphic_shared_ptr_ref(const shared_ptr<Printer> &p){
	cout << p.use_count() << endl;
	p->print("by shared ptr ref");
}

/**
 * Счетчик ссылок уывеличится
 * @param p
 */
void polymorphic_shared_ptr(const shared_ptr<Printer> p){
	cout << p.use_count() << endl;
	p->print("by shared ptr");
}

/**
 * Тесты виртуальных функций, передачи через ссылку и shared_ptr на базовый класс
 */
void test_3(){
	Printer p{};
	p.print("Строка");

	BeautyPrinter bp{};
	bp.print("В ковычках");

	polymorphic_for_printer(p);
	polymorphic_for_printer(bp);

	cout << "shared by value" << endl;
	{
		shared_ptr<Printer> sp = make_shared<Printer>();
		cout << sp.use_count() << endl;
		polymorphic_shared_ptr(sp);

		shared_ptr<Printer> sbp = make_shared<BeautyPrinter>();
		cout << sbp.use_count() << endl;
		polymorphic_shared_ptr(sbp);
		cout << sbp.use_count() << endl;
	}


	cout << "shared by reference" << endl;
	{
		shared_ptr<Printer> sp = make_shared<Printer>();
		cout << sp.use_count() << endl;
		polymorphic_shared_ptr_ref(sp);

		shared_ptr<Printer> sbp = make_shared<BeautyPrinter>();
		cout << sbp.use_count() << endl;
		polymorphic_shared_ptr_ref(sbp);
		cout << sbp.use_count() << endl;
	}
}

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
	test_3();
	return 0;
}
