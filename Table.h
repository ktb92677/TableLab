#ifndef TABLE_
#define TABLE_

#include "Dimension.h"
#include "Color.h"
#include "List.h"
#include "Materials.h"
#include "Book.h"

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
                        while (dim.w <= 0) {
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
			items_on_table.add(new Book(&available_surface_area));
			cout << "Added book" << endl;
		}

		void removeBook() {
			int temp_num;
			cout << "Please select a book using the listed index to remove: " << items_on_table.size << endl;
			for (int i = 0; i < items_on_table.size; i++) {
				if (items_on_table.get(i)->book != NULL) {
					cout << i << ": "<< items_on_table.get(i)->book->title << endl;
				}
			}
			while (true) {
				cin >> temp_num;
				if (temp_num < 0 || temp_num >= items_on_table.size) {
					cout << "Index is out of bounds. Please try again" << endl;
					continue;
				}
                               	if (items_on_table.get(temp_num)->book != NULL) {
					items_on_table.remove(temp_num);
					break;
                               	} else {
					cout << "This object is not a book, please try again" << endl;
					continue;
				}
			}
			cout << "Removed book!" << endl;
		}

		void openBook() {
			int temp_num;
                        cout << "Please select a book using the listed index to open/close: " << items_on_table.size << endl;
                        for (int i = 0; i < items_on_table.size; i++) {
                                if (items_on_table.get(i)->book != NULL) {
                                        cout << i << ": "<< items_on_table.get(i)->book->title << endl;
                                }
                        }
                        while (true) {
                                cin >> temp_num;
                                if (temp_num < 0 || temp_num >= items_on_table.size) {
                                        cout << "Index is out of bounds. Please try again" << endl;
                                        continue;
                                }
                                if (items_on_table.get(temp_num)->book != NULL) {
					items_on_table.get(temp_num)->book->change_book_state(&available_surface_area);
                                        break;
                                } else {
                                        cout << "This object is not a book, please try again" << endl;
                                        continue;
                                }
                        }
		}

		void addTissuebox() {
			
		}

		void removeTissuebox() {
			
		}

		void takeTissue() {
			
		}

		void addLamp() {
			
		}

		void removeLamp() {
			
		}

		void turnoffLamp() {
			
		}
};

#endif
