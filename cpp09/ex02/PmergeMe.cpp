/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:46:58 by cgil              #+#    #+#             */
/*   Updated: 2026/01/28 12:53:10 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::parseInput(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        long value;
        std::istringstream iss(argv[i]);

        if (!(iss >> value) || !iss.eof())
            throw std::runtime_error("Error");
        if (value <= 0 || value > INT_MAX)
            throw std::runtime_error("Error");

        _vec.push_back(static_cast<int>(value));
        _deq.push_back(static_cast<int>(value));
    }
}

static std::list<size_t> jacobsthal(size_t n)
{
    std::list<size_t> seq;

    if (n <= 1)
        return seq;

    size_t j0 = 0;
    size_t j1 = 1;

    while (true)
    {
        size_t next = j1 + 2 * j0;
        if (next >= n)
            break;
        seq.push_back(next);
        j0 = j1;
        j1 = next;
    }
    return seq;
}

// vector

static void insertVector(std::vector<int>& v, int value)
{
    std::vector<int>::iterator it = v.begin();
    while (it != v.end() && *it < value)
        ++it;
    v.insert(it, value);
}

static void fordJohnsonVector(std::vector<int>& v)
{
    if (v.size() <= 1)
        return;

    std::vector<int> mainSeq;
    std::vector<int> pending;
    bool hasExtra = false;
    int extra = 0;

    if (v.size() % 2 != 0)
    {
        extra = v.back();
        v.pop_back();
        hasExtra = true;
    }

    for (size_t i = 0; i < v.size(); i += 2)
    {
        if (v[i] > v[i + 1])
        {
            mainSeq.push_back(v[i]);
            pending.push_back(v[i + 1]);
        }
        else
        {
            mainSeq.push_back(v[i + 1]);
            pending.push_back(v[i]);
        }
    }

    fordJohnsonVector(mainSeq);

    std::vector<bool> used(pending.size(), false);
    std::list<size_t> order = jacobsthal(pending.size());

    for (std::list<size_t>::iterator it = order.begin(); it != order.end(); ++it)
    {
        if (*it >= pending.size() || used[*it])
            continue;
        insertVector(mainSeq, pending[*it]);
        used[*it] = true;
    }
    for (size_t i = 0; i < pending.size(); ++i)
    {
        if (!used[i])
            insertVector(mainSeq, pending[i]);
    }

    if (hasExtra)
        insertVector(mainSeq, extra);

    v = mainSeq;
}

// deque
static void insertDeque(std::deque<int>& d, int value)
{
    std::deque<int>::iterator it = d.begin();
    while (it != d.end() && *it < value)
        ++it;
    d.insert(it, value);
}

static void fordJohnsonDeque(std::deque<int>& d)
{
    if (d.size() <= 1)
        return;

    std::deque<int> mainSeq;
    std::deque<int> pending;
    bool hasExtra = false;
    int extra = 0;

    if (d.size() % 2 != 0)
    {
        extra = d.back();
        d.pop_back();
        hasExtra = true;
    }

    for (size_t i = 0; i < d.size(); i += 2)
    {
        if (d[i] > d[i + 1])
        {
            mainSeq.push_back(d[i]);
            pending.push_back(d[i + 1]);
        }
        else
        {
            mainSeq.push_back(d[i + 1]);
            pending.push_back(d[i]);
        }
    }

    fordJohnsonDeque(mainSeq);

    std::vector<bool> used(pending.size(), false);
    std::list<size_t> order = jacobsthal(pending.size());
    for (std::list<size_t>::iterator it = order.begin(); it != order.end(); ++it)
    {
        if (*it >= pending.size() || used[*it])
            continue;
        insertDeque(mainSeq, pending[*it]);
        used[*it] = true;
    }
    for (size_t i = 0; i < pending.size(); ++i)
    {
        if (!used[i])
            insertDeque(mainSeq, pending[i]);
    }
    if (hasExtra)
        insertDeque(mainSeq, extra);

    d = mainSeq;
}

// sort and print
void PmergeMe::sortAndPrint() const
{
    std::vector<int> vecCopy = _vec;
    std::deque<int>  deqCopy = _deq;

    std::cout << CYAN << "Before: " << RESET;
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    clock_t start = clock();
    fordJohnsonVector(vecCopy);
    clock_t end = clock();
    double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    start = clock();
    fordJohnsonDeque(deqCopy);
    end = clock();
    double deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    std::cout << CYAN << "After: " << RESET;
    for (size_t i = 0; i < vecCopy.size(); ++i)
        std::cout << vecCopy[i] << " ";
    std::cout << std::endl;

    std::cout << GREEN << "Time to process a range of " << vecCopy.size()
              << " elements with std::" << RED "vector : " << RESET
              << vecTime << " us" << std::endl;

    std::cout << GREEN << "Time to process a range of " << deqCopy.size()
              << " elements with std::" << RED << "deque : " << RESET
              << deqTime << " us" << std::endl;
}
