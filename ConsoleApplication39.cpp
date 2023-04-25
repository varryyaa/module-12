#include <iostream>
#include <string>
using namespace std;
void LPS(string pat, int* lps) 
{
    int j = 0;

    lps[0] = 0; 

    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void IsKPeriodic(int K, const string& str) 
{
    if (K < 1) 
    {
        cout << "Введите К > 0" << endl;
    }
    else
    {
        string str2; 
        for (int i = 0; i < K; ++i)
            str2.push_back(str[i]);

        int* lps = new int[str2.size()];

        LPS(str2, lps);

        int i = 0;
        int j = 0;
        int val = 0;
        while (i < str.size()) {
            if (str2[j] == str[i])
            {
                j++;
                i++;
            }
            if (j == str2.size()) {
                val++; 
                j = lps[j - 1];
            }

            else if (i < str.size() && str2[j] != str[i]) {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i = i + 1;
                }
            }
        }
        if (K * val == str.size())
            cout << "Строка " << str << " кратна " << K << endl;
        else cout << "Строка " << str << " не кратна " << K << endl; 
        delete[] lps;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int K;
    string str; 
    cout << "Введите строку: ";
    cin >> str;
    cout << "Введите число К: ";
    cin >> K;
    IsKPeriodic(K, str);
    return 0;
}
