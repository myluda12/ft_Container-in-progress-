// #include "random_access_iterator.hpp"
// #include "iterator_traits.hpp"
// #include "vector.hpp"
// #include <vector>
// #include <iterator>
// #include <vector>
// #include <iostream>
// #include <iterator>
// #include <utility>
// #include <ctime>
// #include <iomanip>
// #include <unistd.h>---
// #include <signal.h>
// #include <sys/time.h>
// #include <random>
// #define TIME_FAC 4 // the ft::Set methods can be slower up to std::set methods * TIME_FAC (MAX 20)

// #define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))

// time_t get_time(void)
// {
//     struct timeval time_now;

//     gettimeofday(&time_now, NULL);
//     time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
//     return (msecs_time);
// }

# include "avl.hpp"
int main()
{
    ft::node<int, int>* root;
    std::pair<int, int> p2(2, 2);
    std::pair<int, int> p3(3, 3);
    std::pair<int, int> p1(1, 1);
    std::pair<int, int> p4(4, 4);
    std::pair<int, int> p5(5, 5);
    std::pair<int, int> p6(10, 10);
    root = NULL;
    ft::avl<int, int> a;
    // Function call to insert the nodes
    root = a.Insert(root, NULL, &p1);
    root = a.Insert(root, NULL, &p2);
    root = a.Insert(root, NULL, &p3); 
    root = a.Insert(root, NULL, &p4);
    root = a.Insert(root, NULL, &p5);
    root = a.Insert(root, NULL, &p6);

 
    // Print the tree before deleting node
    std::cout << "Before deletion:\n";
    a.printpreorder(root);
 
    // Function Call to delete node 10
    root = a.Delete(root, &p6);
 
    // Print the tree after deleting node
    std::cout << "After deletion:\n";
    a.printpreorder(root);
}

// int main () {
//     //RAAAANDOOOOOOM ACCCEEEEESSSSS ITEEEERATOOOOOOOOOOOR
     //std::cout << "Parametre Constructor of random_access_iterator\n" << std::endl;
  //  ft::random_access_iterator<int> p1(tab);
  //   ft::random_access_iterator<int> p2(tab + 5);
  //   // ft::random_access_iterator<int> p3(tab + 10);


  //   std::cout << "p1 address " << p1.get_pointer() << std::endl;
  //   std::cout << "p2 address " << p2.get_pointer() << std::endl;
  //   std::cout << "p2 - p1\n" << p2 - p1 << std::endl;
    // std::cout << "p3 address " << p3.get_pointer() << "\n\n";

    // std::cout << "Copy Constructor p4(p1) of random_access_iterator\n" << std::endl;
    // ft::random_access_iterator<int> p4(p1);
    // std::cout << "expected p4 " << p4.get_pointer() << std::endl;
    // std::cout << "expected p1 " << p1.get_pointer() << "\n\n";

    // std::cout << "Assignment Operator of p4 '=' p2 random_access_iterator\n" << std::endl;
    // p4 = p2;
    // std::cout << "expected p4 " << p4.get_pointer() << std::endl;
    // std::cout << "expected p2 " << p2.get_pointer() << std::endl;


    // std::cout << "Increment Operator of ++p1; random_access_iterator\n" << std::endl;
    // ++p1;
    // std::cout << "expected p1 " << p1.get_pointer() << "\n\n";

    // std::cout << "Decrement Operator of --p1; random_access_iterator\n" << std::endl;
    // --p1;
    // std::cout << "expected p1 " << p1.get_pointer() << "\n\n";

    // std::cout << "Addition Operator of 'p1 += 5' random_access_iterator\n" << std::endl;
    // p1 += 5;
    // std::cout << "expected p1 " << p1.get_pointer() << "\n\n";

    // std::cout << "Substraction Operator of 'p1 -= 5' random_access_iterator\n" << std::endl;
    // p1 -= 5;
    // std::cout << "expected p1 " << p1.get_pointer() << "\n\n";

    // std::cout << "Comparison Operator of random_access_iterator\n" << std::endl;
    // const ft::random_access_iterator<int> p9(tab);
    // if (p9 == p1)
    //     std::cout << "p9 == p1\n";
    // else
    //     std::cout << "p9 != p1\n";
    // return 0;

    // std::vector<int> v(50);
    // v.push_back(1);
    // std::vector<int> v2(102);
    // if (v2 > v)
    //     std::cout << "v2 > v\n";
    // else if (v2 == v)
    //     std::cout << "v2 == v\n";
    // else
    //     std::cout << "v2 < v\n";
    // ft::vector<int>::reverse_iterator my_rit2(v.end());
    // ft::vector<int>::const_reverse_iterator c_it, c_ob(v.end());
    //     c_it = my_rit2;
      //  ft::vector<int> v(4, 5);

      //  ft::vector<int>::reverse_iterator it;

      //  it = v.rbegin();
      //  it += 2;
        //ft::vector<int>::reverse_iterator my_rit2(v.end());
        //ft::vector<int>::const_reverse_iterator c_it(v.end());
      //   c_it = my_rit2;
      //   EQUAL(&(*my_rit2) == &(*c_it) );


    //REVEEEEEERSEEEEEE ITERATOOOOOOOOOO
   // ft::reverse_iterator<ft::random_access_iterator<int> > p1(tab);
   
            // time_t start, end, diff;
            // /*------------------ std::vectors ---------------------*/
            // // std::vector<std::string> v1(1e6, "string1");
            // // std::vector<std::string> v2(1e6, "string2");
            // // start = get_time();
            // // v1 = v2;
            // // end = get_time();
            // // diff = end - start;
            // // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            // /*-----------------------------------------------------*/
            // /*------------------ ft::vectors ---------------------*/
            // ft::vector<std::string> ft_v1(10, "string1");
            // ft::vector<std::string> ft_v2(10, "string2");
            // //ualarm(diff * 10, 0);
            // ft_v1 = ft_v2;
            // //ualarm(0, 0);
            // time_t start, end, diff;
            // /*
            //  * test with n greater than vector capacity
            //  */
            // /*------------------ std::vectors ---------------------*/
            // std::vector<std::string> v1(10, "string2");
            // start = get_time();
            // v1.resize(100000);
            // end = get_time();
            // diff = end - start;
            // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            // /*------------------ ft::vectors ---------------------*/
            // ft::vector<std::string> ft_v1(10, "string2");
            // ualarm(diff * 1e3, 0);
            // ft_v1.resize(100000);
            // ualarm(0, 0);
            /*----------------------------------------------------*/
            /*
             *	test with n lesser than capacity and greater than size
             */
            // /*------------------ std::vectors ---------------------*/
            // v1.resize(20);
            // start = get_time();
            // v1.resize(1e5);
            // end = get_time();
            // diff = end - start;
            // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            // /*------------------ ft::vectors ---------------------*/
            // ft_v1.resize(20);
            // ualarm(diff * 1e3, 0);
            // ft_v1.resize(1e5);
            // ualarm(0, 0);
            // /*----------------------------------------------------*/
            // /*
            //  * test with n lesser than capacity and lesser an size
            //  */
            // /*------------------ std::vectors ---------------------*/
            // v1.resize(100);
            // start = get_time();
            // v1.resize(50);
            // end = get_time();
            // diff = end - start;
            // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            // /*------------------ ft::vectors ---------------------*/
            // ft_v1.resize(100);
            // ualarm(diff * 1e3, 0);
            // ft_v1.resize(50);
            // ualarm(0, 0);
            // /*----------------------------------------------------*/


//LAAATEEEEEEEEEEEEERR
            // std::vector<std::string> v;
            // ft::vector<std::string> ft_v;

            // std::vector<std::string>::iterator it;
            // ft::vector<std::string>::iterator ft_it;

            // size_t s;
            // size_t ft_s;

            // size_t c;
            // size_t ft_c;

            // bool cond;
            // it = v.insert(v.begin(), "hello");
            // ft_it = ft_v.insert(ft_v.begin(), "hello");
            // ft_it->length();

            // s = v.size();
            // ft_s = ft_v.size();
            // c = v.capacity();
            // ft_c = ft_v.capacity();
            // std::string str;
            // std::string ft_str;
            // for (size_t i = 0; i < v.size(); ++i)
            //     str += v[i];
            // for (size_t i = 0; i < ft_v.size(); ++i)
            //     ft_str += ft_v[i];
            // cond = ((str == ft_str) && (s == ft_s) && (c == ft_c) && (*ft_it == *it));

            /*------------------ std::vectors ---------------------*/
        // std::vector<std::string> v1(10, "string2");
        // std::vector<std::string> v2;
        // v1 = v2;
        // /*-----------------------------------------------------*/
        // /*------------------ ft::vectors ---------------------*/
        // ft::vector<std::string> ft_v1(10, "string2");
        // ft::vector<std::string> ft_v2;
        // ft_v1 = ft_v2;
        // /*----------------------------------------------------*/
        // /*------------------ strings to store the results ----*/
        // std::string res, ft_res;
        // /*----------------------------------------------------*/
        // for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
        //     res += *it;

        // for (ft::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
        //     ft_res += *it;

        // EQUAL(res == ft_res);
    
    /*---------------------------------------------------------------------------------------------------------------------
    // ----------------------------------*/
    //  std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " pop_back method "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     /*------------------ std::vectors ---------------------*/
    //     std::vector<std::string> v(20, "string");
    //     /*------------------ std::vectors ---------------------*/
    //     ft::vector<std::string> ft_v(20, "string");
    //     /*
    //      * Strings to store the results
    //      */
    //     std::string s1, ft_s1;
    //     /*
    //      * Var to store the size and the capacity
    //      */
    //     size_t z1, ft_z1;
    //     size_t c1, ft_c1;
    //     v.pop_back();
    //     ft_v.pop_back();
    //     z1 = v.size();
    //     ft_z1 = ft_v.size();
    //     c1 = v.capacity();
    //     ft_c1 = ft_v.capacity();
    //     for (size_t i = 0; i < v.size(); ++i)
    //         s1 += v[i];
    //     for (size_t i = 0; i < ft_v.size(); ++i)
    //         ft_s1 += ft_v[i];
    //     EQUAL(z1 == ft_z1 && c1 == ft_c1 && s1 == ft_s1);
    // }
    // std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert method (single element) "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     /*
    //      * strings to store the resutls
    //      */
    //     std::string str, ft_str;
    //     /*
    //      * var to store the size and the capacity
    //      */
    //     ft::vector<std::string>::size_type s, ft_s;
    //     ft::vector<std::string>::size_type c, ft_c;
    //     ft::vector<std::string>::iterator ft_it;
    //     std::vector<std::string>::iterator it;
    //     /*
    //      * bool to store the comparison
    //      */
    //     bool cond;

    //     /*------------------------------- test 1: empty vector ----------------------------------------*/
    //     // insert at the begin
    //     {
    //         std::vector<std::string> v;
    //         ft::vector<std::string> ft_v;
    //         it = v.insert(v.begin(), "hello");
    //         ft_it = ft_v.insert(ft_v.begin(), "hello");
    //         ft_it->length();

    //         s = v.size();
    //         ft_s = ft_v.size();
    //         c = v.capacity();
    //         ft_c = ft_v.capacity();
    //         for (size_t i = 0; i < v.size(); ++i)
    //             str += v[i];
    //         for (size_t i = 0; i < ft_v.size(); ++i)
    //             ft_str += ft_v[i];
    //         cond = ((str == ft_str) && (s == ft_s) && (c == ft_c) && (*ft_it == *it));
    //     }
    
    //  std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert method (single element) "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     /*
    //      * strings to store the resutls
    //      */
    //     std::string str, ft_str;
    //     /*
    //      * var to store the size and the capacity
    //      */
    //     ft::vector<std::string>::size_type s, ft_s;
    //     ft::vector<std::string>::size_type c, ft_c;
    //     ft::vector<std::string>::iterator ft_it;
    //     std::vector<std::string>::iterator it;
    //     /*
    //      * bool to store the comparison
    //      */
    //     bool cond;

    //     /*------------------------------- test 1: empty vector ----------------------------------------*/
    //     // insert at the begin
    //     {
    //         std::vector<std::string> v;
    //         ft::vector<std::string> ft_v;
    //         it = v.insert(v.begin(), "hello");
    //         ft_it = ft_v.insert(ft_v.begin(), "hello");
    //         std::cout <<  "********* " << *ft_it << std::endl;

    //         s = v.size();
    //         ft_s = ft_v.size();
    //         c = v.capacity();
    //         ft_c = ft_v.capacity();
    //         for (size_t i = 0; i < v.size(); ++i)
    //             str += v[i];
    //         for (size_t i = 0; i < ft_v.size(); ++i)
    //             ft_str += ft_v[i];
    //         cond = ((str == ft_str) && (s == ft_s) && (c == ft_c) && (*ft_it == *it));
    //     }
    //     // insert at the end
    //     {
    //         std::vector<std::string> v;
    //         ft::vector<std::string> ft_v;

    //         it = v.insert(v.end(), "hello");
    //         ft_it = ft_v.insert(ft_v.end(), "hello");
    //         ft_it->length();

    //         str.clear();
    //         ft_str.clear();

    //         s = v.size();
    //         ft_s = ft_v.size();
    //         c = v.capacity();
    //         ft_c = ft_v.capacity();
    //         for (size_t i = 0; i < v.size(); ++i)
    //             str += v[i];
    //         for (size_t i = 0; i < ft_v.size(); ++i)
    //             ft_str += ft_v[i];
    //         cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it));
    //     }
    //     /*---------------------------------------------------------------------------------------------------*/
    //     /*------------------------------- test 2: the vector capacity >= size + the new element ----------------------------------------*/
    //     {
    //         std::vector<std::string> v(20, "string");
    //         ft::vector<std::string> ft_v(20, "string");
    //         ft::vector<std::string>::iterator valid_it;

    //         v.reserve(30);
    //         ft_v.reserve(30);
    //         valid_it = ft_v.begin();
    //         it = v.insert(v.begin() + 10, "hello");
    //         ft_it = ft_v.insert(ft_v.begin() + 10, "hello");
    //         ft_it->length();

    //         str.clear();
    //         ft_str.clear();
    //         s = v.size();
    //         ft_s = ft_v.size();
    //         c = v.capacity();
    //         ft_c = ft_v.capacity();
    //         for (size_t i = 0; i < v.size(); ++i)
    //             str += v[i];
    //         for (size_t i = 0; i < ft_v.size(); ++i)
    //             ft_str += ft_v[i];
    //         cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it) && (&(*valid_it) == &(*ft_v.begin())));
    //     }
    //     /*---------------------------------------------------------------------------------------------------*/
    //     /*------------------------------- test 3: the vector capacity < size + the new element ----------------------------------------*/
    //     {
    //         std::vector<std::string> v(20, "string");
    //         ft::vector<std::string> ft_v(20, "string");

    //         it = v.insert(v.begin() + 10, "hello");
    //         ft_it = ft_v.insert(ft_v.begin() + 10, "hello");
    //         ft_it->length();

    //         str.clear();
    //         ft_str.clear();
    //         s = v.size();
    //         ft_s = ft_v.size();
    //         c = v.capacity();
    //         ft_c = ft_v.capacity();
    //         for (size_t i = 0; i < v.size(); ++i)
    //             str += v[i];
    //         for (size_t i = 0; i < ft_v.size(); ++i)
    //             ft_str += ft_v[i];
    //         cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (*it == *ft_it));
    //     }
    //     /*---------------------------------------------------------------------------------------------------*/
    //     EQUAL(cond);
    // }

            //NECESSERRYY TEEEST !!!
            
//             ft::vector<int> myvector (3,100);
//             ft::vector<int>::iterator it;

//             it = myvector.begin();
//             it = myvector.insert ( it , 200 );

//             myvector.insert (it,2,300);

//             // "it" no longer valid, get a new one:
//             it = myvector.begin();

//             ft::vector<int> anothervector (2,400);
//             myvector.insert (it+2,anothervector.begin(),anothervector.end());

//             int myarray [] = { 501,502,503 };
//             myvector.insert (myvector.begin(), myarray, myarray+3);

//             std::cout << "myvector contains:";
//             for (it=myvector.begin(); it<myvector.end(); it++)
//                 std::cout << ' ' << *it;
//             std::cout << '\n';
        
// }