#include<sstream>
#include <iostream>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include <ctime>
#include<map>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<iterator>
#include<string.h>
#define MAX 500
int table[MAX];
using namespace std;
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
}

struct s
{
    int day,month,year;
    int parity,f=0;
    char c[100];
};
const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;

// Returns true if
// given year is valid.



// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    // create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there
      // are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there
//       are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
   //sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
bool isLeap(int year)
{
// Return true if year
// is a multiple pf 4 and
// not multiple of 100.
// OR year is multiple of 200.
return (((year % 4 == 0) &&
         (year % 100 != 0)) ||
         (year % 200 == 0));
}

// Returns true if given
// year is valid or not.
bool isValidDate(int d, int m, int y)
{
    // If year, month and day
    // are not in given range
    if (y > MAX_VALID_YR ||
        y < MIN_VALID_YR)
    return false;
    if (m < 1 || m > 12)
    return false;
    if (d < 1 || d > 31)
    return false;

    // Handle February month
    // with leap year
    if (m == 2)
    {
        if (isLeap(y))
        return (d <= 29);
        else
        return (d <= 28);
    }

    // Months of April, June,Sept and Nov must have number of daysless than or equal to 30.
    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);

    return true;
}
void shifttable(string p,int n)
{
    for(int i=0;i<250;i++)
        table[i]=n-1;
    for(int j=0;j<n-1;j++)
    {
        table[p[j]]=n-1-j;
    }
}
int horspool(string p,string t)
{
     int i=p.size()-1,m=t.size();
     int n=p.size();
   while(i<=m-1)
   {
       //cout<<setw(100)<<i<<endl;
       int k=0;
       while((k<=n-1)&&(p[n-1-k]==t[i-k]))
       {
            k=k+1;
       }
       if(k==n)
       {
           //cout<<setw(100)<<"the string is found at position"<<i-n+2;
           return 1;
       }
       else
        {
             i=i+table[t[i]];
        }
   }
   return 0;
}
int main() {
    char x=178;

   // current Date/time based on current system
   system("color 09");
   system("cls");
         for(int i=0;i<10;i++)
            cout<<endl;
            for(int i=0;i<3;i++)
               {
                   delay(1);
                    cout<<setw(107)<<x<<x<<x<<x<<x<<x<<x<<endl;
               }
            for(int i=0;i<3;i++)
            {
                delay(1);
                cout<<setw(100);
                if(i==1)
                    cout<<x<<x<<x<<x<<x<<x<<x<<x<<x<<x<<x<<x<<x<<"PLANNER";

                else{
                        for(int j=0;j<20;j++)
                    cout<<x;}

                cout<<endl;
            }
            for(int i=0;i<3;i++)
                cout<<setw(107)<<x<<x<<x<<x<<x<<x<<x<<endl;
                cout<<setw(125)<<"ADD YOUR IDEAS"<<endl;

   system("color 09");
   system("color 0A");
   delay(1);
   system("color 0c");
   delay(1);
   system("color 09");
    time_t now = time(0);
    char c1,c2,task[100],line[100];
    int cnt=0,f=0,arr[100],fl=0,i,ch;
    struct s cDate,s1[100];
     //char* dt = ctime(&now);
    tm *ltm = localtime(&now);
    fstream fi;
    do
    {

        system("cls");
        for(int i=0;i<10;i++)
            cout<<endl;
        cout<<setw(100)<<"TODAY'S NOTIFICATION"<<endl;
        cout<<x;
                        for(int u=0;u<cnt;u++)
                        {
                            if(s1[u].day==ltm->tm_mday&s1[u].month==(1+ ltm->tm_mon)&s1[u].year==(1900 + ltm->tm_year))
                            {
                                cout<<setw(100)<<s1[u].c;
                                fl++;
                            }
                        }
                        if(fl==0)
                        {
                            cout<<endl<<setw(103)<<"No notification for today"<<endl;
                        }
        for(int i=0;i<10;i++)
            cout<<endl;
        cout<<endl<<setw(85)<<"1.New Reminder"<<endl<<setw(87)<<"2.View Reminders"<<endl<<setw(100)<<"3.Search Reminder of the date"<<endl<<setw(88)<<"4.Search reminder"<<endl<<setw(77)<<"5.Exit"<<endl<<endl<<setw(89)<<"Enter your choice"<<endl<<setw(100)<<endl;
        cin>>ch;
        cnt=0;
        fi.open("task");
        while (fi.getline( line,100))
            cnt++;
        //cout<<endl<<setw(100)<<setw(100)<<cnt;
        fi.close();
        fi.open("task");
        for(int u=0;u<cnt;u++)
        {
            char d[5],m[5],y[5];
            fi.getline(d,100,'/');
            stringstream g1,g2,g3;
            g1<<d;
            g1>>s1[u].day;
            fi.getline(m,100,'/');
            g2<<m;
            g2>>s1[u].month;
            fi.getline(y,100,':');
            g3<<y;
            g3>>s1[u].year;
            fi.getline(s1[u].c,100);
            s1[u].parity=s1[u].day+s1[u].month*30+s1[u].year*365;
            arr[u]=s1[u].parity;
        }
        mergeSort(arr,0,cnt-1);
        fi.close();
        switch(ch)
        {
            case 1:{
                        do
                        {
                            i=0;
                            cout<<setw(100)<<"Enter Date dd/mm/yy format"<<endl;
                            cin>>cDate.day>>c1>>cDate.month>>c2>>cDate.year;
                            if (c1!='/' || c2!='/')
                            {
                                cout<<setw(100)<<"Please follow the format specified"<<endl;
                                i++;
                            }
                            if(!(isValidDate(cDate.day,cDate.month,cDate.year)))
                            {
                                i++;
                                cout<<setw(100)<<"Date doesnot exists"<<endl;
                            }
                            cin.ignore();
                            // convert now to string form
                            if(i==0)
                            {
                                if(cDate.year<(1900+ltm->tm_year))
                                {
                                    f=1;
                                    cout<<setw(100)<<"Expired year"<<endl;
                                }
                                else
                                {
                                    if (cDate.year==(1900+ltm->tm_year))
                                    {
                                        if(cDate.month<(1+ltm->tm_mon))
                                        {
                                            cout<<setw(100)<<"Expired month"<<endl;
                                            f=1;
                                        }
                                        else
                                            if(cDate.month==(1+ltm->tm_mon))
                                            {
                                                if(cDate.day<ltm->tm_mday)
                                                {
                                                    cout<<setw(100)<<"Expired Date"<<endl;
                                                    f=1;
                                                }
                                            }
                                        }
                                    }

                                if(f==0 && i==0)
                                {
                                    cout<<setw(100)<<"Enter memo"<<endl;
                                    cin.getline(task,100);
                              //      break;
                                }}
                            }while(i!=0 && f==1);
                            //cout<<setw(100)<<"ur memo"<<task<<endl;
                            //convert Date to string
                            stringstream ss;
                            string D;
                            ss<<cDate.day<<'/'<<cDate.month<<'/'<<cDate.year;
                            ss>>D;
                            //map with Date as key and memo as value
                            // insert elements into map
                            map<string, char*> map1;
                            map1.insert(pair<string, char*>(D,task));
                            map<string, char*>::iterator itr;
                            //store map in file
                            fi.open("task",ios_base::app);
                            if(f==0 && i==0)
                            {for (itr=map1.begin(); itr!=map1.end(); ++itr)
                            {
                                fi <<itr->first<<":"<< itr->second<<endl ;
                            }}
                            fi.close();
                        }
                        break;

            case 2:{int c=0;
                        system("cls");
                 for(int i=0;i<20;i++)
                    cout<<endl;
                cout<<setw(100)<<"REMINDER"<<endl<<endl<<endl;
                        for(int u=0;u<cnt;u++)
                        {
                            for(int v=0;v<cnt;v++)
                            {
                                if(s1[v].parity==arr[u] && s1[v].f==0 && s1[v].day!=0)
                                {   c++;
                                    cout<<setw(100)<<"Date:"<<s1[v].day<<"/"<<s1[v].month<<"/"<<s1[v].year<<setw(20)<<"Reminder:"<<s1[v].c<<endl<<endl<<endl;
                                    s1[v].f=1;
                                }
                            }
                        }
                        if (c==0)
                            cout<<"No reminder set"<<endl;
                        getch();
                    }
                    break;
            case 3:
                {
                    system("cls");
                    for(int i=0;i<20;i++)
                        cout<<endl;
                    cout<<setw(100)<<"Enter Date to check"<<endl;
                    do
                        {
                            i=0;
                            cout<<setw(100)<<"Enter Date dd/mm/yy format"<<endl;
                            cin>>cDate.day>>c1>>cDate.month>>c2>>cDate.year;
                            if (c1!='/' || c2!='/')
                            {
                                cout<<setw(100)<<"Please follow the format specified"<<endl;
                                i++;
                            }
                            if(!(isValidDate(cDate.day,cDate.month,cDate.year)))
                            {
                                i++;
                                cout<<setw(100)<<"Date does not exists"<<endl;
                            }
                        }while(i!=0);
                                if(i==0)
                                {
                                    int chck,p=0;

                                    chck=cDate.day+cDate.month*30+cDate.year*365;
                                    system("cls");
                                    for(int i=0;i<20;i++)
                                        cout<<endl;
                                    cout<<setw(100)<<"Reminder"<<endl;
                                    for(int u=0;u<cnt;u++)
                                    {
                                        if (s1[u].parity==chck)
                                        {
                                            p=1;
                                            //system("cls")
                                            //cout<<setw(100)<<"+REMINDER"<<endl<<endl<<endl;
                                            cout<<setw(100)<<"+"<<s1[u].c<<endl;
                                        }
                                    }
                                    if (p==0)
                                        cout<<setw(100)<<"No reminder"<<endl;
                                }
                            getch();
                }
                break;
            case 4:
            {
                int c=0;
                system("cls");
                for(int i=0;i<20;i++)
                    cout<<endl;
                cout<<setw(100)<<"Enter reminder to search"<<endl;
                 string p,t;
                getline(cin,p);
                getline(cin,p);
                int n=p.size();
                shifttable(p,n);
                system("cls");
                 for(int i=0;i<20;i++)
                    cout<<endl;
                cout<<setw(100)<<"REMINDER"<<endl<<endl<<endl;

                for(int i=0;i<cnt;i++)
                {
                    int pos=0;
                    pos=horspool(p,s1[i].c);
                    if(pos==1)
                       {c++;
                        cout<<setw(80)<<s1[i].day<<"/"<<s1[i].month<<"/"<<s1[i].year<<setw(20)<<s1[i].c<<endl;
                       }
                }
                if (c==0)
                    cout<<"No reminder found";getch();
            }break;
            case 5:exit(0);
            default:cout<<setw(100)<<"Invalid choice"<<endl;
        }
    }while(1);
}
