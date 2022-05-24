#ifndef TASKS_RK1_H
#define TASKS_RK1_H
#include <QList>
#include <tuple>
#include <list>
#include <map>
#include <string>
#include <iostream>

using namespace std;
//task1
class WorkWithFile {
    private :
        char* dataOfFile;
        void readFromFile(const char* fileName);	//������� ������ �� �����
        void prepareTestFile(const char* fileName);	//������� ��� �������� ��������� �����
        int size;

    public :
        WorkWithFile();
        ~WorkWithFile();

        void writeStatInfoToFile(const char* outFile);
};


//task2
char* convertDecToBin(int number);


//task3
char* convertBinToHex(const char* binNum);


//task4
void buildTree(int);


//task5
std::vector<std::pair<int/*����� ������*/, float /*������� ��������*/>> averStr2DArray(const float* ar, int colCount, int rowCount);


//task6
struct Node  {
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
};


//task8
class StudentInfo {
    private :
        std::tuple<string /*�������*/,string /*���*/,char* /*� ���� ������*/> info;
        std::map<string/*�������� ��������*/, std::pair<std::list<int> /*������ ������*/, float /*������� ������*/>> subjMark;
    public :
        /*	desription	:	���������� ������� �� ���������� ��������
            input		:	subjName - �������� ��������, mark -- ������
            output		:	0 - ������ ���������, 1 - ��� ������ ��������
            author		:
            date		:
        */
        int addMark(const string& subjName, int mark);
        /*	desription	:	���������� ������� �� ���������� ��������
            input		:	subjName - �������� ��������
            output		:	0 - ������� ��������, 1 - ����� ������� ��� ����
            author		:
            date		:

        */
        int addSubj(const string& subjName);
        /*	desription	:	���������� ������ ��������
            input		:	subjName - �������� ��������
            output		:	������� �������� ������
            author		:
            date		:
        */
        float getAverMark(const string& subjName);
        /*	desription	:	���������� ������� ������ �� ���������
            input		:	subjName - �������� ��������
            output		:	������� �������� ������
            author		:
            date		:
        */
        void printInfoStudent();
        /*	desription	:	������ ������ � ���� ������ �����
                                [�������] [���] : [����� ������]
                                    [������� 1]	:	[������ 1], [������ 2],... [������ N] -- [������� ��������]
                                    [������� 2]	:	[������ 1], [������ 2],... [������ N] -- [������� ��������]
            input		:	subjName - �������� ��������
            output		:	������� �������� ������
            author		:
            date		:
        */
        void writeAllInfoToFile();
};


#endif // TASKS_RK1_H
