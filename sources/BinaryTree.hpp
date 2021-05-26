#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
namespace ariel{
    template<typename T>
    class BinaryTree {
    private:
        struct Node {
            T data;
            Node(const T& v)
            :data(v){}
        };
        struct Node* root;
        BinaryTree* left;
        BinaryTree* right;
    public:
        BinaryTree(struct Node* b=nullptr) : root(b),left(nullptr),right(nullptr) {
	    }
	    ~BinaryTree() {
            //
	    }
    private:
        BinaryTree* search(const T& v,BinaryTree* head){
            if(head==nullptr){
                return nullptr;
            }
            if(head->root->data==v){
                return head;
            }
            BinaryTree* left=search(v,head->left);
            if(left->root !=nullptr){
                return left;
            }
            else{
                BinaryTree* right=search(v,head->right);
                return right;
            }
        }
        u_long height(BinaryTree* head){
            if(head==nullptr) return 0;
            u_long left=height(head->left);
            u_long right = height(head->right);
            if(left>right){
                return left+1;
            }
            else{
                return right+1;
            }
        }
        vector<T> printCurrentLevel(BinaryTree* head, int level){
            vector<T> levelv;
            if (head == nullptr){
                vector<T> stam;
                return stam;
            }
            if (level == 1){
                levelv.insert(levelv.end(),head->root->data);
            }
            else if (level > 1)
            {
                vector<T> left=printCurrentLevel(head->left, level-1);
                vector<T> right=printCurrentLevel(head->right, level-1);
                levelv.insert(levelv.end(),left.begin(),left.end());
                levelv.insert(levelv.end(),right.begin(),right.end());

            }
            return levelv;
        }
        vector<BinaryTree*> postorder(BinaryTree* head){
            vector<BinaryTree*>res;
            if(head->left!=nullptr){
                vector<BinaryTree*>left=postorder(head->left);
                res.insert(res.end(),left.begin(),left.end());
            }
            if(head->right!=nullptr){
                vector<BinaryTree*>right=postorder(head->right);
                res.insert(res.end(),right.begin(),right.end());
            }
            res.insert(res.end(),head);
            return res;
        }
        vector<BinaryTree*> preorder(BinaryTree* head){
            vector<BinaryTree*>res;
            res.insert(res.end(),head);
            if(head->left!=nullptr){
                vector<BinaryTree*>left=preorder(head->left);
                res.insert(res.end(),left.begin(),left.end());
            }
            if(head->right!=nullptr){
                vector<BinaryTree*>right=preorder(head->right);
                res.insert(res.end(),right.begin(),right.end());
            }
            return res;
        }
        vector<BinaryTree*> inorder(BinaryTree* head){
            vector<BinaryTree*>res;
            if(head->left!=nullptr){
                vector<BinaryTree*>left=inorder(head->left);
                res.insert(res.end(),left.begin(),left.end());
            }
            res.insert(res.end(),head);
            if(head->right!=nullptr){
                vector<BinaryTree*>right=inorder(head->right);
                res.insert(res.end(),right.begin(),right.end());
            }
            return res;
        }
    public:
        class iterator{
            private:
                u_long index;
                vector<BinaryTree*>val;
            public:
                iterator(vector<BinaryTree*> ptr = nullptr,u_long i=0)
                    :index(i),val(ptr){
                }
                T& operator*() const {
			        return val.at(index)->root->data;
	    	    }
                T* operator->() const{
                    return &(val.at(index)->root->data);
                }
                iterator& operator++() {
			        index++;
			        return *this;
		        }
                const iterator operator++(int) {
			        iterator tmp= *this;
			        index++;
			        return tmp;
		        }
                bool operator==(const iterator& rhs) const {
			        return val.at(index) == rhs.val.at(index);
		        }
                bool operator!=(const iterator& rhs) const {
			        return val.at(index) != rhs.val.at(rhs.index);
		        }
        };
        BinaryTree& add_root(const T& v){
            if(root == nullptr){
                root=new struct Node(v);
            }
            else{
                root->data=v;
            }
            return *this;
        }
        BinaryTree& add_left(const T& v1,const T& v2){
            BinaryTree* ptr=search(v1,this);
            if(ptr!=nullptr){
                if(ptr->left==nullptr){
                    ptr->left=new BinaryTree(new struct Node(v2));
                }
                else{
                    ptr->left->root->data=v2;
                }
            }
            return *this;
        }
        BinaryTree& add_right(const T& v1,const T& v2){
            BinaryTree* ptr=search(v1,this);
            if(ptr!=nullptr){
                if(ptr->right==nullptr){
                    ptr->right=new BinaryTree(new struct Node(v2));
                }
                else{
                    ptr->right->root->data=v2;
                }
            } 
            return *this;
        }
        iterator begin_preorder(){
            vector<BinaryTree*>res=preorder(this);
            res.insert(res.end(),nullptr);
            return iterator(res);
        }
        iterator end_preorder(){
            vector<BinaryTree*>res=preorder(this);
            res.insert(res.end(),nullptr);
            return iterator(res,res.size() -1);
        }
        iterator begin_inorder(){
            vector<BinaryTree*>res=inorder(this);
            res.insert(res.end(),nullptr);
            return iterator(res);
        }
        iterator end_inorder(){
            vector<BinaryTree*>res=inorder(this);
            res.insert(res.end(),nullptr);
            return iterator(res,res.size() -1);
        }
        iterator begin_postorder(){
            vector<BinaryTree*>res=postorder(this);
            res.insert(res.end(),nullptr);
            return iterator(res);
        }
        iterator end_postorder(){
            vector<BinaryTree*>res=postorder(this);
            res.insert(res.end(),nullptr);
            return iterator(res,res.size() -1);
        }
        iterator begin(){
            vector<BinaryTree*>res=inorder(this);
            res.insert(res.end(),nullptr);
            return iterator(res);
        }
        iterator end(){
            vector<BinaryTree*>res=inorder(this);
            res.insert(res.end(),nullptr);
            return iterator(res,res.size() -1);
        }
        ostream& print(ostream& output){
            output<<endl;
            u_long h = height(this);
            u_long i;
            vector<vector<T>>tree;
            for(u_long j=0;j<h;j++){
                vector<T> tmp;
                tree.insert(tree.end(),tmp);
            }
            for (i=1; i<=h; i++){
                vector<T>level1=printCurrentLevel(this, i);
                tree.at(i-1).insert(tree.at(i-1).end(),level1.begin(),level1.end());
            }
            for(i=1;i<=h;i++){
                u_long maxspace=pow(2,h-i+1)*2;
                for(auto val:tree.at(i-1)){
                    output<<val;
                    for(u_long j=0;j<maxspace;j++){output<<" ";}
                }
                output<<endl;
                u_long size;
                maxspace=pow(2,h-i)*2;
                if(i==h)size=0;
                else size=tree.at(i).size();
                if(size>0){
                    output<<"|";
                    for(u_long j=0;j<size-1;j++){
                        for(u_long j=0;j<maxspace;j++){output<<"-";}
                        output<<"|";
                    }
                }
                output<<endl;
            }
            return output;
        }
    };
    template<typename Tl>
    ostream& operator<<(ostream& output,BinaryTree<Tl> b){
        return b.print(output);
    }
}