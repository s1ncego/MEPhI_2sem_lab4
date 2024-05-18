#include "menu.h"
#include "tests.h"
#include "structures.h"

int main() {

    Test();
    cout << "\nAll tests completed successfully!\n";

    cout << "\n-~~~~==Hello!==~~~~-\n";
    cout << "Press 1 to run BinaryTree menu, Press 2 to run BinaryHeap menu, Press 3 to run Set menu:\n";
    int typeStructure;
    cin >> typeStructure;

    cout << "Press 1 to use Integer, Press 2 to use Float, Press 3 to use Person:\n";
    int typeElement;
    cin >> typeElement;


    int initInteger;
    double initFloat;
    int ID;
    if (typeElement == 1) {
        cout << "\nInput first element of structure: \n";
        cin >> initInteger;
        switch (typeStructure) {
            case 1:
                BinaryTreeMenu(initInteger);

                break;
            case 2:
                BinaryHeapMenu(initInteger);

                break;
            case 3:
                SetMenu(initInteger);

                break;
            default:
                cout << "\nUnknown command, try again.\n";

                break;
        }
    } else if (typeElement == 2) {
        cout << "\nInput first element of structure: \n";
        cin >> initFloat;
        switch (typeStructure) {
            case 1:
                BinaryTreeMenu(initFloat);

                break;
            case 2:
                BinaryHeapMenu(initFloat);

                break;
            case 3:
                SetMenu(initFloat);

                break;
            default:
                cout << "\nUnknown command, try again.\n";

                break;
        }
    } else if (typeElement == 3) {
        cout << "\nInput ID of the person: \n";
        cin >> ID;

        cout << "\nInput First name of the person: \n";
        string FN;
        cin >> FN;

        cout << "\nInput Second name of the person: \n";
        string SN;
        cin >> SN;

        cout << "\nInput Second name of the person: \n";
        string LN;
        cin >> LN;

        Person person(ID, FN, SN, LN);
        switch (typeStructure) {
            case 1:
                BinaryTreePersonMenu(ID, person);

                break;
            case 2:
                BinaryHeapPersonMenu(ID, person);

                break;
            case 3:
                SetPersonMenu(ID, person);

                break;
            default:
                cout << "\nUnknown command, try again.\n";

                break;
        }
    } else {
        cout << "\nUnknown command, try again.\n";
    }

    return 0;
}