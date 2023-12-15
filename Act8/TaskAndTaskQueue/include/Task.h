#ifndef TASK_H
#define TASK_H
#include <string>

using namespace std;
class Task
{
    public:
        Task();
        Task(string _name);
        virtual ~Task();

        string getName();
        void setName(string _name);

    protected:

    private:
        string name;
};

#endif // TASK_H
