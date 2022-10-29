# CPP_Works
Contains the modules of code for core functionalities of meta programming

# TemplateCondition.cpp
     std::tuple<int, bool, float> tuple;
     std::cout<< contains_type<bool, decltype(tuple)>::value << "\n";

# VariadicTemplates.cpp
     std::forward<T>(value)
     template<typename TUPLE, std::size_t ... indices>
     void Print_Tuple_Impl(TUPLE&& t, std::index_sequence<indices...>)
     {
          PrintN(std::get<indices>(std::forward<TUPLE>(t))...); // PrintN(std::get<0>(t), std::get<1>(t), std::get<2>(t)...)
     }
     
     
