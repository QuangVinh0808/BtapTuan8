#include <iostream>

using namespace std;

//typedef Node* node;

struct Node{
    int mu;
    int heso;
    Node* next;
};
typedef Node* node;
node taoNode(int _mu, int _heso)
{
    node tmp = new Node();
    tmp->mu = _mu;
    tmp->heso = _heso;
    tmp->next = NULL;
    return tmp;
}

void display(node head){
    while(head != NULL){
        if(head->mu == 0){ 
            cout << head->heso;
            return;
        }
        else
        {
            cout << head->heso << "x^" << head->mu;
            if(head->next && head->next->heso > 0) cout << " + ";
            head = head->next;
        }
    }
    
}

void themNode(node &head, int _somu, int _heso){
    if(_heso == 0) return;
    node moi = taoNode(_somu, _heso);
    if(head == NULL){
        head = moi;
    }
    else{
        node tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = moi;
    }
}
int main()
{
    int n; // Bac cua da thuc
    cin >> n;

    node head = NULL;
    for(int i = n; i >= 0; i--)
    {
        int x; // he so
        cout << "Nhap he so cua x^" << i << ' ';
        cin >> x;
        themNode(head, i, x);
    }

    display(head);
}