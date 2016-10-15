#ifndef BOOK_
#define BOOK_

#include <iostream>
#include <string>
#include "Dimension.h"

using namespace std;

class Book {
	private:
		Dimension dim;
		bool open;
		int num_pages;
	public:
		string title;
		Book(int *table) {
			cout << "What are the dimensions of your book?" << endl;

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

			open = false;
			*table += dim.l * dim.w;

			cout << "What are the number of pages in the book? ";
			cin >> num_pages;
                        while (num_pages <= 0) {
                                cout << "Number is negative... please try again" << endl;
                                cin >> num_pages;
                        }
			cin.ignore();
			cout << "What is the title of the book? ";
			getline(cin, title);

		}

		void change_book_state(int *table) {
			open = !open;

			if (open) {
				*table -= dim.l * dim.w;
			} else {
				*table += dim.l * dim.w;
			}
		}
};

#endif
