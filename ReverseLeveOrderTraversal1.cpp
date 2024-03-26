#include<bits/stdc++.h>
using namespace std;


class Node {
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int d){
			this->data = d;
			this->left = NULL;
			this->right = NULL;
		};
};


Node* buildTree(Node* root){
	cout<<"Enter the data: "<<endl;
	int data;
	cin>>data;
	
	root  = new Node(data);
	
	if(data == -1){
		return NULL;
	}
	
	cout<<"Enter the data for inserting in left of: "<<data<<endl;
	root->left = buildTree(root->left);
	cout<<"Enter the data for inserting in right of: "<<data<<endl;
	root->right = buildTree(root->right);
	
	return root;
}

vector<int> reverseLevelOrder(Node* root){
     vector<int> arr;
     stack<int> S;
     queue<Node*> q;

     if(root == NULL){
         return {};
     }

     if(root->left == NULL && root->right == NULL) {
         return {root->data};
     }

     q.push(root);

     while(!q.empty()){
         Node* temp = q.front();
         q.pop();

         S.push(temp->data);

         if(temp->left){
             q.push(temp->left);
         }
         if(temp->right){
             q.push(temp->right);
         }
     }

     while(!S.empty()){
         int x = S.top();
         S.pop();
         arr.push_back(x);
     }

     return arr;

}


int main() {
	Node* root = NULL;
	
	// build tree
	root = buildTree(root);
	
	vector<int> arr;
	arr = reverseLevelOrder(root);
	
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	
	cout<<endl;
}