#include <iostream>
#include <stdbool.h>
#include <queue>

using namespace std;

namespace ariel{
template <typename T> class BinaryTree
{
private:
  
    struct node
    {
        T val;
        node* left;
        node* right;
        node(const T& v):val(v), left(nullptr), right(nullptr){};

        ~node()
        {
            delete right;
            delete left;
        }
    };
    node* root;


    node* findnode(node * n, T value)
    {
        if(n == nullptr) {return nullptr;}
        if(n->val == value) {return n;}
        node *lefty = findnode(n->left, value);
        if(lefty != nullptr) {return lefty;}
        return findnode(n->right, value);
    }

    void copytree(node * totree, node * fromtree)
    {
        if(fromtree->right != nullptr)
        {
            node * newright = new node(fromtree->right->val);
            totree->right = newright;
            copytree(totree->right, fromtree->right);
        };

        if(fromtree->left != nullptr)
        {
            node * newleft = new node(fromtree->left->val);
            totree->left = newleft;
            copytree(totree->left, fromtree->left);
        };
    };  


public:

    BinaryTree &operator=(const BinaryTree& b)
    {
        if(this == &b) {return *this;}
        if(this->root!=nullptr) {delete this->root;}
        if(b.root != nullptr)
        {
            this->root = new node(b.root->val);
            copytree(this->root, b.root);
        }
        return *this;
    };
    
    BinaryTree &operator=(BinaryTree &&b) noexcept
    {
        
        this->root = b->root;
        b.root = nullptr;
        return *this;
    }

    BinaryTree(const BinaryTree& b)
    {
        if(b.root != nullptr)
        {
            this->root = new node(b.root->val);
            copytree(this->root, b.root);
        };
    }; 

    BinaryTree(BinaryTree &&b) noexcept
    {
        this->root = b.root;
        b.root = nullptr;
    }

    BinaryTree()
    {
        root = nullptr;
    }

    ~BinaryTree()
    {
        delete root;
        
    }
    
    BinaryTree <T> & add_root(const T& value)
    { 
        if (this->root==nullptr)
        {
            root = new node(value);
            return *this;
        }
        root->val = value;
        return *this;
    };

    BinaryTree <T> & add_left(const T& place ,const T& value)
    {
        if (root == nullptr){throw invalid_argument{"the root does not exist"};}
        if (findnode(root, place) == nullptr)
        {
             throw invalid_argument{"the node does not exist"};
        }
        node * tmp = findnode(root, place);
        if (tmp->left == nullptr)
        {
            tmp->left = new node(value);
            return *this;
        }
        tmp->left->val = value;
        return *this;
    }
    
    BinaryTree <T> & add_right(const T& place ,const T& value)
    {
        if (root == nullptr){throw invalid_argument{"the root does not exist"};}
        if (findnode(root, place) == nullptr)
        {
             throw invalid_argument{"the node does not exist"};
        }
        node * tmp = findnode(root, place);
        if (tmp->right == nullptr)
        {
            tmp->right = new node(value);
            return *this;
        }
        tmp->right->val = value;
        return *this;
    };
    
    friend ostream& operator<<(ostream &out, const BinaryTree& rhs){return out;};
   
    static void in(node ** n, queue<node *> &q)
    {
        /*node* curr = n;
        while (curr != nullptr || s.empty() == false)
        {
            while (curr !=  nullptr)
            {
                s.push(curr);
                curr = curr->left;
            };

            curr = s.top();
            s.pop();
 
            q.push(curr);
 
            curr = curr->right;
 
        };*/
        if(*n==nullptr){ return;}
        in(&(*n)->left, q);
        q.push(*n);
        in(&(*n)->right, q);
        
        
    };

    static void post(node ** n, queue<node *> &q)
    {
        /*node* curr = n;
        s.push(curr);
        while (s.empty() == false)
        {      
            while (curr != nullptr)
            {
                if (curr->right!=nullptr)s.push(curr->right);
                s.push(curr);
                curr = curr->left;
            };
            curr = s.top();
            s.pop();
            if (curr->right != nullptr && curr->right == s.top())
            {
                s.top();
                s.pop();
                s.push(curr);
                curr = curr->right;
            }
            else 
            {
                q.push(curr);
                curr = nullptr;
            }
        };*/
        if(*n==nullptr) {return;}
        post(&(*n)->left, q);
        post(&(*n)->right, q);
        q.push(*n);
    };

    static void pre(node ** n, queue<node *> &q)
    {
        /*node* curr = n;
        s.push(curr);
        while (s.empty() == false)
        {
            if (curr == nullptr){s.pop();}
            else 
            {
                q.push(s.top());
                s.pop();
                s.push(curr->right);
                s.push(curr->left);
                curr = s.top();
            }
 
        };*/
        if(*n==nullptr){ return;}
        q.push(*n);
        pre(&(*n)->left, q);
        pre(&(*n)->right, q);
        
    };


    class iterator
    {
        private:
            node* pointer;
            queue<node *> qi;
            int flag;
        public:
            iterator(node* ptr = nullptr, int flag=0): pointer(ptr), flag(flag)
            {
                while (!qi.empty()) {qi.pop();}
                if(pointer != nullptr)
                {  
                    if(flag == 1) {in(&pointer, qi);}
                    if(flag == 2){ pre(&pointer, qi);}
                    if(flag == 3) {post(&pointer, qi);}
                }
                qi.push(nullptr);
                pointer = qi.front();
                qi.pop();
            }
            T& operator*() const {return pointer->val;}
            T* operator->() const 
            {
			    return &(pointer->val);
		    }
       
            iterator& operator++()
            {
                pointer = qi.front();
                qi.pop();
                return *this;
            }

            iterator operator++(int)
            {
                iterator tmp = *this;
                pointer = qi.front();
                qi.pop();
                return tmp;
            }

            bool operator==(const iterator& rhs) const 
            {
			    return pointer == rhs.pointer;
		    }

		    bool operator!=(const iterator& rhs) const 
            {
			    return pointer != rhs.pointer;
		    }
    };

    
    iterator begin() {
       return begin_inorder();
	};
    iterator end() {
		return iterator{nullptr};
	};
    iterator begin_preorder()
    {
        return iterator{root, 2};
    };
    iterator end_preorder()
    {
        return iterator{nullptr};
    };
    iterator begin_inorder()
    {
        return iterator{root, 1};
    };
    iterator end_inorder()
    {
        return iterator{nullptr};
    };
    iterator begin_postorder()
    {
        return iterator{root, 3};
    };
    iterator end_postorder()
    {
        return iterator{nullptr};
    };

};

}

