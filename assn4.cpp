/*
  
    Description: The mian of zombie
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "list.h"
#include "zombie.h"

using namespace std;

void Output(LinkedList<char> *list)
{
    cout << "Size: " << list->Length() << " :: ";
    list->PrintList();
}

void EngineAction(LinkedList<char> *list, Zombie *zombie)
{
    list->AddToFront(zombie->get());
}

void CabooseAction(LinkedList<char> *list, Zombie *zombie)
{
    list->AddToEnd(zombie->get());
}

void JumpLineAction(LinkedList<char> *list, Zombie *zombie)
{
    srand(time(NULL));
    int x = rand() % (list->Length());
    list->AddAtIndex(zombie->get(), x);
}

void EveryOutAction(LinkedList<char> *list)
{
    list->Empty();
}

void DoneAction(LinkedList<char> *list, Zombie *zombie)
{
    list->RemoveTheFirst(zombie->get());
}

void BrainsAction(LinkedList<char> *list, Zombie *zombie)
{
    list->AddToFront(zombie->get());
    list->AddToEnd(zombie->get());
    list->AddAtIndex(zombie->get(), list->Length() / 2);
}

void RainbowBrainAction(LinkedList<char> *list, Zombie *zombie)
{
    list->AddToFront(zombie->get());
    list->AddToEnd('R');
    list->AddToEnd('Y');
    list->AddToEnd('G');
    list->AddToEnd('B');
    list->AddToEnd('M');
    list->AddToEnd('C');
}

void MakeFriendAction(LinkedList<char> *list, Zombie *zombie)
{
    Node<char> *tmp = list->Find(zombie->get());
    if (!tmp)
    {
        list->AddToEnd(zombie->get());
        return;
    }

    srand(time(NULL));
    int x = rand() % 2;

    if (x == 0)
    {
        list->AddBefore(tmp, zombie->get());
    }
    else
    {
        list->AddAfter(tmp, zombie->get());
    }
}

void UnstableZombieAction(LinkedList<char> *list, Zombie *zombie)
{
    if (!list->ElementExists(zombie->get()))
    {
        return;
    }
    int n = list->IndexOf(zombie->get());

    Node<char> *tmp;
    if (list->IndexOf('R') < n)
    {
        tmp = list->Find('R');
        list->AddAfter(tmp, 'R');
    }

    if (list->IndexOf('Y') < n)
    {
        tmp = list->Find('Y');
        list->AddAfter(tmp, 'Y');
    }

    if (list->IndexOf('G') < n)
    {
        tmp = list->Find('G');
        list->AddAfter(tmp, 'G');
    }
    if (list->IndexOf('B') < n)
    {
        tmp = list->Find('B');
        list->AddAfter(tmp, 'B');
    }
    if (list->IndexOf('M') < n)
    {
        tmp = list->Find('M');
        list->AddAfter(tmp, 'M');
    }
    if (list->IndexOf('C') < n)
    {
        tmp = list->Find('C');
        list->AddAfter(tmp, 'C');
    }
}

void InitList(LinkedList<char> *list)
{
    Zombie zombie;

    RainbowBrainAction(list, &zombie);
    srand(time(NULL));
    int n = rand() % 4 + 2;

    for (int i = 0; i < n; i++)
    {
        Zombie zombie;
        RainbowBrainAction(list, &zombie);
    }
}

void MakeRound(LinkedList<char> *list)
{
    int rounds;

    cout << "how many rounds want to run?" << endl;
    cin >> rounds;

    for (int i = 0; i < rounds; i++)
    {
        Zombie zombie;
        srand(time(NULL));
        int n = rand() % 9;
        cout << "Round: " << i << endl;
        cout << "The Zombie Party keeps on groaning!" << endl;
        Output(list);
        switch (n)
        {
        case 0:
            cout << zombie.get() << "zombie jumps in the front of the line! (ENGINE)" << endl;
            EngineAction(list, &zombie);
            break;
        case 1:
            cout << zombie.get() << "zombie pulls up the rear! (CABOOSE)" << endl;
            CabooseAction(list, &zombie);
            break;
        case 2:
            cout << zombie.get() << "zombie jumps in the front of the line! (Jump in the Line!)" << endl;
            JumpLineAction(list, &zombie);
            break;
        case 3:
            cout << zombie.get() << "zombie remove all matching zombies from the linked list! (Everyone Out!)" << endl;
            EveryOutAction(list);
            break;
        case 4:
            cout << zombie.get() << "zombie remove the first matching! (You are done!)" << endl;
            DoneAction(list, &zombie);
            break;
        case 5:
            cout << zombie.get() << "zombie brings its friends to the party! (BRAINS!)" << endl;
            BrainsAction(list, &zombie);
            break;
        case 6:
            cout << zombie.get() << "zombie brought a whole party itself!(RAINBOW BRAINS!)" << endl;
            RainbowBrainAction(list, &zombie);
            break;
        case 7:
            cout << zombie.get() << "zombie makeing new friends! (Making new Friends!)" << endl;
            MakeFriendAction(list, &zombie);
            break;
        case 8:
            cout << zombie.get() << "zombie unstable! (Unstable Zombie!)" << endl;
            UnstableZombieAction(list, &zombie);
            break;
        }
        cout << "The conga line is now:" << endl;
        Output(list);
        cout << "*****************************" << endl;
        cout << endl;
        cout << endl;
        cout << endl;

        if (list->Length() == 0)
        {
            cout << "That the Party is Over" << endl;
            return;
        }
        sleep(1);
    }
}

int main()
{
    LinkedList<char> list;
   
    while (1)
    {
        InitList(&list);
        Output(&list);
        int opt;

        MakeRound(&list);
        cout << "do you want to continue the part(0) or end(1)" << endl;
        cin >> opt;
        if (opt == 1)
        {
            break;
        }
    }
}
