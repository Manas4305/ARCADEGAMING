
//This is our project for SDF-II for semester-2
//a mini games combo project in c++


#include <iostream>
#include <cstdlib>
#include <time.h>
#include <bits/stdc++.h>
#include <string>                                       //header files
#include <math.h>
#include <windows.h>
#include <conio.h>

using namespace std;


class body{                     //the main class from which all the other classes are inherited
    public:

    int random(){
        //srand(time(0));
        int r;

        r=rand();
        return r;
    }

    void intro(){   //the first main screen of the game
        cout<<"***************************************************************************************************"<<endl;
        cout<<"                                WELCOME     TO    THE    ARCADE    ZONE                                         "<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
        cout<<"PRESS THE NUMBER TO CONTINUE"<<endl;
        cout<<"1. PLAY THE GAMES."<<endl;
        cout<<"2. CREDITS."<<endl;
        cout<<"3. EXIT."<<endl;
        cout<<"Your choice --> "<<endl;
    }

    void credits(){    //names of the project group members
        cout<<"***************************************************************************************************"<<endl;
        cout<<"                                            CREDITS                                                "<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
        cout<<"     BATCH-A1A               YEAR-1                   SEMESTER-2                 CAMPUS-JIIT-62    "<<endl<<endl;
        cout<<"                      This is our Project for SDF-II for the second semester                       "<<endl<<endl;
        cout<<"                      GROUP MEMBERS -->                                                            "<<endl<<endl;
        cout<<"                      1. MANAS RANJAN - 22102209                                                    "<<endl;
        cout<<"                      2. ANKIT KESARI - 22102204                                 "<<endl;
        cout<<"                      3. SAUMYA SACHDEVA - 22802010                                          "<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
    }

    void main_exit(){                  //end screen of the game
        cout<<"***************************************************************************************************"<<endl;
        cout<<"                                   THANKS FOR PLAYING                                        "<<endl;
        cout<<"***************************************************************************************************"<<endl<<endl;
        exit(0);
    }

    void main_menu(){ 

                            //main menu screen of the game
        cout<<"---------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                        MAIN MENU                                                  "<<endl;
        cout<<"---------------------------------------------------------------------------------------------------"<<endl<<endl;
        cout<<"PRESS THE NUMBER TO CONTINUE"<<endl;
        cout<<"1. PLAY ROCK-PAPER-SCISSOR"<<endl;
        cout<<"2. THE LOTTERY"<<endl;
        cout<<"3. MATH-O-METER"<<endl;
        cout<<"5. EXIT"<<endl;
        cout<<"Your choice --> "<<endl;
    }
};


class RPS:public body{         //the class for the game "rock-paper-scissor"

    public:

    string comp;
    string you;
    int compPoint=0;
    int youPoint=0;

    void getCOMP(){
        int num= 1+(random()%3);
        if(num==1)
            comp='r';
        else if(num==2)
            comp='p';
        else if(num==3)
            comp='s';
    }

    void menuRPS(){                         //menu for "rock-paper-scissor"
    cout << ("******************************************************************************\n");
    cout << ("                           ROCK PAPER SCISSORS \n                             \n");
    cout << ("******************************************************************************\n");
    cout << ("* 1. Play the game *\n");
    cout << ("* 2. About the game *\n");
    cout << ("* 3. Exit *\n");
    cout << ("******************************************************************************\n");
    cout << "ENTER YOUR CHOICE : \n";
    }

    void AboutRPS(){                             //about the game "rock-paper-scissor"
    cout << ("*******************************************************************************\n");
    cout << ("                               ABOUT THE GAME  \n");
    cout << ("*******************************************************************************\n");
    cout << ("* Rock-Paper-Scissors *\n");
    cout << ("* Rock paper scissors is and intransitive hand game,usually played between *\n");
    cout << ("* two people, in which player simultaneously forms one of three shaped with an  *\n");
    cout << ("* outstretched hand.These shapes are rock,paper and scissors. *\n");
    cout << ("* This game was originated in China and later imported to Japan. *\n");
    cout << ("* *\n");
    cout << ("*******************************************************************************\n\n\n");
    }

    void getYou(){                     //function for user choice
    while( you!="r" && you!="p" && you!="s" && you!="R" && you!="P" && you!="S"){
        cout<<"**********First to 5 points win***************"<<endl<<endl;
        cout<<"YOUR CHOICE -->"<<endl;
        cout<<"Enter 'r' for rock"<<endl;
        cout<<"Enter 'p' for paper"<<endl;
        cout<<"Enter 's' for scissor"<<endl;
        cin>>you;
      }
    }

    void calcGame(){             //function for computer choice
        if( ( you=="r" && comp=="s") || ( you=="R" && comp=="S") ){
            cout<<"You won this point"<<endl;
            youPoint++;
        }
        else if( (you=="s" && comp=="p") || (you=="S" && comp=="p") ){
            cout<<"You won this point"<<endl;
            youPoint++;
        }
        else if( (you=="p" && comp=="r") || (you=="P" && comp=="r") ){
            cout<<"You won this point"<<endl;
            youPoint++;
        }
        else if( (you=="r" && comp=="p") || (you=="R" && comp=="p") ){
            cout<<"\nComputer won this point\n"<<endl;
            compPoint++;
        }
        else if( (you=="s" && comp=="r") || (you=="S" && comp=="r") ){
            cout<<"\nComputer won this point\n"<<endl;
            compPoint++;
        }
        else if( (you=="p" && comp=="s") || (you=="P" && comp=="s") ){
            cout<<"\nComputer won this point\n"<<endl;
            compPoint++;
        }
    }

    void checkWin(){                 //function for checking the game
        you="";
        if(youPoint==5){
            cout<<"********************CONGRATULATIONS!!!!!! YOU WON THE GAME*************************"<<endl<<endl;
            exit(0);
        }
        else if(compPoint==5){
            cout<<"*********************YOU LOST THE GAME . BETTER LUCK NEXT TIME************************"<<endl<<endl;
            exit(0);
        }
    }

    void details(){                  //function to show the points
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"Your choice -> "<<you<<endl<<endl;
        cout<<"Computer choice -> "<<comp<<endl<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"your points -> "<<youPoint<<endl<<endl;
        cout<<"Computer points -> "<<compPoint<<endl<<endl;
         cout<<endl<<" Thanks for Playing "<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;



    }

    int workRPS(){             //working function for the game
        int mainrps;
        MAINRPS:
            menuRPS();
            cin>>mainrps;
            system("cls");
            if(mainrps==1){
                while( youPoint!=5 || compPoint!=5 ){
                getCOMP();
                getYou();
                calcGame();
                details();
                checkWin();
                
                }
            }
            else if(mainrps==2){
                AboutRPS();
                goto MAINRPS;
            }
            else if(mainrps==3){
                return 1;
            }
            else{
                cout<<"\n\nThere is no choice for this number . You may have did it by mistake . Please try again !!!\n\n";
                goto MAINRPS;
            }
    }
};


class lottery:public body{          //class for the game "lottery"

public:

    int n,*arr,lott,yourNum,flag;

    ~lottery(){
        delete arr;
    }

    void inDET(){                         //function to enter the details
        cout<<"ENTER THE NUMBER OF PARTICIPANTS(MAX 5) : ";
        cin>>n;
        cout<<endl<<endl;
        if(n>5 || n<1){
            cout<<"\nXXXX Input a valid value for number of participants.   XXXX\n\n\n";
            inDET();
        }
        else{
            arr=new int[n];
            cout<<"You can choose the number for lottery between 1-20 "<<endl<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<"Enter the lottery number for participant "<<i+1<<" : ";
                cin>>arr[i];
                if(arr[i]>20||arr[i]<0)
                cout<<"WARNING...NO CHANCE OF WINNING"<<endl;
        
            }
        }
    }

    void menuLott(){             //menu for the game
    cout << ("******************************************************************************\n");
    cout << ("               CHECK YOUR LUCK WITH THE LOTTERY GAME *\n");
    cout << ("******************************************************************************\n");
    cout << ("* 1. Play the game *\n");
    cout << ("* 2. About the game *\n");
    cout << ("* 3. Exit *\n");
    cout << ("******************************************************************************\n");
    cout << "ENTER YOUR CHOICE : \n";
    }

    void AboutLott(){                   //about the game
    cout << ("*******************************************************************************\n");
    cout << ("                            ABOUT THE GAME  \n");
    cout << ("*******************************************************************************\n");
    cout << ("* The Lottery Game *\n");
    cout << ("* This game is a game of luck, where you choose a number  *\n");
    cout << ("* and if the chosen number is the same as the lottery     *\n");
    cout << ("* number you will win. The number of participants can be *\n");
    cout << ("* one or more .                                          *\n");
    cout << ("* *\n");
    cout << ("*******************************************************************************\n\n\n");
    }

    void lottNum(){           //function to generate lottery winning number
        lott=1+(random()%20);
    }

    void checkLott(){            //function to check the win condition
        for(int i=0;i<n;i++){
            if(arr[i]==lott){
                flag=1;
                yourNum=i+1;
                break;
            }
            else
                flag=0;
        }
    }

    void print(){                           //function to tell the results
        cout<<"**********************THE RESULTS ARE HERE******************"<<endl<<endl;
        for(int i=0;i<n;i++){
            cout<<"The number choosen by participant "<<i+1<<" is "<<arr[i]<<endl;
        }
        cout<<endl<<"THE LOTTERY NUMBER IS "<<lott<<endl<<endl;
        if(flag==1){
            cout<<"**********CONGRATULATIONS PARTICPANT "<<yourNum<<" has won the lottery*******************"<<endl<<endl;
        }
        else if(flag==0){
            cout<<"*************OOPS ! BETTER LUCK NEXT TIME**************************"<<endl<<endl;
        }
    }

    int workLott(){                     //working function for the game
        int mainlott;
        MAINLOTT:
        menuLott();
        cin>>mainlott;
        system("cls");
        if(mainlott==1){
            inDET();
            lottNum();
            checkLott();
            print();
             cout<<endl<<" Thanks for Playing";
        }
        else if(mainlott==2){
            AboutLott();
            goto MAINLOTT;
        }
        else if(mainlott==3){
            return 1;
        }
        else{
            cout<<"\n\nThere is no choice for this number . You may have did it by mistake . Please try again !!!\n\n";
            goto MAINLOTT;
        }
    }
};


class math:public body{                   //class for the game "math-o-meter"

public:

    int q,a,List[10],temp1=0,i,point=0;
    string Q,A;

    void ques(){                   //function to generate questions in random order
        q=1+(random()%10);
    }

    void Ques(){                   //function to check no question repeats
        while(List[q]==-1){
            q=1+(random()%10);
        }
    }

    void menumath(){              //menu for the game
    cout << ("******************************************************************************\n");
    cout << ("                              MATH-O-METER \n");
    cout << ("******************************************************************************\n");
    cout << ("* 1. Play the game *\n");
    cout << ("* 2. About the game *\n");
    cout << ("* 3. Exit *\n");
    cout << ("******************************************************************************\n");
    cout << "ENTER YOUR CHOICE : \n";
    }

    void Aboutmath(){                //about the game
    cout << ("*******************************************************************************\n");
    cout << ("                              ABOUT THE GAME \n");
    cout << ("*******************************************************************************\n");
    cout << ("* The Math-o-Meter *\n");
    cout << ("* This game is a simple maths game where you will be     *\n");
    cout << ("* asked simple maths school level problems and you have  *\n");
    cout << ("* to answer them in least possible time . you will be    *\n");
    cout << ("* awarded points for every correct answer.               *\n");
    cout << ("* *\n");
    cout << ("*******************************************************************************\n\n\n");
    }

    void qlist(){           //function containing the list of questions
        if(q==1){
            cout<<"--> What is cos(0)*cos(1)*cos(2).....cos(179)*cos(180)\n"<<endl<<endl;
            List[q]=-1;
            cout<<"Your answer --> ";
            cin>>A;
        }
        else if(q==2){
            cout<<"--> 3 = 18\n    4 = 32\n    5 = 5=\n    6 = 72\n    7 = ?\n"<<endl;
            List[q]=-1;
            cout<<"Your answer --> ";
            cin>>A;
        }
        else if(q==3){
            cout<<"--> Find the missing number\n\n22,21,23,22,24,23,__\n"<<endl;
            List[q]=-1;
            cout<<"Your answer --> ";
            cin>>A;
        }
        else if(q==4){
            cout<<"--> You are a point A. You go 1m North then 5m East then\n2m North then 1m West. At what distance are you from A?\n"<<endl;
            List[q]=-1;
            cout<<"Your answer --> ";
            cin>>A;
        }
        else if(q==5){
            cout<<"--> What is the smallest perfect number?\n\nHint : A perfect number is a positive integer that is equal to the \nthe sum of its proper divisors.\n"<<endl;
            List[q]=-1;
            cout<<"Your answer --> ";
            cin>>A;
        }
        else if(q==6){
            cout<<"--> There are 50 dogs signed up for a dog show. There are 36 \nmore small dogs than large dogs,how many smalls dogs are there?\n"<<endl;
            List[q]=-1;
            cout<<"Your answer --> ";

            cin>>A;
        }
        else if(q==7){
            cout<<"--> There is a 3-digit number where the first and third digit is same\nbut the second digit is 4 times the first digit\nand third digit if 3 less than the second digit?\n"<<endl;
            List[q]=-1;
            cout<<"Your answer --> ";
            cin>>A;
        }
        else if(q==8){
            cout<<"--> Find the missing number\n\n1,4,9,16,25,__,49\n"<<endl;
            List[q]=-1;
            cout<<"Your answer --> ";
            cin>>A;
        }
        else if(q==9){
            cout<<"--> Solve : -15+(-5x)=0\n"<<endl;
            List[q]=-1;
            cout<<"Your answer --> ";
            cin>>A;
        }
        else if(q==10){
            cout<<"--> Find the next number in sequence\n36,34,30,28,24,__\n"<<endl;
            List[q]=-1;
            cout<<"Your answer --> ";
            cin>>A;
        }
    }

    void alist(){             //function containing the list of answers
        if(q==1){
            Q="0";
        }
        else if(q==2){
            Q="98";
        }
        else if(q==3){
            Q="25";
        }
        else if(q==4){
            Q="5";
        }
        else if(q==5){
            Q="6";
        }
        else if(q==6){
            Q="43";
        }
        else if(q==7){
            Q="141";
        }
        else if(q==8){
            Q="36";
        }
        else if(q==9){
            Q="-3";
        }
        else if(q==10){
            Q="22";
        }
    }

    void checkans(){         //function to check the correctness of answer
        if(Q==A){
            point++;
            cout<<"Your answer is correct"<<endl<<endl;
        }
        else
            cout<<"You are incorrect"<<endl<<endl;
    }

    void dispP(){
        cout<<"Your total points are : "<<point<<endl<<endl;
        if(point>=8)
            cout<<"Congratulations ! Your performance was good ";
        else if(point>=5)
            cout<<"You did it good but you have to practice more";
        else
            cout<<"Your performance was not good . Go study maths";
    }

    int workMath(){              //working function for the game
    int mainmath;
    MAINMATH:
        menumath();
        cin>>mainmath;
        system("cls");
        if(mainmath==1){
            for(int i=0;i<10;i++){
            ques();
            Ques();
            qlist();
            alist();
            checkans();
            }
            dispP();
            cout<<endl<<" Thanks for Playing";
        }
        else if(mainmath==2){
            Aboutmath();
            goto MAINMATH;
        }
        else if(mainmath==3){
            return 1;
        }
        else{
            cout<<"\n\nThere is no choice for this number . You may have did it by mistake . Please try again !!!\n\n";
            goto MAINMATH;
        }
    }
};


int main(){    //main() function

  int choice1,choice2,Temp;
  body b;

  RPS r;
  math m;
  lottery l;
  MAINMENU:         //main menu label
      b.intro();                     //game screening starts here
      cin>>choice1;
      system("cls");
      if(choice1==3)              //choice for exiting
        b.main_exit();
      else if(choice1==2){                  //choice for credits
        b.credits();
        goto MAINMENU;
      }
      else if(choice1==1){                   //choice to play games
        SUBMENU:
            b.main_menu();
            cin>>choice2;
            system("cls");
            if(choice2==5){                              //exiting the sub menu
                goto MAINMENU;
            }
            else if(choice2==1){                        //playing rock-paper-scissor
                Temp=r.workRPS();
                if(Temp==1)
                    goto SUBMENU;
            }
            else if(choice2==2){                             //playing lottery game
                Temp=l.workLott();
                if(Temp==1)
                    goto SUBMENU;
            }
            else if(choice2==3){                             //playing math-o-meter
                Temp=m.workMath();
                if(Temp==1)
                    goto SUBMENU;
            }
            else{
                cout<<"\n\nThere is no choice for this number . You may have did it by mistake . Please try again !!!\n\n";
                goto SUBMENU;
            }
      }
      else{
            cout<<"\n\nThere is no choice for this number . You may have did it by mistake . Please try again !!!\n\n";
            goto MAINMENU;
        }

    return 0;

}
