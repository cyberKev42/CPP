/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:36:51 by kbrauer           #+#    #+#             */
/*   Updated: 2025/03/29 15:37:43 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {

	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
			std::cout << *it << std::endl;
			++it;
	}
	std::stack<int> s(mstack);

	
	
	std::cout << "___________________________________________________" << std::endl;
	std::list<int> lstack;
	
	lstack.push_back(5);
	lstack.push_back(17);
	
	std::cout << lstack.back() << std::endl;
	
	lstack.pop_back();
	
	std::cout << lstack.size() << std::endl;
	
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	//[...]
	lstack.push_back(0);
	
	std::list<int>::iterator it_l = lstack.begin();
	std::list<int>::iterator ite_l = lstack.end();
	
	++it_l;
	--it_l;
	while (it_l != ite_l)
	{
			std::cout << *it_l << std::endl;
			++it_l;
	}
	std::list<int> l(lstack);
	
	

	
	// std::cout << "___________________________________________________" << std::endl;

	// MutantStack<int> mstack;
	
	// mstack.push(1);
	// mstack.push(2);
	// mstack.push(3);

	// std::cout << mstack.top() << std::endl;

	// mstack.pop();

	// std::cout << mstack.size() << std::endl;
	
	// mstack.push(4);
	// mstack.push(5);
	// mstack.push(6);
	
	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();

	// std::cout << "iterator it: " << std::endl;
	// std::cout << *it << std::endl;
	// ++it;
	// std::cout << *it << std::endl;
	// --it;
	// std::cout << *it << std::endl;
	// std::cout << std::endl;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }	
	
	
	
	return 0;
}