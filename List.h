#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <string>

class List{
private:

     typedef struct node{
        int data;
        int data2;
        int data3;
        //More strs than are often needed initialized to make sure spaces do not run out
        std::string str1;
        std::string str2;
        std::string str3;
        std::string str4;
        std::string str5;
        std::string str6;
        std::string str7;
        std::string str8;
        std::string str9;
        std::string str10;
        std::string str11;
        std::string str12;
        std::string str13;
        std::string str14;
        std::string str15;
        node*next;
    }* nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;


public:
    List();
    void UI();
    void ReadText(int skiplines);
    void starSearch();
    void genSearch(int varType);
    void PrintList();
    void DataEntry();
    void CheckOut();
    

};
#endif