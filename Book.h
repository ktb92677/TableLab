#ifndef BOOK_
#define BOOK_

#include <iostream>
#include <string>
#include "Dimension.h"
#include "Table.h"

using namespace std;

class Book {
	private:
		Dimension dim;
		bool open;
		int num_pages;
		string title;
	public:
		Book(Table *table) {
			cout << "What are the dimensions of your book?" << endl;
			cout << "Length: ";
			cin >> dim.l;
			cout << "Width: ";
			cin >> dim.w;

			open = false;
			table->available_surface_area += dim.l * dim.w;

			cout << "What are the number of pages in the book? ";
			cin >> num_pages;

			cout << "What is the title of the book? ";
			getline(cin, title);

		}

		void change_book_state(Table *table) {
			open = !open;

			if (open) {
				table->available_surface_area += dim.l * dim.w;
			} else {
				table->available_surface_area -= dim.l * dim.w;
			}
		}
};

#endif
