#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct _BSTNode{
    int data;
    _BSTNode* left;
    _BSTNode* right;
    _BSTNode(int x): data(x), left(NULL), right(NULL) {}
}BSTNode;

class BinarySrchTree{
private:
    BSTNode* root = NULL;
    
    BSTNode* Insert(BSTNode* node, int val){
        if (node == NULL){
            return new BSTNode(val);
        }else if(val <= node->data){
            node->left = Insert(node->left, val);
        }else{
            node->right = Insert(node->right, val);
        }
        return node;
    }
    
    bool Search(BSTNode* node, int val){
        if(node == NULL) return false;
        else if(node->data == val) return true;
        else if(val <= node->data) return Search(node->left, val);
        else return Search(node->right, val);
    }
    
    vector<int> LevelOrder(BSTNode* node){
        vector<int> arr;

        if(node == NULL) return arr;
        
        queue<BSTNode*> Q;
        Q.push(node);
        
        while(!Q.empty()){
            BSTNode* curr_node = Q.front();
            
            arr.push_back(curr_node->data);
            
            Q.pop();
            if(curr_node->left != NULL) Q.push(curr_node->left);
            if(curr_node->right != NULL) Q.push(curr_node->right);
        } 
        
        return arr;
    }
    
public:
    void Insert(int val){
        root = Insert(root, val);
    }
    
    bool Search(int val){
        return Search(root, val);
    }
    
    vector<int> LevelOrder(){
        return LevelOrder(root);
    }
};

int main() {
    
    BinarySrchTree tree1;
    tree1.Insert(15);
    tree1.Insert(7);
    tree1.Insert(20);
    tree1.Insert(3);
    tree1.Insert(25);
    tree1.Insert(8);
    tree1.Insert(12);
    tree1.Insert(11);
    
    if(tree1.Search(6)){
        printf("6 found\n");
    }else{
        printf("6 not found\n");
    }

    if(tree1.Search(12)){
        printf("12 found\n");
    }else{
        printf("12 not found\n");
    }
    
    vector<int> arr = tree1.LevelOrder();
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}
