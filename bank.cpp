#include<iostream>
#include<map>
#include<sstream>
#include<algorithm>
#include<vector>
#include<windows.h>
#include<ctime>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<fstream>
#include<random>
#include<string>

using namespace std;


int random_id_card(){

   srand(time(NULL));
   int id1=rand() % 30 + 1985;
          return id1;
}

void gotoxy(int x,int y)
{
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD a={x,y};
  SetConsoleCursorPosition(h,a);

}

class timeline{
private:
int year,month,day,hour,munite,second;
public:
timeline(){};
timeline(int y,int mo,int d,int h,int m,int s): year(y) , month(mo) , day(d),hour(h) ,munite(m) ,second(s){};





void time_set(){

  time_t curr_time;
  curr_time = time(NULL);
  
  char *tm = ctime(&curr_time);
  
  stringstream ss;
  ss<<tm;
  string s1,s2,s3,s4,s5;
  ss>>s1>>s2>>s3>>s4>>s5;

  stringstream syear,smonth,sday;

  year = stoi(s5);

  if(s1 == "Mon") day = 2;
  if(s1 == "Sat") day = 3;
  if(s1 == "Wed") day = 4;
  if(s1 == "Thur") day = 5;
  if(s1 == "Fri") day = 6;
  if(s1 == "Sat") day = 7;
  if(s1 == "Sun") day =8;

  if(s2 == "Jan") month = 1;
  if(s2 == "Feb") month = 2;
  if(s2 == "Mar") month = 3;
  if(s2 == "Apr") month = 4;
  if(s2 == "May") month = 5;
  if(s2 == "Jun") month = 6;
  if(s2 == "Jul") month = 7;
  if(s2 == "Aug") month = 8;
  if(s2 == "Sep") month = 9;
  if(s2 == "Oct") month = 10;
  if(s2 == "Nov") month = 11;
  if(s2 == "Dec") month = 12;

 sday<<s3;
 sday>>day;


  char a;

  ss.clear();
  ss<<s4;
  ss>>hour>>a>>munite>>a>>second;

  vt_time.push_back(timeline(year,month,day,hour,munite,second));
}




void file_cin_time(){
   fstream file;
   file.open("interest_rate_information.txt",ios::app);
   for(int i = 0 ; i<vt_time.size();i++){
   file<<vt_time[i].year<<" "<<vt_time[i].month<<" "<<vt_time[i].day<<" "<<vt_time[i].hour<<" "<<vt_time[i].munite<<" "<<vt_time[i].second<<endl;
   }
   file.close();
}

void file_read_time(){
   
   fstream file;
    file.open("interest_rate_information.txt",ios::in);
    stringstream ss;
    string line;
    while(getline(file,line)){
      ss<<line;
      ss>>year>>month>>day>>hour>>munite>>second;
      ss.clear();
      vt_time.push_back(timeline(year , month , day , hour , munite ,second));
    }  
    file.close();
}

void file_remove_member(int id1){
   fstream file;
    file.open("interest_rate_information.txt",ios::out);
   vt_time.erase(vt_time.begin()+id1);
    for(int i = 0 ; i<vt_time.size();i++){
   file<<vt_time[i].year<<" "<<vt_time[i].month<<" "<<vt_time[i].day<<" "<<vt_time[i].hour<<" "<<vt_time[i].munite<<" "<<vt_time[i].second<<endl;
   }
   file.close();

}


void cout_(){
   for(int id = 0 ; id<vt_time.size() ; id++){
      cout<<vt_time[id].year<<" "<<vt_time[id].month<<" "<<vt_time[id].day<<" "<<vt_time[id].hour<<" "<<vt_time[id].munite<<" "<<vt_time[id].second<<endl;
   }
}
void cout_member(int id){
   cout<<vt_time[id].year<<" "<<vt_time[id].month<<" "<<vt_time[id].day<<" "<<vt_time[id].hour<<" "<<vt_time[id].munite<<" "<<vt_time[id].second<<endl;
}

void calculator_interest_rate_day(int id,int& number){
      number = 0;
      time_set();
      int s = vt_time.size()-1;
      cout<<s<<endl;
      cout<<vt_time[s].month<<endl;
      cout<<vt_time[s].day<<endl;
           number = number + (((vt_time[s].month) - (vt_time[id].month)) * 30);
           number = number + (((vt_time[s].day) - (vt_time[id].day)) * 1) ;
           number = number + (((vt_time[s].hour) - (vt_time[id].hour)) * 1) ;

           vt_time.pop_back();

           
}

vector<timeline> vt_time;
};
void file_read_bank(vector<string>& vtname,vector<string>& vtrate){
   stringstream ss;
   fstream file;
   string line;
   string s1,s2,s3,s4;
   file.open("bank_information.txt",ios::in);
   int flag=0;
   while(getline(file,line)){
     ss<<line;
     if(flag==1){
        ss>>s1>>s2>>s3;
        vtrate.push_back(s3);
      flag--;
      ss.clear();
      continue;
     }
     ss>>s1>>s2;
     vtname.push_back(s2);
     ss.clear();
      flag++;
   }

   file.close();
}



struct member{
    string name;
   
     string username;
     string password;

     int money;
     int card_id;
     int pin_id;


     string bank_name;
     member(){};
     member(string name1,string username1,string password1,int money1,int card_id1,int pin_id1,string bank_name1 ) : name(name1), username(username1), password(password1), money(money1), card_id(card_id1) , pin_id(pin_id1),bank_name(bank_name1) {};

     friend ostream& operator << (ostream& os, member* mb){
        cout<<"Member: "<<mb->name<<endl;
        cout<<mb->bank_name<<": "<<mb->card_id<<mb->card_id<<endl;
        cout<<"PIN: "<<mb->pin_id<<endl;
        cout<<"Money :"<<mb->money<<endl;


        return os;

     }



     friend istream& operator >> (istream& is , member* mb){
      timeline t;
      press_again:
       string pass1,pass2;
       string usename;
       
        cout<<"User_name: ";cin>>mb->username;
        for(int i = 0 ; i<(mb->vt.size()) ;i++){
         if(mb->username == mb->vt[i].username){
            cout<<"This username has been used !"<<endl;
            system("pause");
            goto press_again;
         }
        }
        cout<<"Password: ";cin>>pass1;
        cout<<"Press again password: ";cin>>mb->password;
        if((mb->password ) !=pass1) {
         cout<<"Password mismatched !"<<endl;
         system("pause");
         system("cls");
          goto press_again;
        
        }

        cout<<"Name: ";cin>>mb->name;

        cout<<"PIN: ";cin>>mb->pin_id;

        mb->money = 0;

        int id1 = random_id_card();
        int id2 = random_id_card();

        mb->card_id = id1;

        vector<string> vt1 ; vector<string> vt2;

        file_read_bank(vt1,vt2);

        for(int i = 0 ; i < vt1.size() ;i++){
         cout<<vt1[i]<<" bank interest rate "<<vt2[i]<<"%"<<endl;
        }
        for(int i = 0 ; i<vt1.size();i++){
         gotoxy(33,5+i);cout<<" ( "<<i<<" ) ";
        }
        cout<<""<<endl;
        pressid:
        int bank_id;
        cout<<"Chose bank> ";cin>>bank_id;
        if(bank_id >= vt1.size()) {
         cout<<"Bank id mismatched!"<<endl;
         system("pause");
         goto pressid;
        }
           mb->bank_name = vt1[bank_id];
           t.time_set();
           t.file_cin_time();
         
         

        return is;
     }
     vector<member> vt;
};

void file_read_member(vector<string>& vec){
   int flag1 = 0 ;
   int flag2 = 0;
      string line;
      stringstream ss;
      fstream file;
      file.open("member_information.txt",ios::in);
      while(getline(file,line)){
         string s1,s2,s3;
         flag1++;
         if(flag1==4){
            ss<<line;
            ss>>s1>>s2>>s3;
            vec.push_back(s1);vec.push_back(s3);
            ss.clear();
            continue;
         }
         
             ss<<line;
             
             ss>>s1>>s2;
             vec.push_back(s2);
             ss.clear();
            
             if(flag1 == 6){
            flag1=0;
          }
      }
      file.close();
}

member* cin_member(vector<string> vtc){
    member* mb= new member;
    string name1,username1,password1,money_1,bank_name1;
    int money1,card_id1,pin_id1;
    string interest_rate1; 
    int a = vtc.size() / 7;
    for(int i = 0 ; i<a ; i++ ){
      name1 = vtc[i*7]; username1 = vtc[(i*7)+1]; password1 = vtc[(i*7)+2]; bank_name1 = vtc[(i*7)+3] ; 
      card_id1=stoi(vtc[(i*7)+4]);
      pin_id1 =stoi(vtc[(i*7)+5]);
      money1 = stoi(vtc[(i*7)+6]);
      mb->vt.push_back(member(name1,username1,password1,money1,card_id1,pin_id1,bank_name1));
    }
return mb;
}

struct bank{

string bank_name;

float interest_rate;

      friend ostream& operator << (ostream& os , bank* bk){
               cout<<"Bank: "<<bk->bank_name<<endl; cout<<"Interest rate: "<<bk->interest_rate;
               return os;
      }

      friend istream& operator >> (istream& is , bank* mb){
               
               gotoxy(33,15);;cout<<"Bank: "; cin>>mb->bank_name;
               gotoxy(33,16);;cout<<"Interest rate: "; cin>>mb->interest_rate;
               return is;
      }


};

void file_cin_bank(bank* bk){
       fstream file;
             file.open("bank_information.txt",ios::app);
             file<<"Bank: "<<bk->bank_name<<" bank"<<endl;
             file<<"Interest rate: "<<bk->interest_rate<<endl;
       file.close();
}




void delete_bank(vector<string> vtname,vector<string> vtrate,bool& flag1,int y1_,int y2_){
   flag1=false;
   gotoxy(33,(y2_ -1));cout<<"Press bank's name to delete: "<<endl; string name;gotoxy(33,y2_); cin>>name;
   for(int i = 0 ; i<vtname.size();i++){
      if(name==vtname[i]) {
         vtname.erase(vtname.begin()+i);
         flag1 =true;
   }
   }
   fstream file;
   file.open("bank_information.txt",ios::out);
   for(int i=0;i<vtname.size() ; i++){
   file<<"Bank: "<<vtname[i]<<" bank"<<endl;
   file<<"Interest rate: "<<vtrate[i]<<endl;
   y1_+=2;
   y2_+=2;
   }
   file.close();
}



void delete_member(member* mb,int mem){

   system("cls");
 
   int name=mem;
    mb->vt.erase(mb->vt.begin()+mem);
}

void file_rechange_member(member* mb){
   fstream file;
   file.open("member_information.txt",ios::out);
   for(int i =0 ; i<mb->vt.size() ;i++){
            file<<"Member: "<<mb->vt[i].name<<endl;
            file<<"Username: "<<mb->vt[i].username<<endl;
            file<<"Password: "<<mb->vt[i].password<<endl;
        file<<mb->vt[i].bank_name<<" bank: "<<mb->vt[i].card_id<<endl;
        file<<"PIN: "<<mb->vt[i].pin_id<<endl;
        file<<"Money: "<<mb->vt[i].money<<endl;
   }
   file.close();


}

    




void file_cin_member(member* mb){
   fstream file;
   file.open("member_information.txt",ios::app);
            file<<"Member: "<<mb->name<<endl;
            file<<"Username: "<<mb->username<<endl;
            file<<"Password: "<<mb->password<<endl;
        file<<mb->bank_name<<" bank: "<<mb->card_id<<mb->card_id<<endl;
        file<<"PIN: "<<mb->pin_id<<endl;
        file<<"Money: "<<mb->money<<endl;
   file.close();

}


member* member_create(){
        member* mb = new member;

        cin>>mb;
        file_cin_member(mb);

        return mb;
}

bank* bank_create(){
         bank* bk = new bank;
      cin>>bk;
      file_cin_bank(bk);

      return bk;
}

void login(member* mb,int& choice,int& ID){
   timeline t;
   t.file_read_time();
   vector<string> vt1,vt2_;
   int id;
   re1:
   system("cls");
   string username,password;
   bool b=false;
       cout<<"Username: ";cin>>username;
       cout<<"Password: ";cin>>password;

       for(int i = 0 ; i<(mb->vt.size());i++){
         if(username==mb->vt[i].username && password==mb->vt[i].password){
            system("cls");
            cout<<"Welcome "<<mb->vt[i].name; id = i; ID =id;
            b=true;
            break;
         }
       }
       if(b==false)  {
         cout<<"Username or password doesnt exit !"<<endl;
         system("pause");
         goto re1;
       }

       file_read_bank(vt1,vt2_);

       

       vector<float> vt2;
       stringstream ss;
       for(int i = 0 ; i<vt2_.size();i++){
         ss<<vt2_[i];
         float fl;
         ss>>fl;
         vt2.push_back(fl);
         ss.clear();
       }
int id_bank;
       for(int i = 0 ; i<vt1.size();i++){
          if(mb->vt[id].bank_name == vt1[i]) id_bank = i;
       }

      
            
            int number_day_member_off;  t.calculator_interest_rate_day(id,number_day_member_off); 
            mb->vt[id].money = mb->vt[id].money + (mb->vt[id].money * (number_day_member_off * (vt2[id_bank]/100)));
file_rechange_member(mb);
          re2:
          system("cls");
          cout<<"(1) Rechange money"<<endl;
          cout<<"(2) Withdraw money"<<endl;
          cout<<"(3) Information"<<endl;
          cout<<"(4) Transfer money"<<endl;
          cout<<"(5) Check bank's interest rate"<<endl;
          cout<<"(6) Delete member !"<<endl;
          cout<<"(0) Go back"<<endl;
         
                         
                         int key;cin>>key;
                         switch (key)
                         {
                         case 1:
                         int pin;
                           cout<<"PIN: ";cin>>pin;
                           if(pin != mb->vt[id].pin_id) {
                              cout<<"PIN ID doesnt exit ! "<<endl;
                              system("pause");
                              goto re2;
                           }
                           int money;
                           cout<<"> ";cin>>money;mb->vt[id].money +=money;
                           cout<<"Money: "<<mb->vt[id].money<<" $"<<endl;
                           file_rechange_member(mb);
                           system("pause");
                           goto re2;

                           case 2:
                           
                           cout<<"PIN: ";cin>>pin;
                           if(pin != mb->vt[id].pin_id) {
                              cout<<"PIN ID doesnt exit ! "<<endl;
                              system("pause");
                              goto re2;
                           }
                              re_case2:
                           
                           cout<<"> " ;cin>>money;
                           if(money > mb->vt[id].money){
                              cout<<"Surplus of money doesnt enough !"<<endl;
                              system("pause");
                              goto re2;
                           }
                           
                           mb->vt[id].money -= money;cout<<"Money: "<<mb->vt[id].money;
                           file_rechange_member(mb);
                           system("pause");
                           goto re2;
                             
                           case 3:
                                     cout<<mb->vt[id].bank_name<<" bank : "<<mb->vt[id].card_id<<endl;
                                     cout<<"Money: "<<mb->vt[id].money<<" $"<<endl;
                                     system("pause");
                                     goto re2;
                           case 4:
                                 int id_trans;
                                 int cardid;cout<<"Card id >";cin>>cardid;
                                 b = false;
                                 for(int i = 0 ; i<mb->vt.size();i++){
                                      if(cardid == mb->vt[i].card_id) {
                                       b =true;id_trans = i;
                                      }
                                 }
                                 if(cardid == mb->vt[id].card_id){
                                    b=false;
                                 }
                                 if(b== false){
                                    cout<<"This card id doesnt exit !"<<endl;
                                    system("pause");
                                    goto re2;
                                 }
                                 cout<<"Name of member: "<<mb->vt[id_trans].name<<endl;cout<<""<<endl;
                                 cout<<"Ammound of money need to transfered > ";cin>>money;
                                  if(money > mb->vt[id].money){
                                       cout<<"Surplus of money doesnt enough !"<<endl;
                                       system("pause");
                                       goto re2;
                                    }

                                 mb->vt[id_trans].money += money;
                                 mb->vt[id].money -= money;
                                 file_rechange_member(mb);

                                 cout<<"Done ";system("pause");
                                 goto re2;

                              case 5:
                          
                                 t.file_read_time();
                                 cout<<"Time's member created account: ";t.cout_member(id);
                                 cout<<"Interest rate of "<<vt1[id_bank]<<" bank is:  "<<vt2[id_bank]<<"%"<<endl;
                                 cout<<"This account will earn "<<(vt2[id_bank]/100) * mb->vt[id].money<<"$ in 1 hour!"<<endl;
                                 
                                    
                                 system("pause");
                                goto re2;
                              case 6:
                              
                              delete_member(mb,id);
                     
                              file_rechange_member(mb);
                              choice = 1;
                              system("cls");
                              break;
                               case 0:
                                 choice = 0;

                               break;

                           default:
                           cout<<"This key doesnt exit !"<<endl;
                           system("pause");
                           goto re2;
                         }

}







void printf(){ cout<<"-----***-----"<<endl;}


void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width-1;
    WindowSize.Bottom = height-1;
 
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}



int main(){
             ShowScrollbar(0);
goback:
             int n;
             member* mb_;bank* bk_;
             stringstream ss;string s1,s2,s3,s4,s5;
             vector<string> vtname1,vtrate1;vector<string> vec_member;
             file_read_bank(vtname1,vtrate1);
             file_read_member(vec_member);
             mb_ = cin_member(vec_member);
             timeline t_;
             t_.file_read_time();
            
            

             bool flag1;
             int y1=15;int y2=16;
             system("cls");
      SetWindowSize(70,30);            
      gotoxy(33,10);
      cout<<"Login     (1)"<<endl;
      gotoxy(33,11);
      cout<<"Register  (2)"<<endl;
      gotoxy(33,12);
      cout<<"Bank menu (3)"<<endl;
      gotoxy(33,13);
      cout<<"Close     (0)"<<endl;

      int key;
      gotoxy(33,14);cout<<">";cin>>key;

      switch (key)
      {
      case 1:
      int choice,ID;
         login(mb_,choice,ID);
         if(choice ==1 ){
            t_.file_remove_member(ID);
            cout<<ID<<endl;
            cout<<"Done "; system("pause");
         }
         else {goto goback;}

         goto goback;
      case 2: 
      system("cls");
      mb_ = member_create();
      cout<<"Done ";system("pause");
      goto goback;
      
      case 3:
      goback1:
      y1=15;y2=16;
      system("cls");
      gotoxy(33,10);cout<<"Create bank  (1)"<<endl;
      gotoxy(33,11);cout<<"View banks   (2)"<<endl;
      gotoxy(33,12);cout<<"Delete bank  (3)"<<endl;
      gotoxy(33,13);cout<<"Go back      (0)"<<endl;

     int key;
     gotoxy(33,14);cout<<">";cin>>key;
      switch (key)
      {
      case 1:
         bk_ = bank_create();

         gotoxy(33,18);cout<<"Done ";
         system("pause");
         goto goback1;
      case 2:
      vtname1.clear();vtrate1.clear();
      file_read_bank(vtname1,vtrate1);
      for(int i = 0 ; i < vtname1.size();i++){
         gotoxy(33,y1);cout<<"Bank: "<<vtname1[i]<<endl;
         gotoxy(33,y2);cout<<"Interest rate: "<<vtrate1[i]<<" %"<<endl;
         y1=y1+2;
         y2=y2+2;
      }
      gotoxy(33,y2);system("pause");
      goto goback1;
      case 3:
      vtname1.clear();vtrate1.clear();
      file_read_bank(vtname1,vtrate1);
     
      for(int i = 0 ; i < vtname1.size();i++){
         gotoxy(33,y1);cout<<"Bank: "<<vtname1[i]<<endl;
         gotoxy(33,y2);cout<<"Interest rate: "<<vtrate1[i]<<"%"<<endl;
         y1=y1+2;
         y2=y2+2;
      }

       delete_bank(vtname1,vtrate1,flag1,y1,y2);
       
      if(flag1 == true) {
         gotoxy(33,y2+1);cout<<"Done ";system("pause");goto goback1;
      }
      if(flag1 == false){
         gotoxy(33,y2+1);cout<<"That bank's name doesnt exit!"<<endl;
         gotoxy(33,y2+2);system("pause");
         goto goback1;
      }
      
      
      gotoxy(33,y2+1);cout<<"Done..";
      system("pause");
      goto goback1;

      case 0:
      goto goback;

      default:
         cout<<"That key doesnt exit!"<<endl; system("pause");
         goto goback1;
      }
      cout<<"Done ";
      system("pause");
      goto goback;
      case 0:
      return 0;

      default:
      gotoxy(5,16);
         cout<<"Please press again(That key doesnt include in scope of choice...)"<<endl;
          gotoxy(5,17);system("pause");
         system("cls");
         goto goback;
      }

      system("pause");
      




}










