#include <iostream>
#include "Table.h"

using namespace std;

int main() {
	Table t;
	int index;

	while (true) {
		cout << "What would you like to do?" << endl;
		cout << "1. Manage books" << endl;
		cout << "2. Manage tissues" << endl;
		cout << "3. Manage lamps" << endl;
		cout << "4. Quit" << endl;
		cin >> index;

		if (index == 1) {
			while (true) {
				cout << "What would you like to do with books?" << endl;
				cout << "1. Add book" << endl;
				cout << "2. Remove book" << endl;
				cout << "3. Open/close book" << endl;
				cin >> index;

				if (index == 1) {
					t.addBook();
					break;
				} else if (index == 2) {
					t.removeBook();
					break;
				} else if (index == 3) {
					t.openBook();
					break;
				} else {
					cout << "Unknown option, try again" << endl;
					continue;
				}
			}
		} else if (index == 2) {
			
		} else if (index == 3) {
			
		} else if (index == 4) {
			cout << "Thanks for playing!" << endl;
			break;
		} else {
			cout << "Unknown option, try again" << endl;
			continue;
		}
	}

	t.addBook();
	t.addBook();
	t.removeBook();
	t.removeBook();
	return 0;
}
