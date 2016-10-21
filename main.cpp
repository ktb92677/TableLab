#include <iostream>
#include "Table.h"

using namespace std;

int main() {
	Table t;
	int index;

	while (true) {
		cout << "What would you like to do?" << endl;
		cout << "Current available surface area on table: " << t.available_surface_area<< endl;
		cout << "1. Manage books" << endl;
		cout << "2. Manage tissue boxes" << endl;
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
			while (true) {
				cout << "What would you like to do with tissue boxes?" << endl;
                                cout << "1. Add tissue box" << endl;
                                cout << "2. Remove tissue box" << endl;
                                cout << "3. Take a tissue" << endl;
                                cin >> index;

                                if (index == 1) {
                                        t.addTissuebox();
                                        break;
                                } else if (index == 2) {
                                        t.removeTissuebox();
                                        break;
                                } else if (index == 3) {
                                        t.takeTissue();
                                        break;
                                } else {
                                        cout << "Unknown option, try again" << endl;
                                        continue;
                                }
			}
		} else if (index == 3) {
			while (true) {
                                cout << "What would you like to do with lamps?" << endl;
                                cout << "1. Add lamp" << endl;
                                cout << "2. Remove lamp" << endl;
                                cout << "3. Turn on/off a lamp" << endl;
                                cin >> index;

                                if (index == 1) {
                                        t.addLamp();
                                        break;
                                } else if (index == 2) {
                                        t.removeLamp();
                                        break;
                                } else if (index == 3) {
                                        t.changeLampState();
                                        break;
                                } else {
                                        cout << "Unknown option, try again" << endl;
                                        continue;
                                }
                        }
		} else if (index == 4) {
			cout << "Thanks for playing!" << endl;
			break;
		} else {
			cout << "Unknown option, try again" << endl;
			continue;
		}
	}
	return 0;
}
