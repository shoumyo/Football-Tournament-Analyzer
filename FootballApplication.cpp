#include<bits/stdc++.h>
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

    //opening a file to store the match results
    ofstream MyFile("Results.txt");

    cout<<"WELCOME TO THE FOOTBALL TOURNAMENT PERFORMANCE ANALYZER"<<endl;
    cout<<endl;
    int number;
    cout<<"How many tournament:";
    cin>>number;

    for(int x=0;x<number;x++){  //tournament listing one by one
        string tournamentName;
        cout<<"Name of the "<<x+1<<" Tournament:";
        cin.ignore();
        getline(cin,tournamentName);
        MyFile<<"Tournament Name:";
        MyFile<<tournamentName<<endl;   //storing tournament name to the file
        MyFile<<endl;
        cout<<endl;

        cout<<"Welcome to the "<<tournamentName<<" performance analyzer"<<endl;
        cout<<endl;

        //Forward section

        int forwards;
        cout<<"Number of forwards:";
        cin>>forwards;

        struct forward striker[forwards];

        for(int i=0;i<forwards;i++){
            striker[i].totalGoals=0;               //getting rid from garbage value
            cout<<"Name of no."<<i+1<<" forward:";
            cin.ignore();
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
            cin.ignore();
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
            cin.ignore();
            getline(cin,ref[i].name);
            cout<<"Give the last 3 match mistakes"<<endl;
            for(int j=0;j<3;j++){
                cout<<"Enter "<<j+1<<" match mistakes:";
                cin>>ref[i].wrongDecition[j];
                ref[i].totalWrongDecition +=ref[i].wrongDecition[j];
            }
        }
        cout<<endl;

        //sorting part
        //bubble sort for sorking the structure according to the total number of goals,saves and mistakes

        for(int i=0;i<forwards-1;i++){
            for(int j=1;j<forwards;j++){
                if(striker[i].totalGoals<striker[j].totalGoals){ //swapping the full structure using temp structure just like the swapping ones
                    struct forward temp= striker[i];
                    striker[i]=striker[j];
                    striker[j]=temp;
                }
            }
        }

        for(int i=0;i<goalkeepers-1;i++){
            for(int j=1;j<goalkeepers;j++){
                if(gk[i].totalSave<gk[j].totalSave){  //swapping the whole structure using temp structure just like the swapping ones
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

        //tie-breaking of forwards with public votes

        int tieCountofForwards=1;
        for(int a=1;a<forwards;a++){
            if(striker[0].totalGoals==striker[a].totalGoals){
                tieCountofForwards++;
            }
        }
        if(tieCountofForwards>1){
            cout<<"There are "<<tieCountofForwards<<" players of same total goals.So we are going to rank them according to public votes"<<endl;
        cout<<endl;
        vector<double>forwardVotes(tieCountofForwards);
        for(int i=0;i<tieCountofForwards;i++){
            cout<<"Enter "<<striker[i].name<<" votes:";
            cin>>forwardVotes[i];
        }
        for(int i=0;i<tieCountofForwards-1;i++){
            for(int j=1;j<tieCountofForwards;j++){
                if(forwardVotes[i]<forwardVotes[j]){
                    struct forward temp= striker[i];
                    striker[i]=striker[j];
                    striker[j]=temp;
                }
            }
        }
        }

        //tie-breaking of goalkeepers with public votes

        int tieCountofGks=1;
        for(int a=1;a<goalkeepers;a++){
            if(gk[0].totalSave==gk[a].totalSave){
                tieCountofGks++;
            }
        }
        if(tieCountofGks>1){
            cout<<"There are "<<tieCountofGks<<" players of same total saves.So we are going to rank them according to public votes"<<endl;
        cout<<endl;
        vector<double>gkVotes(tieCountofGks);
        for(int i=0;i<tieCountofGks;i++){
            cout<<"Enter "<<gk[i].name<<" votes:";
            cin>>gkVotes[i];
        }
        for(int i=0;i<tieCountofGks-1;i++){
            for(int j=1;j<tieCountofGks;j++){
                if(gkVotes[i]<gkVotes[j]){
                    struct goalkeeper temp= gk[i];
                    gk[i]=gk[j];
                    gk[j]=temp;
                }
            }
        }
        }

        //tie-breaking of referees with public votes

        int tieCountofRefs=1;
        for(int a=1;a<referees;a++){
            if(ref[0].totalWrongDecition==ref[a].totalWrongDecition){
                tieCountofRefs++;
            }
        }
        if(tieCountofRefs>1){
            cout<<"There are "<<tieCountofRefs<<" players of same total Wrong Decition.So we are going to rank them according to public votes"<<endl;
        cout<<endl;
        vector<double> refVotes(tieCountofRefs);
        for(int i=0;i<tieCountofGks;i++){
            cout<<"Enter "<<ref[i].name<<" votes:";
            cin>>refVotes[i];
        }
        for(int i=0;i<tieCountofRefs-1;i++){
            for(int j=1;j<tieCountofRefs;j++){
                if(refVotes[i]<refVotes[j]){
                    struct referee temp= ref[i]; //making the temp structure just like the swapping structure
                    ref[i]=ref[j];
                    ref[j]=temp;
                }
            }
        }
        }

        //output
        //storing every output to file from this section

        if(forwards>0){
            cout<<"Forwards Ranking"<<endl;
            MyFile<<"Forwards Ranking"<<endl;
        cout<<endl;
        MyFile<<endl;

        //name 20 spacing
        //goals 7 spacing
        //total 10 spacing

        cout<<"Ranking"<<"  "<<"Name"<<"                          "<<"  "<<"Match 1"<<"  "<<"Match 2"<<"  "<<"Match 3"<<"  "<<"Totalgoals"<<endl;
        MyFile<<"Ranking"<<"  "<<"Name"<<"                          "<<"  "<<"Match 1"<<"  "<<"Match 2"<<"  "<<"Match 3"<<"  "<<"Totalgoals"<<endl;
        
        for(int i=0;i<forwards;i++){
            cout<<i+1;
            MyFile<<i+1;
            for(int l=1;l<=9-to_string(i+1).length();l++){
                cout<<" ";
                MyFile<<" ";
            }
            cout<<striker[i].name;
            MyFile<<striker[i].name;
            for(int j=1;j<=30-striker[i].name.length();j++){    //for a good output
                //giving all name the same spacing
                cout<<" ";
                MyFile<<" ";
            }
            cout<<"  ";
            MyFile<<"  ";
            for(int j=0;j<3;j++){
                cout<<striker[i].goals[j];
                MyFile<<striker[i].goals[j];
                for(int k=1;k<=7-to_string(striker[i].goals[j]).length();k++){  //for a beautiful output
                    //turning int value to string and calculating it's length
                    cout<<" ";
                    MyFile<<" ";
                }
                cout<<"  ";
                MyFile<<"  ";
            }
            cout<<striker[i].totalGoals<<endl;
            MyFile<<striker[i].totalGoals<<endl;

        }
        cout<<endl<<endl;
        MyFile<<endl<<endl;
        }

        if(goalkeepers>0){
            cout<<"Goalkeepers Ranking"<<endl;
        cout<<endl;
        MyFile<<"Goalkeepers Ranking"<<endl;
        MyFile<<endl;

        //name 20 spacing
        //goals 7 spacing
        //total 10 spacing

        cout<<"Ranking"<<"  "<<"Name"<<"                          "<<"  "<<"Match 1"<<"  "<<"Match 2"<<"  "<<"Match 3"<<"  "<<"Totalsaves"<<endl;
        MyFile<<"Ranking"<<"  "<<"Name"<<"                          "<<"  "<<"Match 1"<<"  "<<"Match 2"<<"  "<<"Match 3"<<"  "<<"Totalsaves"<<endl;
        
        for(int i=0;i<goalkeepers;i++){
            cout<<i+1;
            MyFile<<i+1;
            for(int l=1;l<=9-to_string(i+1).length();l++){
                cout<<" ";
                MyFile<<" ";
            }
            cout<<gk[i].name;
            MyFile<<gk[i].name;
            for(int j=1;j<=30-gk[i].name.length();j++){    //for a good output
                //giving all name the same spacing
                cout<<" ";
                MyFile<<" ";
            }
            cout<<"  ";
            MyFile<<"  ";
            for(int j=0;j<3;j++){
                cout<<gk[i].save[j];
                MyFile<<gk[i].save[j];
                for(int k=1;k<=7-to_string(gk[i].save[j]).length();k++){  //for a beautiful output
                    //turning int value to string and calculating it's length
                    cout<<" ";
                    MyFile<<" ";
                }
                cout<<"  ";
                MyFile<<"  ";
            }
            cout<<gk[i].totalSave<<endl;
            MyFile<<gk[i].totalSave<<endl;

        }
        cout<<endl<<endl;
        MyFile<<endl<<endl;
        }

        if(referees>0){
            cout<<"Referees Ranking"<<endl;
        cout<<endl;
        MyFile<<"Referees Ranking"<<endl;
        MyFile<<endl;

        //name 30 spacing
        //goals 7 spacing
        //total 10 spacing

        cout<<"Ranking"<<"  "<<"Name"<<"                          "<<"  "<<"Match 1"<<"  "<<"Match 2"<<"  "<<"Match 3"<<"  "<<"Total Wrong Decision"<<endl;
        MyFile<<"Ranking"<<"  "<<"Name"<<"                          "<<"  "<<"Match 1"<<"  "<<"Match 2"<<"  "<<"Match 3"<<"  "<<"Total Wrong Decision"<<endl;
        
        for(int i=0;i<referees;i++){
            cout<<i+1;
            MyFile<<i+1;
            for(int l=1;l<=9-to_string(i+1).length();l++){
                cout<<" ";
                MyFile<<" ";
            }
            cout<<ref[i].name;
            MyFile<<ref[i].name;
            for(int j=1;j<=30-ref[i].name.length();j++){    //for a good output
                //giving all name the same spacing
                cout<<" ";
                MyFile<<" ";
            }
            cout<<"  ";
            MyFile<<"  ";
            for(int j=0;j<3;j++){
                cout<<ref[i].wrongDecition[j];
                MyFile<<ref[i].wrongDecition[j];
                for(int k=1;k<=7-to_string(ref[i].wrongDecition[j]).length();k++){  //for a beautiful output
                    //turning int value to string and calculating it's length
                    cout<<" ";
                    MyFile<<" ";
                }
                cout<<"  ";
                MyFile<<"  ";
            }
            cout<<ref[i].totalWrongDecition<<endl;
            MyFile<<ref[i].totalWrongDecition<<endl;

        }
        cout<<endl<<endl;
        MyFile<<endl<<endl;
        }

        cout<<endl;
        MyFile<<endl;
        //Highlighting the best plater of the tournament
        cout<<"The best player of the "<<tournamentName<<" is:";
        MyFile<<"The best player of the "<<tournamentName<<" is:";
        if(striker[0].totalGoals>gk[0].totalSave){
            cout<<striker[0].name<<endl;
            MyFile<<striker[0].name<<endl;
        }
        else if(striker[0].totalGoals=gk[0].totalSave){
            cout<<striker[0].name<<" & "<<gk[0].name;
            MyFile<<striker[0].name<<" & "<<gk[0].name;
        }
        else{
            cout<<gk[0].name<<endl;
            MyFile<<gk[0].name<<endl;
        }
        cout<<endl<<endl;
        MyFile<<endl<<endl;
    }
    MyFile.close();

    return 0;
}