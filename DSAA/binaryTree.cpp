#include <iostream>
using namespace std;

struct TNode{
    int data;
    TNode* pLeft;
    TNode* pRight;
};

TNode* BTree;

TNode* createNode(int r_value){
    TNode* node = new TNode;
    if(!node){
        cout << "\nNot enough memory.";
        exit(0);
    }
    node->data = r_value;
    node->pLeft = node->pRight = nullptr;
    return node;
}

TNode* Insert(TNode* BTree, int r_value){
    if(BTree == nullptr){
        TNode* p = createNode(r_value);
        if(!p){
            cout << "\nNot enough memory.";
            exit(0);
        }
        else{
            BTree = p;
            return p;
        }
    }
    else{
        if(r_value < BTree->data){
            BTree->pLeft = Insert(BTree->pLeft,r_value);
        }
        else{
            BTree->pRight = Insert(BTree->pRight,r_value);
        }
        return BTree;
    }
}

void InOrder_LNR(TNode* BTree){
	if (BTree != NULL){
		InOrder_LNR(BTree->pLeft);
		cout << BTree->data << " " ;
		InOrder_LNR(BTree->pRight);
	}
}

void PreOrder_NLR(TNode* BTree){
	if (BTree != NULL){
		cout << BTree->data << " " ;
		PreOrder_NLR(BTree->pLeft);
		PreOrder_NLR(BTree->pRight);
	}
}

void PostOrder_LRN(TNode* BTree){
    if(BTree != NULL){
		PreOrder_NLR(BTree->pLeft);
		PreOrder_NLR(BTree->pRight);
        cout << BTree->data << " ";
    }
}

void Free(TNode* BTree)
{
    if(BTree==NULL)return;
    delete BTree->pLeft;
    delete BTree->pRight;
    delete BTree;
}

int main(){
    int n = 0;
    int x = 0;
    cin >> n;
    TNode* BTree = nullptr;
    for(int i = 0; i < n; i++){
        cin >> x;
        BTree = Insert(BTree,x); 
    }
    InOrder_LNR(BTree);
    Free(BTree);
    return 0;
}