#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include "cookies.cpp"
#include <fstream>

using namespace std;

int main() {
    srand(time(0));
    ifstream infile;
    ifstream infile2;
    ofstream ofile;
    ofstream ofile2;

    ofile.open("cookies.txt");
    infile.open("cookies.txt");
    ofile2.open("cookies2.txt");
    infile2.open("cookies2.txt");


    
    if(ofile.is_open()){
        for(int i =0; i<20; i++){
            Cookie c;
            ofile << c;
        }
        ofile.close();
    }

    if(ofile2.is_open()){
        for(int i =0; i<20; i++){
            Cookie c;
            ofile2 << c;
        }
        ofile2.close();
    }

    string s;
    Basket_Vector list;
    Basket_Vector list2;
    
    while(getline(infile,s)){
        if (s == "macadamia Nut Chocolate , small "){
            Cookie c(Cookie::macadamia_nut_chocolate, Cookie::small);
            list.add_cookie(c);

        }else if(s == "macadamia Nut Chocolate , medium " ){
            Cookie c(Cookie::macadamia_nut_chocolate, Cookie::medium);
            list.add_cookie(c);

        } else if(s == "macadamia Nut Chocolate , large " ){
            Cookie c(Cookie::macadamia_nut_chocolate, Cookie::large);  
            list.add_cookie(c);

        } else if(s == "blackberry Galettes , small " ){
            Cookie c(Cookie::blackberry_galettes, Cookie::small);
            list.add_cookie(c);

        } else if( s== "blackberry Galettes , medium " ){
            Cookie c(Cookie::blackberry_galettes, Cookie::medium);
            list.add_cookie(c);

        } else if( s == "blackberry Galettes , large " ){
            Cookie c(Cookie::blackberry_galettes, Cookie::large);
            list.add_cookie(c);

        } else if(s == "white Chocolate Raspberry , small " ){
            Cookie c(Cookie::white_chocolate_raspberry, Cookie::small);
            list.add_cookie(c);

        } else if( s == "white Chocolate Raspberry , medium " ){
            Cookie c(Cookie::white_chocolate_raspberry, Cookie::medium);
            list.add_cookie(c);


        } else if(s == "white Chocolate Raspberry , large " ){
            Cookie c(Cookie::white_chocolate_raspberry, Cookie::large);
            list.add_cookie(c);


        } else if(s == "walnut Chocolate Chunk , small " ){
            Cookie c(Cookie::walnut_chocolate_chunk, Cookie::small);
            list.add_cookie(c);

        } else if (s == "walnut Chocolate Chunk , medium " ){
            Cookie c(Cookie::walnut_chocolate_chunk, Cookie::medium);
            list.add_cookie(c);


        } else if (s == "walnut Chocolate Chunk , large " ){
            Cookie c(Cookie::walnut_chocolate_chunk, Cookie::large);
            list.add_cookie(c);

        }
    }

    while(getline(infile2,s)){
        if (s == "macadamia Nut Chocolate , small "){
            Cookie c(Cookie::macadamia_nut_chocolate, Cookie::small);
            list2.add_cookie(c);

        }else if(s == "macadamia Nut Chocolate , medium " ){
            Cookie c(Cookie::macadamia_nut_chocolate, Cookie::medium);
            list2.add_cookie(c);

        } else if(s == "macadamia Nut Chocolate , large " ){
            Cookie c(Cookie::macadamia_nut_chocolate, Cookie::large);  
            list2.add_cookie(c);

        } else if(s == "blackberry Galettes , small " ){
            Cookie c(Cookie::blackberry_galettes, Cookie::small);
            list2.add_cookie(c);

        } else if( s== "blackberry Galettes , medium " ){
            Cookie c(Cookie::blackberry_galettes, Cookie::medium);
            list2.add_cookie(c);

        } else if( s == "blackberry Galettes , large " ){
            Cookie c(Cookie::blackberry_galettes, Cookie::large);
            list2.add_cookie(c);

        } else if(s == "white Chocolate Raspberry , small " ){
            Cookie c(Cookie::white_chocolate_raspberry, Cookie::small);
            list2.add_cookie(c);

        } else if( s == "white Chocolate Raspberry , medium " ){
            Cookie c(Cookie::white_chocolate_raspberry, Cookie::medium);
            list2.add_cookie(c);


        } else if(s == "white Chocolate Raspberry , large " ){
            Cookie c(Cookie::white_chocolate_raspberry, Cookie::large);
            list2.add_cookie(c);


        } else if(s == "walnut Chocolate Chunk , small " ){
            Cookie c(Cookie::walnut_chocolate_chunk, Cookie::small);
            list2.add_cookie(c);

        } else if (s == "walnut Chocolate Chunk , medium " ){
            Cookie c(Cookie::walnut_chocolate_chunk, Cookie::medium);
            list2.add_cookie(c);


        } else if (s == "walnut Chocolate Chunk , large " ){
            Cookie c(Cookie::walnut_chocolate_chunk, Cookie::large);
            list2.add_cookie(c);

        }
    }
    infile.close();
    infile2.close();

    Cookie c1(Cookie::walnut_chocolate_chunk, Cookie::small);
    Cookie c2(Cookie::blackberry_galettes, Cookie::medium);
    Cookie c3(Cookie::white_chocolate_raspberry, Cookie::small);
    Cookie c4;
    
    // Question 5:
    cout << "\nThese cookies are in the basket 1: \n\n";
    list.print_cookies();
    cout << endl;

    cout << "\nThese cookies are in the basket 2: \n\n";
    list2.print_cookies();

    cout << endl;
    cout << "In basket 1: \n";
    cout << "There are: " << list.cookie_total() << " cookies in total\n" << endl;
    cout << "There are: " << list.cookie_size_total(Cookie::small) << " cookie(s) of size small in total.\n" << endl;
    cout << "There are: " << list.cookie_type_total(Cookie::white_chocolate_raspberry) << " cookie(s) of type white_chocolate_raspberry in total.\n" << endl;

    cout << "In basket 2: \n";
    cout << "There are: " << list2.cookie_total() << " cookies in total\n" << endl;
    cout << "There are: " << list2.cookie_size_total(Cookie::small) << " cookie(s) of size small in total.\n" << endl;
    cout << "There are: " << list2.cookie_type_total(Cookie::white_chocolate_raspberry) << " cookie(s) of type white_chocolate_raspberry in total.\n" << endl;

    
    //Question 6:
    cout << "\nPart 6: " << endl;
    
    Basket& v3 = list;
    Basket& v4 = list2;

    //copy basket:
    cout << endl;
    cout << "copying basket 1: \n";
    Basket_Vector vc;   
    vc.copy_basket(v3);
    vc.print_cookies();
    
    //merge basket:
    cout << endl;
    cout << "Merging basket 1 and basket 2: \n\n";
    Basket_Vector v_m;
    v_m.merge_baskets(v3,v4);
    v_m.print_cookies();

    cout << endl;
    //inserting basket:
    cout << "Intersecting between basket 1 and basket 2: \n\n";
    Basket_Vector v_i;
    v_i.intersect_baskets(v3,v4);
    v_i.print_cookies();

    cout << endl;
    //difference basket:
    cout << "Difference between basket 1 and basket 2: \n\n";
    Basket_Vector v_d;
    v_d.difference_baskets(v3,v4);
    v_d.print_cookies();

    //merge basket:
    cout << endl;
    cout << "Merging basket 1 and basket 2: \n\n";
    Basket_LinkedList v_m2;
    v_m2.merge_baskets(v3,v4);
    v_m2.print_cookies();

    cout << endl;
    //inserting basket:
    cout << "Intersecting between basket 1 and basket 2: \n\n";
    Basket_LinkedList v_i2;
    v_i2.intersect_baskets(v3,v4);
    v_i2.print_cookies();

    cout << endl;
    //difference basket:
    cout << "Difference between basket 1 and basket 2: \n\n";
    Basket_LinkedList v_d2;
    v_d2.difference_baskets(v3,v4);
    v_d2.print_cookies();

    if (list2.is_in_basket(c2)){
        cout << "\ncookie 2 is in the basket\n\n";
    } else {
        cout << "\ncookie 2 is not in the basket\n\n";
    }

    list2.remove_any_cookie();
    list2.print_cookies();
    cout << "\n\n";
    list2.remove_cookie(c2);
    list2.print_cookies();
    cout << "\n\n";
    list2.clear_basket();
    cout << "\nBasket is cleared\n";
    list2.print_cookies();
    /*
    c1.print();
    c2.print();
    c3.print();
    c4.print();
    
    if (c1==c2){
        cout << "\nCookie 1 and Cookie 2 are the same \n";
    } else {
        cout << "\nCookie 1 and Cookie 2 are different \n";
    }

    if (c1==c3){
        cout << "\nCookie 1 and Cookie 3 are the same \n";
    } else {
        cout << "\nCookie 1 and Cookie 3 are different \n";
    }

    if (c1==c4){
        cout << "\nCookie 1 and Cookie 4 are the same \n";
    } else {
        cout << "\nCookie 1 and Cookie 4 are different \n";
    }

    cout << "\n********* part 3 & 4**********\n";

    
    //Question 3,4:
    
    Basket_Vector cookieBasket;
    if(cookieBasket.is_basket_empty()){
        cout<<"\nBasket is empty... \n";
    }

    cout<<"\nAdding some cookies in basket... \n";

    cookieBasket.add_cookie(c1);
    cookieBasket.add_cookie(c2);
    cookieBasket.add_cookie(c3);
    cookieBasket.add_cookie(c4);

    cout<<"\nBasket becomes: \n";
    cookieBasket.print_cookies();

    cout<<"\n\nTotal cookies= "<<cookieBasket.cookie_total();
    cout<<"\nSmall cookies= "<<cookieBasket.cookie_size_total(Cookie::small);
    cout<<"\nmacadamia_nut_chocolate cookies= "<<cookieBasket.cookie_type_total(Cookie::macadamia_nut_chocolate);

    cout<<"\n\n--------------\nRemove random cookie ";
    Cookie c=cookieBasket.remove_any_cookie();
    cout<<"\nRemoved cookie = ";
    c.print();

    cout<<"\nBasket becomes: \n";
    cookieBasket.print_cookies();

    cout<<"\n\n--------------\nRemove cookie 1 \n";
    cookieBasket.remove_cookie(c1);

    cout<<"\nBasket becomes: \n";
    cookieBasket.print_cookies();

    cout<<"\n\n--------------\nCheck cookie 3 is in basket ";
    if(cookieBasket.is_in_basket(c3)){
        cout<<"\nPresent";
    }
    else
        cout<<"\nabsent";


    cout<<"\n\n--------------\nCheck cookie 2 is in basket ";
    
    if (cookieBasket.is_in_basket(c2)){
        cout<<"\nPresent\n";
    }
    else
        cout<<"\nabsent\n";


    cout<<"\nClearing basket... \n";
    cookieBasket.clear_basket();

    cout<<"\ntotal = "<<cookieBasket.cookie_total() << endl;
    

    */
}

