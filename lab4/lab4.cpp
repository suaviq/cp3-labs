#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <tuple>

using namespace std;
// try to predict the shape of aminoacids from txt files 
// collect the data and combine elements
// sth -> shape
// TDLK -> DFFE
// VSHN -> EFEF
// create dictionary of all words that are four elements long, find matching symbols, generating elements to store in container
// output: ADLK -> matching word (if None -> leave empty)


vector<string> files;
vector<char> data_;
vector<char> shape;
vector<vector<char>> W;
vector<vector<char>> Y;

void readtxt()
{
    string line;
    ifstream myfile("C:/Users/alase/OneDrive/Pulpit/studia/list.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line)) {
            //cout << line << endl;
            files.push_back(line);
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}
void openfiles(vector<string> files)
{
    vector<string> whole_data;
    string data_line;
    string data_character;
    string data_shape;
    for (auto const& i : files) {
        ifstream data_files("C:/Users/alase/Downloads/danes2/seq/" + i);
        if (data_files.is_open())
        {
            while (getline(data_files, data_line)) {
                //cout << data_line << endl;
                whole_data.push_back(data_line);
            }
            data_files.close();
        }
    }

    //we have all our data stored in vector whole_data
    for (auto item : whole_data)
    {
        //cout << item << endl;
        char dataindeW = item[6];
        char shapeindeW = item[8];
        data_.push_back(dataindeW);
        shape.push_back(shapeindeW);
        //nowe we have two vector of chars, one with data character and one with shape information character 
    }

    

    for (int i = 0; i < data_.size() - 4; i++)
    {
        vector<char> new_W;
        vector<char> new_y;
        for (int j = 0; j < 4; j++) {
            new_W.push_back(data_[i + j]);
            new_y.push_back(shape[i + j]);
        }
        W.push_back(new_W);
        Y.push_back(new_y);
    }
}

tuple<vector<char>, int> search(vector<char> x)
{
    // algorithm:
    // first we are looking for perfect match (level 0); when our input is for example: ABCD, we are looking for ABCD
    // level 1: we found three letters with perfect match 
    // level 2: we found two letters with perfect match
    // level 3: we found one letter match
    for (int level = 0; level < 4; level++) {
        for (int i = 0; i < W.size(); i++) {
            bool match = true;
            for (int j = 0; j < 4 - level; j++) {
                if (W[i][j] != x[j]) {
                    match = false;
                    break;
                }
            }
            if (match == true) {
                return make_tuple(Y[i], level);
            }
        }
    }
    return make_tuple(W[0], -1);
}

int main()
{
    char input;
    vector<char> x;
    vector<char> match;
    int level;
	readtxt();
    openfiles(files);
    cout << "Hello! Please write four letters to find match for:";
    for (int i = 0; i < 4; i++)
    {
        cin >> input;
        x.push_back(input);
    }

    cout << endl;
    make_tuple(match, level) = search(x);
    for (int i = 0; i < 4; i++) {
        cout << match[i] << " ";
    }
    cout << level;
	return 0;
}

