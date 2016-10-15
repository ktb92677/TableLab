#ifndef TISSUEBOX_
#define TISSUEBOX_

#include <iostream>
#include <string>
#include "Dimension.h"
#include "Table.h"

using namespace std;

class TissueBox {
	private:
		Dimension dim;
		int current_num_tissues;
		int max_num_tissues;
	public:
		string tissue;
		TissueBox(Table *table){
			cout << "What are the dimensions of your tissue box?"<< endl;
			cout << "Length: ";
			cin >> dim.l;
			while (dim.l < 0){
				cout << "That is a negative number, please try again."
				cin >> dim.l;
			}

			cout << "Width: ";
			cin >> dim.w;
			while (dim.w < 0){
				cout << " That is a negative number, please try again.";
				cin >> dim.w;
			}

			Table -> available_surface_area -= dim.l * dim.w;

		cout << "How many tissues can your tissue box hold?"
		cin >> max_num_tissues;
		while (max_num_tissues < 0){
			cout << "That is a negative number, please try again.";;
			cin >> max_num_tissues;
			}
		}

	void take_tissue(Table *table){
		current_num_tissues = max_num_tissues;
		cout << "I have taken a tissue."
		if (current_num_tissues < 0){
			cout << "You ran out of tissues, go buy another box.";
		}else{
			current_num_tissues--;
		}
	}
};


#endif
