#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;


class Cookie{
public:
    enum CookieType
        {
            macadamia_nut_chocolate,
            walnut_chocolate_chunk,
            blackberry_galettes,            
            white_chocolate_raspberry
        };  
    enum CookieSize {small, medium, large}; 

    Cookie() : type(CookieType(rand() % 4)), size(CookieSize(rand() % 3)) {} //default constructor

    Cookie(CookieType t, CookieSize s){
        this->type = t;
        this->size = s;
    }; // constructor

    Cookie(CookieType t) : type(t), size(CookieSize(rand() % 3)) {}
    Cookie(CookieSize s) : type(CookieType(rand() % 4)), size(s) {}


    CookieType get_type() const {return type;} // get type
    CookieSize get_size() const {return size;} // get size

    bool operator== (Cookie& c){
        if (get_type() == c.get_type() && get_size() == c.get_size()) return true;
    } 

    // overloading assignment

    void print() const {
        switch(get_type()){
            case macadamia_nut_chocolate:
                cout<<"macadamia Nut Chocolate ";
                break;
            case walnut_chocolate_chunk:
                cout<<"walnut Chocolate Chunk ";
                break;
            case blackberry_galettes:
                cout<<"blackberry Galettes ";
                break;
            case white_chocolate_raspberry:
                cout<<"white Chocolate Raspberry ";
                break;
        }

        //print size
        switch(get_size()){
                case small:
                cout<<", small \n";
            break;
                case medium:
                cout<<", medium \n";
            break;
                case large:
                cout<<", large \n";
            break;
        }
    }

    bool operator < (Cookie c){ /// for sorting as per size
        return size < c.get_size();
    }
    protected:
    CookieType type;
    CookieSize size;
};




class Basket{
protected: 
vector<Cookie> cookie_basket;
public:
    vector<Cookie> get_cookie() const { return cookie_basket; }
    virtual void add_cookie(const Cookie& c)=0;
    virtual bool is_in_basket(const Cookie& c) const=0;
    virtual Cookie remove_any_cookie()=0;
    virtual void remove_cookie(const Cookie& c)=0;
    virtual void clear_basket()=0;
    virtual bool is_basket_empty() const = 0;
    virtual int cookie_total() const=0;
    virtual int cookie_size_total(Cookie::CookieSize) const=0;
    virtual int cookie_type_total(Cookie::CookieType) const=0;
    virtual void print_cookies() const=0;
    
    //question 6:
    virtual void copy_basket(const Basket& basket)=0;
    virtual void merge_baskets(const Basket& basket1, const Basket& basket2)=0;
    virtual void intersect_baskets(const Basket& basket1, const Basket& basket2)=0;
    virtual void difference_baskets(const Basket& basket1, const Basket& basket2)=0;
};




class Basket_Vector: public Basket {

public:
    virtual void add_cookie(const Cookie& c);
    bool is_in_basket(const Cookie& c) const;
    Cookie remove_any_cookie();
    void remove_cookie(const Cookie& c);
    void clear_basket();
    bool is_basket_empty() const;
    int cookie_total() const;
    int cookie_size_total(Cookie::CookieSize s)const;
    int cookie_type_total(Cookie::CookieType t)const;
    void print_cookies() const;
    
    //question 6:

    virtual void copy_basket(const Basket& basket);
    void merge_baskets(const Basket& basket1, const Basket& basket2);
    void intersect_baskets(const Basket& basket1, const Basket& basket2);
    void difference_baskets(const Basket& basket1, const Basket& basket2);
};




class Basket_LinkedList{
protected:
    struct Node{
        Cookie cookie;
        Node* next;
    };
    Node* head;
public:
    Basket_LinkedList();
    Basket_LinkedList(Cookie c);
    ~Basket_LinkedList();
    void add_cookie(Cookie c);
    bool is_in_basket(Cookie c);
    void remove_any_cookie();
    void remove_cookie(Cookie c);
    void clear_basket();
    bool is_basket_empty();
    int cookie_total();
    int cookie_size_total(Cookie::CookieSize s);
    int cookie_type_total(Cookie::CookieType t);
    void print_cookies();
    //Question 6:

    void copy_basket(const Basket& basket);
    void merge_baskets(const Basket& basket1, const Basket& basket2);
    void intersect_baskets(const Basket& basket1, const Basket& basket2);
    void difference_baskets(const Basket& basket1, const Basket& basket2);
};

//////////////////////////////////////////////////////////////////////////
//VECTORS:
void Basket_Vector::add_cookie(const Cookie& c){
    cookie_basket.push_back(c);
}

bool Basket_Vector::is_in_basket(const Cookie& c) const{
    vector<Cookie>::const_iterator it; 

    for(it = cookie_basket.begin() ; it!= cookie_basket.end() ; it++ ){ 
        if(it->get_size() == c.get_size() && it->get_type() == c.get_type()){
        return true; 
        }
    }
    return false; 
}


Cookie Basket_Vector::remove_any_cookie(){
    int index = rand() % cookie_basket.size();
    Cookie c = cookie_basket[index]; 
    vector<Cookie>:: iterator it = cookie_basket.begin(); 
    it=it+index; 
        
    cookie_basket.erase(it); 
    cout << "A random cookie is ereased.\n\n";
    return c; 
    }



void Basket_Vector::remove_cookie(const Cookie& c){
    vector<Cookie>:: iterator it = cookie_basket.begin(); 
    for( ; it != cookie_basket.end() ;it++){ 
        if(it->get_size() == c.get_size() && it->get_type() == c.get_type()){ 
            cookie_basket.erase(it); 
            cout << "The selected cookie is ereased.\n\n";
        break;
        }
    }
    }

void Basket_Vector::clear_basket(){
    cookie_basket.clear();
    cout << "Basket is cleared.\n\n";
    }

bool Basket_Vector::is_basket_empty() const{
    return cookie_basket.size() == 0;
}

int Basket_Vector::cookie_total() const{
    return cookie_basket.size();
}

int Basket_Vector::cookie_size_total(Cookie::CookieSize s)const{
    int count=0; 
    for( auto i = cookie_basket.begin(); i != cookie_basket.end() ;i++){ 
        if(i->get_size() == s ){ 
            count++;
        }
    }
    
    return count; 
    }

int Basket_Vector::cookie_type_total(Cookie::CookieType t)const{
    int count=0;
    for(auto it = cookie_basket.begin();  it != cookie_basket.end() ;it++){ 
        if(it->get_type() == t ){
            count++;
        }
    }
    
    return count; 
    }

void Basket_Vector::print_cookies() const{
    if(cookie_basket.size()== 0) cout << "\nThe basket is empty\n";
    for(int i=0;i<cookie_basket.size();i++){
        cookie_basket[i].print(); 
    }
}

void Basket_Vector::copy_basket(const Basket& basket){
    vector<Cookie> copy_basket = basket.get_cookie();
    for (auto i = copy_basket.begin(); i != copy_basket.end();i++){
        cookie_basket.push_back(*i);
    }
}

void Basket_Vector::merge_baskets(const Basket& basket1, const Basket& basket2){
    vector<Cookie> intersect_basket1 = basket1.get_cookie();
    vector<Cookie> intersect_basket2 = basket2.get_cookie();
    for (auto i = intersect_basket1.begin(); i != intersect_basket1.end(); i++){
        add_cookie(*i);
    }
    for (auto i = intersect_basket2.begin(); i != intersect_basket2.end(); i++){
        add_cookie(*i);
    }
}

void Basket_Vector::intersect_baskets(const Basket& basket1, const Basket& basket2){
    vector<Cookie> intersect_basket1 = basket1.get_cookie();
    vector<Cookie> intersect_basket2 = basket2.get_cookie();
    for (auto i = intersect_basket1.begin(); i != intersect_basket1.end(); i++){
        if (basket2.is_in_basket(*i)){
            add_cookie(*i);
        }
    }
}

void Basket_Vector::difference_baskets(const Basket& basket1, const Basket& basket2){
    vector<Cookie> intersect_basket1 = basket1.get_cookie();
    vector<Cookie> intersect_basket2 = basket2.get_cookie();
    for (auto i = intersect_basket1.begin(); i != intersect_basket1.end(); i++){
        if (basket2.is_in_basket(*i)){
            continue;
        } else {
            add_cookie(*i);
        }
    }
}


///////////////////////////////////////////////////////
/**********************************************************************/
//LINKED LIST: 


Basket_LinkedList::Basket_LinkedList(){
   head = NULL;
}

Basket_LinkedList::Basket_LinkedList(Cookie c){
   head = new Node;
   head->cookie = c;
   head->next = NULL;
}

Basket_LinkedList::~Basket_LinkedList(){
   while(head != NULL)
   {
       Node *temp = head;
       head = head->next;
       delete(temp);
   }
}

void Basket_LinkedList::add_cookie(Cookie c){
    Node *curr = new Node;
    curr->cookie = c;
    curr->next = head;
    head = curr;
}

bool Basket_LinkedList::is_in_basket(Cookie c){
    Node *curr = new Node;
    curr = head;
    while(curr!=NULL){
        if(curr->cookie == c){
            return true; 
        } 
        curr = curr->next;
    }

    return false;
}

void Basket_LinkedList:: remove_any_cookie(){
    Node *curr = head;
    Node *prev = head;
    Cookie cookie;
   while(curr != NULL)
   {
       if(curr->cookie == cookie)
       {
           if(curr != head){
               prev->next = curr->next;
               delete(curr);
               cout << "cookie 3 is deleted1\n\n";
               return;
            }else{
                head = curr->next;
                delete(curr);
                cout << "cookie 3 is deleted2\n\n";
                return;
            }
       }

       prev = curr;
       curr = curr->next;
   }
}

void Basket_LinkedList::remove_cookie(Cookie c){
    Node *curr = head;
    Node *prev = head;
   while(curr != NULL)
   {
       if(curr->cookie == c)
       {
           if(curr != head){
               prev->next = curr->next;
               delete(curr);
               cout << "cookie is deleted1.\n";
               return;
            }else{
                head = curr->next;
                delete(curr);
                cout << "cookie is deleted2.\n";
                return ;
            }
       }

       prev = curr;
       curr = curr->next;
   }   
}

void Basket_LinkedList::clear_basket(){
    Node *curr = head;
   while(curr != NULL)
   {
       head = curr->next;
       delete curr;
       curr = head;
       
       }
       cout << "The basket is cleared.\n";
   } 

bool Basket_LinkedList::is_basket_empty(){
    if (head == NULL){
        return true;
    }else {
        return false;
    }
} 

int Basket_LinkedList::cookie_total(){
    Node* curr = head;
    int cookie = 0;
    while(curr != NULL){
        cookie += 1;
        curr = curr->next;
    }
    return cookie;
}

int Basket_LinkedList::cookie_size_total(Cookie::CookieSize s){
    Node* curr = head;
    int counter = 0;
    while (curr!=NULL){
        if (curr->cookie.get_size() == s){
            counter +=1;
        }
        curr = curr->next;
    }
    return counter;
}

int Basket_LinkedList::cookie_type_total(Cookie::CookieType s){
    Node* curr = head;
    int counter = 0;
    while (curr!=NULL){
        if (curr->cookie.get_type() == s){
            counter +=1;
        }
        curr = curr->next;
    }
    return counter;
}

void Basket_LinkedList::print_cookies(){
    Node* curr = head;
    Node* prev = head;
    if (curr == NULL){
        cout << "The cookie basket is empty\n";
        return ;
    }

    while(curr!=NULL){
        curr->cookie.print();
        prev = curr;
        curr = curr->next;
    }
    
}

void Basket_LinkedList::copy_basket(const Basket& basket){
    vector<Cookie> copy_basket = basket.get_cookie();
    for (auto i = copy_basket.begin(); i != copy_basket.end(); i++){
        add_cookie(*i);
    }
}

void Basket_LinkedList::merge_baskets(const Basket& basket1, const Basket& basket2){
    vector<Cookie> intersect_basket1 = basket1.get_cookie();
    vector<Cookie> intersect_basket2 = basket2.get_cookie();
    for (auto i = intersect_basket1.begin(); i != intersect_basket1.end(); i++){
        add_cookie(*i);
    }
    for (auto i = intersect_basket1.begin(); i != intersect_basket1.end(); i++){
        add_cookie(*i);
    }
}

void Basket_LinkedList::intersect_baskets(const Basket& basket1, const Basket& basket2){
    vector<Cookie> intersect_basket1 = basket1.get_cookie();
    vector<Cookie> intersect_basket2 = basket2.get_cookie();
    for (auto i = intersect_basket1.begin(); i != intersect_basket1.end(); i++){
        if (basket2.is_in_basket(*i)){
            add_cookie(*i);
        }
    }
}

void Basket_LinkedList::difference_baskets(const Basket& basket1, const Basket& basket2){
    vector<Cookie> intersect_basket1 = basket1.get_cookie();
    vector<Cookie> intersect_basket2 = basket2.get_cookie();
    for (auto i = intersect_basket1.begin(); i != intersect_basket1.end(); i++){
        if (basket2.is_in_basket(*i)){
            continue;
        } else {
            add_cookie(*i);
        }
    }
}

ostream& operator<<(ostream& os, const Cookie& c)
{
    switch(c.get_type()){
            case Cookie::macadamia_nut_chocolate:
                os<<"macadamia Nut Chocolate ";
                break;
            case Cookie::walnut_chocolate_chunk:
                os<<"walnut Chocolate Chunk ";
                break;
            case Cookie::blackberry_galettes:
                os<<"blackberry Galettes ";
                break;
            case Cookie::white_chocolate_raspberry:
                os<<"white Chocolate Raspberry ";
                break;
        }

        //print size
        switch(c.get_size()){
                case Cookie::small:
                os<<", small \n";
            break;
                case Cookie::medium:
                os<<", medium \n";
            break;
                case Cookie::large:
                os<<", large \n";
            break;
        }
    return os;
}
/////////////////////////////////////////////////////////////////////






