#ifndef LIST_
#define LIST_

#include <iostream>

struct Element {Element* next; void* obj; };

class List {
	private:
		Element* head;
	public:
		List() { head = NULL; }
		void add(void* obj) {
			Element* temp = new Element();
			temp->obj = obj;
			temp->next = head;
			head = temp;
		}

		Element* remove(int index) {
			Element* temp = head, *prev;
			while (index >= 0 && temp != NULL) {
				prev = temp;
				temp = temp->next;
				index--;
			}
			if (temp != NULL) {
				prev->next = temp->next;
			}
			return temp;
		}

		Element* get(int index) {
			Element* temp = head;
                        while (index >= 0 && temp != NULL) {
                                temp = temp->next;
                                index--;
                        }
                        return temp;
		}
};

#endif
