inline void printContainer() {}
inline void printArray() {}
inline void printArray2() {}

// template<class Name>
// void printContainer(const Name& name){
// 	cout<<"finish"<<endl;
// }

template<class T>
struct has_begin {
private:
template <class U>
static auto check(U x) -> decltype(x.begin(), std::true_type{});
static std::false_type check(...);
public:
static bool const value = decltype(check(std::declval<T>()))::value;
};

//template<class Primitive, class... Tail, std::enable_if_t<!has_begin<Primitive>::value, std::nullptr_t> = nullptr>

template<class Name,class Container, class... Tail>
inline void printContainer(const Name& name,const Container& c, const Tail&... tail) {
	cout<<name<<endl;
	for (const auto& x : c) {
        for(const auto& p:x){
            cout << p << " ";    
        }
	}
	cout << "\n";
	printContainer(name,tail...);
}

template<class Container,std::enable_if_t<!has_begin<Container>::value, std::nullptr_t> = nullptr>
inline void printHogeHoge(const Container& c) {
	cout<<c<<" ";
}

inline void printHogeHoge(const std::string& c) {
	cout<<c<<endl;
}



template<class Container,std::enable_if_t<has_begin<Container>::value, std::nullptr_t> = nullptr>
inline void printHogeHoge(const Container& c) {
	for (const auto& x : c) {
        printHogeHoge(x);
	}
	cout << "\n";
}

template<class Name,class Container>
inline void printHugaHuga(const Name& name,const Container& c) {
    cout<<name<<endl;
    printHogeHoge(c);
}



template<class Container, class... Tail>
void printArray(string name,vector<ll>& a){
    cout<<name<<endl;
    rep(i,0,a.size()){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}


template<class Name,class Container>
void printArray2(string name,vector<V>& a){
    cout<<name<<endl;
    rep(i,0,a.size()){
        rep(j,0,a[i].size()){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


