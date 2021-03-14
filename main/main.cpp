#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List my_list;

    my_list.push(20);
    my_list.push(4);
    my_list.push(15);
    my_list.push(10);

    /*delaem loop*/
    my_list.head->next->next->next->next = my_list.head->next;
    /*20 -> 4 -> 15 -> 10 -> 4 -> ...*/

    if (my_list.HareTurtleLoopDetect())
        cout << "Loop found";
    else
        cout << "No Loop";

    cout << endl;

    if (my_list.ReverseLoopDetect())
        cout << "Loop found";
    else
        cout << "No Loop";

    return 0;
}