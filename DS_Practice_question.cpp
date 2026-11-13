// Q.1 ) LEFT ROTATION 
// LEFT ROTATION & RIGHT ROTATE  
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

//left rotation
void leftrotate(int arr[],int n,int k){
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
    reverse(arr,arr+n);
}

//right rotation
void rightrotate(int arr[],int n,int k){
    reverse(arr,arr+n-k);
    reverse(arr+n-k,arr+n);
    reverse(arr,arr+n);
}

int main() 
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int left[100];
    int right[100];
    for(int i=0;i<n;i++){
        left[i]=arr[i];
        right[i]=arr[i];
    }
    int k=2;
    k=k%n;
    leftrotate(left,n,k);
    rightrotate(right,n,k);
    cout<<"left rotate : ";
    for(int i=0;i<n;i++){
        cout<<left[i]<<" ";
    }
    cout<<endl;
    cout<<"right rotate : ";
    for(int i=0;i<n;i++){
        cout<<right[i]<<" ";
    }
}

/*-------------------------------------------------------------------------------------------*/


// Q.2) ADDITION AND MULTIPLICATION OF TWO MATRICES
#include <iostream>
using namespace std;

int main() 
{
    int r1,r2,c1,c2;
    cout<<"enter r1,r2,c1,c2 : ";
    cin>>r1;
    cin>>r2;
    cin>>c1;
    cin>>c2;

    int arr1[r1][c1];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin>>arr1[i][j];
        }
    }
    int arr2[r2][c2];
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin>>arr2[i][j];
        }
    }
    int sm[r1][c1];
    
    //addition
    if(r1==r2 && c1==c2){
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                sm[i][j]=arr1[i][j]+arr2[i][j];
            }
        }
        cout<<"addition : \n";
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                cout<<sm[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"addition not possible ";
    }

    //multiplication
    int mul[r1][c2];
    if(c1==r2){
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                mul[i][j]=0;
                for(int k=0;k<c1;k++){
                    mul[i][j] += (arr1[i][k] * arr2[k][j]);
                }
            }
        }
        cout<<"multiplication : \n";
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                cout<<mul[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"multiplication not possible ";
    }
}

/*-------------------------------------------------------------------------------------------*/


// Q.10 ) PALINDROME CHECK USING DOUBLY ENDED QUEUE
#include <iostream>
#include<deque>
using namespace std;

int main() 
{
    string str;
    cout<<"enter string : ";
    cin>>str;
    deque<char>dq;
    for(char ch : str){
        dq.push_back(ch);
    }
    bool ispalindrome=true;
    while(dq.size()>1){
        if(dq.front()!=dq.back()){
            ispalindrome=false;
            break;
        }
        dq.pop_front();
        dq.pop_back();
    }
    if(ispalindrome){
        cout<<"it's palindrome";
    }
    else{
        cout<<"not a palindrome";
    }
}

/*-------------------------------------------------------------------------------------------*/

// Q.11) INSERT , SEARCH FOR PHONE DIARY 

#include <iostream>
#include<deque>
using namespace std;

class Friend{
public:
    string name;
    string num;
};

int main() 
{
    Friend pb[101];
    int n;
    cout<<"number of entry : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>pb[i].name>>pb[i].num;
    }
    //sorting based on name
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(pb[j].name>pb[j+1].name){
                swap(pb[j],pb[j+1]);
            }
        }
    }

    string serachname;
    cout<<"enetr search name : ";
    cin>>serachname;
    string phone;
    pb[n].name=serachname;
    int i=0;
    while(pb[i].name!=serachname){
        i++;
    }
    if(i<n){
        cout<<"name found \n";
        cout<<"number of "<<serachname<<" : "<<pb[i].num<<"\n";
    }
    else{
        cout<<"name not found \n";
        cout<<"enter a number to insert entry : ";
        cin>>phone;
        int pos=0;
        while(pos<n && pb[pos].name<serachname){
            pos+=1;
        }
        for(int j=n;j>pos;j--){
            pb[j]=pb[j-1];
        }
        pb[pos].name=serachname;
        pb[pos].num=phone;
        n+=1;
        cout<<"new friend inserted successfully \n";
        }
    cout<<"print sorted pb \n";
    for(int i=0;i<n;i++){
        cout<<pb[i].name<<" "<<pb[i].num<<" ";
    }

}

/*-------------------------------------------------------------------------------------------*/


// Q.12) FLOAT marks enter MERGESORT it  .

#include <iostream>
#include<deque>
using namespace std;

void merge(float arr[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    float temp[100];
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i+=1;
        }
        else{
            temp[k]=arr[j];
            j+=1;
        }
        k+=1;
    }
    while(i<=mid){
        temp[k]=arr[i];
        i+=1;
        k+=1;
    }
    while(j<=high){
        temp[k]=arr[j];
        j+=1;
        k+=1;
    }
    for(int i=0;i<=high;i++){
        arr[i]=temp[i];
    }
}

void mergesort(float arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main() 
{
    int n;
    cout<<"number of student : ";
    cin>>n;
    float arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    cout<<"enter sorted marks : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

