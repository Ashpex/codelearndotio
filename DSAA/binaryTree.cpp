#include <iostream>
#include <math.h>
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

void Input(TNode*& BTree, int n){
    for(int i = 0; i < n; i++){
        int value = 0;
        cin >> value;
        BTree = Insert(BTree,value);
    }
}

bool isLeafNode(TNode *l){
	return (l->pLeft == nullptr && l->pRight == nullptr);
}

int countLeafNode(TNode* BTree){
    if(BTree == nullptr){
        return 0;
    }
    if(isLeafNode(BTree)){
        return 1;
    }
    return countLeafNode(BTree->pLeft) + countLeafNode(BTree->pRight);
}

int treeLevel(TNode* BTree){
    if(BTree == nullptr){
        return -1;
    }
    return 1 + max(treeLevel(BTree->pLeft), treeLevel(BTree->pRight));   
}

bool isAVL(TNode* BTree){
    if(BTree == nullptr){
        return true;
    }
    if (abs(treeLevel(BTree->pLeft) - treeLevel(BTree->pRight) > 1)){
        return false;
    }
    return isAVL(BTree->pLeft) && isAVL(BTree->pRight);
}

TNode* turnRight(TNode* a){
    TNode* b = a->pLeft;
    TNode* d = b->pRight;
    a->pLeft = d;
    b->pRight = a;
    return b;
}

TNode* turnLeft(TNode* a){
    TNode* b = a->pRight;
    TNode* c = b->pLeft;
    a->pRight = c;
    b->pLeft = a;
    return b;
}

TNode* updateTreeAvl(TNode* T){
    if(abs(treeLevel(T->pLeft) - treeLevel(T->pRight)) > 1){
        if(treeLevel(T->pLeft) > treeLevel(T->pRight)){
            TNode* p = T->pLeft;
            if(treeLevel(p->pLeft) >= treeLevel(p->pRight)){
                T = turnRight(T);
            }
            else{
                T->pLeft = turnLeft(T->pLeft);
                T = turnRight(T);
            }
        }
        else{
            TNode* p = T->pRight;
            if(treeLevel(T->pRight) >= treeLevel(T->pLeft)){
                T = turnLeft(T);
            }
            else{
                T->pRight = turnRight(T->pRight);
                T = turnLeft(T);
            }
        }
    }
    if(T->pLeft != nullptr) {
        T->pLeft = updateTreeAvl(T->pLeft);
    }
    if(T->pRight != nullptr){
        T->pRight = updateTreeAvl(T->pRight);
    }
    return T;
}

int main(){
    int n = 0;
    int x = 0;
    TNode* BTree = nullptr;
    cin >> n;
    Input(BTree,n);
	while(!isAVL(BTree)){
		BTree = updateTreeAvl(BTree);		
	}
	cout << treeLevel(BTree);
    Free(BTree);
    return 0;
}