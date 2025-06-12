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

        //cek jika antrian hanya memiliki satu elemen
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            //jika elemen yang dihapus di posisi terakhir array, kembali ke awal array
            if (front == max - 1)
                front = 0;
            else 
                front = front + 1;
        }
    }

    void display()
    {
        int front_position = front;
        int rear_position = rear;

        //cek apakah antrian kosong
        if (front == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElement in the queue are...\n";

        //jika front_position, iterasi dari front hingga rear
        if (front_position <= rear_position)
        {
            while (front_position <= rear_position)
            {
                cout << queue_array[front_position] << "   ";
                front_position++;
            }
            cout << endl;
        }
        else 
        {
            //jka front_position > rear_position, iterasi dari front hingga akhir array
            while (front_position <= max - 1)
            {
                cout << queue_array[front_position] << "   ";
                front_position++;
            }
            
            front_position = 0;

            while (front_position <= rear_position)
            {
                cout << queue_array[front_position] << "  ";
                front_position++;
            }
            cout << endl;
        }
    }
};

int main() 
{
    queues q;
    char ch;

    while(true) 
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation\n2. Implement delete operation\n3. Display values\n4. Exit\n" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
                case '1':
                {
                    q.insert();
                    break;
                }
                case '2':
                {
                    q.remove();
                    break;
                }
                case '3':
                {
                    q.display();
                    break;
                }
                case '4':
                {
                    return 0;
                }
                default:
                {
                    cout << "Invalid option!!" << endl;
                    break;
                }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }
}