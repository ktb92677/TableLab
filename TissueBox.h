#ifndef TISSUEBOX_
#define TISSUEBOX_

#include <iostream>
#include <string>
#include "Dimension.h"

using namespace std;

class TissueBox {
	private:
		int max_num_tissues;
	public:
		Dimension dim;
		int current_num_tissues;
		bool created;
		TissueBox(int *table){
			cout << "What are the dimensions of your tissue box?" << endl;
			cout << "Length: ";
			cin >> dim.l;
			while (dim.l < 0){
				cout << "That is a negative number, please try again." << endl;
				cin >> dim.l;
			}

			cout << "Width: ";
			cin >> dim.w;
			while (dim.w < 0) {
				cout << " That is a negative number, please try again." << endl;
				cin >> dim.w;
			}
			if ((dim.l * dim.w) > *table) {
                                cout << "Tissuebox is too large for the table. Tissuebox was not added." << endl;
                                created = false;
                        } else {
                                created = true;
                                *table -= dim.l * dim.w;

				cout << "How many tissues can your tissue box hold?";
				cin >> max_num_tissues;
				while (max_num_tissues < 0){
					cout << "That is a negative number, please try again." << endl;
					cin >> max_num_tissues;
				}
				current_num_tissues = max_num_tissues;
			}
		}

		void take_tissue() {
			if (current_num_tissues < 0) {
				cout << "You ran out of tissues, go buy another box." << endl;
			} else {
				cout << "I have taken a tissue" << endl;
				current_num_tissues--;
			}
		}
};


#endif
