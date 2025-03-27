/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:37:10 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/27 18:30:49 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTStACK_HPP

#include <iostream>
#include <list>
#include <stack>

template<class T> class MutantStack : public std::stack<T> {
	private:
	public:
		MutantStack();
		MutantStack(MutantStack& original);
		MutantStack& operator=(const MutantStack& M);
		~MutantStack();
		typedef typename std::deque<T>::iterator iterator;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"
#endif