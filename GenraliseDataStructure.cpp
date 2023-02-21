#include<iostream>
using namespace std;
////////////////////////////////////////////////////
//
// Appliction Name : GenraliseDataStructure
// Description     : implementation Of All STL Library With Some Added Function
// Author          : Siddhesh Naval Mali
// Date            : 22/01/2023
//
//////////////////////////////////////////////////////
template<class T>
struct nodeS   // Structure Defination
{
      T data;
      struct nodeS * next;
};
///////////////////////////////////////////////////
template<class T>
struct nodeD    // Structure Defination
{
      T data;
      struct nodeD * next;
      struct nodeD * prev;
};
/*-----------------------------------------------------------------*/
template<class T>
class SinglyLL    // Diclaration of a class
{
      public:
            struct nodeS<T> * First;

            SinglyLL();
           void InsertFirst(T no);
           void InsertLast(T no);
           void InsertAtPos(int ipos , T no);
           void DeleteFirst();
           void  DeleteLast();
           void  DeleteAtPos(int ipos);
           void Display();
           int Count();
           int SearchFirstOccurnce(T no);
           int SearchLastOccurnce(T no);
           int Frequency(T no);
};
/////////////////////////////////////////////////////////
//
//  Constructor name : SinglyLL
//  Description      : It is a Singly LinkedList constructor Used to inistalise Pointer
//  Parameter        :  none
//  Return value     :  none
//
///////////////////////////////////////////////////////////////
template<class T>
SinglyLL<T> :: SinglyLL()
{
      First = NULL;
}
///////////////////////////////////////////////////////////////
//
//  Function name : InsertFirst
//  Description   : Used to insert at first position of Linked list
//  Parameters    : Data of node
//  Return Value  : Void
//
///////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: InsertFirst(T no)
{
      struct nodeS <T>* newn = new struct nodeS<T>;
      newn->data = no;
      newn->next = NULL;

      if(First == NULL)
      {
            First = newn;
      }
      else
      {
            newn->next = First;
            First = newn;
      }
}
////////////////////////////////////////////////////////////
//
//  Function name : InsertLast
//  Description   : Used to insert at last position of Linked list
//  Parameters    :  Data of node
//  Return Value  : Void
//
////////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: InsertLast(T no)
{
      
      struct nodeS <T>* newn = new struct nodeS<T>;
      newn->data = no;
      newn->next = NULL;

      struct nodeS<T> * temp = First;

      if(First == NULL)
      {
            First = newn;
      }
      else
      {
            while(temp ->next !=NULL)
            {
                  temp = temp ->next;
            }

            temp->next = newn;
      }
}
//////////////////////////////////////////////////////////
//
//  Function name : InsertAtPos
//  Description   : Used to insert at  position of Linked list
//  Parameters    : position & data of node
//  Return Value  : Void
//
//////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: InsertAtPos(int ipos , T no)
{
      int NodeCount = 0;
      NodeCount = Count();

      if((ipos < 1)||(ipos > NodeCount + 1))
      {
            cout<<"Invalid Position"<<"\n";
            return;
      }

      if(ipos == 1)
      {
            InsertFirst(no);
      }
      else if(ipos == NodeCount+1)
      {
            InsertLast(no);
      }
      else
      {
            struct nodeS<T> * newn = new nodeS<T>;
            newn->data = no;
            newn->next = NULL;
            struct nodeS<T> * temp = First;
            int icnt = 0;

            for(icnt = 1;icnt < ipos-1;icnt++)
            {
                  temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
      }
}
//////////////////////////////////////////////////////////
//
//  Function name : DeleteFirst
//  Description   : Used to delete at first  position of Linked list
//  Parameters    : none
//  Return Value  : Void
//
//////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: DeleteFirst()
{
      struct nodeS <T>* temp = First;
      if(First == NULL)
      {
            return;
      }
      else if(First->next == NULL)
      {
            delete First;
            First == NULL;
      }
      else
      {
            First = First ->next;
            delete temp;

      }

}
//////////////////////////////////////////////////////////
//
//  Function name : DeleteLast
//  Description   : Used to delete at last position of Linked list
//  Parameters    : none
//  Return Value  : Void
//
//////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: DeleteLast()
{
       struct nodeS <T>* temp = First;
      if(First == NULL)
      {
            return;
      }
      else if(First->next == NULL)
      {
            delete First;
            First == NULL;
      }
      else
      {
           while(temp->next->next !=NULL)
           {
             temp = temp->next;
           }
            delete temp->next;
            temp->next = NULL;
      }
}
//////////////////////////////////////////////////////////
//
//  Function name : DeleteAtPos
//  Description   : Used to delete at  position of Linked list
//  Parameters    : Position of node
//  Return Value  : Void
//
//////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: DeleteAtPos(int ipos)
{
      int NodeCount = 0;
      NodeCount = Count();

      if((ipos < 1)||(ipos > NodeCount))
      {
            return;
      }

      if(ipos == 1)
      {
            DeleteFirst();
      }
      else if(ipos == NodeCount)
      {
            DeleteLast();
      }
      else
      {
            struct nodeS<T> * temp1 = First;
            struct nodeS<T> * temp2 = NULL;

            for(int icnt = 1 ;icnt<ipos-1;icnt++)
            {
                  temp1 = temp1->next;
            }
            temp2 = temp1->next;
            temp1->next = temp2->next;

            delete temp2;
      }

}
/////////////////////////////////////////////////////////////////
//
//  Function name : SearchFirstOccurnce
//  Description   : Used to search first occurance  of Linked list
//  Parameters    : Data of node
//  Return Value  : int
//
/////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL<T> :: SearchFirstOccurnce(T no)
{
    int Count = 1;
    int ipos = -1;
     struct nodeS<T> * temp = First;

    while(temp !=NULL)
    {
        if(temp->data == no)
        {
            ipos = Count;
           break;
        }
        temp = temp->next;
        Count++;
    }
    return ipos;
}
/////////////////////////////////////////////////////////////////
//
//  Function name : SearchLastOccurnce
//  Description   : Used to search last occurance  of Linked list
//  Parameters    : Data of node
//  Return Value  : int
//
/////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL<T> :: SearchLastOccurnce(T no)
{
    int Count = 1;
    int ipos = -1;
     struct nodeS<T> * temp = First;
    while(temp !=NULL)
    {
        if(temp->data == no)
        {
            ipos = Count;
          
        }
        temp = temp->next;
        Count++;
    }
    return ipos;
}
/////////////////////////////////////////////////////////////////
//
//  Function name : Frequency
//  Description   : Used to search frequency of Linked list
//  Parameters    : Data of node
//  Return Value  : int
//
/////////////////////////////////////////////////////////////////
template<class T>
int SinglyLL<T> :: Frequency(T no)
{
    int Count = 0;
    struct nodeS<T> * temp = First;
   
    while(temp !=NULL)
    {
        if(temp->data == no)
        {
           Count++;
          
        }
        temp = temp->next;
       
    }
    return Count;
}
//////////////////////////////////////////////////////////
//
//  Function name : Display
//  Description   : Used to display elements of Linked list
//  Parameters    : none
//  Return Value  : Void
//
//////////////////////////////////////////////////////////
template<class T>
void SinglyLL<T> :: Display()
{
      struct nodeS<T> * temp = First;

      cout<<"Elements Of Linked List are :"<<"\n";
      while(temp!=NULL)
      {
            cout<<"|"<<temp->data<<"|->";
            temp = temp->next;
      }
      cout<<"NULL"<<"\n";
}
//////////////////////////////////////////////////////////
//
//  Function name : Count
//  Description   : Used to count elements of Linked list
//  Parameters    : none
//  Return Value  : int
//
//////////////////////////////////////////////////////////
template<class T>
int SinglyLL <T>:: Count()
{
      struct nodeS<T> * temp = First;
      int icnt = 0;
   
      while(temp!=NULL)
      {
         icnt++;
         temp = temp->next;
      }
      return icnt;
}
/////////////////////////////////////////////////////////
template<class T>
class SinglyCircular
{
      public:
     struct nodeS <T>*First;
     struct nodeS <T>* Last;
      

      SinglyCircular();   // constructor

      void InsertFirst(T no);  // Behaviour 
      void InsertLast(T no);
      void InsertATPosition(T no ,int ipos);

      void DeleteFirst();
      void DeleteLast();
      void DeleteATPosition(int ipos);

      void Display();
      int Count();
};
//////////////////////////////////////////////////////////

template<class T>
SinglyCircular <T> :: SinglyCircular()
{
      First = NULL;
      Last = NULL;
     
}
template<class T>
void SinglyCircular <T> :: InsertFirst(T no)
{
      struct nodeS <T>* newn = new struct nodeS <T>;

      newn->data = no;
      newn->next = NULL;

      if((First == NULL)&&(Last == NULL))  // Empty LL
      {
            First = Last = newn;
            (Last)->next = First;
      }
      else // At Contains at least 
      {
            newn->next = First;
            First = newn;
            (Last)->next = First;
      }
}
template<class T>
void SinglyCircular <T> ::InsertLast(T no)
{
      
      struct nodeS <T> * newn = new struct nodeS <T>;
      newn->data = no;
      newn->next = NULL;

      if((First == NULL)&&(Last == NULL))  // Empty LL
      {
            First = Last = newn;
            (Last)->next = First;
      }
      else // At Contains at least 
      {
            (Last)->next = newn;
            (Last) = newn;
            (Last)->next = First;
      }
}
template<class T>
void SinglyCircular <T>  :: InsertATPosition(T no ,int ipos)
{
    int iNodeCnt = 0;
    iNodeCnt = Count();
    struct nodeS <T> * newn = NULL;
    struct nodeS <T> * temp = First;
    int icnt = 0;

    if((ipos<1)||(ipos > iNodeCnt + 1))
    {
        return;
    }

    if(ipos == 1)
    {
       InsertFirst(no);
    }
    else if(ipos == iNodeCnt + 1)
    {
      InsertLast(no);
    }
    else
    {
       
         newn = new struct nodeS <T>;
         newn->data = no;
         newn->next = NULL;

         for(icnt = 1;icnt<ipos-1;icnt++)
         {
            temp = temp->next;
         }

         newn->next = temp->next;
         temp->next = newn;
    }

}
template<class T>
void SinglyCircular <T>  :: DeleteFirst()
{
      if((First == NULL)||(Last==NULL))
      {
            return;
      }
      else if(First==Last) // Singly node in LL
      {   
            delete First;   // (*Last)pn chalele 
            First = NULL;  
            Last = NULL; 
      }
      else // more than one Node
      {
            First = (First)->next;
           delete Last->next;
            (Last)->next = First;

      }
}
template<class T>
void SinglyCircular <T> ::DeleteLast()
{
      struct nodeS<T> * temp = First;

      if((First==NULL)||(Last==NULL))
      {
            return;
      }
      else if(First==Last) // Singly node in LL
      {
           delete First;
            First = NULL;  // 
            Last = NULL; 
      }
      else // more than one Node
      {
            while(temp->next !=Last)
            {
                  temp = temp->next;
            }

           delete temp->next;
            Last = temp;
            (Last)->next = First;
      }
}
template<class T>
void SinglyCircular <T> ::DeleteATPosition(int ipos)
{
      struct nodeS <T> * temp1 = First;
      struct nodeS <T>* temp2 = NULL;
      int NodeCnt = 0 ,icnt =0;
      NodeCnt = Count();

      if((ipos < 1)||(ipos >(NodeCnt)))
      {
            return;
      }
      
      if(ipos == 1)
      {
            DeleteFirst();
      }
      else if(ipos == NodeCnt)
      {
            DeleteLast();
      }
      else
      {
            for(icnt = 1;icnt<ipos-1;icnt++)
            {
                  temp1 = temp1->next;
            }

            temp2 = temp1->next;
            temp1->next = temp2->next;

            //free(temp2);
            delete temp2;
          
      }
}
template<class T>
void SinglyCircular <T> ::Display()
{
      struct nodeS <T> * temp = First;

      cout<<"Elements of Linked list are :"<<" \n";

      do
      {
            cout<<"|"<<temp->data<<"|->";
            temp = temp -> next;
      }while(temp != Last->next);
     cout<<"NULL"<<"\n";
}
template<class T>
int SinglyCircular <T> ::Count()
{
      int icnt = 0;
      struct nodeS <T> * temp = First;
      
      do
      {     
            icnt++;
            temp = temp -> next;
      }while(temp != Last->next);
      printf("\n");
     return icnt;
     
}

//////////////////////////////////////////////////////////
template<class T>
class DoublyLL
{
      public:
            struct nodeD<T> * First;

            DoublyLL();
           void InsertFirst(T no);
           void InsertLast(T no);
           void InsertAtPos(int ipos , T no);
           void DeleteFirst();
           void  DeleteLast();
           void  DeleteAtPos(int ipos);
           void Display();
           int Count();
};
/////////////////////////////////////////////////////////

template<class T>
DoublyLL<T> ::DoublyLL()
{
      First = NULL;
}
template<class T>
void DoublyLL<T> :: InsertFirst(T no)
{
      struct nodeD<T> * newn = new struct nodeD<T>;
      newn->data = no;
      newn->next = NULL;
      newn->prev = NULL;

      if(First == NULL)
      {
            First = newn;
      }
      else
      {
            newn->next = First;
            First->prev = newn;
            First = newn;
      }
}
template<class T>
void DoublyLL<T> :: InsertLast(T no)
{
      
      struct nodeD <T>* newn = new struct nodeD<T>;
      newn->data = no;
      newn->next = NULL;
      newn->prev = NULL;

      struct nodeD<T> * temp = First;

      if(First == NULL)
      {
            First = newn;
      }
      else
      {
            while(temp ->next !=NULL)
            {
                  temp = temp ->next;
            }

            temp->next = newn;
            newn->prev = temp;
      }
}
template<class T>
void DoublyLL<T> :: InsertAtPos(int ipos , T no)
{
      int NodeCount = 0;
      NodeCount = Count();

      if((ipos < 1)||(ipos > NodeCount + 1))
      {
            cout<<"Invalid Position"<<"\n";
            return;
      }

      if(ipos == 1)
      {
            InsertFirst(no);
      }
      else if(ipos == NodeCount+1)
      {
            InsertLast(no);
      }
      else
      {
            struct nodeD<T> * newn = new nodeD<T>;
            newn->data = no;
            newn->next = NULL;
             newn->prev = NULL;
            struct nodeD<T> * temp = First;
            int icnt = 0;

            for(icnt = 1;icnt < ipos-1;icnt++)
            {
                  temp = temp->next;
            }
            newn->next = temp->next;
            temp->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;
      }
}
template<class T>
void DoublyLL<T> :: DeleteFirst()
{
      struct nodeD<T>* temp = First;
      if(First == NULL)
      {
            return;
      }
      else if(First->next == NULL)
      {
            delete First;
            First == NULL;
      }
      else
      {
            First = First ->next;
            delete temp->prev;
            temp->prev = NULL;

      }

}
template<class T>
void DoublyLL<T> :: DeleteLast()
{
       struct nodeD<T> * temp = First;
      if(First == NULL)
      {
            return;
      }
      else if(First->next == NULL)
      {
            delete First->prev;
            First == NULL;
      }
      else
      {
           while(temp->next->next !=NULL)
           {
             temp = temp->next;
           }
            delete temp->next;
            temp->next = NULL;
      }
}
template<class T>
void DoublyLL<T> :: DeleteAtPos(int ipos)
{
      int NodeCount = 0;
      NodeCount = Count();

      if((ipos < 1)||(ipos > NodeCount))
      {
            return;
      }

      if(ipos == 1)
      {
            DeleteFirst();
      }
      else if(ipos == NodeCount)
      {
            DeleteLast();
      }
      else
      {
            struct nodeD<T> * temp1 = First;
            struct nodeD<T> * temp2 = NULL;

            for(int icnt = 1 ;icnt<ipos-1;icnt++)
            {
                  temp1 = temp1->next;
            }
            temp2 = temp1->next;
            temp1->next = temp2->next;
            temp2->next->prev = temp1;

            delete temp2;
      }

}
template<class T>
void DoublyLL<T>:: Display()
{
      struct nodeD <T>* temp = First;

      cout<<"Elements Of Linked List are :"<<"\n";
      while(temp!=NULL)
      {
            cout<<"|"<<temp->data<<"|->";
            temp = temp->next;
      }
      cout<<"\n";
}
template<class T>
int DoublyLL<T> :: Count()
{
      struct nodeD<T> * temp = First;
      int icnt = 0;
   
      while(temp!=NULL)
      {
         icnt++;
         temp = temp->next;
      }
      return icnt;
}
////////////////////////////////////////////////////////
template<class T>
class DoublyCircularL
{
      public:
     struct nodeD<T> * First;
     struct nodeD<T> * Last;
      DoublyCircularL();

      void InsertFirst(T no);
      void InsertLast(T no);
      void InsertAtPos(T no,int ipos);

      void DeleteFirst();
      void DeleteLast();
      void DeleteAtPos(int ipos);

      void Display();
      int Count();
};    
//////////////////////////////////////////////////////////
template<class T>
DoublyCircularL<T>:: DoublyCircularL()
{
      First = NULL;
      Last = NULL;
}
template<class T>
void DoublyCircularL<T>:: InsertFirst(T no)
{
    struct nodeD<T>* newn = new struct nodeD<T>;

      newn->data = no;
      newn->next = NULL;
      newn->prev = NULL;

      if((First == NULL)&&(Last == NULL))
      {
            First = newn;
            Last = newn;
           
      }
      else
      {
           newn->next = First;
           (First)->prev = newn;
           First = newn;
      }
      (First)->prev = Last;
      (Last)->next = First;
}
template<class T>
void DoublyCircularL<T>:: InsertLast(T no)
{
     struct nodeD<T>* newn = new struct nodeD<T>;

      newn->data = no;
      newn->next = NULL;
      newn->prev = NULL;

      if((First == NULL)&&(Last == NULL))
      {
           First = newn;
            Last = newn;
      }
      else
      {
            (Last)->next = newn;
            newn->prev = Last;
            Last = newn;
      }
      (First)->prev = Last;
      (Last)->next = First;
}
template<class T>
void DoublyCircularL<T>:: Display()
{
       struct nodeD<T>* temp = First;

      if((First == NULL)&&(Last == NULL))
      {
            cout<<"LinkedList are empty\n";
            return;
      }

      cout<<"Elements of DoublyCircularLinkedList are :\n";

      do
      {
            cout<<"| "<<temp->data<<" | <=>";
            temp = temp->next;
      }while(temp != Last->next);
      cout<<"\n";
}
template<class T>
int DoublyCircularL<T>:: Count()
{
       struct nodeD<T>* temp = First;
     int iCnt = 0;
      if((First == NULL)&&(Last == NULL))
      {
           
            return iCnt;
      }

      do
      {
           iCnt++;
            temp = temp->next;
      }while(temp != Last->next);

      return iCnt;
}
template<class T>
void DoublyCircularL<T> :: DeleteFirst()
{
      if(First == NULL && Last == NULL)
      {
            return;
      }
      else if(First == Last) // singal node
      {
            delete First;
            First = NULL;
            Last = NULL;
      }
      else   // More than one node
      {
            First = (First)->next;

            delete Last->next; // free9(*First ->prev)

            (First)->prev = Last;
            (Last)->next = First;

      }
      
}
template<class T>
void DoublyCircularL<T>:: DeleteLast()
{
      if(First == NULL && Last == NULL)
      {
            return;
      }
      else if(First == Last) // singal node
      {
            delete First;  // (*Last )pn chalel
            First = NULL;
            Last = NULL;
      }
      else   // More than one node
      {
            Last = (Last)->prev;

            free((First)->prev); // Free(*Last->next)

            (First)->prev = Last;
           (Last)->next = First;
      }
     
}
template<class T>
void DoublyCircularL<T>:: InsertAtPos(T no ,int ipos)
{
      int iCnt = 0;
      int NodeCnt = 0;
      struct nodeD<T>* newn = NULL;

      struct nodeD<T>* temp  = NULL;

      NodeCnt = Count();

      if((ipos < 1)||(ipos > NodeCnt + 1))
      {
            cout<<"Invalid postion \n";
            return;
      }

      if(ipos == 1)
      {
            InsertFirst(no);
      }
      else if(ipos == NodeCnt +1)
      {
            InsertLast(no);
      }
      else
      {
           struct nodeD<T>* newn = new struct nodeD<T>;
           newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            temp = First;

            for(iCnt = 1;iCnt < ipos-1;iCnt++)
            {
                  temp = temp->next;
            }

            newn->next = temp->next;
            temp->next->prev = newn;

            temp->next = newn;
            newn->prev = temp;
      }
}
template<class T>
void DoublyCircularL<T>:: DeleteAtPos(int ipos)
{
      int iCnt = 0;
      int NodeCnt = 0;

     struct nodeD<T>* temp  = NULL;

      NodeCnt = Count();

      if((ipos < 1)||(ipos > NodeCnt ))
      {
            cout<<"Invalid postion \n";
            return;
      }

      if(ipos == 1)
      {
            DeleteFirst( );
      }
      else if(ipos == NodeCnt )
      {
            DeleteLast();
      }
      else
      {
           
            temp = First;

            for(iCnt = 1;iCnt < ipos-1;iCnt++)
            {
                  temp = temp->next;
            }

           temp->next = temp->next->next;
           delete temp->next->prev;
           temp->next->prev = temp;
      }
}
////////////////////////////////////////////////////////////
template<class T>
class Stack
{
      public:
         struct nodeS<T> * First;
         int iCount;

         Stack();

         bool InStackEmpty();
         void Push(T no); // Insert
         T Pop();    // Delete
         void Display();
};
///////////////////////////////////////////////////////////////
template<class T>
Stack<T> :: Stack()
{
      First = NULL;
      iCount = 0;
}
template<class T>
bool Stack <T>:: InStackEmpty()
{
      if(iCount == 0)
      {
            return true;
      }
      else
      {
            return false;
      }
}
template<class T>
void Stack<T> :: Push(T no)    // InsertFirst
{
      struct nodeS<T> * newn = new nodeS<T>;
      newn->data = no;
      newn->next = NULL;

      if(First == NULL)
      {
            First = newn;
      }
      else
      {
            newn->next = First;
            First = newn;
      
      }
      iCount++;
      cout<<"gets Pushed in the stack Succesfuly"<<"\n";
}
template<class T>
T Stack<T> :: Pop()     // DeleteFirst
{
      if(First == NULL)
      {
            cout<<"Unable to pop the elemnts as stack is empty"<<"\n";
            return -1;

      }
      else
      {
            int value = First ->data;
            struct nodeS<T> * temp = First;

            First = First->next;
            delete temp;

            iCount --;
            return value;
      }
}
template<class T>
void Stack<T> :: Display()
{
      if(First == NULL)
      {
            cout<<"stack is empty"<<"\n";
      }
      else
      {
            cout<<"Elements of Linked List are :";
            struct nodeS<T> * temp = First;

            while(temp !=NULL)
            {
                  cout<<"|"<<temp->data<<"|->";
                  temp = temp->next;
            }
            cout<<"NULL"<<"\n";
      }
}
/////////////////////////////////////////////////////
template<class T>
class Queue
{
      public:
         struct nodeS<T> * First;
         int iCount;

          Queue();

         bool InQueueEmpty();
         void EnQueue(T no); // Insert
         T DeQueue();    // Delete
         void Display();
};
////////////////////////////////////////////////////
template<class T>
 Queue <T>::  Queue()
{
      First = NULL;
      iCount = 0;
}
template<class T>
bool  Queue <T>:: InQueueEmpty()
{
      if(iCount == 0)
      {
            return true;
      }
      else
      {
            return false;
      }
}
template<class T>
void  Queue <T>:: EnQueue(T no)    // InsertLast
{
      struct nodeS<T> * newn = new nodeS<T>;
      newn->data = no;
      newn->next = NULL;

      if(First == NULL)
      {
            First = newn;
      }
      else
      {
            struct nodeS<T> * temp = First;

            while(temp->next !=NULL)
            {
                  temp = temp->next;

            }
            temp->next = newn;
      
      }
      iCount++;
      cout<<no<<" gets EnQueue in the Queue Succesfuly"<<"\n";
}
template<class T>
T  Queue <T>:: DeQueue()     // DeleteFirst
{
      if(First == NULL)
      {
            cout<<"Unable to DeQueue the elemnts as Queue is empty"<<"\n";
            return -1;

      }
      else
      {
            int value = First ->data;
            struct nodeS<T> * temp = First;

            First = First->next;
            delete temp;

            iCount --;
            return value;
      }
}
template<class T>
void  Queue<T> :: Display()
{
      if(First == NULL)
      {
            cout<<"Queue is empty"<<"\n";
      }
      else
      {
            cout<<"Elements of Linked List are :"<<"\n";
            struct nodeS<T> * temp = First;

            while(temp !=NULL)
            {
                  cout<<"|"<<temp->data<<"|->";
                  temp = temp->next;
            }
            cout<<"NULL"<<"\n";
      }
}
/////////////////////////////////////////////////////////////

int main()
{
      Queue<int> objq;

      objq.EnQueue(11);
      objq.EnQueue(21);
      objq.EnQueue(51);
      objq.EnQueue(101);
      
      objq.Display();
      
      int iRetq = objq.DeQueue();
      cout<<"Removed element is :"<<iRetq<<"\n";

      int fRetq = objq.DeQueue();
      cout<<"Removed element is :"<<fRetq<<"\n";

      objq.Display();


     cout<<"--------------------  Stack ----------------------------------------\n";

      Stack<int> objs;

      objs.Push(11);
      objs.Push(21);
      objs.Push(51);
      objs.Push(101);
      
      objs.Display();
      
      int Rets = objs.Pop();
      cout<<"Poped element is :"<<Rets<<"\n";
      objs.Display();

      cout<<"------------------- stck float-------------------------\n";

      Stack<float> objsf;

      objsf.Push(11.5);
      objsf.Push(21.5);
      objsf.Push(51.25);
      objsf.Push(101.58);
      
      objsf.Display();

      cout<<"----------------------- Doubly Linear------------------------------------\n";

      DoublyLL<int> obj1;
      int iRet = 0;

      obj1.InsertFirst(101);
      obj1.InsertFirst(51);
      obj1.InsertFirst(21);
      obj1.InsertFirst(11);
      obj1.Display();
      iRet = obj1.Count();
      cout<<"Number Node Of Linked list are :"<<iRet<<"\n";

      obj1.InsertLast(111);
      obj1.InsertLast(121);
      obj1.Display();

      obj1.InsertAtPos(4,105);
      obj1.Display();

      obj1.DeleteFirst();
      obj1 .Display();

      obj1.DeleteLast();
      obj1.Display();

      obj1.DeleteAtPos(3);
      obj1.Display();

      iRet = obj1.Count();
      cout<<"Number Node Of Linked list are :"<<iRet<<"\n";

      

     cout<<"------------------------- Singly Linear----------------------------------------\n";
 

      SinglyLL<int> Sobj1;
      int SiRet = 0;

      Sobj1.InsertFirst(101);
      Sobj1.InsertFirst(51);
      Sobj1.InsertFirst(21);
      Sobj1.InsertFirst(11);
      Sobj1.Display();
      SiRet = Sobj1.Count();
      cout<<"Number Node Of Linked list are :"<<SiRet<<"\n";

      Sobj1.InsertLast(111);
      Sobj1.InsertLast(121);
      Sobj1.Display();

      Sobj1.InsertAtPos(4,105);
      Sobj1.Display();

      Sobj1.DeleteFirst();
      Sobj1 .Display();

      Sobj1.DeleteLast();
      Sobj1.Display();

      Sobj1.DeleteAtPos(3);
      Sobj1.Display();

      SiRet = Sobj1.Count();
      cout<<"Number Node Of Linked list are :"<<SiRet<<"\n";
      SiRet = Sobj1.SearchFirstOccurnce(101);
    if(iRet == -1)
    {
        printf("There is no such element in LL\n");
    }
    else
    {
        printf("Elements is there at index: %d\n",iRet);
    }

      cout<<"----------------------- Char-------------------------------------\n";

      SinglyLL<char> Sobjc;
     int ScRet = 0;

      Sobjc.InsertFirst('D');
      Sobjc.InsertFirst('D');
      Sobjc.InsertFirst('I');
      Sobjc.InsertFirst('S');
      Sobjc.Display();
      ScRet = Sobjc.Count();
      cout<<"Number Node Of Linked list are :"<<ScRet<<"\n";

      Sobjc.InsertLast('H');
      Sobjc.InsertLast('E');
      Sobjc.InsertLast('S');
      Sobjc.InsertLast('H');
      Sobjc.Display();

      Sobjc.InsertAtPos(6,'U');
      Sobjc.Display();

      Sobjc.DeleteFirst();
      Sobjc .Display();

      Sobjc.DeleteLast();
      Sobjc.Display();

      Sobjc.DeleteAtPos(5);
      Sobjc.Display();

      ScRet = Sobjc.Count();
      cout<<"Number Node Of Linked list are :"<<ScRet<<"\n";

    
      return 0;
}
