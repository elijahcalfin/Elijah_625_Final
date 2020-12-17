#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "List.h"
using namespace std;

List::List()
{
    head = NULL;
    curr = NULL;
    temp = NULL;
}
void List::UI()
{
    int continuous = 0;
    int firsttime = 1;
    int intChoice;
    string uiChoice = "";
    while(continuous==0)
    {
        if(firsttime==1)
        {
            cout<<"You must have at least one .txt file entered into the database.\n";
            DataEntry();
        }
        if(firsttime==0)
        {
            cout<<"Enter [1] to continue or [X] to exit\n";
            cin>>uiChoice;
            if(uiChoice=="1")
            {
                cout<<"Continuing!\n";
                firsttime=3;
            }
            if(uiChoice=="X"||uiChoice=="x")
            {
                cout<<"Exiting...\n";
                continuous=1;
            }
        }
        else
        {
            cout<<"[9] Read in another .txt file [0] Check in or checkout a copy [1] Lookup by movie title\n[2] Lookup by starring actor [3] Lookup by director [4] Lookup by year released [X] Exit\n";
            cin>>uiChoice;
            if(uiChoice=="9")
            {
                DataEntry();
            }
            if(uiChoice=="0")
            {
                CheckOut(); 
            }
            if(uiChoice=="1"||uiChoice=="3"||uiChoice=="4")
            {
                istringstream ss(uiChoice);
                ss >> intChoice;
                genSearch(intChoice);
            }
            if(uiChoice=="2")
            {
                starSearch();
            }
            if(uiChoice=="X"||uiChoice=="x")
            {
                cout<<"Exiting...";
                continuous=1;
            }
            else
            {
                cout<<"Please enter a number from the given list.\n";
            }
            firsttime=0;
        }
        
    }
}
void List::starSearch()
{
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;
    cout<<"Please enter the name of the star: ";
    string searchStr;
    cin>>searchStr;
    string namebucket = "";
    string stringConv;
    size_t foundBuck = namebucket.find(searchStr);
    int convertInt3=0;
    int met = 0;
    while(curr != NULL && temp != NULL && curr->next !=NULL)
    {
        temp = curr;
        curr = curr->next;
        stringConv = curr->str4;
        stringstream convert(stringConv);
        convert>>convertInt3;
        if(curr->str4=="0")
        {
        }
        else
        {
            namebucket = namebucket+curr->str5+curr->str6+curr->str7+curr->str8+curr->str9+curr->str10+curr->str11+curr->str12;
        }
        foundBuck = namebucket.find(searchStr);
        if(curr==NULL)
        {
            delete delPtr;
        }
        else if(foundBuck!=std::string::npos)
        {
            cout<<curr->str1<<" "<<curr->str2<<" "<< curr->str3 <<" "<<curr->str4<<" "<<curr->str5<<" "<<curr->str6<<" "<<curr->str7<<" "<<curr->str8<<" "<<curr->str9<<" "<<curr->str10<<" "<<curr->str11<<" "<<curr->str12<<" "<<curr->str13<<" "<<curr->str14<<" "<<curr->str15<<"\n";
            delete delPtr;
            namebucket ="";
            if(met>=10)
            {
                int usrChoice=0;
                cout<<"[0] Show more [1] End results: ";
                cin>>usrChoice;
                if(usrChoice==0)
                {
                    met=1;
                }
                else if(usrChoice==1)
                {
                    curr=NULL;
                }
            }
            met++;

        }
        namebucket="";
    }
    if(met == 0)
    {
        cout<<"The search parameter was not found.\n";  
    }
}
void List::ReadText(int skiplines)
{
    nodePtr n = new node;
    std::ifstream file("videodb1.txt");
    std::string str;
    std::string word;
    int xCount = 1; 
    int skipcount = 1;
  
    while (std::getline(file, str))
    {
        for(int x = 0; x<=str.length(); x++)//runs for length of line, plus one more rotation to fetch last digit of checkout date if needed
        {
            if(skipcount<=skiplines && skipcount != 1 && skiplines <= skipcount)
            {
                if (str[x] == ' ' || x==str.length())//separates by spaces, OR condition is set in case there is no space at the end of a line
                {
                    if(xCount==1)
                    {
                        n->str1 = word;    
                    }
                    else if(xCount==2)
                    {
                        n->str2 = word;    
                    }
                    else if(xCount==3)
                    {
                        n->str3 = word;    
                    }
                    else if(xCount==4)
                    {
                        n->str4 = word;    
                    }
                    else if(xCount==5)
                    {
                        n->str5 = word;    
                    }
                    else if(xCount==6)
                    {
                        n->str6 = word;    
                    }
                    else if(xCount==7)
                    {
                        n->str7 = word;    
                    }
                    else if(xCount==8)
                    {
                        n->str8 = word;    
                    }
                    else if(xCount==9)
                    {
                        n->str9 = word;    
                    }
                    else if(xCount==10)
                    {
                        n->str10 = word;    
                    }
                    else if(xCount==11)
                    {
                        n->str11 = word;    
                    }
                    else if(xCount==12)
                    {
                        n->str12 = word;    
                    }
                    else if(xCount==13)
                    {
                        n->str13 = word;    
                    }
                    else if(xCount==14)
                    {
                        n->str14 = word;    
                    }
                    else if(xCount==15)
                    {
                        n->str15 = word;    
                    }
                    //cout<<"*"<<skiplines<<" "<<skipcount<<" ";
                    //cout<<word<<"\n";
                    word = "";
                    xCount = xCount+1;
                }
                //else if(skiplines <= skipcount && skipcount<0)  
                else
                {
                    word = word + str[x];
                }
            }
        }
        //cout<<"\n\n";
        n->next;
        skipcount = skipcount + 1;
        int xCount = 1;
        int x = 0;

    }
    if(head != NULL)
    {
        curr = head;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = n;
    }
    else
    {
        head = n;
    }
    xCount = 1;
    n->next = NULL;
}
void List::DataEntry()
{
    string headID;
    string searchID;
    string intoID;
    int transferID;
    int holdID;
    string whichTxt;
    cout<<"Please enter the name of the .txt file: ";
    cin>>whichTxt;
    int inList;
    ifstream cfile(whichTxt);
    string cstr;
    string headercount;
    int convertInt;
    int cxCount = 0; 
    int q = 1;
    while (std::getline(cfile, cstr)&&cxCount<1)
    {
        headercount = headercount +cstr[0];
        headercount = headercount +cstr[1];
        headID = headID +cstr[3];
        headID = headID +cstr[4];
        headID = headID +cstr[5];
        headID = headID +cstr[6];
        ++cxCount;
    }
    stringstream convert(headercount);
    convert>>convertInt;
    
    

    ++++convertInt;//to account for the first line containing header information and not film
    if (holdID > 0)
    {
        searchID = std::to_string(holdID);
        size_t findID = searchID.find(headID);
        if(findID!=std::string::npos)
        {
            inList = 1;    
        }
        else
        {
            inList = 0;
            searchID = searchID + headID;
            stringstream convert(searchID);
            convert>>holdID;
        }
            
    }
    else
    {
        stringstream convert(headID);
        convert>>transferID;
        holdID = transferID;
    }
    
    if(inList == 0)
    {
        while(convertInt > q)
        {
            ReadText(q);
            q = q+1;
        }
        cout<<"File read in!\n";
    }
    else
    {
        cout<<"That DB has already been imported.\n";
    }
}
void List::genSearch(int varType)
{
    int convertInt2;
    string stringConv;
    nodePtr delPtr = NULL;
    string searchStr="";
    cout<<"\nPlease enter what you are searching for: ";
    cin>>searchStr;
    temp = head;
    curr = head;
    int met = 0;
    string zeta="";
    size_t foundZeta = zeta.find(searchStr);
    while(curr != NULL && temp != NULL && curr->next !=NULL)
    {
        temp = curr;
        curr = curr->next;
        zeta = curr->str1;
        
        
        if(varType==1)
        {
            zeta = curr->str1;    
        }
        if(varType==3)
        {
            zeta = curr->str2;    
        }
        if(varType==4)
        {
            zeta = curr->str3;    
        }
        if(varType==5)
        {
            stringConv = curr->str4;
            stringstream convert(stringConv);
            convert>>convertInt2;
            //Full-Proofing for up to 8 stars...Maybe a problem if Quentin Tarantino makes The Hateful 9 
            if(convertInt2==0)
            {
                if(curr->str5=="in")
                {
                    delete delPtr;
                }
                else
                {
                    zeta = curr->str6;
                }
            }
            else if(convertInt2==1)
            {
                if(curr->str6=="in")
                {
                    delete delPtr;
                }
                else
                {
                    zeta = curr->str7;
                }
            }
            else if(convertInt2==2)
            {
                if(curr->str7=="in")
                {
                    delete delPtr;
                }
                else
                {
                    zeta = curr->str8;
                }
            }
            else if(convertInt2==3)
            {
                if(curr->str8=="in")
                {
                    delete delPtr;
                }
                else
                {
                    zeta = curr->str9;
                }
            }
            else if(convertInt2==4)
            {
                if(curr->str9=="in")
                {
                    delete delPtr;
                }
                else
                {
                    zeta = curr->str10;
                }
            }
            else if(convertInt2==5)
            {
                if(curr->str10=="in")
                {
                    delete delPtr;
                }
                else
                {
                    zeta = curr->str11;
                }
            }
            else if(convertInt2==6)
            {
                if(curr->str11=="in")
                {
                    delete delPtr;
                }
                else
                {
                    zeta = curr->str12;
                }
            }
            else if(convertInt2==7)
            {
                if(curr->str12=="in")
                {
                    delete delPtr;
                }
                else
                {
                    zeta = curr->str13;
                }
            }
            else if(convertInt2==8)
            {
                if(curr->str13=="in")
                {
                    delete delPtr;
                }
                else
                {
                    zeta = curr->str14;
                }
            }
        }
        foundZeta = zeta.find(searchStr);
        if(curr==NULL)
        {
            delete delPtr;
        }

        else if(zeta==searchStr||foundZeta!=std::string::npos)
        {

            cout<<curr->str1<<" "<<curr->str2<<" "<< curr->str3 <<" "<<curr->str4<<" "<<curr->str5<<" "<<curr->str6<<" "<<curr->str7<<" "<<curr->str8<<" "<<curr->str9<<" "<<curr->str10<<" "<<curr->str11<<" "<<curr->str12<<" "<<curr->str13<<" "<<curr->str14<<" "<<curr->str15<<"\n";
            delete delPtr;
            zeta ="";
            if(met>=10)
            {
                int usrChoice=0;
                cout<<"[0] Show more [1] End results: ";
                cin>>usrChoice;
                if(usrChoice==0)
                {
                    met=1;
                }
                else if(usrChoice==1)
                {
                    curr=NULL;
                }
            }
            met++;
        }
        zeta ="";

    }
    if(met == 0)
    {
        cout<<"The search parameter was not found.\n";  
    }
    cout<<"\n";
}
void List::CheckOut()
{
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;
    int fulfilled = 0;
    string checkoDate="";
    cout<<"What is the ID of the member? ";
    string memID;
    cin>>memID;
    cout<<"[1]Check out a title [2]Check in a title\n";
    int CheckOutChoice;
    cin>>CheckOutChoice;
    int convertInt=0;
    string searchStr="";
    string stringConv="";
    if(CheckOutChoice>2||CheckOutChoice<1)
    {
        cout<<"\nPlease enter either 1 or 2.";
    }
    else if(CheckOutChoice==1)
    {
        cout<<"Please enter the date(DD-MM-YY): ";
        cin>>checkoDate;
        cout<<"\nPlease enter the exact title you are searching for: ";
        cin>>searchStr;
        while (curr != NULL && temp != NULL && curr->next !=NULL&&fulfilled!=1)
        {
            while(curr != NULL && curr->str1 != searchStr && curr->next !=NULL)
            {
                temp = curr;
                curr = curr->next;
            }
            if(curr->str1==searchStr) 
            {
                stringConv = curr->str4;
                stringstream convert(stringConv);
                convert>>convertInt;
                if(convertInt==0)
                {
                    if(curr->str5=="out")
                    {

                    }
                    else
                    {
                        curr->str5="out";
                        curr->str6=memID;
                        curr->str7=checkoDate;
                        fulfilled=1;
                    }
                }
                if(convertInt==1)
                {
                    if(curr->str6=="out")
                    {

                    }
                    else
                    {
                        curr->str6="out";
                        curr->str7=memID;
                        curr->str8=checkoDate;
                        fulfilled=1;
                    }
                }
                if(convertInt==2)
                {
                    if(curr->str7=="out")
                    {

                    }
                    else
                    {
                        curr->str7="out";
                        curr->str8=memID;
                        curr->str9=checkoDate;
                        fulfilled=1;
                    }
                }
                if(convertInt==3)
                {
                    if(curr->str8=="out")
                    {
                        
                    }
                    else
                    {
                        curr->str8="out";
                        curr->str9=memID;
                        curr->str10=checkoDate;
                        fulfilled=1;
                    }
                }
                if(convertInt==4)
                {
                    if(curr->str9=="out")
                    {

                    }
                    else
                    {
                        curr->str9="out";
                        curr->str10=memID;
                        curr->str11=checkoDate;
                        fulfilled=1;
                    }
                }
                if(convertInt==5)
                {
                    if(curr->str10=="out")
                    {

                    }
                    else
                    {
                        curr->str10="out";
                        curr->str11=memID;
                        curr->str12=checkoDate;
                        fulfilled=1;
                    }
                }
                if(convertInt==6)
                {
                    if(curr->str11=="out")
                    {

                    }
                    else
                    {
                        curr->str11="out";
                        curr->str12=memID;
                        curr->str13=checkoDate;
                        fulfilled=1;
                    }
                }
                if(convertInt==7)
                {
                    if(curr->str12=="out")
                    {

                    }
                    else
                    {
                        curr->str12="out";
                        curr->str13=memID;
                        curr->str14=checkoDate;
                        fulfilled=1;
                    }
                }
                if(convertInt==8)
                {
                    if(curr->str13=="out")
                    {

                    }
                    else
                    {
                        curr->str13="out";
                        curr->str14=memID;
                        curr->str15=checkoDate;
                        fulfilled=1;
                    }
                }

                if(fulfilled!=1)
                {
                    curr = curr->next;
                    temp->next = curr;
                }
            }
        }
        if(fulfilled==1)
        {        
            cout <<"A copy has been checked out.\n";
        }
        else
        {
            cout<<searchStr<<" isn't in the database, or all copies are checked out.\n";
            delete delPtr;
        }
    }
    else if(CheckOutChoice==2)
    {
        cout<<"Please enter the exact title you are searching for: ";
        cin>>searchStr;
        while (curr != NULL && temp != NULL && curr->next !=NULL&&fulfilled!=1)
        {
            while(curr != NULL && curr->str1 != searchStr && curr->next !=NULL)
            {
                temp = curr;
                curr = curr->next;
            }
            if(curr->str1==searchStr) 
            {
                stringConv = curr->str4;
                stringstream convert(stringConv);
                convert>>convertInt;
                if(convertInt==0)
                {
                    if(curr->str5=="in")
                    {

                    }
                    else if(curr->str6==memID)
                    {
                        curr->str5="in";
                        curr->str7="";
                        fulfilled=1;
                    }
                }
                if(convertInt==1)
                {
                    if(curr->str6=="in")
                    {

                    }
                    else if(curr->str7==memID)
                    {
                        curr->str6="in";
                        curr->str7="";
                        curr->str8="";
                        fulfilled=1;
                    }
                }
                if(convertInt==2)
                {
                    if(curr->str7=="in")
                    {

                    }
                    else if(curr->str8==memID)
                    {
                        curr->str7="in";
                        curr->str8="";
                        curr->str9="";
                        fulfilled=1;
                    }
                }
                if(convertInt==3)
                {
                    if(curr->str8=="in")
                    {
                        
                    }
                    else if(curr->str9==memID)
                    {
                        curr->str8="in";
                        curr->str9="";
                        curr->str10="";
                        fulfilled=1;
                    }
                }
                if(convertInt==4)
                {
                    if(curr->str9=="in")
                    {

                    }
                    else if(curr->str10==memID)
                    {
                        curr->str9="in";
                        curr->str10="";
                        curr->str11="";
                        fulfilled=1;
                    }
                }
                if(convertInt==5)
                {
                    if(curr->str10=="in")
                    {

                    }
                    else if(curr->str11==memID)
                    {
                        curr->str10="in";
                        curr->str11="";
                        curr->str12="";
                        fulfilled=1;
                    }
                }
                if(convertInt==6)
                {
                    if(curr->str11=="in")
                    {

                    }
                    else if(curr->str12==memID)
                    {
                        curr->str11="in";
                        curr->str12="";
                        curr->str13="";
                        fulfilled=1;
                    }
                }
                if(convertInt==7)
                {
                    if(curr->str12=="in")
                    {

                    }
                    else if(curr->str13==memID)
                    {
                        curr->str12="in";
                        curr->str13="";
                        curr->str14="";
                        fulfilled=1;
                    }
                }
                if(convertInt==8)
                {
                    if(curr->str13=="in")
                    {

                    }
                    else if(curr->str14==memID)
                    {
                        curr->str13="in";
                        curr->str14="";
                        curr->str15="";
                        fulfilled=1;
                    }
                }

                if(fulfilled!=1)
                {
                    curr = curr->next;
                    temp->next = curr;
                }
            }
        }
        if(fulfilled==1)
        {        
            cout <<"The copy has been checked in.\n";
        }
        else
        {
            cout<<searchStr<<" isn't in the database, or no copy is checked in under that ID.";
            delete delPtr;
        }
    }
}
//Prints it all...
void List::PrintList()
{
    cout<<"\n";
    curr = head;
    while(curr != NULL)
    {
        cout << curr->str1 <<" " << curr->str2 <<" " << curr->str3 <<" " << curr->str4 <<" " << curr->str5 <<" " << curr->str6 <<" " << curr->str7 <<" " << curr->str8 <<" " << curr->str9 <<" " << curr->str10  << " " << curr->str11 <<" " << curr->str12 <<" "  << curr->str13 <<" "  << curr->str14 <<" " << curr->str15 << "\n";            
        curr = curr->next;
    }
}








