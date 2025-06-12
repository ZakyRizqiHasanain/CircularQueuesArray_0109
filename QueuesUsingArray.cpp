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

        //2. Cek apakah antrian kosong
        if (front == -1)
        {
            front = 0; //2.a
            rear = 0;   //2.b
        }
        else 
        {
            //JIka rear berada di posisi terakhir array, kembali ke awal array
            if (rear == max - 1)
                rear = 0;
            else 
                rear = rear + 1;
        }
        queue_array[rear] = num;
    }

    void remove()
    {
        //cek apakah antrian kosong
        if (front == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe elemnt deleted from the queue is: " << queue_array[front] << "\n";

        