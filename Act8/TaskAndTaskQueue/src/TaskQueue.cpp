#include "TaskQueue.h"

#include <iostream>

using namespace std;

const int TaskQueue::maxSizeValue;

TaskQueue::TaskQueue(){
    this->first = 0;
    this->last = 0;
    this->maxSize = maxSizeValue;
    this->tasks.resize(maxSizeValue);
}

TaskQueue::TaskQueue(int _maxSize):first(0), last(0){
    this->maxSize = min(_maxSize, maxSizeValue);
    this->tasks.resize(maxSize);
}

TaskQueue::TaskQueue(const TaskQueue& other) :   first(0), last(0){
    this->tasks = other.tasks;
    this->maxSize= other.tasks.size();
}

TaskQueue::~TaskQueue()
{
}

Task& TaskQueue::operator[](int i){
    return this->tasks[i];
}
void TaskQueue::operator--() {
    if(!this->isEmpty()){
        this->first = (this->first + 1) % this->maxSize;
    }else {
        cout << "TaskQueue is already Empty -> ABORT" << endl;
    }

}
void TaskQueue::operator+(const Task& _task) {
    if (!this->isFull()) {
        this->tasks[last] = _task;
        this->last = (this->last + 1) % this->maxSize;
    } else {
        cout << "TaskQueue is already Full -> ABORT" << endl;
    }
}

ostream& operator<<(ostream& out, TaskQueue& taskQueue) {
    out << "Current tasks of the task queue you called are:\n";
    for (auto& task : taskQueue.tasks) {
        out << task.getName() << "\n";
    }
    return out;
}

bool TaskQueue::isEmpty() const {
    return this->first == this->last;
}

bool TaskQueue::isFull() const {
    return (this->last + 1) % this->maxSize == this->first;
}
