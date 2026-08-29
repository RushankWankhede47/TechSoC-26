#include <iostream>
#include<windows.h>
using namespace std;

int main()
{
    int generation_counter = 1;
    int row, column, generation;
    string feature;
    getline(cin, feature);

    cin >> row >> column;

    if (feature == "classify")
    {
        generation = 100;
    }
    else
    {
        cin >> generation;
    }

    int population[generation + 1] = {};

    if (row < 2 || column < 2)
    {
        cout << "Invalid, run program again";
        exit(0);
    }

    string row_arrangement[row];

    for (int i = 0; i < row; i++)
    {
        cin >> row_arrangement[i];

        while (row_arrangement[i].length() != column)
        {
            cout << "Number of columns do not match \ntry again" << endl;
            cin >> row_arrangement[i];
        }
    }

    char order[row][column];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            order[i][j] = row_arrangement[i][j];
        }
    }

    // Convert '#' -> 1 and '.' -> 0
    int current_state[row][column];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (order[i][j] == '#')
            {
                current_state[i][j] = 1;
            }
            else if (order[i][j] == '.')
            {
                current_state[i][j] = 0;
            }
            else
            {
                cout << "Something other than '#' and '.' is found! \n"<< "Terminating program...";
                exit(0);
            }
        }
    }

    // Store initial population
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            population[0] += current_state[i][j];
        }
    }
    if (generation == 0 && feature != "metrics")
    {
        cout << "Initial population: " << population[0] << endl;
        cout << "Final population: " << population[0] << endl;
        cout << "Peak Population: " << population[0] << endl;
        cout << "Final Grid: " << endl;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                cout << order[i][j];
            }
            cout << endl;
        }

        return 0;
    }

    if (feature == "")
    {
        while (generation_counter <= generation)
        {
            int executor[row + 2][column + 2] = {};

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    executor[i + 1][j + 1] = current_state[i][j];
                }
            }

            // New generation
            int next_state[row + 2][column + 2] = {};

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    int valueload =
                        executor[i][j] +
                        executor[i][j + 1] +
                        executor[i][j + 2] +
                        executor[i + 1][j] +
                        executor[i + 1][j + 2] +
                        executor[i + 2][j] +
                        executor[i + 2][j + 1] +
                        executor[i + 2][j + 2];

                    if (executor[i + 1][j + 1] == 1)
                    {

                        if (valueload == 2 || valueload == 3)
                        {
                            next_state[i + 1][j + 1] = 1;
                        }
                    }
                    else
                    {

                        if (valueload == 3)
                        {
                            next_state[i + 1][j + 1] = 1;
                        }
                    }
                }
            }

            // Store population of this generation
            population[generation_counter] = 0;

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    population[generation_counter] +=
                        next_state[i + 1][j + 1];
                }
            }

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    current_state[i][j] = next_state[i + 1][j + 1];
                }
            }

            generation_counter++;
        }

        int max = 0;
        for (int i = 0; i < generation + 1; i++)
        {
            if (population[i] > max)
            {
                max = population[i];
            }
        }

        cout << "Initial population: " << population[0] << endl;
        cout << "Final population: " << population[generation] << endl;
        cout << "Peak Population: " << max << endl;

        cout << "Final Grid: " << endl;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (current_state[i][j] == 1)
                {
                    cout << '#';
                }
                else
                {
                    cout << '.';
                }
            }

            cout << endl;
        }
    }

    else if (feature == "toroidal")
    {
        while (generation_counter <= generation)
        {
            int executor[row + 2][column + 2] = {};

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    executor[i + 1][j + 1] = current_state[i][j];
                }
            }
            for (int i = 0; i < row + 1; i++)
            {
                executor[i + 1][0] = executor[i + 1][column];
                executor[i + 1][column + 1] = executor[i + 1][1];
            }
            for (int j = 0; j < column + 1; j++)
            {
                executor[0][j + 1] = executor[row][j + 1];
                executor[row + 1][j + 1] = executor[1][j + 1];
            }
            executor[0][0] = executor[row][column];
            executor[0][column + 1] = executor[row][1];
            executor[row + 1][0] = executor[1][column];
            executor[row + 1][column + 1] = executor[1][1];

            // for(int i = 0; i<row+2;i++){
            //     for(int j =0; j<column+2;j++){
            //         cout<<executor[i][j];
            //     }
            //     cout<<endl;
            // }

            // New generation
            int next_state[row + 2][column + 2] = {};

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    int valueload =
                        executor[i][j] +
                        executor[i][j + 1] +
                        executor[i][j + 2] +
                        executor[i + 1][j] +
                        executor[i + 1][j + 2] +
                        executor[i + 2][j] +
                        executor[i + 2][j + 1] +
                        executor[i + 2][j + 2];

                    if (executor[i + 1][j + 1] == 1)
                    {

                        if (valueload == 2 || valueload == 3)
                        {
                            next_state[i + 1][j + 1] = 1;
                        }
                    }
                    else
                    {

                        if (valueload == 3)
                        {
                            next_state[i + 1][j + 1] = 1;
                        }
                    }
                }
            }

            // Store population of this generation
            population[generation_counter] = 0;

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    population[generation_counter] +=
                        next_state[i + 1][j + 1];
                }
            }

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    current_state[i][j] = next_state[i + 1][j + 1];
                }
            }

            generation_counter++;
        }
        cout << "Mode : Toroidal" << endl;
        cout << "Initial population: " << population[0] << endl;
        cout << "Final population: " << population[generation] << endl;

        cout << "Final Grid: " << endl;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (current_state[i][j] == 1)
                {
                    cout << '#';
                }
                else
                {
                    cout << '.';
                }
            }

            cout << endl;
        }
    }

    else if (feature == "classify")
    {
        int checkextinct = generation + 1;
        int gridcounter[generation + 1][row][column] = {};
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                gridcounter[0][i][j] = current_state[i][j];
            }
        }
        while (generation_counter <= generation)
        {
            int executor[row + 2][column + 2] = {};

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    executor[i + 1][j + 1] = current_state[i][j];
                }
            }

            // New generation
            int next_state[row + 2][column + 2] = {};

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    int valueload =
                        executor[i][j] +
                        executor[i][j + 1] +
                        executor[i][j + 2] +
                        executor[i + 1][j] +
                        executor[i + 1][j + 2] +
                        executor[i + 2][j] +
                        executor[i + 2][j + 1] +
                        executor[i + 2][j + 2];

                    if (executor[i + 1][j + 1] == 1)
                    {

                        if (valueload == 2 || valueload == 3)
                        {
                            next_state[i + 1][j + 1] = 1;
                        }
                    }
                    else
                    {

                        if (valueload == 3)
                        {
                            next_state[i + 1][j + 1] = 1;
                        }
                    }
                }
            }

            // Store population of this generation
            population[generation_counter] = 0;

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    population[generation_counter] +=
                        next_state[i + 1][j + 1];
                }
            }

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    current_state[i][j] = next_state[i + 1][j + 1];
                }
            }

            if (population[generation_counter] == 0)
            {
                checkextinct--;
            }

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    gridcounter[generation_counter][i][j] = current_state[i][j];
                }
            }

            generation_counter++;
        }

        if (checkextinct != generation + 1)
        {
            cout << "Classification : Extinct" << endl;
            cout << "Extinction step: " << generation - checkextinct << endl;
            cout << "Final Population: " << 0 << endl;
        }

        // How would I check if 2x2 matrtix are equal
        bool found = false;
        int matchStart = -1, gridnum = -1;

        for (int count = 0; count <= generation && !found; count++)
        {
            for (int k = count + 1; k <= generation; k++)
            {
                bool same = true;
                for (int i = 0; i < row && same; i++)
                {
                    for (int j = 0; j < column; j++)
                    {
                        if (gridcounter[count][i][j] != gridcounter[k][i][j])
                        {
                            same = false;
                            break;
                        }
                    }
                }
                if (same)
                {
                    found = true;
                    matchStart = count;
                    gridnum = k;
                    break;
                }
            }
        }

        if (found)
        {
            if (gridnum - matchStart > 1)
            {
                cout << "Classification: Oscillator" << endl;
                cout << "Period : " << gridnum - matchStart << endl;
                cout << "First Repeat Step: " << gridnum << " (matches step " << matchStart << ")" << endl;
                cout << "Population : " << population[generation] << endl;
            }
            else if (gridnum - matchStart == 1)
            {
                cout << "Classification: Still Life" << endl;
                cout << "Stable at: " << matchStart << endl;
                cout << "Period : " << gridnum - matchStart << endl;
                cout << "Population : " << population[generation] << endl;
            }
        }
        else
        {
            cout << "Classification: Still evolving (no repeat found within " << generation << " generations)" << endl;
        }
    }

    // metrics
    else if (feature == "metrics")
    {
        while (generation_counter <= generation)
        {
            int executor[row + 2][column + 2] = {};

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    executor[i + 1][j + 1] = current_state[i][j];
                }
            }

            // New generation
            int next_state[row + 2][column + 2] = {};

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    int valueload =
                        executor[i][j] +
                        executor[i][j + 1] +
                        executor[i][j + 2] +
                        executor[i + 1][j] +
                        executor[i + 1][j + 2] +
                        executor[i + 2][j] +
                        executor[i + 2][j + 1] +
                        executor[i + 2][j + 2];

                    if (executor[i + 1][j + 1] == 1)
                    {

                        if (valueload == 2 || valueload == 3)
                        {
                            next_state[i + 1][j + 1] = 1;
                        }
                    }
                    else
                    {

                        if (valueload == 3)
                        {
                            next_state[i + 1][j + 1] = 1;
                        }
                    }
                }
            }

            // Store population of this generation
            population[generation_counter] = 0;

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    population[generation_counter] +=
                        next_state[i + 1][j + 1];
                }
            }

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    current_state[i][j] = next_state[i + 1][j + 1];
                }
            }

            generation_counter++;
        }

        // Calculating COM
        int comx = 0;
        int comy = 0;
        int N = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                switch (current_state[i][j])
                {
                case 1:
                    /* code */
                    comx += j;
                    comy += i;
                    N++;
                    break;
                }
            }
        }
        cout << "Living cells : " << N << endl;

        // Creating Bounding Box
        int maxcolumn = 0;
        int initialRow = row;
        int maxrow = 0;
        int initialColumn=column;
        bool ColumnpatternStart = false;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (current_state[i][j] == 1 && maxcolumn < j)
                {
                    maxcolumn = j;
                }


                if (current_state[i][j] == 1 && maxrow < i)
                {
                    maxrow = i;
                }
            }
        }

        for(int i = row-1; i >= 0 ; i--){
            for(int j = column - 1; j>=0;j--){
                if(current_state[i][j]==1 && initialColumn>j){
                    initialColumn=j;
                }
                if(current_state[i][j]==1 && initialRow>i){
                    initialRow=i;
                }
            }
        }

        
        if (comx != 0 && comy != 0)
        {
            cout << "Center of Mass : (" << ((double)comx / (N)) << ", " << ((double)comy / (N)) << ")" << endl;
            cout << "Bounding Box: " << maxcolumn + 1 - initialColumn<< " x " << maxrow + 1 -initialRow<< " (Rows "<<initialRow<<"-"<<maxrow << ", Cols "<<initialColumn<<"-"<<maxcolumn << ")" << endl;
        }
        else
        {
            cout << "Center of Mass : N/A" << endl;
            cout << "Bounding Box: 0x0"<<endl;
        }

        return 0;
    }

    else if (feature == "animate"){

        cout << "Generation: 0"<< "   " << "Population: " << population[0] << endl
             << endl;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (current_state[i][j] == 1)
                {
                    cout << '#';
                }
                else
                {
                    cout << '.';
                }
            }

            cout << endl;
        }

        Sleep(1000);
        system("cls");

        while (generation_counter <= generation)
        {
            int executor[row + 2][column + 2] = {};

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    executor[i + 1][j + 1] = current_state[i][j];
                }
            }

            // New generation
            int next_state[row + 2][column + 2] = {};

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    int valueload =
                        executor[i][j] +
                        executor[i][j + 1] +
                        executor[i][j + 2] +
                        executor[i + 1][j] +
                        executor[i + 1][j + 2] +
                        executor[i + 2][j] +
                        executor[i + 2][j + 1] +
                        executor[i + 2][j + 2];

                    if (executor[i + 1][j + 1] == 1)
                    {

                        if (valueload == 2 || valueload == 3)
                        {
                            next_state[i + 1][j + 1] = 1;
                        }
                    }
                    else
                    {

                        if (valueload == 3)
                        {
                            next_state[i + 1][j + 1] = 1;
                        }
                    }
                }
            }

            // Store population of this generation
            population[generation_counter] = 0;

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    population[generation_counter] +=
                        next_state[i + 1][j + 1];
                }
            }

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    current_state[i][j] = next_state[i + 1][j + 1];
                }
            }

            cout<<"Generation: "<<generation_counter-1<<"   "<<"Population: "<<population[generation_counter]<<endl<<endl;

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    if (current_state[i][j] == 1)
                    {
                        cout << '#';
                    }
                    else
                    {
                        cout << '.';
                    }
                }

                cout << endl;
            }

            Sleep(1000);
            system("cls");

            generation_counter++;
        }

        cout<<endl<<"simulation complete!"<<endl;

    }

    else{
        cout<<"Maybe you typed something wrong... try again"<<endl;
    }

}
