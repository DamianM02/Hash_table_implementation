#include <iostream>
#include <list>
#include <string>
class hashweed1{
public:
    int n;
    int* tab;
    int rodzaj;
    //bool* a;
    int rozmiar;
    int (*f)(int, int);
    int (*f2)(int, int);
//int funkcja();


    hashweed1(int m, int l, int h(int, int), int *k, int rozmiar1){
        f=h;
        rodzaj=l;
        rozmiar=rozmiar1;
        tab=new int[rozmiar];
        //a=new bool[rozmiar];
        for (int i=0; i<rozmiar; i++){
            ///a[i]=0;
            tab[i]=NULL;
        }
        //f(int)=h(int);



        if(l==2){
            for (int i=0; i <m; i++){
                for (int j=0; j<rozmiar; j++){
                    if(tab[(h(k[i], rozmiar)+j)%rozmiar]==NULL){
                        tab[(h(k[i], rozmiar)+j)%rozmiar]=k[i];
                        //a[(h(k[i], rozmiar)+j)%rozmiar]=1;
                        break;
                    }
                }

            }
        }

        if (l==3){
            for (int i=0; i <m; i++){
                for (int j=0; j<rozmiar; j++){
                    if(tab[(h(k[i], rozmiar)+j+j*j)%rozmiar]==NULL){
                        tab[(h(k[i], rozmiar)+j+j*j)%rozmiar]=k[i];
                        //a[(h(k[i], m)+j+j*j)%m]=1;
                        break;
                    }
                }
            }
        }

    }

    hashweed1(int m, int l, int h(int, int), int h2(int, int), int *k, int rozmiar1){
        f=h;
        f2=h2;
        rozmiar=rozmiar1;
        tab=new int[rozmiar1];
        //a=new bool[rozmiar1];
        //bool a[m];

        for (int i=0; i<rozmiar; i++){
            //a[i]=0;
            tab[i]=NULL;
        }

        if(l==4){
            for (int i=0; i<m; i++){
                for (int j=0; j<m; j++){
                    if(tab[(h(k[i], rozmiar)+j*h2(k[i], rozmiar))%rozmiar]==NULL){
                        tab[(h(k[i], rozmiar)+j*h2(k[i], rozmiar))%rozmiar]=k[i];
                        //a[(h(k[i], m)+j*h2(k[i], m))%m]=1;
                        break;
                    }
                }

            }
        }

    }



    int size()const{
        return rozmiar;
    }

    int search(int e){
        if (rodzaj==2){
            for (int j=0; j<rozmiar; j++){
                if(tab[(f(e, rozmiar)+j)%rozmiar]==e){
                    return (f(e, rozmiar)+j)%rozmiar;
                }
            }
        }
        if (rodzaj==3){
            for (int j=0; j<rozmiar; j++){
                if(tab[(f(e, rozmiar)+j+j*j)%rozmiar]==e){
                    return (f(e, rozmiar)+j+j*j)%rozmiar;
                }
            }
        }

        if (rodzaj==4){
            for (int j=0; j<rozmiar; j++){
                if(tab[(f(e, rozmiar)+j*f2(e, rozmiar))%rozmiar]==e){
                    return (f(e, rozmiar)+j*f2(e, rozmiar))%rozmiar;
                }
            }
        }

        for (int i=0; i<rozmiar; i++){
            //if (a[i]){
            if (tab[i]==e){
                return i;
            }
            //}
        }
        //std::cout<<"Brak"<<std::endl;
        return NULL;
    }

    void delete1(int e){
        if (search(e)!=NULL) {
            tab[search(e)] = NULL;
            //a[search(e)] = 0;
        }
    }

    void insert (int e){
        if (rodzaj==2){
            for (int j=0; j<rozmiar; j++){
                if(tab[(f(e, rozmiar)+j)%rozmiar]==NULL){
                    tab[(f(e, rozmiar)+j)%rozmiar]=e;
                    return;
                }
            }
        }
        if (rodzaj==3){
            for (int j=0; 1; j++){
                if(tab[(f(e, rozmiar)+j+j*j)%rozmiar]==NULL){
                    tab[(f(e, rozmiar)+j+j*j)%rozmiar]=e;
                    return;
                }
            }
        }

        if (rodzaj==4){
            for (int j=0; 1; j++){
                if(tab[(f(e, rozmiar)+j*f2(e, rozmiar))%rozmiar]==NULL){
                    tab[(f(e, rozmiar)+j*f2(e, rozmiar))%rozmiar]=e;
                    return;
                }
            }
        }
    }






};


class hashweed2{
public:
    std::list<int>*tab;
    //bool* a;
    int rozmiar;
    int (*f)(int, int);

    hashweed2(int m, int l, int h(int, int), int *k, int rozmiar1){
        f=h;
        rozmiar=rozmiar1;
        tab=new std::list<int>[rozmiar];
        for (int i=0; i<rozmiar; i++) {
            //a[i]=0;
            tab[i].clear();
        }

        for (int i=0; i<m; i++){
            tab[h(k[i], rozmiar)].push_front(k[i]);
        }

    }

    int size()const{
        return rozmiar;
    }

    void insert(int e){
        tab[f(e, rozmiar)].push_front(e);
    }

    void delete1(int e){

        tab[f(e, rozmiar)].remove(e);

    }

    int search(int e){
        for (std::list<int>::iterator i=tab[f(e, rozmiar)].begin(); i != tab[f(e, rozmiar)].end(); i++){
            if (*i==e) return f(e, rozmiar);
        }
        return NULL;
    }

};
//---------------------------------------------
int h(int key,int m){
    return key%m;
}

int h2(int key, int m){
    return key%(m-1) + 1;
}
//---------------------------------------------
void print(hashweed1 &a){
    std::cout<<'[';

    if (a.tab[0]!=NULL){
        std::cout<<a.tab[0];
    }else{
        std::cout<<"None";
    }



    for (int i=1; i<a.rozmiar; i++){
        if (a.tab[i]!=NULL){
            std::cout<<", "<<a.tab[i];
        }else{
            std::cout<<", "<<"None";
        }

    }
    std::cout<<']';
    std::cout<<std::endl;
}

void print(hashweed2 &a){
    std::cout<<'[';
    for (int i=0; i<a.rozmiar; i++){
        if (a.tab[i].empty()){
            std::cout<<"None";
        }else{
            std::cout<<'[';
            std::list<int>::iterator j=a.tab[i].begin();
            std::cout<<*j;
            j++;
            for ( ; j != a.tab[i].end(); j++){
                std::cout<<", "<<*j;
            }
            std::cout<<']';
        }

        if(i<a.rozmiar-1) std::cout<<", ";
    }

    std::cout<<']'<<std::endl;
}
//---------------------------------------------------
int q(hashweed1 a){
    int t=5;
    int element;
    while(t!=-1){
        std::cin>>t;
        if (t==-1) return 0;
        std::cin>>element;
        if (t==0){
            a.insert(element);
            print(a);
        }
        if (t==1){
            std::cout<<a.search(element)<<std::endl;

        }
        if (t==2){
            a.delete1(element);
            print(a);
        }
    }
    return 0;
}

int q(hashweed2 a){
    int t=5;
    int element;
    while(t!=-1){
        std::cin>>t;
        if (t==-1) return 0;
        std::cin>>element;
        if (t==0){
            a.insert(element);
            print(a);
        }
        if (t==1){
            std::cout<<a.search(element)<<std::endl;

        }
        if (t==2){
            a.delete1(element);
            print(a);
        }
    }
    return 0;
}






//---------------------------------------------
int main() {
    std::cout<<"rozmiar rodzaj element1 element2 element3 ..."<<std::endl;
    int m;
    std::cin>>m;
    int l;
    std::cin>>l;
    int b[m];
    std::string c;
    //std::cin.ignore();
    std::getline(std::cin, c);
    int t=0;
    int d=0;
    for (int i=1; 1; i++){
        //if (!c[i]) break;

        if (c[i]!=' ' && c[i]!=NULL){
            t++;
        }else{
            int f=0;
            for (int j=i-t; j<i; j++){
                int g=c[j]-48;
                for(int l=0; l<t-1; l++){
                    g=g*10;

                }
                t--;
                f=f+g;
            }
            b[d]=f;
            d++;
            if (c[i]==NULL) break;
        }
    }
    //for (int i=0; i<d; i++) std::cout<<b[i]<<' ';

    if (l==1){
        hashweed2 x(d, l, h, b, m);
        print (x);
        if (q(x)==0) return 0;

    }
    if (l==2 || l==3 || l==4){

        if(l==4){
            hashweed1 x(d, l, h, h2, b, m);
            print (x);
            if (q(x)==0) return 0;
        }else {
            hashweed1 x(d, l, h, b, m);
            print (x);
            if (q(x)==0) return 0;
        }


    }

}
