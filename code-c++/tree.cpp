#include<bits/stdc++.h>
using namespace std;

char content[]="ABDH#K###E##CFI###G#HJ###";
int idx=0;

struct Tree{
    char data;
    Tree *left_child;
    Tree *right_child;
};

typedef Tree* BiTree;                  // 只此一个：BiTree = Tree*

void creatTree(BiTree *root)           // BiTree* 就是 Tree**，双指针
{
    char ch=content[idx];            // 1. 取一个字符，游标后移
    idx++;

    if(ch=='#')                        // 2. 空孩子
    {
        *root=NULL;                    //    *root = 外面那个 BiTree 变量本身
    }
    else
    {
        *root=new Tree;                // 3. 造节点，写进外面的变量
        (*root)->data=ch;              // 4. 填数据
        creatTree(&(*root)->left_child);   // 5. 传左孩子指针的地址 Tree**
        creatTree(&(*root)->right_child);  // 6. 传右孩子指针的地址 Tree**
    }
}
//1: main 里 root 这个槽，门牌号是 &root（0x7fff9255cfe0），内容一开始是 NULL。
//   creatTree 收到这个门牌号。
//   new Tree 得到一块新内存，地址 0x5b8648a51050,地址是指向Tree类型的。
//   把它写进槽：门牌号 0x7fff9255cfe0 那一格的内容 NULL → 0x5b8648a51050。
//   再把 'A' 写进这块内存的 data 字段（节点第 0 字节）。
//   然后把 A 的 left_child 槽的门牌号（0x5b8648a51050 + 8 = 0x5b8648a51058）传下去。

//2: 收到门牌号 0x5b8648a51058 —— 这是 A 的 left_child 槽，此时内容是 NULL。
//   new Tree 得到 0x5b8648a520b0。
//   把它写进槽：0x5b8648a51058 那一格的内容 NULL → 0x5b8648a520b0。
//   再把 'B' 写进这块内存的 data 字段。
//   然后把 B 的 left_child 槽的门牌号（0x5b8648a520b0 + 8 = 0x5b8648a520b8）传下去。

void preOrder(BiTree root)             // 这里只要 Tree*，一个 typedef 就够
{
    if(root==NULL)return;

    cout<<root->data;
    preOrder(root->left_child);
    preOrder(root->right_child);
}

int main()
{
    BiTree root;//Tree *root;设一个装Tree的地址的参数,&root就是参数的地址,root就是参数的内容
    root=NULL;//参数的内容是NULL
    creatTree(&root);                  // 把装节点地址的地址传到creatTree里
    //然后判断是否有东西，有东西就分配内存给BitTree,然后Tree指向新的BirTree.

    preOrder(root);
    cout<<endl;

    return 0;
}