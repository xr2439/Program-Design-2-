#include "Sudoku.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

    Sudoku:: Sudoku (void)
    {
        memset (data, 0, sizeof(data));
        memset (C, 0, sizeof(C));
        memset (R, 0, sizeof(R));
        memset (Cube, 0, sizeof(Cube));
    }

    void Sudoku:: ReadIn (void)
    {
        set_map ();
    }

    void Sudoku:: Solve (void)
    {
        status = 0;
        start = 0;
        exit_backtracking = 0;
        ans_num = 0;
        backtracking (location.size());
        if (status == 0)
            cout << "0" <<endl;
        else if (status == 2)
            cout << "2" << endl;
        else
        {
            cout << "1" << endl;
            int element = 0;
            for (int i=0; i<81; i++)
            {
                if ( i%9==0 && i!=0)
                    cout << "\n";
                if (data[i] == 0)
                    cout << ans[element++] << " ";
                else
                    cout << data[i] << " ";
            }
            cout << endl;
        }
    }

    void Sudoku:: GiveQuestion (void)
    {
	int Q1[]={
	0,0,0,0,1,5,0,7,0,0,0,0,7,0,0,0,6,0,0,0,3,0,0,4,0,1,2,
	0,0,6,0,0,0,0,0,0,0,1,0,6,0,9,0,4,0,0,0,0,0,0,0,2,0,0,
	7,9,0,4,0,0,8,0,0,0,6,0,0,0,7,0,0,0,0,8,0,9,5,0,0,0,0};
	int Q2[]={
	0,4,0,0,8,0,0,7,0,1,0,0,0,9,0,0,0,4,0,0,7,4,0,2,5,0,8,
	0,0,9,0,0,0,6,0,0,4,7,0,0,5,0,0,3,1,0,0,5,0,0,0,8,0,0,
	7,0,6,5,0,8,4,0,0,8,0,0,0,7,0,0,0,6,0,2,0,0,6,0,7,0,0};
	int Q3[]={
	0,0,0,2,0,3,0,0,0,0,0,4,0,0,0,3,0,0,0,8,0,9,0,7,0,4,0,
	1,0,0,0,0,0,5,0,6,0,0,0,0,0,0,0,0,0,6,0,3,0,0,0,0,0,2,
	0,5,0,8,0,4,0,7,0,0,0,8,0,0,0,6,0,0,0,0,0,1,0,9,0,0,0};
	int Q4[]={
	5,0,0,0,0,0,0,0,9,0,2,0,1,0,0,0,7,0,0,0,8,0,0,0,3,0,0,
	0,4,0,7,0,2,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,6,0,1,0,
	0,0,3,0,0,0,8,0,0,0,6,0,0,0,4,0,2,0,9,0,0,0,0,0,0,0,5};
	int Q5[]={
	0,0,5,3,0,0,0,0,0,8,0,0,0,0,0,0,2,0,0,7,0,0,1,0,5,0,0,
	4,0,0,0,0,5,3,0,0,0,1,0,0,7,0,0,0,6,0,0,3,2,0,0,0,8,0,
	0,6,0,5,0,0,0,0,9,0,0,4,0,0,0,0,3,0,0,0,0,0,0,9,7,0,0};
        int table[9] = {2,8,5,4,3,1,9,7,6};
        int a = time(NULL);
        int b = time(NULL);
        for (int k=0; k<9; k++)
        {
	    a%=9;
	    b%=9;
            change (table, a%9, b%9);
            a++;
            b+=a;
        }
        if (b%5==1)
            qout(Q1,table);
        else if (b%5==2)
           qout(Q2,table);
        else if (b%5==3)
            qout(Q3,table);
        else if (b%5==4)
            qout(Q4, table);
        else
            qout(Q5, table);
    }

    void Sudoku:: set_map (void)
    {
        int t = 81;
        int i = 0;
        while (t--)
        {
            cin >> data[i];
            if (!data[i])
                location.push_back(i);
            int num = data[i] - 1;
            if (num >= 0)
                C[i%9][num] = R[i/9][num] = Cube[3*((i/9)/3)+(i%9)/3][num] = 1;
            i++;
        }
        return;
    }

    void Sudoku:: set_place (int place, int num)
    {
        C[place%9][num] = R[place/9][num] = Cube[3*((place/9)/3)+(place%9)/3][num] = 1;
    }

    void Sudoku:: set_place_back (int place, int num)
    {
        C[place%9][num] = R[place/9][num] = Cube[3*((place/9)/3)+(place%9)/3][num] = 0;
    }

    bool Sudoku:: is_continue (int place, int num)
    {
       return continue_Lv1 (place, num-1);
    }

    bool Sudoku:: continue_Lv1 (int place, int num)
    {
        if (!C[place%9][num])
            if (!R[place/9][num])
                if (!Cube[3*((place/9)/3)+(place%9)/3][num])
                    return 1;
        return 0;
    }

    void Sudoku:: backtracking (int N)
    {
        if (exit_backtracking == 1)
            return;

        int tmp_size = tmp.size();

        if (tmp_size == N)
        {
            status = 1;
            ans_num++;

            if (ans_num!=1)
            {
                exit_backtracking = 1;
                status = 2;
                return;
            }
            ans = tmp;
            return;
        }

        int i = start;

        for (int j=1; j<10; j++)
        {
            if ( is_continue (location[i], j) )
            {
                tmp.push_back (j);
                start++;
                set_place (location[i], j-1);
                backtracking (N);
                if (exit_backtracking == 1)
                    return;
                tmp.pop_back();
                set_place_back (location[i], j-1);
                start--;
            }
        }
    }

    void Sudoku:: qout (int* Q, int* table)
    {
        for (int i=0; i<81; i++)
        {
            if (i%9==0 && i!=0)
                cout << endl;
            if (Q[i]!=0)
                cout << table[Q[i]-1] << " ";
            else
                cout << "0 ";
        }
	cout << endl;
    }

    void Sudoku:: change (int* table, int i, int j)
    {
        if (i == j)
            j = (j+1)%9;
        int tmp = table [i];
        table[i] = table[j];
        table[j] = tmp;
    }
