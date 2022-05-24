#include <iostream>
#include <QVector>
#include <QString>
#include <QTextStream>
#include <QtGlobal>
#include <stdio.h>
#include <QList>
#include <QFile>
#include <map>
#include <tuple>
#include <string>
#include <fstream>
#include "tasks_rk1.h"

using namespace std;

//task1
void WorkWithFile::readFromFile(const char* fileName) {
    ifstream file(fileName);
    int i = 0;
    file.seekg (0, ios::end);
    size = file.tellg();
    file.seekg(0);
    dataOfFile = new char[size+1];
    while(!file.eof()){
        file >> dataOfFile[i];
        if (dataOfFile[i] == '\n'){
            i--;
        }
        if (!file.eof()){
            }
        i++;
        }
    file.close();
}
void WorkWithFile::prepareTestFile(const char* fileName){
    ofstream file (fileName, ios::trunc);
    file.close();
}

WorkWithFile::WorkWithFile() {
    char* dataOfFile;
    int size = 0;
    readFromFile("test.txt");
}
WorkWithFile::~WorkWithFile() {
    delete[] dataOfFile;
}

void WorkWithFile::writeStatInfoToFile(const char* outFile) {
    prepareTestFile(outFile);
    int k = 1;
    vector<pair<int ,int> > pair;
    pair.push_back({dataOfFile[0], 1});
    for (int i = 1; i < size; i++){
        bool check = false;
        for (int j = 0; j < k; j++){
            if (dataOfFile[i] == (char)pair.at(j).first){
                pair.at(j).second++;
                check = true;
            }
        }
        if (check == false){
            k++;
            pair.push_back({dataOfFile[i], 1});
        }
    }
    ofstream file(outFile, ios::app);
    for (int i = 0; i < k; i++){
        file << (char)pair.at(i).first << "\t" << pair.at(i).second << endl;
    }
    file.close();
}


//task2
char *convertDecToBin(int number){
    static char binNumb[32];
    memset(binNumb, 0x00, 32);

    for (int i = 0; i < 32; i++) {
        binNumb[i] = ((number & 1 << i)) ? 0x31 : 0x30;
    }
    return binNumb;
}


//task3
char *convertBinToHex(const char *binNum){
    static char hexNum[8];
    memset(hexNum, 0x00, 8);

    for (int i = 7; i >= 0; i--){
        int a = 0;
        for(int j = 0; j < 4; j++){
            if (binNum[i*4 + j] == '1'){
                a += pow(2,3-j); //nuzho bylo sdelat cikl, navernoe
                cout << pow(2,3-j) << "  " << a << endl;
            }
        }

        if (a < 10){
            hexNum[i] = '0' + a;
        }
        if (a >= 10)
            hexNum[i] = 'A' + a-10;
    }
    cout << hexNum;
    return hexNum;
}


//task4
void buildTree(int n){
    int b = 1;
    for (int i = 0; i < n; i++)
    {
        int k = n - i;
        for (int j = k; j > 0; j--)
            cout << " ";
        for (int m = b; m > 0; m--)
        {
            cout << "*";
        }
        b+=2;
        cout << endl;
    }
}


//task5
std::vector<std::pair<int, float> > averStr2DArray(const float *ar, int colCount, int rowCount)
{

    std::vector<std::pair<int, float> > vr(rowCount);
        for (int i = 0; i < rowCount; i++){
            float c = 0;
            for (int j = 0; j < colCount; j++){
                c += ar[i*colCount + j] / colCount;
            }
            vr.at(i)={i+1, c};
        }
    return vr;
}


//task6

/*struct Node  {
    Node* next;
    Node* prev;
    int nameNode;
    static int countNodes;   //    ???
};

class LinkedList {
    private :
        Node* Head;
        Node* Tail;
    public :
        LinkedList();
        ~LinkedList();

        void push_back(int nameNode);
        void writeToFileFromTail();
        void writeToFileFromHead();


//task7
        void insert(int nameNode, int pos);
};*/

LinkedList::LinkedList() {
    Node* Head = nullptr;
    Node* Tail = nullptr;
}
LinkedList::~LinkedList() {
    Node* temp = Tail;
    do{
        temp = temp->prev;
        delete[] temp->next;
    }while (Head != temp);
    delete[] temp;
}

void LinkedList::push_back(int nameNode) {
    Node* temp = new Node;
    if ((Head == nullptr) || (Tail == nullptr)){
        Head = temp;
        Tail = temp;
    }
    temp->nameNode = nameNode;
    temp->prev = Tail;
    Tail->next = temp;
    Tail = temp;
}
void LinkedList::writeToFileFromTail() {
    Node* temp = Tail;
    ofstream file("taskList1.txt");
    do{
        file << temp->nameNode;
        temp = temp->prev;
    }while(temp != Head);
    file << Head->nameNode;
    file.close();
}
void LinkedList::writeToFileFromHead() {
    Node* temp = Head;
    ofstream file("taskList2.txt");
    do{
        file << temp->nameNode;
        temp = temp->next;
    }while(temp != Tail);
    file << Tail->nameNode;
    file.close();
}



//task7
void LinkedList::insert(int nameNode, int position) {
    Node* temp = new Node;
    Node* cur = Head;
    if ((Head == nullptr) || (Tail == nullptr)){
        Head = temp;
        Tail = temp;
        cur = temp;
        cur->nameNode = nameNode;
    }
    else{
        for (int i = 0; i < position-1; i++){
            cur = cur->next;
        }
        Node* a;

        a = cur->next;
        cur->next = temp;
        temp->next = a;
        temp->prev = cur;
        temp->next->prev = temp;
        temp->nameNode = nameNode;
    }
}


//task8
/*	desription	:	добавления отметки по выбранному предмету
            input		:	subjName - название предмета, mark -- оценка
            output		:	0 - оценка добавлена, 1 - нет такого предмета
            author		:
            date		:
        */
int StudentInfo::addMark(const string& subjName, int mark){}
/*	desription	:	добавления отметки по выбранному предмету
    input		:	subjName - название предмета
    output		:	0 - предмет добавлен, 1 - такой предмет уже есть
    author		:
    date		:

*/
int StudentInfo::addSubj(const string& subjName){}
/*	desription	:	добавления нового предмета
    input		:	subjName - название предмета
    output		:	среднее значение оценки
    author		:
    date		:
*/
float StudentInfo::getAverMark(const string& subjName) {}
/*	desription	:	вычисления средней оценки по предметам
    input		:	subjName - название предмета
    output		:	среднее значение оценки
    author		:
    date		:
*/
void StudentInfo::printInfoStudent(){}
/*	desription	:	запись данных в файл формат файла
                        [Фамилия] [имя] : [номер билета]
                            [предмет 1]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
                            [предмет 2]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
    input		:	subjName - название предмета
    output		:	среднее значение оценки
    author		:
    date		:
*/
void StudentInfo::writeAllInfoToFile() {}

int main(){
//WorkWithFile a;
//a.writeStatInfoToFile("test1.txt");                       1
//cout << convertDecToBin(10);                              2
//convertBinToHex("11110000111100001010010110100111");      3
//buildTree(5);                                             4
//averStr2DArray(a, m, n);                                  5


/*LinkedList list;                                          6
    list.push_back(0);
    list.push_back(1);
    list.push_back(3);
    list.insert(2,2);                                       7
    list.writeToFileFromHead();
    list.writeToFileFromTail();
*/
    return 0;
}
