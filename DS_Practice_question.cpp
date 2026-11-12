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

