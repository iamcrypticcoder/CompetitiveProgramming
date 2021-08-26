/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
    Rank :
    Complexity:
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Person {
    string name;
    int age;
    int salary;

    Person() {}
    Person(string name, int age, int salary) {
        this->name = name;
        this->age = age;
        this->salary = salary;
    }
};

struct CompareAge {
    bool operator() (Person const& p1, Person const& p2) {
        if (p1.age == p2.age)
            return p1.name > p2.name;
        return p1.age > p2.age;
    }
};

// name, then age, then salary
struct CompareAll {
    bool operator() (Person const& p1, Person const& p2) {
        if (p1.name == p2.name) {
            if (p1.age == p2.age)
                return p1.salary > p2.salary;
            return p1.age > p2.age;
        }
        return p1.name > p2.name;
    }
};

void defaultPriorityQueueExample() {
    vector<int> v {1, 2, 3, 4, 5};
    priority_queue<int> pq;
    for (int i = 0; i < v.size(); i++)
        pq.push(v[i]);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void priorityQueueIncreasing() {
    vector<int> v {5, 1, 8, 4, 10, 2};
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < v.size(); i++)
        pq.push(v[i]);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void customComparatorExample1() {
    priority_queue<Person, vector<Person>, CompareAll> pq;
    pq.push(Person("c", 21, 100));
    pq.push(Person("d", 20, 500));
    pq.push(Person("d", 20, 400));
    pq.push(Person("a", 15, 300));
    pq.push(Person("b", 32, 200));

    while (!pq.empty()) {
        Person p = pq.top();
        printf("%s - %d - %d\n", p.name.c_str(), p.age, p.salary);
        pq.pop();
    }
    cout << endl;
}

void customComparatorUsingLambdaExample() {
    auto comp = [](Person p1, Person p2) {
        if (p1.name == p2.name) {
            if (p1.age == p2.age)
                return p1.salary > p2.salary;
            return p1.age > p2.age;
        }
        return p1.name > p2.name;
    };
    priority_queue<Person, vector<Person>, decltype(comp)> pq(comp);
    pq.push(Person("c", 21, 100));
    pq.push(Person("d", 20, 500));
    pq.push(Person("d", 20, 400));
    pq.push(Person("a", 15, 300));
    pq.push(Person("b", 32, 200));

    while (!pq.empty()) {
        Person p = pq.top();
        printf("%s - %d - %d\n", p.name.c_str(), p.age, p.salary);
        pq.pop();
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);

    // defaultPriorityQueueExample();
    // priorityQueueIncreasing();
    // customComparatorExample();
    customComparatorUsingLambdaExample();
}