inline void printContainer() {}
inline void printArray() {}
inline void printArray2() {}

template<class Name>
void printContainer(const Name& name){
	cout<<"finish"<<endl;
}

template<class Name,class Container, class... Tail>
inline void printContainer(const Name& name,const Container& c, const Tail&... tail) {
	cout<<name<<endl;
	for (const auto& x : c) {
		cout << x << " ";
	}
	cout << "\n";
	printContainer(name,tail...);
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


template<class Container, class... Tail>
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


