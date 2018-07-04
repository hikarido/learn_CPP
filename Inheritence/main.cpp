//
// Created by hikarido on 7/4/18.
//
#include <iostream>
#include <string>

using namespace std;

struct Fruit{
	int weight = 10;
	string name = "Fruit";
};

struct Apple: Fruit{
	Apple(){
		weight = 15;
		name = "Apple";
	}
};

struct Orange: Fruit{
	Orange(){
		weight = 20;
		name = "Orange";
	}
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

int main(){
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
	return 0;
}
