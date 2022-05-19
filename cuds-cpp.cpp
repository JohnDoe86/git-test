void fun1(int const& t)
{
   auto f = [](int const& t){  //no use para t of fun1 
       return ([&t](auto b){
           return t;
       });
   };
}

void fun2(int const& k)
{
   auto f = [](int const& t){  //no use para t of fun1 
       return ([&t](auto b){
           int bili;
           return bili;
       });
   };
}

void fun3(int const& k)
{
   auto f = [](int const& t){  //no use para t of fun1 
       return ([&t](auto b){
           int k;
       });
   };
}

// void fun4(int const& t)
// {
//    auto f = [](int const& t){  //no use para t of fun1 
//        return ([t](auto b){
//            int bili;
//            return bili;
//        });
//    };
// }

// void fun5(int const& k)
// {
//    auto f = [](int const& t){  //no use para t of fun1 
//        return ([t](auto b){
//            int bili;
//            return bili;
//        });
//    };
// }

// void fun6(int const& k)
// {
//    auto f = [](int const& t){  //no use para t of fun1 
//        return ([t](auto b){
//            int k;
//        });
//    };
// }

// void fun1_1(int const& t)
// {
//    auto f = [](auto const& t){  //no use para t of fun1 
//        return ([&t](auto b){
//            int bili;
//            return bili;
//        });
//    };
// }

// void fun2_1(int const& k)
// {
//    auto f = [](auto const& t){  //no use para t of fun1 
//        return ([&t](auto b){
//            int bili;
//            return bili;
//        });
//    };
// }

// void fun3_1(int const& k)
// {
//    auto f = [](auto const& t){  //no use para t of fun1 
//        return ([&t](auto b){
//            int k;
//        });
//    };
// }

// void fun4_1(int const& t)
// {
//    auto f = [](auto const& t){  //no use para t of fun1 
//        return ([t](auto b){
//            int bili;
//            return bili;
//        });
//    };
// }

// void fun5_1(int const& k)
// {
//    auto f = [](auto const& t){  //no use para t of fun1 
//        return ([t](auto b){
//            int bili;
//            return bili;
//        });
//    };
// }

// void fun6_1(int const& k)
// {
//    auto f = [](auto const& t){  //no use para t of fun1 
//        return ([t](auto b){
//            int k;
//        });
//    };
// }

// //no-compliant

// // void fun2(int const& t)
// // {
// //    auto f = [](auto const& t){
// //        return ([&t](auto b){
// //            return t>b?t:b;
// //        });
// //    };
// // }

// // void fun3(int const& k)
// // {
// //    auto f = [](int const& t){  //no use para t of fun1 
// //        return ([&t](auto b){
// //            return t>b?t:b;
// //        });
// //    };
// // }

// // void fun4(char const& k)
// // {
// //    auto f = [](int const& t){  //no use para t of fun1 
// //        return ([&t](auto b){
// //            return t;
// //        });
// //    };
// // }


// // void fun3(const int& t)
// // {
// //    auto f = [](const int& a){
// //        return ([&a](int b){
// //            return a>b?a:b;
// //        });
// //    };
// // }
// // //no-compliant