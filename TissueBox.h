#ifndef TISSUEBOX_
#define TISSUEBOX_

#include <iostream>
#include <string>
#include "Dimension.h"
#include "Table.h"

using namespace std;

class TissueBox (){
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
			cout << "Width: ";
			cin >> dim.w;

			Table -> available_surface_area -= dim.l * dim.w;

		cout << "How many tissues can your tissue box hold?"
		cin >> max_num_tissues;
		if (max_num_tissues < 0)
			cout << "That is a negative number, please try again.";;
		}

	void take_tissue(Table *table){
		cout << "How many tissues does your tissue box currently have?"
		cin >> current_num_tissues;
		if (current_num_tissues < 0)
			cout << "That is a negative number, please try again."

		current_num_tissues--;
		cout << "I have taken a tissue."
		if (current_num_tissues == 0){
			cout << "You ran out of tissues, go buy another box.";
	}
};


#endif
