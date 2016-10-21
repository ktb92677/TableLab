#ifndef LIST_
#define LIST_

#include <iostream>
#include "Book.h"
#include "TissueBox.h"
#include "Lamp.h"

struct Element {Element* next; Book* book; TissueBox* tissue; Lamp* lamp; };

class List {
	private:
		Element* head;
	public:
		int size;
		List() { head = NULL; size = 0; }
		void add(Book* obj) {
			Element* temp = new Element();
			temp->book = obj;
			temp->tissue = NULL;
			temp->lamp = NULL;
			temp->next = head;
			head = temp;
			size++;
		}

		void add(TissueBox* obj) {
                        Element* temp = new Element();
                        temp->book = NULL;
                        temp->tissue = obj;
                        temp->lamp = NULL;
                        temp->next = head;
                        head = temp;
                        size++;
                }

		void add(Lamp* obj) {
                        Element* temp = new Element();
                        temp->book = NULL;
                        temp->tissue = NULL;
                        temp->lamp = obj;
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
