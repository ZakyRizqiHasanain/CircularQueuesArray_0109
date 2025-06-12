#include <iostream>
using namespace std;

//CircularQueuesArray_0109
//Commit minimal = 15 commit


class queues
{
private:
    static const int max = 5;
    int front, rear;
    int queue_array[5];

public:
    queues()
    {
        front = -1;
        rear = -1;
    }

    void insert()
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        //1. Cek apakah antrian penuh
        if ((front == 0 && rear == max - 1) || (front == rear + 1))
        {
            cout << "\nQueue overflow\n"; //1.a
            return;                       //2.a
        }

        