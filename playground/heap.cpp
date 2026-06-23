#include<bits/stdc++.h>
using namespace std;
class heap{
    private:
        vector<int> arr;
        int size = 0;
    public:
        heap(int size){
            arr.resize(size+1);
        }
        void insert(int num){
            //don't modify the size
            size = size+1;
            if(size > size+1){
                cout<<"heap full";
                return;
            }
            arr[size] = num;
            int idx = size;

            //now we have to check if it's on the correct position
            int parent_idx = idx / 2;
            while(parent_idx > 0 && arr[parent_idx] < arr[idx]){
                swap(arr[parent_idx] , arr[idx]);
                idx = idx/2;
                parent_idx = parent_idx/2;
            }
        }
        void deletefromheap(){//deleting here means deleting the root node 
            if(size==0){
                cout<<"Nothing to delete.";
                return;
            }
            arr[1] = arr[size];
            size--;

            int i = 1;
            
            while(i < size){
                int largest = i;
                int l = i * 2;
                int r = i * 2 + 1;

                if(l <= size && arr[l] > arr[largest]) largest = l;
                if(r <=size && arr[r] > arr[largest]) largest  = r;
                if(largest == i) break;
                swap(arr[i], arr[largest]);
                i = largest;
            }

        }
        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ,";
            }
            cout<<endl;
        }
};
int main(){
    char x = 'y';
    heap heap1(20);
    // do{
    //     int a;
    //     cout<<"Press 1 for insertion & 2 for print\n";
    //     cin>>a;
    //     switch(a){
    //         case 1:
    //             cout<<"Enter the no.->";
    //             int temp;
    //             cin>>temp;
    //             heap1.insert(temp);
    //             break;
    //         case 2:
    //             heap1.print();
    //     }

    //     cout<<"\nDo you want to continue";
    //     cin>>x;
    // }while(x=='y');

    heap1.insert(90);
    heap1.insert(50);
    heap1.insert(55);
    heap1.insert(45);
    heap1.insert(46);
    heap1.insert(51);
    heap1.insert(52);
    heap1.insert(40);
    heap1.deletefromheap();
    heap1.print();
    return 0;

}