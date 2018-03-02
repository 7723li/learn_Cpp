#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class animal
{
	public:
		animal(int age);
		animal(const animal& a){this -> age = a.age;}
		animal(): age(-1){printf("creating an animal\n");}
		~animal(){printf("deleting an animal\n");}
		void setname();
		void eat();
		void printName(){cout << this -> age << ':' << this -> name << endl;}

	private:
		int age;
		string name;
	protected:
		double speed;
};

void animal::setname(){
	string name;
	cin >> name;
	this -> name = name;
}

void animal::eat(){
	cout << "eating" << endl;
}

class Dog : public animal
{
	public:
		Dog(){printf("creating a dog\n");}
		~Dog(){printf("deleting a dog\n");};
		void setspeed(double speed){ this -> speed = speed; }
	private:
		double speed;
};

int main(int argc, char const *argv[])
{
	Dog test;
	printf("dog test at %p\n", &test);
	int i;
	vector<Dog> dog(10);
	for(i=0; i<10; i++){
		dog[i].setname();
		dog[i].printName();
		dog[i].setspeed(i * 10);
		printf("dog[%d] at %p\n", i + 1, &dog[i]);
	}
	return 0;
}

// a b c d e f g h i j
