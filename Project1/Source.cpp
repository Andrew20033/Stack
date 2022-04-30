#include <iostream>
using namespace std;
const int n = 3;
struct Stack
{
    int A[n];
    int count;
};
//создание стека
void Creation(Stack* p)
{
    p->count = 0;
}
//проверка стека на пустоту
int Full(Stack* p)
{
    if (p->count == 0) return 1;
    else if (p->count == n) return -1;
    else return 0;
}
//добавление элемента
void Add(Stack* p)
{
    int value;
    cout << "Enter element > "; cin >> value;
    p->A[p->count] = value;
    p->count++;
}
//удаление элемента
void Delete(Stack* p)
{
    p->count--;
}
//вывод верхнего элемента
int Top(Stack* p)
{
    return p->A[p->count - 1];
}
//вывод стека на экран
void print(Stack* p)
{
    /*Stack *count = p;
    while (count) {
     cout << p->count << " ";
     count = count->A;
    }*/

    for (int i = 0; i < p->count; i++)
    {
        printf("%d  ", p->A[i]);
    }
    /*return 0;*/
}
//размер стека
int Size(Stack* p)
{
    return p->count;
}
//главная функция
void main()
{
    Stack s;
    Creation(&s);
    char number;
    do
    {
        cout << "1. Add element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Remove the top element" << endl;
        cout << "4. Check stack size" << endl;
        cout << "5. Display stack on screen " << endl;
        cout << "0. Log off" << endl;
        cout << "Number of command > "; cin >> number;
        switch (number)
        {
        case '1':
            if (Full(&s) == -1) cout << endl << "Stack full\n\n";
            else
            {
                Add(&s);
                cout << endl << "Element added to the stack\n\n";
            } break;
            //-----------------------------------------------
        case '2':
            if (Full(&s) == 1) cout << endl << " Stack is empty\n\n";
            else
            {
                Delete(&s);
                cout << endl << "Item removed from stack\n\n";
            } break;
            //-----------------------------------------------
        case '3':
            if (Full(&s) == 1) cout << endl << "Stack is empty\n\n";
            else cout << "\nTop element : " << Top(&s) << "\n\n";
            break;
            //-----------------------------------------------
        case '4':
            if (Full(&s) == 1) cout << endl << "Stack is empty\n\n";
            else cout << "\nStack size: " << Size(&s) << "\n\n";
            break;
            //-----------------------------------------------
        case '5':

            cout << "Stack: ";
            print(&s);
            cout << "\n\n";
            break;
            //-----------------------------------------------
        case '0': break;
        default: cout << endl << "Command not defined\n\n";
            break;
        }
    } while (number != '0');
    system("pause");
}