#ifndef TASKQUEUE_H
#define TASKQUEUE_H
#include "Task.h"
#include <vector>
#include <iostream>

using namespace std;

class TaskQueue
{


    public:
        static const int maxSizeValue = 100;
        TaskQueue();
        TaskQueue(int _maxSize);
        TaskQueue(const TaskQueue& other);

        virtual ~TaskQueue();

        Task& operator[] (int i);
        void operator--();
        void operator+(const Task& tache);
        friend ostream& operator<<(ostream& out, TaskQueue& taskQueue);

        bool isEmpty() const;
        bool isFull() const;

    protected:

    private:
        int first,last;
        int maxSize;
        vector<Task> tasks;

};

#endif // TASKQUEUE_H
