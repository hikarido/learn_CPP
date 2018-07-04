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
	void Eat(const Fruit& fruit){
		cout << type << " was eated the " << fruit.name << endl;
	}
	string type = "animal";
};

class Cat: public Animal{
public:
	Cat(){
		type = "Cat";
	}
};

class Dog: public Animal{
public:
	Dog(){
		type = "Dog";
	}
};

int main(){
	Animal a{};
	Apple ap{};
	Orange o{};
	a.Eat(ap);
	a.Eat(o);


	Dog d{};
	Cat c{};

	d.Eat(o);
	d.Eat(ap);

	c.Eat(o);
	c.Eat(ap);
	return 0;
}
