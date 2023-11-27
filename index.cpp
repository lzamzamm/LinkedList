#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int angka;
    node *next;
    node *prev;
};

node *head, *tail, *lk, *current, *del;

void createNode(int a)
{
    head = new node();
    head->angka = a;
    head->next = NULL;
    head->prev = NULL;
    tail = head;
}

void addedNodePrev(int a)
{
    lk = new node();
    lk->angka = a;
    lk->next = head;
    lk->prev = NULL;
    head->prev = lk;
    head = lk;
}

void addedNodeNext(int a)
{
    lk = new node();
    lk->angka = a;
    lk->next = NULL;
    lk->prev = tail;
    tail->next = lk;
    tail = lk;
}

void deleteHead()
{
    del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
}
void deleteTail()
{
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
}

void insertAtPosition(int a, int position)
{
    lk = new node();
    if (current != NULL)
    {
        cout << "Position invalid";
    }
    else
    {
        current = lk;
        lk->angka = a;
        tail->prev->next = current;
        tail->prev = current;
    }
}

void printNode()
{
    if (head == NULL)
    {
        cout << "Node kosong";
    }
    else
    {
        cout << "Node Angka : " << endl;
        current = head;
        while (current != NULL)
        {
            cout << "angka :" << current->angka << endl;
            current = current->next;
        }
        // current2 = tail;
        // while (current2 != NULL)
        // {
        //     cout << "angka :" << current2->angka << endl;
        //     current2 = current2->next;
        // }
    }
}

int main()
{
    int num, pilihan, numNext, numPrev;
    string lanjut1, lanjut2;

    do
    {
        cout << "Masukan angka untuk head : ";
        cin >> num;
        cout << endl;

        createNode(num);

        cout << endl;
        do
        {
            printNode();
            cout << endl;

            cout << "Pilih perintah :\n1. Menambah node didepan head\n2. Menambah node di belakang tail\n3. Hapus head\n4. Hapus tail" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            cout << endl;

            switch (pilihan)
            {
            case 1:
                cout << "Masukan angka : ";
                cin >> numPrev;
                cout << endl;
                addedNodePrev(numPrev);
                printNode();
                break;
            case 2:
                cout << "Masukan angka : ";
                cin >> numNext;
                cout << endl;
                addedNodeNext(numNext);
                printNode();
                break;
            case 3:
                deleteHead();
                printNode();
                break;
            case 4:
                deleteTail();
                printNode();
                break;
            default:
                cout << "Pilihan tidak ada" << endl;
            }

            cout << endl;
            cout << "Apakah anda ingin lanjut[y/n] : ";
            cin >> lanjut1;
            system("CLS");
        } while (lanjut1 == "y");
        cout << endl;
        cout << "Apakah anda ingin mengulang[y/n] : ";
        cin >> lanjut2;
    } while (lanjut2 == "y");

    // createNode(20);
    // addedNodePrev(40);
    // addedNodeNext(60);
    // addedNodeNext(10);
    // addedNodePrev(70);
    // deleteHead();
    // deleteTail();
    // deleteTail();
    // printNode();
}