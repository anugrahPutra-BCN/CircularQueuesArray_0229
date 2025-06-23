/**
 * @mainpage Documentation circular Queues
 * 
 * @section Introduction
 * poroject ini merupakan project struktur data
 * menggunkan struktur data queues dengan pendekatan circular arrays.
 * 
 * @section Opretation
 * - en queue for insert elements into queue
 * - de queue for delete elements form queue
 * - show data / display
 * 
 * @section How to use
 * 1. Insert 
 * 2. Delete
 * 3. Display
 * 4. Exit
 * 
 * 
 * @author yProfil
 * - Nama : Anugrah Putra Rizkia
 * - Nim : 20240140229
 * - Kelas : E
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */



#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief This class is for operation queues
 * 
 */
class Queues {
private:
    int FRONT; /// private variable front for indicate firts element  
    int REAR; /// private variable rear for indicate the last element
    int max = 5; /// private variable max for capasity of element
    int queue_array[5]; /// private variable queue_array to store elements

public:
   /**
    * @brief Constructor a new Queues object
    * set default queues null
    * with front = -1 and rear = -1
    */
   Queues() {
    FRONT = -1;
    REAR = -1;
   }

   /**
    * @brief method for entering data into a queue
    * 
    */
   void insert() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << endl;

    // cek apakah antrian penuh
    if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
        cout << "\nQueue overflow\n";
        return;
    }

    // Cek apakah antrian penuh
    if (FRONT == -1) {
        FRONT = 0;
        REAR = 0;
    }
    else {
        // jika REAR bearada di posisi terakhir array, kembali ke awal array
        if (REAR == max - 1)
            REAR = 0;
        else 
            REAR = REAR + 1;
    }
    queue_array[REAR] = num;
   }

   void remove() {
    // cek apakah antrian kosong
    if (FRONT == -1) {
        cout << "Queue under flow\n";
        return;
    }
    cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

    // cek jika antrian hanya memiliki satu  elemen
    if (FRONT == REAR) {
        FRONT = -1;
        REAR = -1;
    }
    else {
        // jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
        if (FRONT == max - 1)
            FRONT = 0;
        else
            FRONT = FRONT + 1;
    }
   }

   void display() {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        // cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements is i the queue are...\n";

        // jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            // jika FRONT_position >REARR_position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max -1) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }

            FRONT_position = 0;

            // iterasi dari awal array hingga rear
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
            
        }
    }
};

int main()
{
    Queues q;
    char ch;

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout  << endl;
        
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