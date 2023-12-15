#include "Task.h"
#include <string>

Task::Task(): name("Empty Task")
{

}

Task::Task(string _name): name(_name)
{

}

Task::~Task()
{

}


string Task::getName(){
    return this->name;
}
void Task::setName(string _name){
    this->name = _name;
}
