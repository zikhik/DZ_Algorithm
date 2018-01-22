//
//  binomstuct1.h
//  Dz_Algoritm
//
//  Created by Admin on 17.01.18.
//  Copyright © 2018 Ivan Slavyanskiy. All rights reserved.
//

#ifndef binomstuct1_h
#define binomstuct1_h
#include <cstring>
class bmheap
{
public:
    int key;
    std::string value;
    int degree;
    bmheap *parent;
    bmheap *child;
    bmheap *sibling;
    int max_key;
public:
    bmheap():degree(NULL),child(nullptr),sibling(nullptr),value(""),key(0), max_key(-2147483648){};
    bmheap(int k, std::string a, int mk):degree(0),child(nullptr),sibling(nullptr),value(a),key(k),max_key(mk){};
    void bmheap_linktress( bmheap *y,  bmheap *z);
    bmheap* bmheap_mergelists( bmheap *a,  bmheap *b);
    bmheap* bmheap_union( bmheap *a,  bmheap *b);
    bmheap* bmheap_insert( bmheap *h, int key, std::string value);
    inline const int getmax();
    void print_heap();
    void print_tree(bmheap * a);
    bmheap* operator=(bmheap* a);
    
};
bmheap* bmheap::operator=(bmheap* a)
{
    this->key = a->key;
    this->value = a->value;
    this->parent = a->parent;
    this->child= a->child;
    this->sibling = a->sibling;
    this->degree = a->degree;
    return this;
}
void  bmheap::print_heap()
{
    bmheap* x=new bmheap();
    x->key=this->key;
    cout<<x->key;
    x->value=this->value;
    x->parent=this->parent;
    x->child=this->child;
    x->sibling=this->sibling;
    x->degree=this->degree;
    if ((x!=nullptr)&&(x->sibling==nullptr)) cout<<x->key;
    else
    while (x->sibling!=nullptr)
    {
        cout<<"voshel v cikl";
        x->print_tree(x);
        x= x->sibling;
        while (x->parent!=nullptr)
        {
            x=x->parent;
        }
    }
        
    
    

}
void bmheap::print_tree(bmheap* a)
{
    cout<<"pechat dereva";
    while (a)
    {
        cout << a->key << " ";
        print_tree(a->child);
        a = a->sibling;
        
    }
    

}
inline const int bmheap:: getmax(){return max_key;}
void bmheap::bmheap_linktress( bmheap *y,  bmheap *z)
{
    y->parent = z;
    y->sibling = z->child; z->child = y; z->degree++;
}

bmheap*  bmheap::bmheap_mergelists( bmheap *a, bmheap *b)
{
    bmheap *head = new bmheap;
    bmheap* sibling = new bmheap;
    bmheap* end = new bmheap;
    end = head = nullptr;
    while (a != nullptr && b != nullptr) {
        if (a->degree < b->degree)
        {
            sibling = a->sibling;
            if (end == nullptr) {
                end = a;
                head = a; } else {
                    end->sibling = a;
                    end = a;
                    a->sibling = nullptr;
                }
            a = sibling; }
        else {
            sibling = b->sibling; if (end == nullptr) {
                end = b;
                head = b; } else {
                    end->sibling = b; end = b; b->sibling = nullptr;
                }
            b = sibling; }
    }
    while (a != nullptr) { sibling = a->sibling; if (end == nullptr) {
        end = a; } else {
            end->sibling = a; end = a; a->sibling = nullptr;
        }
        a = sibling; }
    while (b != nullptr) { sibling = b->sibling; if (end == nullptr) {
        end = b; } else {
            end->sibling = b; end = b; b->sibling = nullptr;
        }
        b = sibling; }
    return head; }


bmheap* bmheap::bmheap_union( bmheap *a,  bmheap *b) {
    bmheap *h, *prevx, *x, *nextx;
    h = bmheap_mergelists(a, b); prevx = nullptr;
    x = h;
    nextx = h->sibling;
    while (nextx != nullptr) {
        if ((x->degree != nextx->degree) ||
            (nextx->sibling != nullptr && nextx->sibling->degree == x->degree))
        {
            x = nextx; }
        else if (x->key <= nextx->key) { /* Case 3 */
            x->sibling = nextx->sibling;
            bmheap_linktress(nextx, x); } else {
                /* Case 4 */
                if (prevx == nullptr)
                {
                    h = nextx;
                }
                else
                {
                    prevx->sibling = nextx;
                }
                bmheap_linktress(x, nextx); x = nextx;
            }
        nextx = x->sibling;
    }
    return h;
}



bmheap* bmheap::bmheap_insert( bmheap *h, int key, std::string value)
{
    if (key>max_key) max_key = key;
    bmheap *node = new bmheap(key,value,max_key);
    if (h == nullptr) return node;
    return bmheap_union(h, node);
};
#endif /* binomstuct1_h */
