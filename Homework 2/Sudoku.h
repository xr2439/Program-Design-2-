#include <vector>

using namespace std;

class Sudoku{
public:
    Sudoku (void);
    void ReadIn (void);
    void Solve (void);
    void GiveQuestion (void);
private:
    void set_map (void);
    void set_place (int, int);
    void set_place_back (int, int);
    bool is_continue (int, int);
    bool continue_Lv1 (int, int);
    void backtracking (int);
    void qout (int*, int*);
    void change (int*, int, int);
    int data[81];
    int C[9][9];
    int R[9][9];
    int Cube[9][9];
    int status;
    int exit_backtracking;
    int ans_num;
    int start;
    vector <int> location;
    vector <int> ans;
    vector <int> tmp;
};
