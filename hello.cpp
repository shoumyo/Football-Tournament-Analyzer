//#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;

struct forward{
    string name;
    int goals[3]; //last 3 matches
    int totalGoals;
};

struct goalkeeper{
    string name;
    int save[3]; //last 3 matches
    int totalSave;
};

struct referee{
    string name;
    int wrongDecition[3]; //last 3 matches
    int totalWrongDecition;
};

int main(){

    cout<<"WELCOME TO THE FOOTBALL TOURNAMENT PERFORMANCE ANALYZER"<<endl;
    cout<<endl;
    int number;
    cout<<"How many tournament:";
    cin>>number;
    cout<<endl;

    //Forward Section

    int forwards;
    cout<<"Number of forwards:";
    cin>>forwards;

    struct forward striker[forwards];

    for(int i=0;i<forwards;i++){
        striker[i].totalGoals=0;               //getting rid from garbage value
        cout<<"Name of no."<<i+1<<" forward:";
        getline(cin,striker[i].name);

        cout<<"Give the last 3 match goals"<<endl;
        for(int j=0;j<3;j++){
            cout<<"Enter "<<j+1<<" match goal:";
            cin>>striker[i].goals[j];
            striker[i].totalGoals+=striker[i].goals[j];
        }
    }

    //Goalkeeper Section

    int goalkeepers;
    cout<<"Number of Goalkeepers:";
    cin>>goalkeepers;

    struct goalkeeper gk[goalkeepers];

    for(int i=0;i<goalkeepers;i++){
        gk[i].totalSave=0;               //getting rid from garbage value
        cout<<"Name of no."<<i+1<<" goalkeeper:";
        getline(cin,gk[i].name);

        cout<<"Give the last 3 match savess"<<endl;
        for(int j=0;j<3;j++){
            cout<<"Enter "<<j+1<<" match saves:";
            cin>>gk[i].save[j];
            gk[i].totalSave+=gk[i].save[j];
        }
    }

    //Referee Section

    int referees;
    cout<<"Number of Referees:";
    cin>>referees;

    struct referee ref[referees];

    for(int i=0;i<referees;i++){
        ref[i].totalWrongDecition=0;               //getting rid from garbage value
        cout<<"Name of no."<<i+1<<" referee:";
        getline(cin,ref[i].name);
        cout<<"Give the last 3 match mistakes"<<endl;
        for(int j=0;j<3;j++){
            cout<<"Enter "<<j+1<<" match mistakes:";
            cin>>ref[i].wrongDecition[j];
            ref[i].totalWrongDecition+=ref[i].wrongDecition[j];
        }
    }

    //sorting part
    //bubble sort for sorking the structure according to the total number of goals,saves and mistakes

    for(int i=0;i<forwards-1;i++){
        for(int j=1;j<forwards;j++){
            if(striker[i].totalGoals<striker[j].totalGoals){ //swapping the full structure
                struct forward temp= striker[i];
                striker[i]=striker[j];
                striker[j]=temp;
            }
        }
    }

    for(int i=0;i<goalkeepers-1;i++){
        for(int j=1;j<goalkeepers;j++){
            if(gk[i].totalSave<gk[j].totalSave){  //swapping the whole structure
                struct goalkeeper temp= gk[i];
                gk[i]=gk[j];
                gk[j]=temp;
                }
            }
        }

        for(int i=0;i<referees-1;i++){
            for(int j=1;j<referees;j++){
                if(ref[i].totalWrongDecition<ref[j].totalWrongDecition){ //swapping using temp structure
                    struct referee temp= ref[i]; //making the temp structure just like the swapping structure
                    ref[i]=ref[j];
                    ref[j]=temp;
                }
            }
        }

        if(forwards>0){
            cout<<"Forwards Ranking"<<endl;
        cout<<endl;

        //name 20 spacing
        //goals 7 spacing
        //total 10 spacing

        cout<<"Ranking"<<"  "<<"Name"<<"                "<<"  "<<"Match 1"<<"  "<<"Match 2"<<"  "<<"Match 3"<<"  "<<"Totalgoals"<<endl;
        
        for(int i=0;i<forwards;i++){
            cout<<i+1<<"  "<<striker[i].name;
            for(int j=1;j<=20-striker[i].name.length();j++){    //for a good output
                //giving all name the same spacing
                cout<<" ";
            }
            cout<<"  ";
            for(int j=0;j<3;j++){
                cout<<striker[i].goals[j];
                for(int k=1;k<=7-to_string(striker[i].goals[j]).length();k++){  //for a beautiful output
                    //turning int value to string and calculating it's length
                    cout<<" ";
                }
                cout<<"  ";
            }
            cout<<striker[i].totalGoals<<endl;

        }
        cout<<endl<<endl;
        }

        if(goalkeepers>0){
            cout<<"Goalkeepers Ranking"<<endl;
        cout<<endl;

        //name 20 spacing
        //goals 7 spacing
        //total 10 spacing

        cout<<"Ranking"<<"  "<<"Name"<<"                "<<"  "<<"Match 1"<<"  "<<"Match 2"<<"  "<<"Match 3"<<"  "<<"Totalsaves"<<endl;
        
        for(int i=0;i<goalkeepers;i++){
            cout<<i+1<<"  "<<gk[i].name;
            for(int j=1;j<=20-gk[i].name.length();j++){    //for a good output
                //giving all name the same spacing
                cout<<" ";
            }
            cout<<"  ";
            for(int j=0;j<3;j++){
                cout<<gk[i].save[j];
                for(int k=1;k<=7-to_string(gk[i].save[j]).length();k++){  //for a beautiful output
                    //turning int value to string and calculating it's length
                    cout<<" ";
                }
                cout<<"  ";
            }
            cout<<gk[i].totalSave<<endl;

        }
        cout<<endl<<endl;
        }

        if(referees>0){
            cout<<"Referees Ranking"<<endl;
        cout<<endl;

        //name 20 spacing
        //goals 7 spacing
        //total 10 spacing

        cout<<"Ranking"<<"  "<<"Name"<<"                "<<"  "<<"Match 1"<<"  "<<"Match 2"<<"  "<<"Match 3"<<"  "<<"Total Wrong Decision"<<endl;
        
        for(int i=0;i<referees;i++){
            cout<<i+1<<"  "<<ref[i].name;
            for(int j=1;j<=20-ref[i].name.length();j++){    //for a good output
                //giving all name the same spacing
                cout<<" ";
            }
            cout<<"  ";
            for(int j=0;j<3;j++){
                cout<<ref[i].wrongDecition[j];
                for(int k=1;k<=7-to_string(ref[i].wrongDecition[j]).length();k++){  //for a beautiful output
                    //turning int value to string and calculating it's length
                    cout<<" ";
                }
                cout<<"  ";
            }
            cout<<ref[i].totalWrongDecition<<endl;

        }
        cout<<endl<<endl;
        }

    return 0;
}