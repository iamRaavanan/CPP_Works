#include <iostream>
#include<type_traits>
#include<tuple>

void PrintN()
{
    std::cout<< std::endl;
}

template<typename LAST>
void PrintN(LAST& T)
{
    std::cout<< std::forward<LAST>(T) << std::endl;
}

template<typename T0, typename ... T1toN>
void PrintN(T0&& t, T1toN&& ... remaining)
{
    std::cout<< std::forward<T0>(t)<<std::endl;
    PrintN(std::forward<T1toN>(remaining)...);
}

template<typename TUPLE, std::size_t ... indices>
void Print_Tuple_Impl(TUPLE&& t, std::index_sequence<indices...>)
{
    PrintN(std::get<indices>(std::forward<TUPLE>(t))...); // PrintN(std::get<0>(t), std::get<1>(t), std::get<2>(t)...)
}

template<typename TUPLE>
void Print_Tuple(TUPLE&& t)
{
    Print_Tuple_Impl(std::forward<TUPLE>(t), std::make_index_sequence<std::tuple_size<std::remove_reference_t<TUPLE>>::value>{});
}

int main()
{
    std::cout<<std::boolalpha;
    PrintN(7, "Hello", 1.5f, true, "Welcome", false);
    PrintN("=============== TUPLE ===============");
    const auto tuple = std::make_tuple(7, "Hello", 1.5f, true, "Welcome", false);
    Print_Tuple(tuple);
    
}