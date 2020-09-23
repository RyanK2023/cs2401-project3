/*

    Name: Ryan Kilkenney
    Date:3/1/2020
    Purpose:Header file for the college class. Has all of the function prototype


*/
#include<iostream>
#include<string>
#include<fstream>
#include"node.h"
#ifndef COLLEGE_H
#define COLLEGE_H

using namespace std;

class College {

    public:
    College();

    void add(course c);
    void display(ostream& cout);
    void remove(string coursename);
    double hours();
    double gpa();

    ~College();
    College(const College& other);
	College& operator = (const College& other);

    void load(istream& ins);
	void save(ostream& outs);
    void set_name(string fullname);

    private:
    string name;
    node * head;

};
#endif