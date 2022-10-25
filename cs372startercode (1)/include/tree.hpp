//
// File:    Tree.h
// Author:  Adam.Lewis@athens.edu
// Purpose:
// Use C++ templates, STL classes and functions, and smart pointers to
// implement a binary search tree.
//
// A binary search tree is defined as being either empty, or a 3-tuple
// (left.subtree, value, right.subtree) where left.subtree is a binary search
// tree that only contains values less than our value and right.subtree is a
// binary search tree that only contains values larger than our value.
//
//ref geeksforgeeks.org/deletion-binary-tree/
#pragma once

#include <memory>
#include <functional>
#include <cassert>
#include <queue>
#include <iostream>
using namespace std;

template<class T>
class Tree
{
    // The inner struct Node represents one node of the tree.  This defines the
    // underlying structure implied by the mathematical definition of the Tree
    // ADT
    //
    struct Node
    {
        Node(std::shared_ptr<const Node> const & lft
             , T val
             , std::shared_ptr<const Node> const & rgt)
        : _lft(lft), _val(val), _rgt(rgt)
        {}

        std::shared_ptr<const Node> _lft;
        T _val;
        std::shared_ptr<const Node> _rgt;
        
    };

    //
    // And this private constructor defines how we keep track of the root of the
    // tree while not exposing that information to clients of this class.
    //
    explicit Tree(std::shared_ptr<const Node> const & node)
      : _root(node) {}
        
  

public:
    //
    // The first two public constructors provide the protocol for creating a
    // Tree per the mathematical definition of the Tree ADT.
    //
    Tree() {}

    Tree(Tree const & lft, T val, Tree const & rgt)
    : _root(std::make_shared<const Node>(lft._root, val, rgt._root))
    {
        assert(lft.isEmpty() || lft.root() < val);
        assert(rgt.isEmpty() || val < rgt.root());
    }

    //
    // We add an additional constructor that we use to construct a Tree from
    // an initializer list.
    //
    Tree(std::initializer_list<T> init) {
        Tree t;
        for (T v: init) {
            t = t.insert(v);
        }
        _root = t._root;
    }

    //
    // The next portion of the protocol allows the client to query the state
    // of the Tree.   Again, note how we avoid exposing the state to the client.
    //
    bool isEmpty() const { return !_root; }

    T root() const {
        assert(!isEmpty());
        return _root->_val;
    }


    Tree left() const {
        assert(!isEmpty());
        return Tree(_root->_lft);
    }

    Tree
    right() const {
        assert(!isEmpty());
        return Tree(_root->_rgt);
    }

    //
    // Now we manipulate the tree.
    // Note insert operates... we don't try to "fix" an existing treee.
    // Rather we build a new tree, inserting the new value at the correct point.
    //
    // Note also the implicit assumption about the template class... it must
    // support the comparison operator, or mathematically, must be partially
    // ordered.
    //
    Tree insert(T x) const {
        if (isEmpty())
            return Tree(Tree(), x, Tree());
        T y = root();
        if (x < y)
            return Tree(left().insert(x), y, right());
        else if (y < x)
            return Tree(left(), y, right().insert(x));
        else
            return *this; // no duplicates
    }
    Tree remove( const T & x )
        {
            remove( x, root());
        }
    
    
  /*  void deletDeepest(struct Node* root,
                      struct Node* d_node)
    {
        queue<struct Node*> q;
        q.push(root);
     
        // Do level order traversal until last node
        struct Node* temp;
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            if (temp == d_node) {
                temp = NULL;
                delete (d_node);
                return;
            }
            if (temp->right) {
                if (temp->right == d_node) {
                    temp->right = NULL;
                    delete (d_node);
                    return;
                }
                else
                    q.push(temp->right);
            }
     
            if (temp->left) {
                if (temp->left == d_node) {
                    temp->left = NULL;
                    delete (d_node);
                    return;
                }
                else
                    q.push(temp->left);
            }
        }
    }
    
     Node* deleate(struct Node* _root,T x){
        if(_root == NULL){
            return NULL;
        }
         
         queue<struct Node*> q;
            q.push(root);
         
            struct Node* temp;
            struct Node* key_node = NULL;
         
            // Do level order traversal to find deepest
            // node(temp) and node to be deleted (key_node)
            while (!q.empty()) {
                temp = q.front();
                q.pop();
         
                if (temp->x == x)
                    key_node = temp;
         
                if (temp->left)
                    q.push(temp->left);
         
                if (temp->right)
                    q.push(temp->right);
            }
         
            if (key_node != NULL) {
                int x = temp->x;
                deletDeepest(_root, temp);
                x_node->x = x;
            }
            return _root;
        }*/
    
    /*Tree deleatNode(T x){
        if (isEmpty())
            return Tree(Tree(), x, Tree());
        T y = root();
        //int temp = 3;
        if(y > x){
          //  T test =left();
            
        }
        else
           // return *this; // no duplicates
    }*/



    bool member(T x) const {
        if (isEmpty())
            return false;
        T y = root();
        if (x < y)
            return left().member(x);
        else if (y < x)
            return right().member(x);
        else
            return true;
    }
    
    void remove( const T & x, Tree * & t )
       {
           if( t == nullptr )
               return;   // Item not found; do nothing
           
           if( x < t->element )
               remove( x, t->left );
           else if( t->element < x )
               remove( x, t->right );
           else if( t->left != nullptr && t->right != nullptr ) // Two children
           {
               t->element = findMin( t->right )->element;
               remove( t->element, t->right );
           }
           else
           {
               Tree *oldNode = t;
               t = ( t->left != nullptr ) ? t->left : t->right;
               delete oldNode;
           }
           
           balance( t );
       }

    //
    // For each of traversal functions, we assume that the parameter is a
    // function pointer, object, or lambda expression that returns void and is
    // passed an object of type T.
    //
    void preorder(std::function<void(T)> visit) const {
        if (isEmpty())
            return;
        T contents = root();
        visit(contents);
        left().preorder(visit);
        right().preorder(visit);
    }

    void inorder(std::function<void(T)> visit) const {
        if (isEmpty()) return;
        left().inorder(visit);
        T contents = root();
        visit(contents);
        right().inorder(visit);
    }

    void postorder(std::function<void(T)> visit) const {
        if (isEmpty()) return;
        left().postorder(visit);
        right().postorder(visit);
        T contents = root();
        visit(contents);
    }
    
    void levelTrnsveral(std::function<void(T)> visit){
        
        if(isEmpty()) return;
        queue<T> test;
        T contents = giveMeStuff(test.front());
        
        
        
        
        
        
    }
    void makeEmoty(Tree * & x){
        if(x != nullptr ){
            left().makeEmoty(x);
            right().makeEmoty(x);
            delete x;
        }
        x = nullptr;
    }
    int giveMeStuff(T x){
        T contents = root();
        if(contents != x){
            left().giveMeStuff(x);
        }
        return contents;
    }
  
    
    
    
   
        
    
    
private:
    std::shared_ptr<const Node> _root;
    
};


