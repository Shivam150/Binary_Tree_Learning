#include<iostream>
#include<queue>
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



// General way to create tree
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


// Create tree from leve Order 

// void buildTreeFromLeveOrder(Node* &root){
	
// }




// 1. Leve Order traversal 

void leveOrderTraversal(Node* root){
	// create queue
	queue<Node*> q;
	// push root element 
	q.push(root);
	
	// push NULL to use as seperator  for formate 
	q.push(NULL);
	
	while(!q.empty()){
		Node* temp = q.front();
//		cout<<temp->data<<" ";
		q.pop();
		
		// check if previous level is complete 
		if(temp == NULL) {
			cout<<endl; // press enter for next line 
			// now check if q is not empty
			if(!q.empty()){  // if queue is not empty mean we need one more seperator
				q.push(NULL);  // so push NULL
			}
			
			
		}else{
		   
		    cout<<temp->data<<" ";	
		    if(temp->left) {
		     	q.push(temp->left);
	    	}
		
		    if(temp->right) {
		    	q.push(temp->right);	
	    	}
		}
		
	}
}

// 2. InOrder Traversal - Using Recursion
void inOrderTraversal(Node* root){
	if(root == NULL){
		return;
	}
	
	// follow LNR for inorder traversal
	
	
	// L - left subtree
	inOrderTraversal(root->left);
	
	//visit N - print
	
	cout<<root->data<<" ";
	
	// R - right subtree
	
	inOrderTraversal(root->right);
	
}

// 3. Pre-Order Traversal - Using Recursion

void preOrderTraversal(Node* root){
	if(root == NULL){
		return;
	}
	
	
	// follow NLR for Pre-Order traversal
	
	//N - visit Node print
	cout<<root->data<<" ";
	
	// L- traverse left subtree 
	
	preOrderTraversal(root->left);
	
	
	// R - traverse right subtree
	
	preOrderTraversal(root->right);
	
	
}

// 4. Post-Order Traversal  - Using Recursion

void postOrderTraversal(Node* root){
	if(root == NULL){
		return;
	}
	
	// follow LRN for post-Order traversal
	
	//l - traverse left subTree
	postOrderTraversal(root->left);
	
	//R - traverse right subTree
	postOrderTraversal(root->right);
	
	//N - print Node or visit Node 
	
	cout<<root->data<<" ";
	
}





int main() {
	
	Node* root = NULL;
	
	// build tree
	root = buildTree(root);
	
	cout<<root->right->left->data<<endl;
	
	//1 3 7 -1 -1 11 5 17 -1 -1 -1
	
	cout<<" leve-Order Traversal OutPut: "<<endl;
	leveOrderTraversal(root);
	cout<<endl;
	
	
	
	cout<<" In-Order Traversal OutPut: "<<endl;
    inOrderTraversal(root);
    cout<<endl;
    
    
	cout<<" pre-Order Traversal OutPut: "<<endl;
    preOrderTraversal(root);
    cout<<endl;
    
    cout<<" Post-Order Traversal OutPut: "<<endl;
    postOrderTraversal(root);
    cout<<endl;
	
	
	return 0;
}