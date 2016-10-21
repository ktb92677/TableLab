#ifndef TABLE_
#define TABLE_

#include "Dimension.h"
#include "Color.h"
#include "List.h"
#include "Materials.h"
#include "Book.h"
#include "TissueBox.h"
#include "Lamp.h"

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
			Book* temp = new Book(&available_surface_area);
			if (temp->created) {
				items_on_table.add(temp);
				cout << "Added book" << endl;
			}
		}

		void removeBook() {
			int temp_num;
			bool test = false;
			cout << "Please select a book using the listed index to remove: " << endl;
			for (int i = 0; i < items_on_table.size; i++) {
				if (items_on_table.get(i)->book != NULL) {
					cout << i << ": "<< items_on_table.get(i)->book->title << endl;
					test = true;
				}
			}
			if (!test) {
				cout << "Oops! Looks like there aren't any books on the table" << endl;
			} else {
				while (true) {
					cin >> temp_num;
					if (temp_num < 0 || temp_num >= items_on_table.size) {
						cout << "Index is out of bounds. Please try again" << endl;
						continue;
					}
                               		if (items_on_table.get(temp_num)->book != NULL) {
						items_on_table.remove(temp_num);
						Book* book = static_cast<Book*>(items_on_table.get(temp_num)->book);
						if (book->open) {
							available_surface_area += book->dim.l * book->dim.w * 2;
						} else {
							available_surface_area += book->dim.l * book->dim.w;
						}
						break;
                               		} else {
						cout << "This object is not a book, please try again" << endl;
						continue;
					}
				}
				cout << "Removed book!" << endl;
			}
		}

		void openBook() {
			int temp_num;
			bool test = false;
                        cout << "Please select a book using the listed index to open/close: " << endl;
                        for (int i = 0; i < items_on_table.size; i++) {
                                if (items_on_table.get(i)->book != NULL) {
                                        cout << i << ": "<< items_on_table.get(i)->book->title << endl;
					test = true;
                                }
                        }
			if (!test) {
                                cout << "Oops! Looks like there aren't any books on the table" << endl;
                        } else {
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
		}

		void addTissuebox() {
			TissueBox* temp = new TissueBox(&available_surface_area);
                        if (temp->created) {
                                items_on_table.add(temp);
                                cout << "Added tissuebox" << endl;
                        }
		}

		void removeTissuebox() {
			int temp_num;
			bool test = false;
                        cout << "Please select a tissue box using the listed index to remove: " << endl;
                        for (int i = 0; i < items_on_table.size; i++) {
                                if (items_on_table.get(i)->tissue != NULL) {
                                        cout << i << ": current number of tissues - " << items_on_table.get(i)->tissue->current_num_tissues << endl;
					test = true;
                                }
                        }
			if (!test) {
                                cout << "Oops! Looks like there aren't any tissueboxes on the table" << endl;
                        } else {
                        	while (true) {
                                	cin >> temp_num;
                                	if (temp_num < 0 || temp_num >= items_on_table.size) {
                                        	cout << "Index is out of bounds. Please try again" << endl;
                                        	continue;
                                	}
                                	if (items_on_table.get(temp_num)->tissue != NULL) {
                                        	items_on_table.remove(temp_num);
						TissueBox* tissue = static_cast<TissueBox*>(items_on_table.get(temp_num)->tissue);
                                        	available_surface_area += tissue->dim.l * tissue->dim.w;
                                        	break;
                                	} else {
                                        	cout << "This object is not a tissue box, please try again" << endl;
                                        	continue;
                                	}
                        	}
                        	cout << "Removed tissue box!" << endl;
			}
		}

		void takeTissue() {
			int temp_num;
			bool test = false;
                        cout << "Please select a lamp using the listed index to take a tissue: " << endl;
                        for (int i = 0; i < items_on_table.size; i++) {
                                if (items_on_table.get(i)->tissue != NULL) {
                                        cout << i << ": current number of tissues - " << items_on_table.get(i)->tissue->current_num_tissues << endl;
					test = true;
                                }
                        }
			if (!test) {
                                cout << "Oops! Looks like there aren't any tissueboxes on the table" << endl;
                        } else {
                        	while (true) {
                                	cin >> temp_num;
                                	if (temp_num < 0 || temp_num >= items_on_table.size) {
                                        	cout << "Index is out of bounds. Please try again" << endl;
                                        	continue;
                                	}
                                	if (items_on_table.get(temp_num)->tissue != NULL) {
                                        	items_on_table.get(temp_num)->tissue->take_tissue();
                                        	break;
                                	} else {
                                        	cout << "This object is not a book, please try again" << endl;
                                        	continue;
                                	}
                        	}
			}
		}

		void addLamp() {
			Lamp* temp = new Lamp(&available_surface_area);
                        if (temp->created) {
                                items_on_table.add(temp);
                                cout << "Added lamp" << endl;
                        }
		}

		void removeLamp() {
			int temp_num;
			bool test = false;
                        cout << "Please select a lamp using the listed index to remove: " << endl;
                        for (int i = 0; i < items_on_table.size; i++) {
                                if (items_on_table.get(i)->lamp != NULL) {
                                        cout << i << ": lamp color - " << items_on_table.get(i)->lamp->color << endl;
					test = true;
                                }
                        }
			if (!test) {
                                cout << "Oops! Looks like there aren't any lamps on the table" << endl;
                        } else {
                        	while (true) {
                                	cin >> temp_num;
                                	if (temp_num < 0 || temp_num >= items_on_table.size) {
                                        	cout << "Index is out of bounds. Please try again" << endl;
                                        	continue;
                                	}
                                	if (items_on_table.get(temp_num)->lamp != NULL) {
                                       		items_on_table.remove(temp_num);
						Lamp* lamp = static_cast<Lamp*>(items_on_table.get(temp_num)->lamp);
                                        	available_surface_area += lamp->dim.l * lamp->dim.w;
                                        	break;
                                	} else {
                                        	cout << "This object is not a lamp, please try again" << endl;
                                        	continue;
                                	}
                        	}
                        	cout << "Removed lamp!" << endl;
			}
		}

		void changeLampState() {
			int temp_num;
			bool test = false;
                        cout << "Please select a lamp using the listed index to turn off/on: " << endl;
                        for (int i = 0; i < items_on_table.size; i++) {
                                if (items_on_table.get(i)->lamp != NULL) {
                                        cout << i << ": lamp color - " << items_on_table.get(i)->lamp->color << endl;
					test = false;
                                }
                        }
			if (!test) {
                                cout << "Oops! Looks like there aren't any books on the table" << endl;
                        } else {
                        	while (true) {
                                	cin >> temp_num;
                               		if (temp_num < 0 || temp_num >= items_on_table.size) {
                                        	cout << "Index is out of bounds. Please try again" << endl;
                                        	continue;
                                	}
                                	if (items_on_table.get(temp_num)->lamp != NULL) {
                                        	items_on_table.get(temp_num)->lamp->on_off();
                                        	break;
                                	} else {
                                        	cout << "This object is not a book, please try again" << endl;
                                        	continue;
                                	}
                        	}
			}
		}
};

#endif
