#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <fstream>


using namespace std;
int main() {
  ofstream dataOut;
  ifstream infile;
  int bet, credit, hitStay;
  int game;
  int userCard1,userCard2, userCard3, dealerCard1, dealerCard2, dealerCard3, userSum, dealserSum;
  char ace, king, queen,jack,userCard3thing;
  bool hitStayflag;
  bool creditFlag;
  bool betFlag;
  bool hitTester;
  int winner;
  int creditAdder;
  char dealerCard1check;
  string gameHistory;


  betFlag=true;
  creditFlag=true;
  hitTester=true;


  ace='A';
  king='K';
  queen='Q';
  jack='J';

 
  
  
  cout<<"welcome to black jack"<<endl;
do
{ 
  
    

    cout<<"press (1) to play"<<endl<<"press (2) to view game history"<<endl<<"Press (3) to end the game"<<endl;
    cin>>game;
  
  
  switch(game){
      case 1:
      hitStayflag=true;
      //opens a text file to store game history
      infile.open("SatterleeHisttory.txt");
      if(infile.is_open())
      {
        dataOut.open("SatterleeHisttory.txt",fstream::app);
      }
      else {
        dataOut.open("SatterleeHisttory.txt");
        dataOut<<"Card 1"<<setw(20)<<"Card 2"<<setw(20)<<"Card 3"<<setw(20)<<"Bet"<<setw(20)<<"Dealer"<<setw(20)<<"W/L"<<setw(20)<<"Balance"<<endl;
      }
      
     
      if (creditFlag==true){
      cout<<"Please type how much money you have you have rember you have to have more the 10$ to play."<<endl;
      cin>>credit;
      creditFlag=false;
      }
       else
      {
        cout<< "Your cridit as of right now is "<<credit<<endl;
      }
      //user does not have enough credits(they broke)
      while(credit<10){
      if(credit<10)
      {
        cout<<"You do not have enough credits to play the game\npress (1) to add more money \npress (2) to quit"<<endl;
        cin>>creditAdder;
      }
        
       if(creditAdder==1){
          cout<<"Please enter how much money you will like to add"<<endl;
          cin>>creditAdder;
          credit=credit+creditAdder;
          cout<<"Your new blance is "<<credit<<"$"<<endl;
        }
        else if(creditAdder==2)
        {
          cout<<"Thank you for using this program"<<endl;
          return 0;
        }
        else 
        {
          {
            cout<<"Your input was an invaild option please press 1 or 2"<<endl;
          }
        }
      }
        
       

        
      
     
      while(betFlag== true){
      cout<<"Please type how much money you are going to place for a bet."<<endl<<" remember you can only place minimum of 10$ and a maximum of 150$ "<<endl;
      cin>>bet;
      
      if (bet<10)//user did not read insuctions
        {
          cout<<"Your bet needs to be over 10$, Please increase your ammount"<<endl;
          betFlag=true;
        }
        else if(bet>150)
        {
          cout<<" Your bet is to high, Please enter an amount that is lower then 150$ "<<endl;
          betFlag=true;
        }
        else if(credit<bet)
        {
          cout<<"Your bet excceds the ammount of money you have, please lower your bet"<<endl;
          betFlag=true;
        }
      
       else 
       {betFlag=false;}
      }
       
      //detrimins how much money you bet 
      credit=credit-bet;
      //math to detrin how money you will recive if you win
        winner=bet*2;
    
      //starts random numbers
      srand(time(NULL));

      //stores randoms numbers to cards
      //userCard1=rand()%13+1;
      dealerCard1=rand()%13+1;
      userCard2=rand()%13+1;
      dealerCard2=rand()%13+1;
      userCard1=rand()%13+1;
    
      


      //detringing what the users first card is 
        if(userCard1==1){
          userCard1=2;
          cout<<"your first card is "<<userCard1<<endl;
          dataOut<<setw(3)<<userCard1;
        }
        else if(userCard1==2){
          userCard1=3;
          cout<<"your first card is "<<userCard1<<endl;
          dataOut<<setw(3)<<userCard1;
        }
        else if(userCard1==3){
          userCard1=4;
          cout<<"your first card is "<<userCard1<<endl;
          dataOut<<setw(3)<<userCard1;
        }
        else if(userCard1==4){
          userCard1=5;
          cout<<"your first card is "<<userCard1<<endl;
          dataOut<<setw(3)<<userCard1;
        }
        else if(userCard1==5){
          userCard1=6;
          cout<<"your first card is "<<userCard1<<endl;
          dataOut<<setw(3)<<userCard1;
        }
        else if(userCard1==6){
          userCard1=7;
          cout<<"your first card is "<<userCard1<<endl;
          dataOut<<setw(3)<<userCard1;
        }
        else if(userCard1==7){
          userCard1=8;
          cout<<"your first card is "<<userCard1<<endl;
          dataOut<<setw(3)<<userCard1;
        }
        else if(userCard1==8){
          userCard1=9;
          cout<<"your first card is "<<userCard1<<endl;
          dataOut<<setw(3)<<userCard1;
        }
        else if(userCard1==9){
          userCard1=10;
          cout<<"your first card is "<<userCard1<<endl;
          dataOut<<setw(3)<<userCard1;
        }
        else if (userCard1==10){
          userCard1=10;
          cout<<"your first card is an "<<jack<<endl;
          dataOut<<setw(3)<<jack;
        }
          else if(userCard1==11){
            userCard1=10;
            cout<<"your first card is an "<<queen<<endl;
            dataOut<<setw(3)<<queen;
          }
          else if (userCard1==12){
            userCard1=10;
            cout<<"your first card is an "<<king<<endl;
            dataOut<<setw(3)<<king;
          }
        else if(userCard1==13){
          userCard1=11; 
          cout<<"your first card is an "<<ace<<endl;
          dataOut<<setw(3)<<ace;
        }

      //dealers first card
        cout<<"The dealer delt a card to themself faced down"<<endl;
        if(dealerCard1==1)
          dealerCard1=2;
        else if(dealerCard1==2)
          dealerCard1=3;
        else if(dealerCard1==3)
          dealerCard1=4;
        else if(dealerCard1==4)
          dealerCard1=5;
        else if(dealerCard1==5)
          dealerCard1=6;
        else if(dealerCard1==6)
          dealerCard1=7;
        else if(dealerCard1==7)
          dealerCard1=8;
        else if(dealerCard1==8)
          dealerCard1=9;
        else if(dealerCard1==9)
          dealerCard1=10;
        else if(dealerCard1==11){
          dealerCard1=10;
          dealerCard1check=jack;
        }
        else if(dealerCard1==12){
          dealerCard1=10;
          dealerCard1check=queen;
        }
        else if(dealerCard1==13){
          dealerCard1=11;
          dealerCard1check=ace;  
        }


        //detringing what the users second card is 
      if(userCard2==1){
          userCard2=2;
          cout<<"your second card is "<<userCard2<<endl;
          dataOut<<setw(20)<<userCard2;
        }
        else if(userCard2==2){
          userCard2=3;
          cout<<"your second card is "<<userCard2<<endl;
          dataOut<<setw(20)<<userCard2;
        }
        else if(userCard2==3){
          userCard2=4;
          cout<<"your second card is "<<userCard2<<endl;
          dataOut<<setw(20)<<userCard2;
        }
        else if(userCard2==4){
          userCard2=5;
          cout<<"your second card is "<<userCard2<<endl;
          dataOut<<setw(20)<<userCard2;
        }
        else if(userCard2==5){
          userCard2=6;
          cout<<"your second card is "<<userCard2<<endl;
          dataOut<<setw(20)<<userCard2;
        }
        else if(userCard2==6){
          userCard2=7;
          cout<<"your second card is "<<userCard2<<endl;
          dataOut<<setw(20)<<userCard2;
        }
        else if(userCard2==7){
          userCard2=8;
          cout<<"your second card is "<<userCard2<<endl;
          dataOut<<setw(20)<<userCard2;
        }
        else if(userCard2==8){
          userCard2=9;
          cout<<"your second card is "<<userCard2<<endl;
          dataOut<<setw(20)<<userCard2;
        }
        else if(userCard2==9){
          userCard2=10;
          cout<<"your second card is "<<userCard2<<endl;
          dataOut<<setw(20)<<userCard2;
        }
        else if (userCard2==10){
          userCard2=10;
          cout<<"your second card is an "<<jack<<endl;
          dataOut<<setw(20)<<jack;
        }
         else if(userCard2==11){
            userCard2=10;
            cout<<"your second card is an "<<queen<<endl;
            dataOut<<setw(20)<<queen;
          }
        else if (userCard2==12){
            userCard2=10;
            cout<<"your second card is an "<<king<<endl;
            dataOut<<setw(20)<<king;
          }
        else if(userCard2==13){
          userCard2=11; 
          cout<<"your second card is an "<<ace<<endl;
          dataOut<<setw(20)<<ace;
        }


         if(dealerCard2==1){
        dealerCard2=2;
        cout<<"The dealers second card is an "<<dealerCard2<<endl;
       }
       else if(dealerCard2==2){
        dealerCard2=3;
        cout<<"The dealers second card is an "<<dealerCard2<<endl;
       }
       else if(dealerCard2==3){
        dealerCard2=4;
        cout<<"The dealers second card is an "<<dealerCard2<<endl;
       }
       else if(dealerCard2==4){
        dealerCard2=5;
        cout<<"The dealers second card is an "<<dealerCard2<<endl;
       }
       else if(dealerCard2==5){
        dealerCard2=6;
        cout<<"The dealers second card is an "<<dealerCard2<<endl;
       }
       else if(dealerCard2==6){
        dealerCard2=7;
        cout<<"The dealers second card is an "<<dealerCard2<<endl;
       }
       else if(dealerCard2==7){
        dealerCard2=8;
        cout<<"The dealers second card is an "<<dealerCard2<<endl;
       }
       else if(dealerCard2==8){
        dealerCard2=9;
        cout<<"The dealers second card is an "<<dealerCard2<<endl;
       }
       else if(dealerCard2==9){
        dealerCard2=10;
        cout<<"The dealers second card is an "<<dealerCard2<<endl;
       }
       else if (dealerCard2==10){
        dealerCard2=10;
        cout<<"The dealers second card is a "<<jack<<endl;
       }
       else if(dealerCard2==11){
         dealerCard2=10;
         cout<<"dealers second card is an "<<queen <<endl;
       }
       else if(dealerCard2==12){
        dealerCard2=10;
        cout<<"dealers second card is an "<<king<<endl;
       }
       else if(dealerCard2==13){
        dealerCard2=11; 
        cout<<"dealer second card is an "<<ace<<endl;
       }
      dealserSum=dealerCard1+dealerCard2;
      
      //Detrimins if ace is a 1 or an 11 for user and dealer
       userSum=userCard1+userCard2;
        if(userSum>21 && userCard1 == 11){
            userCard1=1;
            userSum=userCard1+userCard2;
          }
          else if(userSum>21 &&userCard2 == 11){
            userCard2=1;
            userSum=userCard1+userCard2;

            }
          else if (userSum>21 && userCard1==11 && userCard2==11){
            userCard1=1;
            userSum=userCard1+userCard2;
          } 
          else
          userSum= userSum;

       dealserSum=dealerCard1+dealerCard2;
        if(dealserSum>21 && dealerCard1 == 11){
        dealerCard1=1;
        dealserSum=dealerCard1+dealerCard2;
        }
        else if(dealserSum>21 && dealerCard2 == 11){
        dealerCard2=1;
        dealserSum=dealerCard1+dealerCard2;
        }
        else if (dealserSum>21 && dealerCard1==11 && dealerCard2==11){
          dealerCard1=1;
          dealserSum=dealerCard1+dealerCard2;
        }
        else 
       

        
        

      
      //prints how much you bet to a text file  
       
      if(userSum!=21)
      {

      
     while(userSum!=21 && hitTester==true ){
      cout<<"Your total right now is "<<userSum<<endl<<"Would you like to hit or stay?"<<endl;
      cout<<"Press (1) for hit"<<endl;
      cout<<"press (2) for stay"<<endl;
      cin>>hitStay;
       if(hitStay==1){
          hitStayflag=true;
          hitTester=false;
       }
        else if(hitStay ==2){
          cout<<"Your total is "<<userSum<<endl;
          hitStayflag= false;
          hitTester=false;
          userCard3thing='-';
          dataOut<<setw(20)<<userCard3thing;
        }
        else 
          cout<<"Your input was invaild, plese press 1 if you would like a hit or press 2 to stay."<<endl;
     }
    
      while(hitStayflag==true){
        if(hitStay==1){
          userCard3=rand()%13+1;
          }
          if(userCard3==1){
            userCard3=2;
            cout<<"Your third card is "<<userCard3<<endl;
            dataOut<<setw(20)<<userCard3;
          }
           else if(userCard3==2){
            userCard3=3;
            cout<<"Your third card is "<<userCard3<<endl;
            dataOut<<setw(20)<<userCard3;
            }
           else if(userCard3==3){
              userCard3=4;
              cout<<"Your third card is "<<userCard3<<endl;
              dataOut<<setw(20)<<userCard3;
            }
           else if(userCard3==4){
              userCard3=5;
              cout<<"Your third card is "<<userCard3<<endl;
              dataOut<<setw(20)<<userCard3;
            }
           else if(userCard3==5){
              userCard3=6;
              cout<<"Your third card is "<<userCard3<<endl;
              dataOut<<setw(20)<<userCard3;
            }
           else if(userCard3==6){
              userCard3=7;
              cout<<"Your third card is "<<userCard3<<endl;
              dataOut<<setw(20)<<userCard3;
            }
           else if(userCard3==7){
              userCard3=8;
              cout<<"Your third card is "<<userCard3<<endl;
              dataOut<<setw(20)<<userCard3;
            }
            else if(userCard3==8){
              userCard3=9;
              cout<<"Your third card is "<<userCard3<<endl;
              dataOut<<setw(20)<<userCard3;
            }
            else if(userCard3==9){
              userCard3=10;
              cout<<"Your third card is "<<userCard3<<endl;
              dataOut<<setw(20)<<userCard3;
            }
            else if (userCard3==10){
              userCard3=10;
              cout<<"Your third card is "<<jack<<endl;
              dataOut<<setw(20)<<jack;
            }
            else if (userCard3==11){
              userCard3=10;
              cout<<"Your third card is "<<queen<<endl;
              dataOut<<setw(20)<<queen;
            }
            else if(userCard3==12){
              userCard3=10;
              cout<<"Your third card is "<<king<<endl;
              dataOut<<setw(20)<<king;
            }
            else {
              userCard3=11; 
              cout<<"Your third card is an "<<ace<<endl;
              dataOut<<setw(20)<<ace;
            }
           
            userSum=userSum+userCard3;

            if(userSum>21 && userCard3 == 11 ){
            userSum=userSum-userCard3;
            userCard3=1;
            userSum=userSum+userCard3;
            hitStayflag= false;
            }
             else if(userSum>21 && userCard1 == 11 ){
            userSum=userSum-userCard1;
            userCard1=1;
            userSum=userSum+userCard1;
            userSum=userSum+userCard3;
            hitStayflag= false;
            }
            else if(userSum>21 && userCard2 == 11 ){
            userSum=userSum-userCard2;
            userCard2=1;
            userSum=userSum+userCard2;
            userSum=userSum+userCard3;
            hitStayflag= false;
            }
            else {
            hitStayflag= false;
            }
        }
      }
        
        
          if(dealerCard1==2)
            cout<<"The dealers first card is an "<<dealerCard1<<endl;
            else if(dealerCard1==3)
              cout<<"The dealers first card was "<<dealerCard1<<endl;
            else if(dealerCard1==4)
              cout<<"The dealers first card was "<<dealerCard1<<endl;
            else if(dealerCard1==5)
              cout<<"The dealers first card was "<<dealerCard1<<endl;
            else if(dealerCard1==6)
              cout<<"The dealers first card was "<<dealerCard1<<endl;
            else if(dealerCard1==7)
              cout<<"The dealers first card was "<<dealerCard1<<endl;
            else if(dealerCard1==8)
              cout<<"The dealers first card was "<<dealerCard1<<endl;
            else if(dealerCard1==9)
              cout<<"The dealers first card was "<<dealerCard1<<endl;
            else if(dealerCard1==10 && dealerCard1check==jack)
              cout<<"The dealers first card was an "<<jack<<endl;
            else if(dealerCard1==10 && dealerCard1check==queen)
            cout<<"The dealers first card was an "<<queen<<endl;
            else if(dealerCard1==10 && dealerCard1check==king)
            cout<<"The dealers first card was an "<<king<<endl;
            else if(dealerCard1==11){
              cout<<"The dealers first card was "<<ace<<endl;
            
          }

     
     if (userSum!=21)
     {
     
        //prints how much you bet to the file
         dataOut<<setw(23)<<bet;

      if(dealserSum>21 && dealerCard1 == 11){
        dealerCard1=1;
        dealserSum=dealerCard1+dealerCard2;
        }
        else if(dealserSum>21 && dealerCard2 == 11){
        dealerCard2=1;
        dealserSum=dealerCard1+dealerCard2;
        }
        else if (dealserSum>21 && dealerCard1==11 && dealerCard2==11){
          dealerCard1=1;
          dealserSum=dealerCard1+dealerCard2;
        }
        else 
        dealserSum=dealerCard1+dealerCard2;
     

      if (dealserSum<17){
        hitStayflag=true;
        dealerCard3=rand()%13+1;
        cout<<"The dealer decided to hit"<<endl;
      }
      else  {
        hitStayflag=false;
        dealserSum=dealserSum;
        dataOut<<setw(18)<<dealserSum;
      }
      
      while(hitStayflag==true){
        if(dealerCard3==1){
         dealerCard3=2;
         cout<<"The dealers third card is an "<<dealerCard3<<endl;
        
         }
         else if(dealerCard3==2){
          dealerCard3=3;
          cout<<"The dealers third card is an "<<dealerCard3<<endl;
          
         }
         else if(dealerCard3==3){
          dealerCard3=4;
          cout<<"The dealers third card is an "<<dealerCard3<<endl;
         
         }
         else if(dealerCard3==4){
          dealerCard3=5;
          cout<<"The dealers third card is an "<<dealerCard3<<endl;
          
         }
         else if(dealerCard3==5){
          dealerCard3=6;
          cout<<"The dealers third card is an "<<dealerCard3<<endl;
          
         }
         else if(dealerCard3==6){
          dealerCard3=7;
          cout<<"The dealers third card is an "<<dealerCard3<<endl;
         
         }
         else if(dealerCard3==7){
          dealerCard3=8;
          cout<<"The dealers third card is an "<<dealerCard3<<endl;
          
         }
         else if(dealerCard3==8){
          dealerCard3=9;
          cout<<"The dealers third card is an "<<dealerCard3<<endl;
          
         }
         else if(dealerCard3==9){
          dealerCard3=10;
          cout<<"The dealers third card is an "<<dealerCard3<<endl;
         
         }
         else if (dealerCard3==10){
          dealerCard3=10;
          cout<<"The dealers third card is an "<<jack<<endl;
         
         }
         else if(dealerCard3==11){
          dealerCard3=10;
          cout<<"The dealers third card is an "<<queen<<endl;
         
         }
         else if(dealerCard3==12){
          dealerCard3=10;
          cout<<"The dealers third card is an "<<king<<endl;
          
         }
         else {
          dealerCard3=11; 
          cout<<"The dealers third card is an "<<ace<<endl;
          
         }
        //total for dealer if they hit
        dealserSum=dealserSum+dealerCard3;

        if(dealserSum>21 && dealerCard3 == 11){
          dealserSum=dealserSum-dealerCard3;
          dealerCard3=1;
          dealserSum=dealserSum+dealerCard3;
          dataOut<<setw(20)<<dealserSum;
          hitStayflag=false;
          }
         else if(dealserSum>21 && dealerCard1 == 11){
          dealserSum=dealserSum-dealerCard1;
          dealerCard1=1;
          dealserSum=dealserSum+dealerCard1;
          dealserSum=dealserSum+dealerCard3;
           dataOut<<setw(20)<<dealserSum;
          hitStayflag=false;
          }
         else if(dealserSum>21 && dealerCard2 == 11){
          dealserSum=dealserSum-dealerCard2;
          dealerCard1=2;
          dealserSum=dealserSum+dealerCard2;
          dealserSum=dealserSum+dealerCard3;
          dataOut<<setw(20)<<dealserSum;
          hitStayflag=false;
          }
         
          else {
          dataOut<<setw(18)<<dealserSum;
          hitStayflag=false;
          }
       }
         
       

      //detimiuns who won the game
      if (userSum >21){
        cout<<"The hand you had was "<<userSum<<" which is over 21 and you busted, The dealer won. You lost "<<bet<<"$"<<endl;
        dataOut<<setw(20)<<"L";
        
        }
        else if(dealserSum> 21){
          cout<<"The hand that the dealer had was "<<dealserSum<< " which is over 21 so they busted, You win. You won "<<winner<<"$"<<endl;
          credit=credit+winner;
          dataOut<<setw(20)<<"W";
        }
        else if (userSum == 21 && dealserSum<userSum){
          cout<<"The user got and won Blackjack. The ammounnt won is "<<winner<<"$"<<endl;
          credit=credit+winner;
           dataOut<<setw(20)<<"W";
        }
        else if(dealserSum==21 && dealserSum>userSum){
          cout<<"The dealer got a Blackjack and won this game. You lost "<<bet<<"$"<<endl;
          dataOut<<setw(20)<<"L";
          
        }
        else if(dealserSum == userSum){
          cout<<"It was a tie, There is no winner and no credits was lost. You get to keep "<<bet<<"$"<<endl;
          credit=credit+bet;
          dataOut<<setw(20)<<"T";
        }
        else if (dealserSum>userSum){
          cout<<"The dealer won with a hand "<<dealserSum<< ". You had hand of "<<userSum<< " You lost "<<bet<<"$" <<endl;
          dataOut<<setw(20)<<"L";
        }
        else if (userSum>dealserSum){
          cout<<"You have won this round with hand of "<<userSum<<". The dealer had a hand of "<<dealserSum<<" You won "<<winner<<"$"<<endl;
          credit=credit+winner;
          dataOut<<setw(20)<<"W";

        }
     }
      
     
        betFlag=true;//resets the bets
        while(userSum==21 && hitStayflag==true)
        if(userSum >dealserSum )
          {
            cout<<"You got a balckjack and won! the amount you won is "<<winner<<"$"<<endl;
            credit=credit+winner;
            dataOut<<setw(20)<<"W";
            hitStayflag=false;
          }
        else if(userSum ==dealserSum )
          {
            cout<<"You and the dealer both got an blackjack, That means you got a push. No money was gained or lost"<<endl;
            credit=credit+bet;
            dataOut<<setw(20)<<"T";
            hitStayflag=false;
          }
      
      dataOut<<setw(20)<<credit<<endl;
      
      hitStayflag=false;
      hitTester=true;
      dataOut.close();
      infile.close();
     
      break;
     
      


    case 2:
    infile.open("SatterleeHisttory.txt");
    if(infile.is_open())
    {
    while(getline (infile,gameHistory)){
    
    
      cout<<gameHistory<<endl;
    }
      infile.close();
    }

    else 
    {
     cout<<"There is no histoy of any game"<<endl;
    }
    
    
  }
  

  
}while (game !=3);

cout<<"Thank you for using this program."<<endl;

return 0;
}
  