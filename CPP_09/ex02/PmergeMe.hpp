#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cstdlib>

class PmergeMe {
    private:
        std::list<int> lst;
        std::vector<int> vector;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &cpy);
        PmergeMe &operator = (const PmergeMe &cpy);

        void check_and_fill(int ac, char **av);
        void run(int ac, char **av);

        std::vector<int> mergeForVec(const std::vector<int> &left, const std::vector<int> &right);
        std::vector<int> fordJohnsonSortForVec(std::vector<int> &vec);
        void printVec(std::string title, std::vector<int> &vec);

        std::list<int> mergeForList(const std::list<int> &left, const std::list<int> &right);
        std::list<int> fordJohnsonSortForList(std::list<int> &lst);
        void printList(std::string title, std::list<int> &lst);

        ~PmergeMe();
};

#endif