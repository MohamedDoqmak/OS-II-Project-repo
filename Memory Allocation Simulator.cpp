#include <iostream>
#include <iomanip>

using namespace std;

void First_Fit(int Number_Of_Blocks, int Number_Of_Processes, int* block_sizes, int* processes_sizes)
{
    int* filled = new int[Number_Of_Blocks];
    int* final_arr = new int[Number_Of_Blocks];


    for (int i = 0; i < Number_Of_Blocks; i++)
    {
        filled[i] = 0;
    }

    for (int i = 0; i < Number_Of_Processes; i++)
    {
        for (int j = 0; j < Number_Of_Blocks; j++)
        {
            if ((block_sizes[j] >= processes_sizes[i]) && (filled[j] == 0))
            {
                final_arr[j] = processes_sizes[i];
                filled[j] = 1;
                break;
            }
        }
    }

    cout << "Hole      Process" << endl;
    for (int i = 0; i < Number_Of_Blocks; i++)
    {
        if (filled[i] == 1)
        {
            cout << block_sizes[i] << "           " << final_arr[i] << endl;
        }
        else
        {
            cout << block_sizes[i] << "           " << 0 << endl;
        }

    }
}

int getInput() {
    int num = 0;
    cin >> setw(1) >> num;

    while (!cin.good()) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cout << "Please enter a positive integer!" << endl;
        cin >> setw(1) >> num;
    }

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    return num;
}

int main() {
    int Number_Of_Blocks = 0;
    while (Number_Of_Blocks != -1) {
        cout << "Enter number of blocks or -1 to exit the program: ";
        Number_Of_Blocks = getInput();
        if (Number_Of_Blocks == -1) {
            break;
        }
        else if (Number_Of_Blocks < -1) {
            cout << "Please enter a positive integer or -1 to exit the program!" << endl;
            continue;
        }
        int* block_sizes = new int[Number_Of_Blocks];
        int* filled = new int[Number_Of_Blocks];

        for (int i = 0; i < Number_Of_Blocks; i++) {
            cout << "Enter size of hole " << i + 1 << ": ";
            block_sizes[i] = getInput();
            filled[i] = 0;
        }

        int Number_Of_Processes;
        cout << "Enter number of processes: ";
        Number_Of_Processes = getInput();
        int* processes_sizes = new int[Number_Of_Processes];

        for (int i = 0; i < Number_Of_Processes; i++) {
            cout << "Enter size of process " << i + 1 << ": ";
            processes_sizes[i] = getInput();
        }

        int choice;
        cout << "Choose 1-Best Fit 2-Worst Fit 3-First Fit: ";
        choice = getInput();

        if (choice == 1) {
            bestFit(block_sizes, filled, Number_Of_Blocks, processes_sizes, Number_Of_Processes);
        }
        else if (choice == 2) {
            worstFit(block_sizes, filled, Number_Of_Blocks, processes_sizes, Number_Of_Processes);
        }
        else if (choice == 3) {
            First_Fit(Number_Of_Blocks, Number_Of_Processes, block_sizes, processes_sizes);
        }
    }
    return 0;
}