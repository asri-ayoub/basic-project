
template<typename A, typename B>
void print_is_same()
{
    std::cout << static_cast<bool>(std::is_same<A,B>::value) << std::endl;
}
