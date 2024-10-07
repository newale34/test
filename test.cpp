#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

int main()
{
    vector<int> deck(49, 0);

    int idx = 0;
    for (; idx < 4; idx++)
    {
        deck[idx] = 1;
    }
    for (; idx < 8; idx++)
    {
        deck[idx] = 2;
    }

    int otherG1 = 8;

    for (; idx < 8 + otherG1; idx++)
    {
        deck[idx] = 3;
    }

    int count = 100000;
    int success = 0;
    random_device rd;
    mt19937 g(rd());

    for (int t = 0; t < count; t++)
    {
        bool flg = false;
        shuffle(deck.begin(), deck.end(), g);

        for (int i = 0; i < 5; i++)
        {
            if (deck[i] == 1)
            {
                flg = true;
                break;
            }
            else if (deck[i] == 0)
            {
                if (deck[i + 5] == 1)
                {
                    flg = true;
                    break;
                }
                swap(deck[i], deck[i + 5]);
            }
        }

        if (flg)
        {
            success++;
            continue;
        }

        shuffle(deck.begin() + 5, deck.end(), g);

        int pa = 0;
        bool asist = true;
        for (int i = 0; i < 6; i++)
        {
            if (deck[i] == 1)
            {
                flg = true;
                break;
            }
            else if (deck[i] == 2)
            {
                pa++;
            }
            else if (deck[i] == 3)
            {
                asist = false;
            }
        }

        if (flg)
        {
            success++;
            continue;
        }

        if (deck[6] == 1 || deck[7] == 1 || deck[8] == 1 || deck[9] == 1 || deck[10] == 1)
        {
            success++;
            continue;
        }

        for (int i = 0; i < pa; i++)
        {
            if (deck[i + 6] == 1 || deck[i + 7] == 1 || deck[i + 8] == 1 || deck[i + 9] == 1 || deck[i + 10] == 1)
            {
                success++;
                break;
            }

            shuffle(deck.begin() + 7 + i, deck.end(), g);
        }
    }

    cout << success << " / " << count << endl;
}
