#ifndef _MAP_TEMPLATE_H_
#define _MAP_TEMPLATE_H_
#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;
class Key_already_exists{};
template<class Yeeet, class Meat> class map_template{
	private:
		vector<pair<Yeeet, Meat>> data;
	public:
		class Key_already_exists k;
		map_template(){};
		Meat* Find(const Yeeet& key){
			for(auto& pair : data){
				if(key == pair.first)
					return &pair.second;
			}
			return NULL;
		}
		void Add(const Yeeet& key,Meat value){
			if(!Find(key)) data.push_back(make_pair(key, value));
			else throw Key_already_exists();
		}
		friend ostream& operator << (ostream& o, const map_template<Yeeet, Meat> &map){
			for(unsigned int i = 0; i < map.data.size(); o << (map.data[i]).first << ", " << (map.data[i]).second << endl, ++i);
			return o;
		}

};
class Employee{
	public:
		string Name;
		string Position;
		unsigned int Age;
		Employee(string name = "", string position = "", int age = 0): Name(name), Position(position), Age(age) {};
		friend ostream& operator << (ostream& o, const Employee& e){
			o << "Name: " << e.Name << ", Position: " << e.Position << ", Age: " << e.Age << endl;
			return o;
		}
};
 class Book{ 
 	public:
 		string Author;
 		string Status;
 		string Category;
		unsigned int ISBN;
 		Book(string Author = "", string Status = "", string Category = "",unsigned int ID = 0): Author(Author), Status(Status), Category(Category), ISBN(ID) {};
 		friend ostream& operator << (ostream& o, const Book& b){
			o << "Name of author: " << b.Author << ", Status: " << b.Status << ", Category: " << b.Category<< ", ISBN: "<< b.ISBN<< endl;
			return o;
		}
};
#endif