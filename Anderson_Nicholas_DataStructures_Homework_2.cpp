/* Homework 2 Nicholas Anderson */

#include <iostream>
#include <stdio.h>
using namespace std;
int SLLSize = 0;
int DLLSize = 0;
class SLLNode{
    public:
        SLLNode()
        {
            next = 0;
        }
        SLLNode(char i, SLLNode *in = 0)
        {
            info = i; next = in;
        }
        char info;
        SLLNode *next;
};
class DLLNode{
    public:
        DLLNode()
        {
            next = 0;
            previous = 0;
        }
        char info;
        DLLNode *next;
        DLLNode *previous;
};
SLLNode *SLLhead=0;
SLLNode *SLLtail=0;
DLLNode *DLLhead=0;
DLLNode *DLLtail=0;
int Operations(int);
int menu();
int SizeCheck(int, int);
int main()
{
    int option = menu();
}
int menu()
{
    int option;
    cout << "M E N U" << endl << endl;
    cout << "SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)" <<endl<<"DLL: IH(6), IT(7), DH(8), DT(9) SD(10), PD(11)"<<endl<<"Exit Program (12)"<<endl<<endl<<"Please select an option"<<endl;
    cin >> option;
    Operations(option);
    return 0;
}
int Operations(int option)
{
    bool deletedtail = false;
    if(option == 12)
    {
        return 0; //Ends Operation
    }
    else if(option < 6) //Single Linked List Operations
    {
        int code = 0;
        int check = SizeCheck(SLLSize, code);
        if(option >1)
        {
            if(check == 0)
            {
                cout << "There is nothing in the Single Linked List" << endl;
                menu();
            } 
            else if(option == 2) //Delete Head SLL WORKING 
            {
                SLLNode *tmpDHSL;
                tmpDHSL = new SLLNode();
                tmpDHSL = SLLhead;
                SLLhead = SLLhead->next;
                delete tmpDHSL;
                SLLSize-=1;
                check = SizeCheck(SLLSize, code);
                menu();
            }
            else if(option == 3) //Delete Tail SLL WORKING
            {
                SLLNode *tmpDTSL;
                tmpDTSL = new SLLNode();
                if(SLLSize >1)
                {
                    for(tmpDTSL = SLLhead; tmpDTSL->next !=SLLtail;tmpDTSL = tmpDTSL->next)
                    {

                    } 
                    deletedtail = true;
                    SLLtail = tmpDTSL;
                    tmpDTSL = tmpDTSL->next;
                    delete tmpDTSL;
                    SLLtail->next = 0;
                    SLLSize-=1;
                    check = SizeCheck(SLLSize, code);
                }
                else{
                    delete SLLhead;
                    SLLSize-=1;
                    check = SizeCheck(SLLSize, code);
                }
            menu();
            }
            else if(option == 4) //Search & Delete SLL WORKING
            {
                SLLNode *tmpSDSL;
                tmpSDSL = SLLhead;
                char input;
                cout <<"What character would you like to delete"<<endl;
                scanf(" %c", &input);
                for(tmpSDSL = SLLhead;tmpSDSL->next !=0 && tmpSDSL->info != input;tmpSDSL = tmpSDSL->next)
                {}
                SLLNode *next;
                next = tmpSDSL->next;         
                if(tmpSDSL->info == input)
                {
                    if(tmpSDSL->next == 0) //Input is tail
                    {
                        if(SLLSize > 1)
                        {
                            for(tmpSDSL = SLLhead;tmpSDSL->next !=SLLtail;tmpSDSL= tmpSDSL->next){}
                            SLLtail = tmpSDSL;
                            tmpSDSL = tmpSDSL->next;
                            delete tmpSDSL;
                            SLLtail->next = 0;
                        }
                        else{
                            delete SLLhead;
                        }
                    }
                    else if(tmpSDSL->info == SLLhead->info) //Input is head
                    {
                        SLLhead = SLLhead->next;
                        delete tmpSDSL;
                    }
                    else
                    {
                        SLLNode *tmpSDSL2;
                        for(tmpSDSL2= SLLhead; tmpSDSL2->next->info!=input; tmpSDSL2 = tmpSDSL2->next){}
                        tmpSDSL2->next = next;
                        delete tmpSDSL;
                    }
                SLLSize-=1;
                check = SizeCheck(SLLSize, code);
                }
                else{
                    cout <<"The search has failed"<<endl;
                }
                menu();
            }
            else if(option == 5) //Print SLL WORKING
            {
                SLLNode *tmpPRNTSL;
                //tmpPRNTSL = new SLLNode();
                
                cout << "The current Single Linked List is: "<<endl;
                tmpPRNTSL = SLLhead;
                if(SLLSize == 1)
                {
                    cout <<SLLhead->info << " ";
                }
                else
                {
                    while(tmpPRNTSL->next!=0)
                    {
                        cout <<tmpPRNTSL->info<< " ";
                        tmpPRNTSL = tmpPRNTSL->next;
                    }
                    cout <<tmpPRNTSL->info<<" "; //To print the tail
                }
                cout <<endl <<endl;
                menu();
            }
        }
        else if(option == 1) //Insert SLL Tail WORKING
        {
            SLLNode *tmpINSLT;
            tmpINSLT = new SLLNode();
            cout << "Choose a value to insert into SLL tail"<<endl;
            scanf("%s", &tmpINSLT->info);
            SLLSize++;
            check = SizeCheck(SLLSize, code);
            if (check == 1)
            {
                tmpINSLT->next = 0;
                SLLhead = tmpINSLT;
                SLLtail = tmpINSLT;
            }
            else
            {
                SLLtail->next = tmpINSLT;
                SLLtail = tmpINSLT;
                SLLtail->next = 0;
            }
            menu();
        }
        else if(option == 0) //Insert SLL Head WORKING
        {
            SLLNode *tmpINSLH;
            tmpINSLH = new SLLNode();
            cout <<"Choose a value to insert into SLL head"<<endl;
            scanf("%s", &tmpINSLH->info);
            SLLSize++;
            check = SizeCheck(SLLSize, code);
            if (check == 1)
            {
                tmpINSLH->next=0;
                SLLhead = tmpINSLH;
                SLLtail = tmpINSLH;
            }
            else
            {
                tmpINSLH->next = SLLhead;
                SLLhead = tmpINSLH;
            }
            menu();
        }
    }
    else //Double Linked List
    {
        int code = 1;
        int check = SizeCheck(DLLSize, code);
        if(option > 7)
        {
            if (check == 0)
            {
                cout << "There is nothing in the Double Linked List"<<endl;
                menu();
            }
            else if(option == 8 || option == 9) //Delete operations
            {
                if(DLLSize == 1)
                {
                    delete DLLhead;
                }
                else
                {
                    if(option == 8)
                    {
                        DLLNode *tmpDHDL;
                        DLLhead = DLLhead->next;
                        delete DLLhead->previous;
                        DLLhead->previous = 0;
                    }
                    if(option == 9)
                    {
                        DLLNode *tmpDTDL;
                        DLLtail = DLLtail->previous;
                        delete DLLtail->next;
                        DLLtail->next = 0;
                    }
                }
                DLLSize--;
                check = SizeCheck(DLLSize, code);
                menu();
            }
            else if(option == 10)
                {
                    DLLNode *tmpDTSD;
                    char input;
                    cout<<"What value would you like to remove? "<<endl;
                    scanf(" %c", &input);
                    for(tmpDTSD = DLLhead; tmpDTSD->info!=input && tmpDTSD->next!=0; tmpDTSD=tmpDTSD->next){}
                    if(tmpDTSD->info == input)
                    {
                        if(DLLSize == 1)
                        {
                            delete DLLhead;
                        }
                        else if(tmpDTSD->next == 0)//Input is tail
                        {
                            DLLtail = tmpDTSD->previous;
                            delete tmpDTSD;
                            DLLtail->next = 0;
                        }
                        else if(tmpDTSD->previous == 0)//Input is head
                        {
                            DLLhead = tmpDTSD->next;
                            delete tmpDTSD;
                            DLLhead->previous = 0;
                        }
                        else
                        {
                            DLLNode *prev;
                            DLLNode *next;
                            prev = tmpDTSD->previous;
                            next = tmpDTSD->next;
                            prev->next = next;
                            delete tmpDTSD;
                        }
                        DLLSize--;
                        check = SizeCheck(DLLSize, code);
                    }
                    else{
                        cout << "Search has failed"<<endl;
                    }
                    menu();
                }
            else//Print DLL
            {
                DLLNode *tmpPRNTDL;
                cout << "The current Double Linked List is: "<<endl;
                tmpPRNTDL = DLLhead;
                if(DLLSize == 1)
                {
                    cout <<DLLhead->info << " ";
                }
                else
                {
                    while(tmpPRNTDL->next!=0)
                    {
                        cout <<tmpPRNTDL->info<< " ";
                        tmpPRNTDL = tmpPRNTDL->next;
                    }
                    cout <<tmpPRNTDL->info<<" "; //To print the tail
                }
                cout <<endl <<endl;
                menu();
            }
        }
        else if(option == 6)//Insert DLL head
        {
            DLLNode *tmpINDLH;
            tmpINDLH = new DLLNode();
            cout <<"Chose a value to insert into DLL head"<<endl;
            scanf("%s", &tmpINDLH->info);
            DLLSize++;
            check = SizeCheck(DLLSize, code);
            if(check==1)
            {
                tmpINDLH->next=0;
                tmpINDLH->previous = 0;
                DLLhead = tmpINDLH;
                DLLtail = tmpINDLH;
            }
            else
            {
                tmpINDLH->next = DLLhead;
                DLLhead->previous = tmpINDLH;
                DLLhead = tmpINDLH;
                DLLhead->previous = 0;
            }
            menu();
        }
        else if(option == 7)//Insert DLL tail
        {
            DLLNode *tmpINDLT;
            tmpINDLT = new DLLNode();
            cout << "Choose a value to insert into DLL tail"<<endl;
            scanf("%s", &tmpINDLT->info);
            DLLSize++;
            check = SizeCheck(DLLSize, code);
            if (check == 1)
            {
                tmpINDLT->next = 0;
                tmpINDLT->previous = 0;
                DLLhead = tmpINDLT;
                DLLtail = tmpINDLT;
            }
            else
            {
                tmpINDLT->previous = DLLtail;
                DLLtail->next = tmpINDLT;
                DLLtail = tmpINDLT;
                DLLtail->next = 0;
            }
            menu();
        }   
    }
    return 0;
}
int SizeCheck(int size, int code)
{
    if (size == 0)
    {
        if(code == 0)
        {
            SLLhead = 0;
            SLLtail = 0;
        }
        else if(code == 1)
        {
            DLLhead = 0;
            DLLtail = 0;
        }
        return 0;
    }
    if (size == 1)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
