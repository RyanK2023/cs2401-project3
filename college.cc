/*

    Name: Ryan Kilkenney
    Date:3/1/2020
    Purpose: Source code file for the college class. Has the code for all the functions 


*/
#include<iostream>
#include<string>
#include<fstream>
#include"node.h"
#include"college.h"

using namespace std;

College::College() {
    name = " ";
    head = NULL;
}

College::~College() {
    node * rmptr;
    while (head != NULL) {
        rmptr = head;
        head = head->link();
        delete rmptr;
    }
}

College::College(const College& other) {
    if(other.head == NULL) {
        head == NULL;
    } else {
        node * s_ptr;
        node * d_ptr;
        head = new node(other.head->data());
        s_ptr = other.head->link();
        d_ptr = head;
        while(s_ptr != NULL) {
            d_ptr->set_link(new node(s_ptr->data()));
            d_ptr = d_ptr->link();
            s_ptr = s_ptr->link();
        }
    }
}

College& College::operator =(const College& other) {
    if(this == &other) {
        return * this;
    }
    node * tmptr;
    while(head != NULL) {
        tmptr = head;
        head = head->link();
        delete tmptr;
    }
    if (other.head != NULL) {
        head = new node(other.head->data());
        const node * s_ptr = other.head->link();
        node * d_ptr = head;
        while(s_ptr != NULL){
            d_ptr->set_link(new node(s_ptr->data()));
            d_ptr=d_ptr->link();
            s_ptr=s_ptr->link();
        }
    }
    return * this;
}

//this works?
void College::add(course c) {
    if(head == NULL) {
        head = new node(c);
    } 
    else if (head->data().get_course_number() > c.get_course_number()) {
        node * cursor = head;
        head = new node(c);
        head->set_link(cursor);
        
    } 
    else {
        node * cursor = head;
        node * previous = cursor;
        while (cursor != NULL && cursor->data().get_course_number() <= c.get_course_number()) {
            previous = cursor;
            cursor = cursor->link();
        } 
        previous->set_link(new node(c));
        previous = previous->link();
        previous->set_link(cursor);
    }
    
}

//infinte loop
void College::display(ostream& cout) {
   node * cursor = head;

   while(cursor != NULL) {
       cout << cursor->data() << endl;
       cursor = cursor->link();
   }
}

void College::remove(string coursedata) {
    if (head == NULL) {
        return;
    }

    if (head->data().get_course_number() == coursedata) {
        node * tmp = head;
        head = head->link();
        delete tmp;
    } else {
        node * cursor = head;
        node * prev = head;
        while(cursor != NULL && cursor->data().get_course_number() != coursedata) {
            prev = cursor;
            cursor = cursor->link();
        }
        if (cursor != NULL) {
            prev->set_link(cursor->link());
            delete cursor;
        }
    }

}

double College::hours() {
    double hours = 0.0;
    node * cursor = head;

    while(cursor != NULL) {
        hours += cursor->data().get_hours();
        cursor = cursor->link();
    }

    return hours;
}

double College::gpa() {
    double points = 0.0;
    node * cursor = head;
    double h = hours();

    while(cursor != NULL) {
        points += (cursor->data().get_hours() * cursor->data().get_number_grade());
        cursor = cursor->link();
    }

    points = points/h;
    return points;

}

void College::load(istream& ins) {
    getline(ins, name);

    course c;
    ins >> c;

    while (!ins.eof())
    {
        add(c);
        ins >> c;
    }
    
}

void College::save(ostream& outs) {
    node * cursor = head;
    outs << name << endl;
    while(cursor != NULL) {
        outs << cursor->data();
        cursor = cursor->link();
    }
}

void College::set_name(string fullname) {
    name = fullname;
}