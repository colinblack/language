template<class charT>
class basic_string{

private:
    basic_string& append(basic_string& s){

    } 
};

template<class charT>
basic_string<charT> operator+(basic_string<charT>& ls, basic_string<charT>& rs){
    basic_string<charT> tmp(ls); 
    tmp.append(rs);
    return tmp;
} 

