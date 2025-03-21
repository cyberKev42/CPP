/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:02:16 by kevin             #+#    #+#             */
/*   Updated: 2025/03/21 12:31:13 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<class T> Array<T>::Array() {
    this->arr = nullptr;
	this->_size = 0;
}
template<class T> Array<T>::Array(unsigned int n) {
    this->arr = new T[n];
	this->_size = n;
}
template<class T> Array<T>::Array(Array& original) {
	this->_size = original._size;
	this->arr = new T[size()];
	for (int i = 0; i < size(); i++)
    	this->arr[i] = original.arr[i];
}
template<class T> 
Array<T>& Array<T>::operator=(const Array& A) {
    if (this != &A) {
		this->_size = A._size;
		if (this->arr)
			delete[] this->arr;
		this->arr = new T[size()];
		for (int i = 0; i < size(); i++)
    		this->arr[i] = A.arr[i];
	}
	return *this;
}
template<class T> Array<T>::~Array() {
    delete[] this->arr;
}

template<class T> 
T& Array<T>::operator[](unsigned int index) {
    if (index >= this->_size)
		throw InvalidIndex();
	return this->arr[index];
}

template<class T> 
int Array<T>::size() const {
	return this->_size;
}
