#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include <cstdlib>
using namespace std;

bool checkForWord(string file,string keyword){
    fstream TheFile;
    TheFile.open(file, ios::in);
  unsigned int found = 0;
    if (TheFile.is_open())
    {
        string Line;

        while (getline(TheFile, Line)) {
            if (Line.find(keyword) != string::npos){
                   ++found;
            }
        }
      //cout << "the word " << keyword << " was found " << found << " times" << endl;
    }
    else
    {
     //  cout<<"there isnt such file"<<endl;
    }
      if(found>0){return true;}else{return false;}

  //  cout << "press enter to exit " << endl;
   // int c = getch();
}
int splitEmails(string file,vector<bool> &emailCheck){
    string endings[] = {"Yours Faithfully","Yours faithfully","Yours truly","Yours Truly","yours truly","Yours Truly"};
    fstream TheFile;
    //TheFile.open("C:/Users/cozilas/Desktop/hw10/ex2/GeorgeArab/emails/Hello.txt", ios::in);
    TheFile.open("./emails/database.txt", ios::in);
        string savingText= "";
        string Line;
        unsigned int found = 0;
        int emailCounter = 0;

        ofstream outfile ();
        while (getline(TheFile, Line)) {
                savingText+=Line;
                savingText+="\n";
                for(int i = 0;i<6;i++)
                {
                    if (Line.find(endings[i]) != string::npos)
                    {
                       ++found;
                        ofstream outfile ("./emails/email_"+ to_string(emailCounter)+".txt");
                        outfile<<savingText;
                        emailCheck.push_back(1);
                        savingText ="";
                        emailCounter++;
                        break;
                    }
                }
        }
        return emailCounter;
      //  cout<<savingText;
}
void whichEmails(vector<bool> &emailsCheck,string keyword){
        int counter = 0;

          for(int i = 0;i<emailsCheck.size();i++)
        {
            if(checkForWord("./emails/email_" +to_string(i)+".txt",keyword))
            {
                    counter++;
                   // cout<< i<<endl;
            }else{
            emailsCheck[i] = 0;
            }
        }
}
void reset(vector<bool>&group){
  for(int i = 0;i<group.size();i++)group[i] = true;
   cout<<"enter keyword you want you find : ";
}
void printEmailNumbers(vector<bool> &group){
    bool isThereEmails=false;
for(int i = 0 ;i<group.size();i++){
    if(group[i]){
               cout<<"----------------- email : "<<i<<"-------------------"<<endl;
            isThereEmails = true;
    }
}
if(!isThereEmails){cout<<"No emails with that keyword."<<endl<<"The program has been reset "<<endl<<endl<<"Try a new keyword : ";
                    reset(group);
}else{
    cout<<"Use the 'print' conmmand if you wish to print the above emails"<<endl<<"Use the 'reset' command if you wish to reset the program"<<endl;
            cout<<"enter word you want you find from these emails : "<<endl;
}

}
void printEmails(vector<bool> &group){
    bool isThereEmails=false;
for(int i = 0 ;i<group.size();i++){
    if(group[i]){
            cout<<"----------------- email : "<<i<<"-------------------"<<endl;
            ifstream file( "./emails/email_"+to_string(i)+".txt" ) ;
            cout << file.rdbuf() ;
            isThereEmails = true;
    }
}
}
int main(){
    string keyword;
    vector<bool> group;

    splitEmails("./emails/database.txt",group);

      //  cout<<"Use the 'print' conmmand if you wish to print the emails found"<<endl;
        cout<<"enter keyword you want you find : ";
    while(getline(cin,keyword))
    {

        if(keyword == "print"){
            printEmails(group);
        }else if(keyword == "reset"){
           reset(group);
        }
        else{
         whichEmails(group,keyword);
         system("cls");
         printEmailNumbers(group);
        }
    }
    return 0;
}
