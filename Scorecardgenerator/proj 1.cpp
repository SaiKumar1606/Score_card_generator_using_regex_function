/* C++ PROGRAM TO GENERATE CRICKET SCOREBOARD FROM STANDARD PROFESSIONAL ENGLISH COMMENTARY OF ANY MATCH, ANY INNINGS */

#include <bits/stdc++.h>
#include <fstream>
#include <regex>
#include <string.h>
using namespace std;

int main()
{
    int c=0,i=0,j=0,num=0,way=0,first=0,second=0,tot=0,wic=0;
    string line,file1,file2,T,f1name[11],l1name[11],f2name[11],l2name[11],cric[15];
    string c1,c2,c3,c4;
    float runs[11]={0},balls[11]={0},fours[11]={0},sixes[11]={0},str[11]={0},d[11]={0};
    float b[11]={0},wd[11]={0},lb[11]={0},r[11]={0},w[11]={0},eco[11]={0},nb[11]={0};
    float pos1[11],pos2[11],crr=0.0;
    vector <string> v,t1,t2,bat,ball;

    file1 = "C:\\Users\\DEVI GIRI\\OneDrive\\Desktop\\DAA PROJECT COMMENTARY.txt";
    file2 = "C:\\Users\\DEVI GIRI\\OneDrive\\Desktop\\DAA PROJECT SCOREBOARD.txt";

    cric[0] = "India";
    cric[1] = "Australia";
    cric[2] = "England";
    cric[3] = "New Zealand";
    cric[4] = "West Indies";
    cric[5] = "Pakistan";
    cric[6] = "Afghanistan";
    cric[7] = "Bangladesh";
    cric[8] = "Sri Lanka";
    cric[9] = "Zimbabwe";
    cric[10] = "Scotland";
    cric[11] = "Ireland";
    cric[12] = "Namibia";
    cric[13] = "Netherlands";

    ifstream fin;
    fin.open(file1);

    while (fin)
    {
           getline(fin, line);
           T = line;
           for(i=0;i<14;i++)
           {
                 if((T.find(": 1")!=-1 )&& (T.find(cric[i]) == 0))
                 {
                       j++;
                       if(j==1)
                            first = i;
                       else if(j==2)
                            second = i;
                       break;
                 }
           }
            if(j==1)
            {
                       c=0;
                       stringstream X(line);
                       while(getline(X,T,','))
                      {
                            c++;
                            int pos = T.find(": ");
                            if(c<=9)
                                 t1.push_back(T.substr(pos+4));
                           else
                                 t1.push_back(T.substr(pos+5));
                       }
                       continue;
            }
            else if(j==2)
            {
                       c=0;
                       stringstream X(line);
                       while(getline(X,T,','))
                      {
                            c++;
                           int pos = T.find(": ");
                           if(c<=9)
                                t2.push_back(T.substr(pos+4));
                          else
                                t2.push_back(T.substr(pos+5));

                     }
                     j++;
               }
               else if(j==3 && i==14)
                {
                       if((T.find(", 1 run")!=-1)&&(T.find(" to ")!=-1)&&(T.find(", ")>T.find(" to "))&&(T.find(", 1 run")==T.find(", ")))
                       {
                            // cout << T << endl;
                              stringstream X(line);
                              while(getline(X,T,' '))
                              {
                                    for(i=0;i<t1.size();i++)
                                    {
                                          if(t1[i].find(T)!=-1)
                                          {
                                                way = 2;
                                                break;
                                          }
                                          else if(t2[i].find(T)!=-1)
                                          {
                                                 way = 1;
                                                 break;
                                          }

                                    }
                                    break;
                              }
                               break;
                       }

                }
              //break;
    }


    if(way == 1)
    {
           for(i=0;i<t1.size();i++)
           {
                  bat.push_back(t1[i]);
                  ball.push_back(t2[i]);
           }

    }
    else if(way == 2)
    {
           for(i=0;i<t2.size();i++)
           {
                  bat.push_back(t2[i]);
                  ball.push_back(t1[i]);
           }
           swap(first,second);
    }

    cout <<"\n\n  ==============================================================\n";
    cout << "  ||      " <<cric[first]<<" Squad";
    j= 8;
    while(j--)
    {
        cout << " ";
    }
    cout << "  ||       "<<cric[second]<<" Squad       ||\n";
    cout <<"  ==============================================================\n";
    for(i=0;i<bat.size();i++)
    {
       f1name[i] = "",l1name[i] = "";
       pos1[i] = bat[i].find(" ");
       f1name[i] += bat[i].substr(0,pos1[i]);
       if((bat[i].substr(pos1[i]+1).find(" (")!=-1)||(bat[i].substr(pos1[i]+1).find(".")!=-1))
       {
           int pos=0;
           if((bat[i].substr(pos1[i]+1).find(" (")!=-1))
               pos = bat[i].substr(pos1[i]+1).find(" (");
           else
               pos = bat[i].substr(pos1[i]+1).find(".");
           l1name[i] += (bat[i].substr(pos1[i]+1)).substr(0,pos);

       }
       else
       {
            l1name[i] += bat[i].substr(pos1[i]+1);
            if(l1name[i] == "Dhawan")
                    l1name[i] = "S "+l1name[i];
            else if(bat[i] == "Rohit Sharma")
                    l1name[i] = "Rohit Sharma";
       }

       f2name[i] = "",l2name[i] = "";
       pos2[i] = ball[i].find(" ");
       f2name[i] += ball[i].substr(0,pos2[i]);

       if((ball[i].substr(pos2[i]+1).find(" (")!=-1)||(ball[i].substr(pos2[i]+1).find(".")!=-1))
       {
           int pos = 0;
           if((ball[i].substr(pos2[i]+1).find(" (")!=-1))
               pos = ball[i].substr(pos2[i]+1).find(" (");
           else
               pos = ball[i].substr(pos2[i]+1).find(".");
           l2name[i] += (ball[i].substr(pos2[i]+1)).substr(0,pos);
       }
       else
            l2name[i] += ball[i].substr(pos2[i]+1);

       string a="",b="";
       int k = 20-bat[i].length();
       while(k--)
       {
           a = a.append(" ");
       }
       k = 20-ball[i].length();
       while(k--)
       {
           b = b.append(" ");
       }
       bat[i] = bat[i]+a;
       ball[i] = ball[i]+b;
       if(i<=8)
            cout <<"  ||  "<<i+1<< "). " << bat[i]<<" ||    "<<i+1<< "). "<<ball[i]<<" ||  \n";
        else
            cout <<"  ||  "<<i+1<< "). " << bat[i]<<"||    "<<i+1<< "). "<<ball[i]<<"||\n";
    }
    cout <<"  ==============================================================\n";
    cout << endl << endl;
    fin.close();

    fin.open(file1);
    cout << "\nThe useful ball by ball commentary lines are the following.\n\n";
     int vis[50];
       for(i=0;i<50;i++)
       {
               vis[i]=0;
       }
    while(fin)
    {

       getline(fin, line);
       T = line;
       if((T.find(" to ")==-1)||(T.find(",")==-1))
       {
           continue;
       }
       static int n=0;
       for(i=0;i<11;i++)
       {
           if((T.find(f1name[i])==-1)&&(T.find(l1name[i])==-1))
                continue;
           for(j=0;j<11;j++)
           {
              if((T.find(f2name[j])==-1)&&(T.find(l2name[j])==-1))
                    continue;
              else
              {
                c1="",c2="",c3="",c4="";
                c1 = c1.append(f2name[j]);
                c1 = c1.append(" to ");
                c1 = c1.append(f1name[i]);
                c1 = c1.append(", ");

                c2 = c2.append(f2name[j]);
                c2 = c2.append(" to ");
                c2 = c2.append(l1name[i]);
                c2 = c2.append(", ");

                c3 = c3.append(l2name[j]);
                c3 = c3.append(" to ");
                c3 = c3.append(f1name[i]);
                c3 = c3.append(", ");

                c4 = c4.append(l2name[j]);
                c4 = c4.append(" to ");
                c4 = c4.append(l1name[i]);
                c4 = c4.append(", ");

                if((T.find(c1) != -1)||(T.find(c2) != -1)||(T.find(c3) != -1)||(T.find(c4) != -1))
                {
                     if((n%6== 0)&&((vis[n/6])==0) )
                     {
                           vis[(n/6)]=1;

                           if(n/6 == 0)
                                   cout <<endl <<(n/6)+1<<"st over\n\n";
                           else if(n/6 == 1)
                                   cout <<endl <<(n/6)+1<<"nd over\n\n";
                           else if(n/6 == 2)
                                   cout <<endl <<(n/6)+1<<"rd over\n\n";
                           else
                                   cout <<endl <<(n/6)+1<<"th over\n\n";
                     }
                    cout <<"  "<< T << "\n";

                    if(T.find(", 1 run") != -1)
                        num=1;
                    else if(T.find(", 2 runs") != -1)
                        num =2;
                    else if(T.find(", 3 runs") != -1)
                        num=3;
                    else if(T.find(", FOUR runs") != -1)
                    {
                        num=4;
                        fours[i]++;
                    }
                    else if(T.find(", SIX runs") != -1)
                    {
                        num=6;
                        sixes[i]++;
                    }
                    else if(T.find(", no run") != -1)
                    {
                        num = 0;
                        d[i]++;
                    }
                    else if(T.find(", OUT") != -1)
                    {
                        num=0;
                        w[j]++;
                    }
                    else if(T.find(", 1 wide") != -1)
                    {

                        num=1;
                        wd[j]++;
                        --runs[i];
                        --b[j];
                        --n;
                        --balls[i];
                    }
                    else if(T.find(", 1 leg bye")!=-1)
                    {
                        num = 1;
                        lb[j]++;
                        runs[i]--;
                        --r[j];
                    }
                    else if(T.find(", 1 bye")!=-1)
                    {
                        num = 1;
                        lb[j]++;
                        runs[i]--;
                        --r[j];
                    }
                    else if(T.find(", (no ball)")!=-1)
                    {
                        if(T.find(", (no ball) 1 run")!=-1)
                        {
                             num = 2;
                             nb[j]++;
                             --runs[i];
                             --b[j];
                             --n;

                        }
                        else
                        {
                             num = 1;
                             nb[j]++;
                             --runs[i];
                             --b[j];
                             --n;
                        }

                    }


                    runs[i]+=num;
                    balls[i]++;
                    r[j]+=num;
                    b[j]++;
                    ++n;
                 }
              }
           }
       }
    }

    for(i=0;i<11;i++)
    {
        if(runs[i]>0)
            str[i] = (float)(runs[i]*100.00)/balls[i];
        else if(runs[i]==0)
            str[i]=0;
        if(b[i]>0)
        {
              eco[i] = (float)(r[i]*6.00)/b[i];
              tot+=b[i];
        }
        else if(b[i]==0)
            eco[i]=0;
        tot+=lb[i];
        wic+=w[i];
    }
    crr = (float)(tot*6.00)/300;
    cout <<"\nThe total score at the end of first innings is "<< tot << "/"<<wic<<endl;
    cout << "The required run rate for the chasing team (or) the run rate of the batting team at the end of first innings is " << crr << endl << endl;
    fin.close();



    ofstream fout;
    fout.open(file2);
    i=0;
    transform(cric[first].begin(),cric[first].end(),cric[first].begin(),::toupper);
     transform(cric[second].begin(),cric[second].end(),cric[second].begin(),::toupper);
    fout << "\n              "<<cric[first]  <<" VS "<<cric[second]<<" ODI, 1ST INNINGS SCOREBOARD";
    fout << "\n              ----------------------------------------------\n\n";
    fout << "\nBATTING SCORECARD\n";
    fout << "-----------------\n\n";
    fout << left << setw(20) << "Batsman" << left << setw(8) << "Runs"<< left << setw(8) << "Balls"<< left << setw(8) << "Fours" << left << setw(8) <<"Sixes" <<left << setw(8)<< "Dots"<< left << setw(8)<<"S.Rate" << endl << endl << endl;
    while (fout && i<11)
    {
        fout << bat[i] << left << setw(8) << runs[i] <<left << setw(8) <<  balls[i] <<left << setw(8) << fours[i] << left << setw(8) <<sixes[i] <<left <<setw(8) << d[i]<<left << setw(8)<< str[i] << endl ;
        i++;
    }
    fout << "\n--------------------------------------------------------------------------------";
    fout << "\n--------------------------------------------------------------------------------\n\n";


    fout << "\nBOWLING SCORECARD\n";
    fout << "-----------------\n\n";
    i=0;
    fout << left << setw(20) << "Bowler" << left << setw(8) << "Overs"<< left << setw(8) <<"Wickets" <<left << setw(8) << "Runs" <<left << setw(8) << "Wide"<< left << setw(8) << "N.Balls" <<left << setw(8) << "Byes"<<left << setw(8)<<"E.Rate"<< endl << endl << endl;
    while (fout && i<11)
    {
        fout   << ball[i] <<  left << setw(8) <<(b[i]/6)<< left << setw(8)  << w[i]<<left << setw(8)  << r[i]<< left << setw(8)  << wd[i] << left << setw(8) << nb[i]<<left <<setw(8)<< lb[i]<<left <<setw(8) << eco[i]<< endl;
        i++;
    }
    fout << "\n---------------------------------------------------------------------------------";
    fout << "\n---------------------------------------------------------------------------------\n\n";
    fout << "\nThe total score at the end of first innings is "<< tot << "/"<<wic<<endl<<endl;
    fout << "The required run rate for the chasing team (or) the run rate of the batting team at the end of first innings is " << crr << endl << endl;
    fout.close();

    return 0;
}
