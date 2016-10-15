#ifndef TISSUEBOX_
#define TISSUEBOX_

#include <iostream>
#include <string>
#include "Dimension.h"
#include "Table.h"


class TissueBox (Table *table){
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


	void take_tissue(Table *table){
		cout << "How many tissues can your tissue box hold?"
		cin >> max_num_tissues;
		cout << "How many tissues does your tissue box currently have?"
		cin >> current_num_tissues;

		current_num_tissues--;;
	}
};

#endif
