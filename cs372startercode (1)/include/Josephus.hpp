
//

#pragma once

#include<iostream>


using namespace std;
struct Node{
    int num;
    Node *next;
};

class Josephus{
private:
    // list<int> Jose;
    Node *first;
    Node *p;
public:
    Josephus(){
        first = new Node;
        first -> num = 1;
        first ->next =first;
    };
    void createJose(int N);
    void printJose();
    //void Josephusring(int N,int M);
    void deleteJose(int M, int N);
    Node *getJose(){return first;}
};

void Josephus::createJose(int N){
    Node *s =first ;
    s = first->next;
    for (int i=2; i<=N; ++i) {
        Node *q = new Node;
        q->num = i;
        q->next = first;
        s->next =q;
        s=q;
    }
}

void Josephus::printJose(){
    cout << first->num <<" ";
    Node *q = first->next;
    while ( q != first) {
        cout << q->num <<" ";
        q = q->next;
    }
    cout <<endl;
}

void Josephus::deleteJose(int M, int N){
    Node *q = nullptr, *s =nullptr; //q for the pre of p, s for each time the first one to pass
    int Nleft = N;
    s=first;
    //cout<<p->num <<endl;
    if (M > 0) {
        while (Nleft != 1) {
            //cout<< "1"<<endl;
            p = s;
            for (int i = 1; i <= M; ++i) {
                q = p;
                p = p->next;
                s = p->next;
            }
            cout << p->num << " ";
            if (p->next !=NULL){
                q->next = p->next;
            }
            else{
                q->next = first;
            }
            
            delete p;
            
            --Nleft;
        }
        cout<<endl;
        //cout << q->next->num<<" ";
    }
    else {
        while (Nleft !=1) {
            p =s;
            s=p->next;
            cout<< p->num <<" ";
            delete p;
            
            --Nleft;
        }
        cout<<endl;
        //   p= p->next;
        
    }
    p=p->next;
    cout <<"Number "<< p->num << " win!";
    
}


