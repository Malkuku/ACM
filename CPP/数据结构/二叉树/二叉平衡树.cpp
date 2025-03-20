#include<bits/stdc++.h>

class BalanceTree{
public:   
    struct Node{ //基本节点
        int key,val;  //存储数据----搜索树结构由key决定
        Node *left,*right; //左右节点
        int height; //高度
        Node(int key,int val) : key(key),val(val),left(NULL),right(NULL),height(1){} //构造
        Node(int key) : key(key),val(0),left(NULL),right(NULL),height(1){} 
    };

     Node* head = NULL;

public:
    BalanceTree(Node* head){
        this->head = head;
    };
    ~BalanceTree() = default;
    //获取高度
    int getHeight(Node* node){
        return node ? node->height : 0;
    }
    //更新高度
    void updateHeight(Node* node){
        node->height = 1 + std::max(getHeight(node->left),getHeight(node->right));
        //自平衡操作
        node = reBalance(node);
    }
    //插入节点
    Node* insertNode(Node* node,int key,int val){
        if(!node) return new Node(key,val);
        if(key < node->key) node->left = insertNode(node->left,key,val);
        else if(key > node->key) node->right = insertNode(node->right,key,val);
        else node->val = val;
        updateHeight(node);
    }
    //删除节点
    Node * deleteNode(int key,Node* node){
        if(!node) return NULL;
        if(key < node->key) node->left = deleteNode(key,node->left);
        else if(key > node->key) node->right = deleteNode(key,node->right);
        else{
            if(!node->left || !node->right){
                Node* tmp = node->left ? node->left : node->right;
                if(!tmp){
                    tmp = node;
                    node = NULL;
                } 
                else *node = *tmp; // ???
                delete tmp;
            }
            else{
                //与最小值交换后删除最小值位置
                Node* tmp = minValueNode(node->right); 
                node->key = tmp->key;
                node->val = tmp->val;
                node->right = deleteNode(tmp->key,node->right);
            }
        }
        if(!node) return node;
        updateHeight(node);
    }
    //当前子树最小值节点
    Node *minValueNode(Node* node){
        Node* ptr = node;
        while(ptr && ptr->left) ptr = ptr->left;
        return ptr;
    }
    //计算当前节点平衡值
    int getBalanceValue(Node* node){
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }  
    //右旋
    Node* rotateRight(Node* y){
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }
    //左旋
    Node* rotateLeft(Node* y){
        Node* x = y->right;
        Node* T2 = x->left;
        x->left = y;
        y->right = T2;
        updateHeight(x);
        updateHeight(y);
        return x;
    }
    //平衡操作
    Node* reBalance(Node* node){
        int balance = getBalanceValue(node); //获取平衡因子值
        //LL
        if(balance > 1 && getBalanceValue(node->left) >= 0){
            return rotateRight(node);
        } 
        //LR
        if(balance > 1 && getBalanceValue(node->left) < 0){
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        //RR
        if(balance < -1 && getBalanceValue(node->right) <= 0){
            return rotateLeft(node);
        }
        //RL
        if(balance < -1 && getBalanceValue(node->right) > 0){
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    //打印二叉树
    void printBalanceTree(Node* node){
        if(node == NULL) return;
        std::cout << node->key << " ";
        printBalanceTree(node->left);
        printBalanceTree(node->right);
    }
};


int main(){
    BalanceTree tree(new BalanceTree::Node(1));
    tree.insertNode(tree.head,4,0);
    tree.insertNode(tree.head,3,0);
    tree.insertNode(tree.head,5,0);
    tree.insertNode(tree.head,2,0);

    tree.printBalanceTree(tree.head);

    //测试插入操作
    return 0;
}