#ifndef LAMP_
#define LAMP_

#include <iostream>
#include <string>
#include "Dimension.h"
#include "Color.h"

using namespace std;

class Lamp {
	private:
		bool on;
	public:
		Dimension dim;
		Color color;
		bool created;
		Lamp(int *table) {
			int temp;

			cout << "What are the dimensions of your lamp?" << endl;
			cout << "Length: ";
			cin >> dim.l;
			while  (dim.l < 0){
				cout << "This number is a negative, please try again." << endl;
				cin >> dim.l;
			}
			cout << "Width: ";
			cin >> dim.w;
			while (dim.w < 0){
				cout << "This number is a negative please try again." << endl;
				cin >> dim.w;
			}
			if ((dim.l * dim.w) > *table) {
                                cout << "Lamp is too large for the table. Lamp was not added." << endl;
                                created = false;
			} else {
				created = true;
				*table -= dim.l * dim.w;

				cout << "Please select a color for your lamp: " << endl;
                        	for (int i = 0; i < NUM_COLORS; i++) {
                                	cout << i << ": " << colors[i] << endl;
                        	}
                        	cin >> temp;
                        	while (temp < 0 || temp >= NUM_COLORS) {
                                	cout << "Out of bounds... please try again" << endl;
                                	cin >> temp;
                        	}
                        	color = colors[temp];

				on = false;
			}
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
