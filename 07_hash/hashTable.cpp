#include <iostream>
#include <string> 

#define N 7  

using namespace std; 

typedef struct _reg {
    int key; 
    string data; 
    struct _reg *next; 
} reg; 

class hashTable {
   reg *table[N];

public:
   hashTable() {
       int i; 
       for (i=0; i<N;i++)
          table[i] = NULL; 
   }

   ~hashTable() {
       clear(); 
    }

   int hash(int k) {
      return k%N; 
   }

   int insert(int key, string data) {
      reg *tmp, *last; 
      int i = hash(key); 
      last=table[i]; 
      tmp = (reg *)malloc(sizeof(reg));  
      tmp->key = key; 
      tmp->data = data; 
      tmp->next = NULL; 

      if (last==NULL) {
         table[i] = tmp; 
      }  else {
         while (last->next!=NULL) last = last->next; 
         last->next = tmp; 
      }
      return i; 
   }

   void print() {
      int i; 
      reg *tmp; 
      for (i=0; i<N; i++) {
         cout << i << ": ";
         tmp = table[i]; 
         while(tmp!=NULL) {
              cout << tmp->key << "," << tmp->data << "|\t";  
              tmp = tmp->next; 
         }
         cout << endl; 
      }
   }

   void clear() {
     int i; 
     reg *tmp, *next; 
     for (i=0; i<N; i++) {
       next=table[i]; 
       while(next!=NULL) {
           tmp=next->next; 
           free(next); 
           next=tmp; 
       }   
       table[i]=NULL; 
     }   
   }
};

int main() {
    hashTable t; 
    
    //t.print(); 

    t.insert(133, "Juanito"); 
    t.insert(4, "Pedro"); 
    t.insert(19, "Hugo"); 
    t.insert(33, "Paco"); 
    t.insert(44, "Luis");
    t.insert(100, "Tio Mc"); 
 
    t.print();
    t.clear();    
}

