#pragma once
#include <iostream>

template <class T>
class Lista {
public:

	T* first = nullptr;

	void addLast(T *nT);
	void addFirst(T *nT);


	void remove(T *t);
	void clear();
};

template <class T>
class No {
public:

	T* next = nullptr;
	T* prev = nullptr;
};


template<class T>
inline void Lista<T>::addLast(T *nT) {

	if (first == nullptr) {
		first = nT;
		nT->prev = nullptr;
		return;
	}

	T *iT = first;
	while (iT != nullptr) {

		if (iT->next == nullptr) {
			nT->prev = iT;
			iT->next = nT;
			break;
		} else {
			iT = iT->next;
		}
	}
}

template<class T>
inline void Lista<T>::addFirst(T *nT) {
	nT->next = first;
	first->prev = nT;
	first = nT;
}

template<class T>
inline void Lista<T>::remove(T *t) {

	if (t->prev == nullptr) {
		first = t->next;
	} else {
		t->prev->next = t->next;
		// to implement
	}
	//delete t;
}

template<class T>
inline void Lista<T>::clear() {
	// to implement
	first = nullptr;
}