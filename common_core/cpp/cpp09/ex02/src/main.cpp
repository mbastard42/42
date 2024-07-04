#include <chrono>
#include <list>
#include <vector>
#include <iostream>

void vector_merge(std::vector<int>& v1, std::vector<int>& v2, std::vector<int>& result) {

    size_t i1 = 0, i2 = 0;
    while (i1 < v1.size() && i2 < v2.size()) {
        if (v1[i1] < v2[i2]) {
            result.push_back(v1[i1]);
            i1++;
        } else {
            result.push_back(v2[i2]);
            i2++;
        }
    }
    while (i1 < v1.size()) {
        result.push_back(v1[i1]);
        i1++;
    }
    while (i2 < v2.size()) {
        result.push_back(v2[i2]);
        i2++;
    }
}

void vector_sort(std::vector<int>& v) {

    if (v.size() <= 1)
        return;

    std::vector<int> v1, v2;
    for (size_t i = 0; i < v.size() / 2; i++) {
        v1.push_back(v[i]);
    }
    for (size_t i = v.size() / 2; i < v.size(); i++) {
        v2.push_back(v[i]);
    }

    vector_sort(v1);
    vector_sort(v2);

    v.clear();
    vector_merge(v1, v2, v);
}

void list_merge(std::list<int>& l1, std::list<int>& l2, std::list<int>& result) {

    std::list<int>::iterator it1 = l1.begin();
    std::list<int>::iterator it2 = l2.begin();

    while(it1 != l1.end() && it2 != l2.end()) {
        if(*it1 < *it2) { result.push_back(*it1); it1++; }
        else { result.push_back(*it2); it2++; }
    }
    while(it1 != l1.end()) { result.push_back(*it1); it1++; }
    while(it2 != l2.end()) { result.push_back(*it2); it2++; }
}

void list_sort(std::list<int>& l) {

    if(l.size() <= 1)
        return;

    std::list<int> l1, l2;
    std::list<int>::iterator it = l.begin();
    for (size_t i = 0; i < l.size() / 2; i++) { l1.push_back(*it); it++; }
    while (it != l.end()) { l2.push_back(*it); it++; }

    list_sort(l1);
    list_sort(l2);

    l.clear();
    list_merge(l1, l2, l);
}

int main(int ac, char **av __unused) {

    std::chrono::time_point<std::chrono::system_clock> stop;
    std::chrono::duration<double> time;
    std::list<int> lst;
    std::vector<int> vec;

    if (ac > 1) {
        for (int i = 1; i < ac; i++) {
            for (int j = 0; av[i][j]; j++) {
                if (!strchr("0123456789", av[i][j])) {
                    std::cout << "Error" << std::endl;
                    return 0;
                }
            }
            vec.push_back(std::stoi(av[i]));
            lst.push_back(std::stoi(av[i]));
        }
        std::cout << "Before: ";
        for (int i = 1; i < ac; i++)
            std::cout << av[i] << " ";
        std::cout << std::endl << std::endl;
        stop = std::chrono::system_clock::now();
        list_sort(lst);
        std::cout << "After (list): ";
        while (lst.size()) {
            std::cout << lst.front() << " ";
            lst.pop_front();
        }
        std::cout << std::endl;
        time = std::chrono::system_clock::now() - stop;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::list : " << time.count() << " sec" << std::endl << std::endl;
        stop = std::chrono::system_clock::now();
        vector_sort(vec);
        std::cout << "After (vector): ";
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
        time = std::chrono::system_clock::now() - stop;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << time.count() << " sec" << std::endl;
    } else { std::cout << "Error" << std::endl; }
    vec.clear();
    return 0;
}