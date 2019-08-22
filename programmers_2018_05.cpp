#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > answer(2);


typedef struct node{
    int x;
    int num;
    struct node * left;
    struct node * right;
};

typedef struct q_node{
    int x;
    int y;
    int num;
};

struct compare{
    bool operator()(q_node a, q_node b)
    {
        if(a.y == b.y)
        {
            return a.x > b.x;
        }
        return a.y < b.y;
    }
};

node *root = NULL;

void find(node *curr, node *newNode){
    
    if(curr -> x > newNode -> x && curr -> left != NULL){
        find(curr -> left, newNode);
    }
    else if(curr -> x > newNode -> x && curr -> left == NULL){
        curr -> left = newNode;
    }
    else if(curr -> x < newNode -> x && curr -> right != NULL){
        find(curr -> right, newNode);
    }
    else{
        curr -> right = newNode;
    }   
}

void preorder(node *curr){
    if(curr == NULL) return;
    answer[0].push_back(curr -> num);
    preorder(curr->left);
    preorder(curr->right);
}

void postorder(node *curr){
    if(curr == NULL) return;
    postorder(curr->left);
    postorder(curr->right);    
    answer[1].push_back(curr -> num);

}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    priority_queue<q_node, vector<q_node>, compare> pq;
    
    q_node temp;

    int size = nodeinfo.size();
    for(int i = 0; i<size; i++)
    {
        temp.x= nodeinfo[i][0];
        temp.y= nodeinfo[i][1];
        temp.num=i+1;
        pq.push(temp);
    }
    
    q_node curr;
    node *newNode, *tmp;
    
    newNode = (node *)malloc(sizeof(node));
    
    curr = pq.top();
    pq.pop();
    newNode -> x = curr.x;
    newNode -> num = curr.num;
    newNode -> right = newNode -> left = NULL;
    root = newNode;
    
    while(!pq.empty())
    {
        curr = pq.top();
        pq.pop();
        newNode = (node *)malloc(sizeof(node));

        newNode -> x = curr.x;
        newNode -> num = curr.num;
        newNode -> right = newNode -> left = NULL;
        find(root, newNode);
    }
    
    preorder(root);
    postorder(root);
    
    return answer;
}
