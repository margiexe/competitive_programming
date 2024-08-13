#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

class MinHeap{
    private:

    vector<int> heap;

    int parent(int index){
        return (index-1)/2;
    }

    int left(int index){
        return index*2+1;
    }

    int right(int index){
        return index*2+2;
    }

    void swap(int i, int j){
        int temp = heap[i]; 
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void upheap(int index){
        if(index==0) return;
        int p = parent(index);
        if(heap[index]<heap[p]){
            swap(index,p);
            upheap(p);
        }
    }

    void downheap(int index){
        int l = left(index);
        int r = right(index);
        int small = index;
        if(l<heap.size() && heap[l]<heap[small]){
            small = l;
        }
        if(r<heap.size() && heap[r]<heap[small]){
            small = r;
        }
        if(small!=index){
            swap(index,small);
            downheap(small);
        }
    }

    public:

    MinHeap() {}

    void insert(int num){
        heap.push_back(num);
        upheap(heap.size()-1);
    }

    void removemin(){
        if(heap.empty()){
            return;
        }
        int mini = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if(!heap.empty()) downheap(0);
    }

    int getmin(){
        if(heap.size()==0){
            return 0;
        }
        return heap[0];
    }

    bool isempty(){
        return heap.size()==0;
    }

    void print(){
        for(auto &x:heap){
            cout<<x<<" ";
        }
        cout<<endl;
    }
};

void solve() {
    MinHeap h;
    h.insert(2);
    h.insert(4);
    h.insert(5);
    h.insert(19);
    h.insert(1);
    h.insert(10);
    h.print();
    cout<<h.getmin()<<endl;
    h.isempty();
    h.removemin();
    h.print();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
