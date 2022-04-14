#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <deque>

using namespace std;

// fifo scheduling
void fifo(vector<deque<int>> timing, int n, queue<int> ready)
{
    cout << "FIFO scheduling" << endl;
    int globalTime = 1;
    // processes that are blocked
    set<int> pBlocked;
    // unfinished processes
    int unfinished = n;
    while (unfinished != 0)
    {
        // process that is running
        if (!ready.empty())
        {
            int pRunning = ready.front();

            int timeSpan = timing[pRunning - 1][0];
            for (int i = 0; i < timeSpan; i++)
            {
                cout << "Cycle " << globalTime << ": ";
                // state for each process
                for (int j = 1; j <= n; j++)
                {
                    cout << "P" << j << ": ";
                    if (j == pRunning && timing[j - 1].size() > 1)
                    {
                        cout << "Run    ";
                    }
                    else if (j == pRunning && timing[j - 1].size() == 1)
                    {
                        cout << "Terminate    ";
                    }
                    else
                    {
                        if (pBlocked.find(j) != pBlocked.end())
                        {
                            cout << "Blocked    ";
                            timing[j - 1][0]--;
                            if (timing[j - 1][0] == 0)
                            {
                                pBlocked.erase(j);
                                ready.push(j);
                                timing[j - 1].pop_front();
                            }
                        }
                        else if (!timing[j - 1].empty())
                        {
                            cout << "Ready  ";
                        }
                        else
                        {
                            cout << "    ";
                        }
                    }
                }
                globalTime++;
                cout << endl;
            }

            ready.pop();
            timing[pRunning - 1].pop_front();
            if (timing[pRunning - 1].empty())
            {
                unfinished--;
            }
            else
            {
                pBlocked.insert(pRunning);
            }
        }
        // no process in the ready queue
        else
        {

            cout << "Cycle " << globalTime << ": ";
            for (int i = 1; i <= n; i++)
            {
                cout << "P" << i << ": ";
                if (pBlocked.find(i) != pBlocked.end())
                {
                    cout << "Blocked  ";
                    timing[i - 1][0]--;
                    if (timing[i - 1][0] == 0)
                    {
                        pBlocked.erase(i);
                        ready.push(i);
                        timing[i - 1].pop_front();
                    }
                }
                else
                {
                    cout << "    ";
                }
            }
            globalTime++;
            cout << endl;
        }
    }
}

vector<deque<int>> buildTiming(vector<int> input, int start)
{
    vector<deque<int>> timing;
    int i = start;
    while (i < input.size())
    {
        deque<int> temp;
        temp.push_back(input[i]);
        temp.push_back(input[i + 1]);
        temp.push_back(input[i + 2]);
        temp.push_back(input[i + 3]);
        temp.push_back(1);
        timing.push_back(temp);
        i += 4;
    }
    return timing;
}

int main()
{
    vector<int> input;
    int i = 0;
    cout << "Your Input: " << endl;
    while (true)
    {
        cin >> i;
        input.push_back(i);
        if (cin.peek() == '\n')
        {
            break;
        }
    }
    // number of processes
    int n = input.at(0);

    // scheduling algorithm
    int SA = input.at(1);

    // process in ready queue
    queue<int> ready;
    for (int i = 0; i < n; i++)
    {
        ready.push(i + 1);
    }

    // each inner vector is the running and blocking time for each process
    vector<deque<int>> timing;

    // fifo scheduling
    if (SA == 1)
    {
        timing = buildTiming(input, 2);
        fifo(timing, n, ready);
    }
    // RR scheduling
    else if (SA == 2)
    {
        timing = buildTiming(input, 3);
    }
    else
    {
        return 0;
    }
}
