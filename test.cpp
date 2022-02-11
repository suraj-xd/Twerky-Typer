#include <bits/stdc++.h>
#include <windows.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;
#define clr() system("cls")
vector<string> files(string ch){
    vector<string> file;
    string s;
    ifstream in(ch);

    while(in.eof()==0){
        getline(in,s);
        file.push_back(s);
    }
    file.push_back(s);
    in.close();
    return file;
}
void welcome(){
    clr();
    system("color e4");
    cout<<"\n        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\n        | >>  * WELCOME TO TWERKY TYPER *   <<  |\n";
    cout<<"\n        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
void thanks(){
    clr();
    system("color e4");
    cout<<"\n\n\n\n";
    cout<<"\n    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\n    > > > THANKS FOR USING TWERKY TYPER! < < <\n";
    cout<<"\n    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    sleep(2);
    system("exit");
}
void thanks(int wordcnt,string readme,clock_t clk){
    clr();
    system("color 17");
    int words = 0;
    int time =  double(clock() - clk) * 1.0 / CLOCKS_PER_SEC ;
    if(readme[4]=='1') words = 32;
    else if(readme[4]=='2') words = 54;
    else words = 66;
    double wp = (wordcnt/5)/((time/60)+0.1);
    cout<<"\n|---------------------------------------";
    cout<<"\n|";
    cout<<"\n|  Finished In : "<<int(time/(1.5))<<" seconds"<<"     ";
    cout<<"\n|";
    cout<<"\n|  Typed words : "<<wordcnt<<" /"<<" "<<words<<" ";
    cout<<"\n|";
    cout<<"\n|  Gross WPM   : "<<int(wp)<<"       "<<endl;   
cout<<"|\n";
cout<<"|---------------------------------------\n";
}
void start(vector<string> typing,string readme){
    clr();
    system("color 3f");
    clock_t clk = clock();
    bool quit = false;
    int typeLen = typing.size()-1;
    int wordcnt = 0;

    cout<<"\n [enter \'exit\' for next line or \'quit\' to exit]\n\n";
    cout<<"\n [ Start Typing ]\n\n";
    for(auto text:typing){
        if((typeLen--)<1) break;
        cout<<" > " <<text<<"\n"; 
        int len = text.length();
        string ans = "";
        cout<<"\n > ";
        while(1){
            if(ans.length() >= len) break;
            string word = "";
            cin>>word;
            wordcnt++;
            if(word=="quit") {quit = true; break;}
            if(word=="exit") break;
            else ans+=(word+' ');
        }cout<<"\n";
        if(quit) break;
    }
    thanks(wordcnt,readme,clk);
}
void modes(){
    clr();
    cout<<"\n  SELECT MODE:\n";
    cout<<"  > EASY:   Press 1\n";
    cout<<"  > MEDIUM: Press 2\n";
    cout<<"  > HARD:   Press 3\n";
}
string mode(){
    modes();
    auto choice = -1;
    cout<<"\n";
    while(1){
            cout<<" -> Select A Mode : ";
            cin>>choice;
            if(!cin || choice>3 || choice<1 ){
            cout<<"!! Wrong Choice !! ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                continue;
            }else break;
    }
    return "read"+to_string(choice)+".txt";
}
int main(){
    system("mode 650");
    welcome();
    bool quit = false;
    while(1){
        string ch = mode();
        vector<string> fi = files(ch);
        start(fi,ch);
        cout<<"\n>  Press '1' to restart or '0' to quit  <\n";
        auto choice = -1;
        while(1){
            cout<<"\n   Enter A Choice: ";
            cin>>choice;
            if(!cin || choice>1 || choice<0 ){
                cout<<"!! Wrong Choice !! ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                continue;
            }else break;
        }
        if(choice==1){
            continue;
        }else break;
    }
    thanks();

}
