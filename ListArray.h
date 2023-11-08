#include <iostream>
#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {

   	private:
	    T *arr;
	    int max;
	    int n;
	    static const int MINSIZE = 2;
	    void resize(int new_size){
	    	T* arr2 = new T[new_size];
		for(int i=0;i<n;i++){
		  arr2[i]=arr[i];
		}
		delete[] arr;
		arr = arr2;
		max = new_size;
	    }
	public:
	    void insert(int pos,T e){
	    	 if (pos < 0 || pos > n) {
     		   throw std::out_of_range("fuera de rango");
    		} else {
        		for (int i = n; i >= pos+1; i--) {
            			arr[i] = arr[i-1];
        		}
       			 arr[pos] = e;
       			 n++;
    			}
	    }
	     void append(T e){
	    	if(n>=max){
		  resize(n+1);
		}
		insert(n,e);
	    }

	    void prepend(T e){
		if(n>=max){
                  resize(n+1);
                }
                insert(0,e);
            }

	      T remove(int pos){
	     	T r = arr[pos];
		if(pos>=0 && pos<n){
		   for(int i=pos;i<n;i++){
		   	arr[i] = arr[i+1];
		   }
		   n--;
		}else{
		   throw std::out_of_range("fuera de rango");
		}
		return r;
	     }

	      T get(int pos) const{
	     	 if(pos>=0 && pos<n){
                   return arr[pos];
                 }else{
                   throw std::out_of_range("fuera de rango");
                  }
             }

	      int search(T e) const{
	      	for(int i=0; i<size();i++){
		  if(arr[i]==e){
		    return i;
		  }
		
		 }
		 return -1;
	      }

	      bool empty() const  {
	      	if (n > 0){
			return false;
	        }else{
		    return true;
	         }
		}

	      int size() const {
		  
		    return n;
	      }
	     

	    ListArray(){
		if(MINSIZE!=2){
		   throw std::invalid_argument("Está mal");
		}
		n = 0;
		arr = new T[MINSIZE];
		max = MINSIZE;
	    }
	    
	    ~ListArray(){
	    	delete[] arr;
	    }
	    
	    T operator[](int pos){
	    	if(pos>=0 && pos<n){
                   return arr[pos];
                }else{
                   throw std::out_of_range ("fuera de rango");
                }

	    }

	    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
		    for (int i = 0; i < list.size(); i++) {
     			   out << list.get(i) << " ";
    		    }
		    return out;
	    }	    

	   
	      
	    
};
