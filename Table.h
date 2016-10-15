#ifndef TABLE_
#define TABLE_

#include "Dimension.h"
#include "Color.h"
#include "List.h"
#include "Materials.h"

class Table {
	private:
		Dimension dim;
		List items_on_table;
		Color color;
		int num_legs;
		Material material;
	public:
		int available_surface_area;
		Table() {
			int temp;

			cout << "What are the dimensions of your table?" << endl;
			cout << "Length: ";
                        cin >> dim.l;
                        while (dim.l <= 0) {
                                cout << "Number is negative... please try again" << endl;
                                cin >> dim.l;
                        }

                        cout << "Width: ";
                        cin >> dim.w;
                        while (dim.l <= 0) {
                                cout << "Number is negative... please try again" << endl;
                                cin >> dim.w;
                        }
			available_surface_area = dim.w * dim.l;

			cout << "Please select a color for your table: " << endl;
			for (int i = 0; i < NUM_COLORS; i++) {
				cout << i << ": " << colors[i] << endl;
			}
			cin >> temp;
			while (temp < 0 || temp >= NUM_COLORS) {
				cout << "Out of bounds... please try again" << endl;
				cin >> temp;
			}
			color = colors[temp];

			cout << "Please select a material for your table: " << endl;
                        for (int i = 0; i < NUM_MATERIALS; i++) {
                                cout << i << ": " << materials[i] << endl;
                        }
                        cin >> temp;
                        while (temp < 0 || temp >= NUM_MATERIALS) {
                                cout << "Out of bounds... please try again" << endl;
                                cin >> temp;
                        }
                        material = materials[temp];

			cout << "How many legs does your table have? " << endl;
                        cin >> num_legs;
                        while (num_legs <= 0) {
                                cout << "Number cannot be negative... please try again" << endl;
                                cin >> num_legs;
                        }
		}

		void addBook() {
			
		}

		void removeBook() {
			
		}

		void addTissuebox() {
			
		}

		void addLamp() {
			
		}

		void removeLamp() {
			
		}
};

#endif
