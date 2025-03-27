/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:16:30 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/27 18:38:40 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template<class T>MutantStack<T>::MutantStack() {};
template<class T>MutantStack<T>::MutantStack(MutantStack& original) {
	*this = original;
};
template<class T> MutantStack<T>& MutantStack<T>::operator=(const MutantStack& M) {
	if (this != &M)
		this->c = M->c;
	return this;
};
template<class T>MutantStack<T>::~MutantStack() {};

template<class T> typename MutantStack<T>::iterator MutantStack<T>::begin() { 
	return this->c.begin();
}

template<class T> typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}