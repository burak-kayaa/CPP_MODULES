#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &cpy) {
    if (this != &cpy) {
        this->lst = cpy.lst;
        this->vector = cpy.vector;
    }
}

PmergeMe &PmergeMe::operator = (const PmergeMe &copy) {
    (void)copy;
    return *this;
}

PmergeMe::~PmergeMe() { }

void exit_program() {
    std::cout << "Error\n";
    exit(1);
}

void is_number(std::string value) {
    for (int i = 0; i < (int)value.length(); i++) {
        if (!(value[i] >= '0' && value[i] <= '9'))
            exit_program();
    }
}

int ft_stoi(std::string str) {
    int i = 0;
    int num = 0;
    int isNegative = 0;

    if (str[i] == '-' || str[i] == '+')
        if (str[i++] == '-')
            isNegative = 1;
    while (str[i] >= '0' && str[i] <= '9') {
        num = num * 10 + (str[i++] - '0');
    }
    if (isNegative)
        num *= -1;
    return (num);
}


void PmergeMe::check_and_fill(int ac, char **av) {
    for (int i = 1; i < ac; i++) {
        is_number(av[i]);
        int value = ft_stoi(av[i]);
        if (value < 1)
            exit_program();
        vector.push_back(value);
        lst.push_back(value);
    }
}

std::vector<int> PmergeMe::mergeForVec(const std::vector<int> &left, const std::vector<int> &right) {
    std::vector<int> result;
    size_t i = 0, j = 0;
    
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i++]);
        } else {
            result.push_back(right[j++]);
        }
    }
    while (i < left.size()) {
        result.push_back(left[i++]);
    }
    while (j < right.size()) {
        result.push_back(right[j++]);
    }
    
    return result;
}

std::vector<int> PmergeMe::fordJohnsonSortForVec(std::vector<int> &vec) {
    if (vec.size() <= 1) return vec;
    
    size_t mid = vec.size() / 2;
    std::vector<int> left(vec.begin(), vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.end());
    
    left = fordJohnsonSortForVec(left);
    right = fordJohnsonSortForVec(right);
    
    return mergeForVec(left, right);
}

void PmergeMe::printVec(std::string title, std::vector<int> &vec) {
    std::cout << title;
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

std::list<int> PmergeMe::mergeForList(const std::list<int> &left, const std::list<int> &right) {
    std::list<int> result;
    std::list<int>::const_iterator it1 = left.begin();
    std::list<int>::const_iterator it2 = right.begin();

    while (it1 != left.end() && it2 != right.end()) {
        if (*it1 <= *it2) {
            result.push_back(*it1++);
        } else {
            result.push_back(*it2++);
        }
    }
    while (it1 != left.end()) {
        result.push_back(*it1++);
    }
    while (it2 != right.end()) {
        result.push_back(*it2++);
    }

    return result;
}

std::list<int> PmergeMe::fordJohnsonSortForList(std::list<int> &lst) {
    if (lst.size() <= 1) return lst;
    
    std::list<int>::iterator mid = lst.begin();
    std::advance(mid, lst.size() / 2);
    std::list<int> left(lst.begin(), mid);
    std::list<int> right(mid, lst.end());
    
    left = fordJohnsonSortForList(left);
    right = fordJohnsonSortForList(right);
    
    return mergeForList(left, right);
}

void PmergeMe::printList(std::string title, std::list<int> &lst) {
    std::cout << title;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::run(int ac, char **av) {
        std::vector<int> sorted_vector;
        std::list<int> sorted_list;
        check_and_fill(ac, av);

        printVec("Before: ", vector);
        sorted_vector = fordJohnsonSortForVec(vector);
        printVec("After: ", sorted_vector);

        std::clock_t startVector = std::clock();
        sorted_vector = fordJohnsonSortForVec(vector);
        std::clock_t endVector = std::clock();
        double vectorTime = 1000.0 * (endVector - startVector) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << sorted_vector.size() << " elements with std::vector: " << vectorTime << " ms\n";

        std::clock_t startList = std::clock();
        sorted_list = fordJohnsonSortForList(lst);
        std::clock_t endList = std::clock();
        double listTime = 1000.0 * (endList - startList) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << sorted_list.size() << " elements with std::list: " << listTime << " ms\n";
}
