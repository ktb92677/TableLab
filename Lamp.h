#ifndef LAMP_
#define LAMP_

#include <iostream>
#include <string>
#include "Dimension.h"
#include "Table.h"

using namespace std;

class Lamp {
	private:
		Dimension dim;
		bool on;
		string color;
	public:
		Lamp(Table *table){
			cout << "What are the dimensions of your lamp?"
			cout << "Length: ";
			cin >> dim.l;
			while  (dim.l < 0){
				cout << "This number is a negative, please try again.";
				cin >> dim.l;
			}
			cout << "Width: ";
			cin >> dim.w;
			while (dim.w < 0){
				cout << "This number is a negative please try again.";
				cin >> dim.w;
			}
			Table->avaiable_surface_area -= dim.l * dim.w;

			cout << "What color is your lamp?";
			cin >> color;
		}


	void on_off(){
		on = !on;
		if (on)
			cout << "Your lamp is on.";
		else
			cout << "Your lamp is off.";
	}
};
#endif
