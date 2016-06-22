#ifndef _H_LINKLIST_
#define _H_LINKLIST_
// author : Avlin liu
// function : sort or not sort linklist 
// history : 
//      2016 06 21  ----- v 0.1 unsort linklist support :
//          pop :
//              insert item at the link list head
//          insert :
//              requrie item and index [option default : 0]
//          del :
//              require item  
//              remove the first find item from linklist when item in linklist and return true ,otherwise return false 
//          push :
//              remove item at the head from the link 
//          len:
//              return the length of the link
//          << or print :
//              print the item in the link
//
#include<iostream>
using std::ostream;
template<class T>
class CST
{
    public:
        T item;
        CST *next;
};
template<class T> class CLinklist;
template<class T>
ostream& operator<< (ostream & os ,const CLinklist<T> & list);

template<class T>
class CLinklist
{
    private:
        CLinklist(const CLinklist &);
        CLinklist& operator=(CLinklist &);
        typedef CST<T> ST;
    private:
        int m_len;// the length of the linklist
        bool m_sort_en; // 0: normal link 1: sort link
        ST * m_head;//pointer to  top element 
        ST * m_end;
    public:
        explicit CLinklist(bool sort_en=false);
        ~CLinklist();
        const int len() const { return m_len;};
        bool pop(void);// remove top element from the linklists
        void push(T& item);// insert the item at top of the linklist
        bool insert(const T& item,const int index=0);//insert item at the index
        bool del(T& item); // remove item from the linklist
        void print(void) const; // print all the element in the linlist
        friend ostream & operator<< <> (ostream & os, const CLinklist<T>&  list);
};

template<class T>
CLinklist<T>::CLinklist(bool sort_en)
{
    m_end =  m_head = NULL;
    m_len = 0;
    m_sort_en = sort_en;
}

template<class T>
CLinklist<T>::~CLinklist()
{
    while(pop())
        ;
}

template<class T>
bool CLinklist<T>::pop(void)
{
    if(!m_head)
        return false;
    ST *tmp=m_head;
    m_head = m_head->next;
    delete tmp;
    --m_len;
    return true;
}

template<class T>
void CLinklist<T>::push(T& item)
{
    ST *tmp = new ST;
    tmp->item=item;
    ++m_len;
    tmp->next=m_head;
    if(m_end==NULL)
        m_end=tmp;
    m_head = tmp;
}

template<class T>
bool CLinklist<T>::insert(const T& item,const int index)
{
    if(index<0||index>m_len)
        return false;
    int i=0;
    ++m_len;
    ST *tmp = new ST;
    tmp->item=item;
    tmp->next=NULL;
    if(index==0)// insert head
    {
        tmp->next=m_head;
        m_head = tmp;
        return true;
    }
    else if (index==m_len)
    {
        m_end->next = tmp;
        m_end=tmp;
        return true;
    }
    ST *current=m_head;
    ST *front=NULL;
    while(i<index)
    {

        ++i;
        front=current;
        current=current->next;
    }
    tmp->next=current;
    front->next=tmp;
    return true;
}

template<class T>
bool CLinklist<T>::del(T& item)
{
    ST *front=NULL;
    ST *cur =m_head;
    while(cur)
    {
        if(cur->item==item)
            break;
        front=cur;
        cur=cur->next;
    }
    if(!cur)
        return false;
    front->next=cur->next;
    delete cur;
    --m_len;
    return true;
}

template<class T>
void CLinklist<T>::print(void) const 
{
    ST*tmp=m_head;
    while(tmp)
    {
        std::cout<<tmp->item<<'\t';
        tmp=tmp->next;
    }
    std::cout<<"\n";
}

template<class T>
ostream & operator<<(ostream &os,const CLinklist<T> & list)
{
    list.print();
    return os;
}

#endif
