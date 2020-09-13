#include <bits/stdc++.h>
#include <list>
using namespace std;

class Worker
{
public:
    int id;
    string name;
    string job;
    Worker(int id, string name, string job)
    {
        this->id = id;
        this->name = name;
        this->job = job;
    }
};
list<Worker> workers;
map<int, list<Worker>::iterator> idMap;
map<string, list<Worker>::iterator> nameMap;

Worker searchName(string name)
{
    return *nameMap[name];
}
// wok
Worker searchId(int id)
{
    return *idMap[id];
}

bool addWorker(int id, string name, string job)
{
    if (idMap.find(id) != idMap.end() && nameMap.find(name) != nameMap.end())
    {
        workers.push_back(Worker(id, name, job));
        list<Worker>::iterator it = workers.end();
        idMap[id] = it;
        nameMap[name] = it;
        return true;
    }
    else
        return false;
}
bool removeName(string name)
{
    list<Worker>::iterator rmit = nameMap.find(name)->second;
    bool ret = nameMap.erase(name) && idMap.erase(rmit->id);
    workers.erase(rmit);
}

void fileReader()
{
    ifstream fin("data.dat");
    int id;
    string name;
    string job;
    while (!fin.eof()) //行末没空格
    {
        cin >> id >> name >> job;
        addWorker(id, name, job);
    }
    fin.close();
}

void fileWriter()
{
    ofstream fout("data.dat");
    if (workers.size() > 0) //行末没空格
    {
        list<Worker>::iterator it = workers.begin();
        cout << it->id << ' ' << it->name << ' ' << it->job;
        for (int i = 1; i < workers.size(); i++)
        {
            cout << endl
                 << it->id << ' ' << it->name << ' ' << it->job;
        }
    }
    fout.close();
}

int opt;
int id;
string name;
string job;
int main()
{
    fileReader();
    while (1)
    {
        cin >> opt;
        switch (opt)
        {
        case 1: //add
            /* code */
            cin >> id >> name >> job;

            break;

        default:
            break;
        }
    }
    fileWriter();
}