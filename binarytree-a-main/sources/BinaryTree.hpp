#include <iostream>
#include <stdbool.h>
using namespace std;

namespace ariel{
template <typename T> class BinaryTree
{
private:
    BinaryTree& operator=(const BinaryTree& b);
    BinaryTree(const BinaryTree& rhs);
    struct node
    {
        T val;
        node* left;
        node* right;
        node(const T& v, node* l, node* r):val(v), left(l), right(r){};
    };
    node* root;
    
public:
    BinaryTree(){}
    ~BinaryTree(){}
    BinaryTree <T> & add_root(const T& value){return *this;};
    BinaryTree <T> & add_left(const T& place ,const T& value){return *this;}
    BinaryTree <T> & add_right(const T& place ,const T& value){return *this;};
    friend ostream& operator<<(ostream &out, const BinaryTree& rhs){return out;};
        
    class iterator
    {
        private:
            node* pointer;
        public:
            iterator(node* ptr = nullptr): pointer(ptr){}
            T& operator*() const {return pointer->val;}
            T* operator->() const 
            {
			    return &(pointer->val);
		    }
            iterator& operator++()
            {
                pointer = pointer->left;
                return *this;
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
		return iterator{root};
	};
    iterator end() {
		return iterator{root};
	};
    iterator begin_preorder()
    {
        return iterator{root};
    };
    iterator end_preorder()
    {
        return iterator{root};
    };
    iterator begin_inorder()
    {
        return iterator{root};
    };
    iterator end_inorder()
    {
        return iterator{root};
    };
    iterator begin_postorder()
    {
        return iterator{root};
    };
    iterator end_postorder()
    {
        return iterator{root};
    };

};

}

