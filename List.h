#ifndef LIST_
#define LIST_

#include <iostream>
#include "Book.h"

struct Element {Element* next; Book* book; };

class List {
	private:
		Element* head;
	public:
		int size;
		List() { head = NULL; size = 0; }
		void add(Book* obj) {
			Element* temp = new Element();
			temp->book = obj;
			temp->next = head;
			head = temp;
			size++;
		}

		Element* remove(int index) {
			Element* temp = head, *prev;
			while (index > 0 && temp != NULL) {
				prev = temp;
				temp = temp->next;
				index--;
			}
			if (temp != NULL) {
				prev->next = temp->next;
				size--;
			}
			return temp;
		}

		Element* get(int index) {
			Element* temp = head;
                        while (index > 0 && temp != NULL) {
                                temp = temp->next;
                                index--;
                        }
                        return temp;
		}
};

#endif
