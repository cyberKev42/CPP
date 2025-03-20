/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:51:22 by kevin             #+#    #+#             */
/*   Updated: 2025/03/20 19:05:15 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>

template<class T> class Array {
    private:
    public:
        Array();
        Array(unsigned int n);
		Array(Array& original);
        Array& operator=(const Array& A);
        ~Array();
		
        T* 				arr;
		unsigned int 	_size;
		
		int size() const;
		T& operator[](unsigned int index);
		
		class InvalidIndex : public std::exception {
		public:
			const char* what() const noexcept override {
				return "Index is out of bound";
			}
		};
};

#include "Array.tpp"
#endif