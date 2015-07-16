#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class ZipCode {

    private:
    string store;
    string str_ans;
    int int_ans;
    
    public:
    ZipCode (string str_input)
    {
        store = str_input;
        str_ans = store;
        trans_to_int (store);
    }

    ZipCode (int int_input)
    {
        char tmp[6];
        int_ans = int_input;
        for (int i=0,t=10000; i<5; i++, t/=10)
        {
            tmp[i] = int_input / t + '0';
            int_input %= t;
        }
        tmp[5] = '\0';
        store.assign (tmp);
        trans_to_str (store);
    }

    private:
    void trans_to_int (string turn)
    {
        int t;
        int val;
        int_ans = 0;
        for (int i=0; i<5; i++)
        {
            t = 3;
            val = 7;
            int tmp = 0;
            for (int j=i*5+1; j<i*5+6; j++)
            {
                tmp += (turn[j] - '0' )*val;
                val -= t;
                if ( t!=1 )
                    t--;
            }
            if (tmp == 11)
            {
                int_ans *= 10;
                int_ans += 0;
            }
            else
            {
                int_ans *= 10;
                int_ans += tmp;
            }
        }
    }

    void trans_to_str (string turn)
    {
        char tmp_ans[28];
        tmp_ans[0] = '1';
        for (int i=0; i<5; i++)
        {
            if ( turn[i] == '0' )
            {
                tmp_ans[i*5+1] = tmp_ans[i*5+2] = '1';
                tmp_ans[i*5+3] = tmp_ans[i*5+4] = tmp_ans[i*5+5] = '0';
            }
            else
            {
                int tmp = 7;
                int reduce = 3;
                int countnum = 0;
                int run = turn[i] - '0';
                for (int k=1; k<6; k++)
                {
                    tmp_ans[i*5+k] = '0';
                    if (countnum < 2 && run >= tmp )
                    {
                        tmp_ans[i*5+k] = '1';
                        run -= tmp;
                        countnum++;
                    }
                    tmp -= reduce;
                    if (reduce!=1)
                        reduce--;
                }
            }
        }
        tmp_ans[26] = '1';
        tmp_ans[27] = '\0';
        str_ans.assign (tmp_ans);
    }
    public:
    int if_valid_int (void)
    {
        if (int_ans >= 0 && int_ans <= 99999)
            return 1;
        else
            return 0;
    }
    int if_valid_str (void)
    {
	if (store.length()!=27)
	    return 0;
        if (str_ans[0]!='1' || str_ans[26]!= '1')
            return 0;
        int countnum = 0;
        for (int i=1; i<26; i++)
        {
            if (str_ans[i] == '1')
                countnum ++;
            if (str_ans[i] != '0' && str_ans[i] != '1')
                return 0;
            if ( i%5 == 0)
            {
                if (countnum!=2)
                    return 0;
                countnum = 0;
            }
        }
        return 1;
    }

    int int_turn (void)
    {
        return int_ans;
    }

    string str_turn (void)
    {
        return str_ans;
    }

};

int main ()
{
    int choice;
    int num;
    string str;
    for (;;)
    {
        cout << "請選擇動作 <0.結束程式 1.輸入整數 2.輸入字串>: ";
        cin >> choice;
        if ( !choice )
            return 0;
        cout << "請輸入 zip code: ";
        if ( choice == 1 )
        {
            cin >> num;
            ZipCode Zip(num);
            if (Zip.if_valid_int())
            {
                cout << endl;
                cout << "--output--" << endl;
                cout << "in int: " << setw(5) << setfill('0') << Zip.int_turn() << endl;
                cout << "in str: " << Zip.str_turn() << endl;
                cout << "--end of output--" << endl;
            }
            else
                cout << "Error! The \"zip code\" you enter is invalid." << endl;
        }
        if ( choice == 2 )
        {
            cin >> str;
            ZipCode Zip(str);
            if (Zip.if_valid_str())
            {
                cout << endl;
                cout << "--output--" << endl;
                cout << "in int: " << setw(5) << setfill('0') << Zip.int_turn() << endl;
                cout << "in str: " << Zip.str_turn() << endl;
                cout << "--end of output--" << endl;
            }
            else
                cout << "Error! The \"zip code\" you enter is invalid." << endl;
        }
    }

}

