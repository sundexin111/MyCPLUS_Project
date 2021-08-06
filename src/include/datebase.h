#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Database{
public:
    Database(){
        //constructor
    }
    ~Database(){
        //destructor
    }

    void write(vector<vector<string>> mainList);
    vector<vector<string>> read();

    vector<vector<string>> mainList;
    string name;
protected:
private:
};